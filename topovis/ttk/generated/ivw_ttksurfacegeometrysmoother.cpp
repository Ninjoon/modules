#include "ivw_ttksurfacegeometrysmoother.h"

#include <inviwo/core/common/inviwomodule.h>
#include <inviwo/ttk/processors/ttkgenericprocessor.h>
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
#include <ttkSurfaceGeometrySmoother.h>
#include <warn/pop>

namespace inviwo {
namespace ttkwrapper {
namespace {

#include <warn/push>
#include <warn/ignore/conversion>

struct Wrapper0 {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        filter.SetNumberOfIterations(property.get());
        return true;
    }
    IntProperty property{"NumberOfIterations",
                         "Iteration Number",
                         R"(Number of iterations for the smoothing filter.)"_help,
                         1,
                         std::pair{0, ConstraintBehavior::Ignore},
                         std::pair{100, ConstraintBehavior::Ignore}};
};

struct Wrapper1 {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        filter.SetForceIdentifiersField(property.get());
        return true;
    }
    BoolProperty property{"ForceIdentifiersField", "Force Vertex Identifiers Field",
                          R"(Use a non-default vertex identifiers field.)"_help, false};
};

struct Wrapper2 : FieldSelection {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        if (name.size() == 0) return false;
        filter.SetInputArrayToProcess(0, 0, 0, fieldAssociation.get(), name.get().c_str());
        return true;
    }
    OptionPropertyString name{"name", "Name", {}, 0};

    OptionProperty<vtkDataObject::FieldAssociations> fieldAssociation{
        "fieldAssociation",
        "Field Association",
        {{"points", "Points", vtkDataObject::FIELD_ASSOCIATION_POINTS},
         {"cells", "Cells", vtkDataObject::FIELD_ASSOCIATION_CELLS},
         {"none", "None", vtkDataObject::FIELD_ASSOCIATION_NONE},
         {"pointsThenCells", "Points then Cells",
          vtkDataObject::FIELD_ASSOCIATION_POINTS_THEN_CELLS}},
        3};

    CompositeProperty property{[&]() {
        CompositeProperty tmp{"VertexIdsField", "Identifiers Field",
                              R"(Select the vertex identifiers field.)"_help};
        tmp.addProperties(name, fieldAssociation);
        return tmp;
    }()};

    static constexpr std::string_view inport = "Input";
};

struct Wrapper3 {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        filter.SetUseMaskScalarField(property.get());
        return true;
    }
    BoolProperty property{"UseMaskScalarField", "Use a Scalar Field as Mask",
                          R"(Check this box if an input scalar field should be considered as
vertex mask (used to mark vertices to smooth).)"_help,
                          true};
};

struct Wrapper4 {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        filter.SetForceInputMaskScalarField(property.get());
        return true;
    }
    BoolProperty property{"ForceInputMaskScalarField", "Force Input Mask Scalar Field",
                          R"(Check this box to choose a non-default scalar field as mask
(default mask scalar field is named ttk::MaskScalarFieldName).)"_help,
                          false};
};

struct Wrapper5 : FieldSelection {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        if (name.size() == 0) return false;
        filter.SetInputArrayToProcess(1, 0, 0, fieldAssociation.get(), name.get().c_str());
        return true;
    }
    OptionPropertyString name{"name", "Name", {}, 0};

    OptionProperty<vtkDataObject::FieldAssociations> fieldAssociation{
        "fieldAssociation",
        "Field Association",
        {{"points", "Points", vtkDataObject::FIELD_ASSOCIATION_POINTS},
         {"cells", "Cells", vtkDataObject::FIELD_ASSOCIATION_CELLS},
         {"none", "None", vtkDataObject::FIELD_ASSOCIATION_NONE},
         {"pointsThenCells", "Points then Cells",
          vtkDataObject::FIELD_ASSOCIATION_POINTS_THEN_CELLS}},
        3};

    CompositeProperty property{[&]() {
        CompositeProperty tmp{"InputMaskNew", "Mask Field",
                              R"(Input mask field (used to mark vertices to smooth).)"_help};
        tmp.addProperties(name, fieldAssociation);
        return tmp;
    }()};

    static constexpr std::string_view inport = "Input";
};

