/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2020-2024 Inviwo Foundation
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

#pragma once

#include <inviwo/devtools/devtoolsmoduledefine.h>
#include <inviwo/core/common/inviwo.h>
#include <inviwo/core/processors/processor.h>
#include <inviwo/core/properties/boolproperty.h>
#include <inviwo/core/properties/stringproperty.h>
#include <inviwo/core/ports/imageport.h>
#include <modules/fontrendering/properties/fontproperty.h>
#include <modules/fontrendering/textrenderer.h>

namespace inviwo {

/** \docpage{org.inviwo.LogRendererProcessors, Log Renderer Processors}
 * ![](org.inviwo.LogRendererProcessors.png?classIdentifier=org.inviwo.LogRendererProcessors)
 * A Processor that listens to Log messages and prints them to a canvas.
 *
 */
class IVW_MODULE_DEVTOOLS_API LogRendererProcessors : public Processor {
    class LoggerHandler : public Logger {
    public:
        // Inherited via Logger
        LoggerHandler(LogRendererProcessors* owner) : owner_(owner) {}

        virtual ~LoggerHandler() { owner_ = nullptr; }

        virtual void log(std::string_view logSource, LogLevel logLevel, LogAudience audience,
                         std::string_view file, std::string_view function, int line,
                         std::string_view msg) override;

        LogRendererProcessors* owner_;
    };

public:
    LogRendererProcessors();
    virtual ~LogRendererProcessors() = default;

    virtual void process() override;

    virtual const ProcessorInfo& getProcessorInfo() const override;
    static const ProcessorInfo processorInfo_;

private:
    ImageOutport outport_;
    FontProperty font_;

    StringProperty fmt_;
    StringProperty fmtDesc_;

    BoolProperty logInfo_;
    BoolProperty logWarnings_;
    BoolProperty logErrors_;

    TextRenderer textRenderer_;

    std::vector<std::string> rows_;

    std::shared_ptr<LoggerHandler> loggerHandler_;
};

}  // namespace inviwo
