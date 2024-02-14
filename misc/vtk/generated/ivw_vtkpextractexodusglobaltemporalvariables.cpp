#include "ivw_vtkpextractexodusglobaltemporalvariables.h"
#include <inviwo/core/common/inviwomodule.h>
#include <inviwo/vtk/processors/vtkgenericprocessor.h>
#include <inviwo/core/properties/ordinalproperty.h>
#include <inviwo/core/properties/optionproperty.h>
#include <inviwo/core/properties/boolproperty.h>
#include <inviwo/core/properties/buttonproperty.h>
#include <inviwo/core/properties/stringproperty.h>
#include <inviwo/core/properties/fileproperty.h>

#include <tuple>
#include <array>
#include <string_view>

#include <warn/push>
#include <warn/ignore/all>
#include <vtkDataObject.h>
#include <vtkPExtractExodusGlobalTemporalVariables.h>
#include <warn/pop>

namespace inviwo {
namespace vtkwrapper {
namespace {

#include <warn/push>
#include <warn/ignore/conversion>

#include <warn/pop>

}  // namespace
template <>
struct VTKTraits<vtkPExtractExodusGlobalTemporalVariables> {
    static constexpr std::string_view uri = "vtk.vtkPExtractExodusGlobalTemporalVariables";
    static constexpr std::string_view className = "vtkPExtractExodusGlobalTemporalVariables";
    static constexpr std::string_view identifier = "ExtractFieldDataOverTime";
    static constexpr std::string_view displayName = "Plot Global Variables Over Time";
    static constexpr std::string_view category = "vtk";
    static constexpr std::string_view tags = "VTK";
    inline static std::array<InputData, 1> inports = {
        InputData{"Input", "vtkDataSet", -1, R"(The input from which the selection is
extracted.)"}};
    inline static std::array<OutputData, 0> outports = {};
    inline static std::array<Group, 0> groups = {};
    std::tuple<> properties;
    static constexpr std::string_view doc = R"(This filter extracts the variables that reside in a
dataset's field data and are defined for all timesteps. Such variables
are generated by certain readers, like the Exodus reader.)";
};

void registervtkPExtractExodusGlobalTemporalVariables(InviwoModule* module) {
    module->registerProcessor<VTKGenericProcessor<vtkPExtractExodusGlobalTemporalVariables>>();
}

}  // namespace vtkwrapper
}  // namespace inviwo