struct Wrapper6 {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        filter.SetUseAllCores(property.get());
        return true;
    }
    BoolProperty property{"Debug_UseAllCores", "Use All Cores", R"(Use all available cores.)"_help,
                          true};
};

struct Wrapper7 {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        filter.SetThreadNumber(property.get());
        return true;
    }
    IntProperty property{"Debug_ThreadNumber",
                         "Thread Number",
                         R"(The maximum number of threads.)"_help,
                         1,
                         std::pair{1, ConstraintBehavior::Ignore},
                         std::pair{256, ConstraintBehavior::Ignore}};
};

struct Wrapper8 {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        filter.SetDebugLevel(property.get());
        return true;
    }
    IntProperty property{"Debug_DebugLevel",
                         "Debug Level",
                         R"(Debug level.)"_help,
                         3,
                         std::pair{0, ConstraintBehavior::Ignore},
                         std::pair{5, ConstraintBehavior::Ignore}};
};

struct Wrapper9 {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        filter.SetCompactTriangulationCacheSize(property.get());
        return true;
    }
    DoubleProperty property{"CompactTriangulationCacheSize",
                            "Cache",
                            R"(Set the cache size for the compact triangulation as a
ratio with respect to the total cluster number.)"_help,
                            0.2,
                            std::pair{0.0, ConstraintBehavior::Ignore},
                            std::pair{1.0, ConstraintBehavior::Ignore}};
};

struct Wrapper10 {
    bool set(ttkSurfaceGeometrySmoother& filter) {
        filter.Modified();
        return true;
    }
    ButtonProperty property{"Debug_Execute", "Execute",
                            R"(Executes the filter with the last applied parameters, which is
handy to re-start pipeline execution from a specific element
without changing parameters.)"_help};
};

#include <warn/pop>

}  // namespace
template <>
struct TTKTraits<ttkSurfaceGeometrySmoother> {
    static constexpr std::string_view className = "ttkSurfaceGeometrySmoother";
    static constexpr std::string_view identifier = "ttkSurfaceGeometrySmoother";
    static constexpr std::string_view displayName = "TTK SurfaceGeometrySmoother";
    static constexpr std::string_view category = "topology";
    static constexpr std::string_view tags = "TTK";
    inline static std::array<InputData, 2> inports = {
        InputData{"Input", "vtkPointSet", 1, R"(Point-set to smooth.)"},
        InputData{"Surface", "vtkPointSet", -1, R"(Input triangulated surface.)"}};
    inline static std::array<OutputData, 0> outports = {};
    inline static std::array<Group, 2> groups = {
        Group{"Input options",
              {"Input", "NumberOfIterations", "ForceIdentifiersField", "VertexIdsField",
               "UseMaskScalarField", "ForceInputMaskScalarField", "InputMaskNew"}},
        Group{"Testing",
              {"Debug_UseAllCores", "Debug_ThreadNumber", "Debug_DebugLevel",
               "CompactTriangulationCacheSize", "Debug_Execute"}}};
    std::tuple<Wrapper0, Wrapper1, Wrapper2, Wrapper3, Wrapper4, Wrapper5, Wrapper6, Wrapper7,
               Wrapper8, Wrapper9, Wrapper10>
        properties;
    static constexpr std::string_view doc = R"(GeometrySmoother with a twist!

This class smoothes and projects a 1D or a 2D mesh onto a 2D
closed triangulated surface

Online examples:

- https://topology-tool-kit.github.io/examples/persistentGenerators_casting/

- https://topology-tool-kit.github.io/examples/persistentGenerators_fertility/

- https://topology-tool-kit.github.io/examples/persistentGenerators_skull/)";
};

void registerttkSurfaceGeometrySmoother(InviwoModule* module) {
    module->registerProcessor<TTKGenericProcessor<ttkSurfaceGeometrySmoother>>();
}

}  // namespace ttkwrapper
}  // namespace inviwo
