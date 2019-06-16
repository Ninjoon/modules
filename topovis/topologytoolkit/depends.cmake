# Inviwo module dependencies for current module
# List modules on the format "Inviwo<ModuleName>Module"
set(dependencies
    InviwoPlottingModule
    #InviwoEigenUtilsModule
)

# Add an alias for this module. Several modules can share an alias. 
# Useful if several modules implement the same functionality.
# A depending module can depend on the alias, and a drop down of 
# available implementations will be presented in CMake  
#set(aliases ModuleAlias)

# Mark the module as protected to prevent it from being reloaded
# when using runtime module reloading. 
#set(protected ON)
