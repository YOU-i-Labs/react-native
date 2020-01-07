cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

include(${CMAKE_CURRENT_LIST_DIR}/cmake/HunterGate.cmake)
HunterGate(
    URL "https://api.github.com/repos/You-i-Labs/Hunter/tarball/v0.21.10-youi-p3?access_token=$ENV{GITHUB_ACCESS_TOKEN}"
    SHA1 "72645851d85509ecd5602231e5d4655b1c56d03d"
)

project(react-native VERSION "0.60.6")

option(USE_JSC "" ON)

set(_ReactNative_EXPORTS_NAMESPACE "react-native::")
set(_ReactNative_EXPORT_NAME ${PROJECT_NAME})

include(GNUInstallDirs)
set(_ReactNative_CMake_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(_ReactNative_CMake_INSTALLDIR ${_ReactNative_CMake_LIBDIR}/cmake/${_ReactNative_EXPORT_NAME})

add_subdirectory(ReactCommon)

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/generated/${_ReactNative_EXPORT_NAME}Config.cmake
    INSTALL_DESTINATION ${_ReactNative_CMake_INSTALLDIR}
)

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/generated/${_ReactNative_EXPORT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ExactVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/generated/${_ReactNative_EXPORT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/generated/${_ReactNative_EXPORT_NAME}ConfigVersion.cmake
    DESTINATION ${_ReactNative_CMake_INSTALLDIR}
)
