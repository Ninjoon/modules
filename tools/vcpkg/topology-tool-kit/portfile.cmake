vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO topology-tool-kit/ttk
    REF 2317a20bfcdaf04808d74bf2330be86d2f516a10 
    SHA512 cda720db8f0601fae934a541f8f8a893eba510e64003a446ddefbfb9fb2cebf3b902258a0349de6317fa55b7e2034e396f6ed60205dd385be734d1147d2539d5
    HEAD_REF master
    PATCHES "cmake-config-files.patch"
)

vcpkg_configure_cmake(
    SOURCE_PATH ${SOURCE_PATH}
    PREFER_NINJA
    OPTIONS
        -DTTK_BUILD_DOCUMENTATION=OFF
        -DTTK_BUILD_PARAVIEW_PLUGINS=OFF
        -DTTK_BUILD_STANDALONE_APPS=OFF
        -DTTK_BUILD_VTK_PYTHON_MODULE=OFF
        -DTTK_BUILD_VTK_WRAPPERS=ON
        -DTTK_ENABLE_EIGEN=ON
        -DTTK_ENABLE_ZLIB=ON
        -DTTK_ENABLE_OPENMP=OFF
        -DTTK_ENABLE_SCIKIT_LEARN=OFF
)
vcpkg_install_cmake()
vcpkg_copy_pdbs()
vcpkg_fixup_cmake_targets(
    CONFIG_PATH lib/cmake
    TARGET_PATH share/topology-tool-kit 
)
#vcpkg_fixup_cmake_targets(
#    CONFIG_PATH lib/cmake/ttkBase 
#   TARGET_PATH share/topology-tool-kit 
#    DO_NOT_DELETE_PARENT_CONFIG_PATH
#)
#vcpkg_fixup_cmake_targets(
#    CONFIG_PATH lib/cmake/ttkVTK 
#    TARGET_PATH share/topology-tool-kit 
#    DO_NOT_DELETE_PARENT_CONFIG_PATH
#)
#file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}lib/cmake" "${CURRENT_PACKAGES_DIR}/debug/lib/cmake")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

file(
    INSTALL ${SOURCE_PATH}/LICENSE 
    DESTINATION ${CURRENT_PACKAGES_DIR}/share/topology-tool-kit 
    RENAME copyright
)
