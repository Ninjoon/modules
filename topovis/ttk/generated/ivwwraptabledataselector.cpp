#include "ivwwraptabledataselector.h"

#include <inviwo/core/common/inviwomodule.h>
#include <inviwo/ttk/processors/ttkgenericprocessor.h>
#include <inviwo/core/properties/ordinalproperty.h>
#include <inviwo/core/properties/optionproperty.h>
#include <inviwo/core/properties/boolproperty.h>
#include <inviwo/core/properties/stringproperty.h>
#include <inviwo/core/properties/fileproperty.h>

#include <tuple>
#include <array>
#include <string_view>

#include <warn/push>
#include <warn/ignore/all>
#include "ttkTableDataSelector.h"
#include <warn/pop>

namespace inviwo {
namespace ttkwrapper {
namespace {

#include <warn/push>
#include <warn/ignore/conversion>

struct Wrapper0 {
    bool set(ttkTableDataSelector& filter) {
        filter.SetRangeId(property.get(0), property.get(1));
        return true;
    }
    IntVec2Property property{"RangeId", "Range Id", ivec2{0, 999},
                             std::pair{ivec2{0}, ConstraintBehavior::Ignore},
                             std::pair{ivec2{100}, ConstraintBehavior::Ignore}};
};

struct Wrapper1 {
    bool set(ttkTableDataSelector& filter) {
        filter.SetRegexpString(property.get().c_str());
        return true;
    }
    StringProperty property{"RegexFilter", "RegexFilter", ".*"};
};

struct Wrapper2 {
    bool set(ttkTableDataSelector& filter) {
        filter.SetUseAllCores(property.get());
        return true;
    }
    BoolProperty property{"Debug_UseAllCores", "Use All Cores", true};
};

struct Wrapper3 {
    bool set(ttkTableDataSelector& filter) {
        filter.SetThreadNumber(property.get());
        return true;
    }
    IntProperty property{"Debug_ThreadNumber", "Thread Number", 1,
                         std::pair{1, ConstraintBehavior::Ignore},
                         std::pair{256, ConstraintBehavior::Ignore}};
};

struct Wrapper4 {
    bool set(ttkTableDataSelector& filter) {
        filter.SetDebugLevel(property.get());
        return true;
    }
    IntProperty property{"Debug_DebugLevel", "Debug Level", 3,
                         std::pair{0, ConstraintBehavior::Ignore},
                         std::pair{5, ConstraintBehavior::Ignore}};
};

#include <warn/pop>

}  // namespace
template <>
struct TTKTraits<ttkTableDataSelector> {
    static constexpr std::string_view identifier = "ttkTableDataSelector";
    static constexpr std::string_view displayName = "TTK TableDataSelector";
    inline static std::array<InputData, 1> inports = {InputData{"Input", "vtkTable", -1}};
    inline static std::array<OutputData, 0> outports = {};
    inline static std::array<Group, 2> groups = {
        Group{"Input options", {"ScalarFields", "RangeId", "RegexFilter"}},
        Group{"Testing",
              {"Debug_UseAllCores", "Debug_ThreadNumber", "Debug_DebugLevel", "Debug_Execute"}}};
    std::tuple<Wrapper0, Wrapper1, Wrapper2, Wrapper3, Wrapper4> properties;
};

void registerttkTableDataSelector(InviwoModule* module) {
    module->registerProcessor<TTKGenericProcessor<ttkTableDataSelector>>();
}

}  // namespace ttkwrapper
}  // namespace inviwo
