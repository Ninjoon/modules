/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2023 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************/

#include <inviwo/vtk/processors/vtktoimage.h>

#include <inviwo/core/datastructures/image/image.h>
#include <inviwo/core/datastructures/image/layer.h>
#include <inviwo/core/util/utilities.h>

#include <inviwo/vtk/util/arrayutils.h>

#include <vtkImageData.h>
#include <vtkPointData.h>
#include <vtkDataArray.h>
#include <vtkDataSet.h>

namespace inviwo {

// The Class Identifier has to be globally unique. Use a reverse DNS naming scheme
const ProcessorInfo VTKToImage::processorInfo_{
    "org.inviwo.VTKToImage",               // Class identifier
    "VTK To Image",                        // Display name
    "VTK",                                 // Category
    CodeState::Experimental,               // Code state
    Tag::CPU | Tag{"VTK"} | Tag{"Image"},  // Tags
    R"(Converts a VTKImageData dataset to an Inviwo image)"_unindentHelp};

const ProcessorInfo VTKToImage::getProcessorInfo() const { return processorInfo_; }

VTKToImage::VTKToImage()
    : Processor{}
    , inport_{"vtkdata", VTK_IMAGE_DATA, "VTK dataset. Only VTK image data is accepted."_help}
    , outport_{"outport", "Image extracted from the VTK dataset"_help}
    , source_{"source", "Source"}
    , precision_{"precision",
                 "Output Precision",
                 {{"input", "Same As Input", 0},
                  {"low", "8 bit", 8},
                  {"medium", "16 bit", 16},
                  {"high", "32 bit", 32},
                  {"full", "64 bit", 64}},
                 0}
    , information_("Information", "Data information") {

    outport_.setHandleResizeEvents(false);
    addPorts(inport_, outport_);

    addProperties(source_, precision_, information_);
}

void VTKToImage::updateSources(vtkDataSet* data) {
    std::vector<OptionPropertyOption<int>> opts;

    if (data) {
        auto arrays = data->GetPointData();
        const auto nArrays = arrays->GetNumberOfArrays();
        for (int i = 0; i < nArrays; ++i) {
            auto array = arrays->GetAbstractArray(i);
            opts.emplace_back(
                util::stripIdentifier(array->GetName()),
                fmt::format("{} ({}D {})", array->GetName(), array->GetNumberOfComponents(),
                            array->GetDataTypeAsString()),
                i);
        }
    }

    source_.replaceOptions(opts);
}

void VTKToImage::process() {
    auto data = inport_.getData();
    auto vtkImg = vtkImageData::SafeDownCast(data);

    if (inport_.isChanged()) {
        updateSources(vtkImg);
    }

    if (source_.size() == 0) {
        outport_.detachData();
        return;
    }

    if (inport_.isChanged() || source_.isModified() || precision_.isModified()) {
        layer_ = vtk::vtkImageDataToLayer(vtkImg, source_.getSelectedValue(), precision_);
    }

    auto image = std::make_shared<Image>(layer_);
    information_.updateForNewImage(*image);

    outport_.setData(image);
}

}  // namespace inviwo
