if (PARAVIEW_BUILD_QT_GUI AND PARAVIEW_ENABLE_PYTHON AND PARAVIEW_ENABLE_CATALYST)
  pv_plugin(CatalystScriptGeneratorPlugin
    DESCRIPTION "Plugins for creating co-processing Python scripts"
    DEFAULT_ENABLED)
endif()
