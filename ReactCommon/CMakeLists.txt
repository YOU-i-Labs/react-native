cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(REACT_COMMON_YOGA_SOURCE
    yoga/yoga/YGConfig.cpp
    yoga/yoga/YGNodePrint.cpp
    yoga/yoga/YGNode.cpp
    yoga/yoga/YGLayout.cpp
    yoga/yoga/Utils.cpp
    yoga/yoga/YGEnums.cpp
    yoga/yoga/Yoga.cpp
    yoga/yoga/YGStyle.cpp
)

set(REACT_COMMON_PRIVATE_DATA_SOURCE
    privatedata/PrivateDataBase.cpp
)

set(REACT_COMMON_MICRO_PROFILER_SOURCE
    microprofiler/MicroProfiler.cpp
)

set(REACT_COMMON_JS_INSPECTOR_SOURCE
    jsinspector/InspectorInterfaces.cpp
)

set(REACT_COMMON_JSC_HELPERS_SOURCE
    jschelpers/Value.cpp
    jschelpers/Unicode.cpp
    jschelpers/JSCWrapper.cpp
    jschelpers/JSCHelpers.cpp
    jschelpers/systemJSCWrapper.cpp
)

set(REACT_COMMON_JSC_CXXREACT_SOURCE
    cxxreact/JSCExecutor.cpp
    cxxreact/JSCUtils.cpp
    cxxreact/JSCTracing.cpp
    cxxreact/JSCSamplingProfiler.cpp
    cxxreact/JSCPerfStats.cpp
    cxxreact/JSCNativeModules.cpp
    cxxreact/JSCMemory.cpp
    cxxreact/JSCLegacyTracing.cpp
    cxxreact/Platform.cpp
)

set(REACT_COMMON_CXXREACT_SOURCE
    cxxreact/JSBundleType.cpp
    cxxreact/JSBigString.cpp
    cxxreact/Instance.cpp
    cxxreact/CxxNativeModule.cpp
    cxxreact/RAMBundleRegistry.cpp
    cxxreact/NativeToJsBridge.cpp
    cxxreact/ModuleRegistry.cpp
    cxxreact/MethodCall.cpp
    cxxreact/JSIndexedRAMBundle.cpp
)

set(REACT_COMMON_YOGA_HEADERS
    yoga/yoga/Utils.h
    yoga/yoga/YGConfig.h
    yoga/yoga/YGNodePrint.h
    yoga/yoga/YGMacros.h
    yoga/yoga/YGEnums.h
    yoga/yoga/Yoga.h
    yoga/yoga/Yoga-internal.h
    yoga/yoga/YGStyle.h
    yoga/yoga/YGNode.h
    yoga/yoga/YGLayout.h
)

set(REACT_COMMON_PRIVATE_DATA_HEADERS
    privatedata/PrivateDataBase.h
)

set(REACT_COMMON_MICRO_PROFILER_HEADERS
    microprofiler/MicroProfiler.h
)

set(REACT_COMMON_JS_INSPECTOR_HEADERS
    jsinspector/InspectorInterfaces.h
)

set(REACT_COMMON_JSC_HELPERS_HEADERS
    jschelpers/JavaScriptCore.h
    jschelpers/JSCHelpers.h
    jschelpers/JSCWrapper.h
    jschelpers/noncopyable.h
    jschelpers/Value.h
    jschelpers/Unicode.h
)

set(REACT_COMMON_JSC_CXXREACT_HEADERS
    cxxreact/JSCExecutor.h
    cxxreact/JSCUtils.h
    cxxreact/JSCTracing.h
    cxxreact/JSCSamplingProfiler.h
    cxxreact/JSCPerfStats.h
    cxxreact/JSCNativeModules.h
    cxxreact/JSCMemory.h
    cxxreact/JSCLegacyTracing.h
    cxxreact/Platform.h
)

set(REACT_COMMON_CXXREACT_HEADERS
    cxxreact/Instance.h
    cxxreact/CxxNativeModule.h
    cxxreact/CxxModule.h
    cxxreact/JSExecutor.h
    cxxreact/JSBundleType.h
    cxxreact/SystraceSection.h
    cxxreact/SharedProxyCxxModule.h
    cxxreact/RecoverableError.h
    cxxreact/RAMBundleRegistry.h
    cxxreact/NativeToJsBridge.h
    cxxreact/NativeModule.h
    cxxreact/ModuleRegistry.h
    cxxreact/MethodCall.h
    cxxreact/MessageQueueThread.h
    cxxreact/JsArgumentHelpers.h
    cxxreact/JsArgumentHelpers-inl.h
    cxxreact/JSModulesUnbundle.h
    cxxreact/JSIndexedRAMBundle.h
    cxxreact/JSBigString.h
)

set(REACT_COMMON_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/ReactCommonStub.cpp # Stub for OSes other than OSX/iOS/tvOS
    ${REACT_COMMON_YOGA_SOURCE}
    ${REACT_COMMON_PRIVATE_DATA_SOURCE}
    ${REACT_COMMON_MICRO_PROFILER_SOURCE}
    ${REACT_COMMON_JS_INSPECTOR_SOURCE}
    ${REACT_COMMON_CXXREACT_SOURCE}
)

set(REACT_COMMON_HEADERS
    ${REACT_COMMON_YOGA_HEADERS}
    ${REACT_COMMON_PRIVATE_DATA_HEADERS}
    ${REACT_COMMON_MICRO_PROFILER_HEADERS}
    ${REACT_COMMON_JS_INSPECTOR_HEADERS}
    ${REACT_COMMON_CXXREACT_HEADERS}
)

set(MMAN_WIN32_SOURCE
    sys/mman.c
)

set(MMAN_WIN32_HEADERS
    sys/mman.h
)

if(USE_JSC)
    list(APPEND REACT_COMMON_SOURCE ${REACT_COMMON_JSC_HELPERS_SOURCE} ${REACT_COMMON_JSC_CXXREACT_SOURCE})
    list(APPEND REACT_COMMON_HEADERS ${REACT_COMMON_JSC_HELPERS_HEADERS} ${REACT_COMMON_JSC_HEADERS})
endif(USE_JSC)

if(USE_MMAN_WIN32)
    list(APPEND REACT_COMMON_SOURCE ${MMAN_WIN32_SOURCE})
    list(APPEND REACT_COMMON_HEADERS ${MMAN_WIN32_HEADERS})
else()
    set(_EXCLUDE_MMAN_WIN32_PATTERN "*mman.*")
endif()

hunter_add_package(folly)
find_package(folly CONFIG REQUIRED)

hunter_add_package(double-conversion)
find_package(double-conversion CONFIG REQUIRED)

hunter_add_package(glog)
find_package(glog CONFIG REQUIRED)

if (USE_JSC AND NOT APPLE)
    # matches the target_link_libraries below
    hunter_add_package(WebKit)
    find_package(WebKit CONFIG REQUIRED)
endif()

include(GNUInstallDirs)
set(_ReactCommon_CMake_EXPORT_NAME "ReactCommon")
set(_ReactCommon_CMake_BINDIR ${CMAKE_INSTALL_BINDIR})
set(_ReactCommon_CMake_INCLUDE_DIR ${CMAKE_INSTALL_INCLUDEDIR}/ReactCommon)
set(_ReactCommon_CMake_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(_ReactCommon_CMake_INSTALLDIR ${_ReactNative_CMake_INSTALLDIR})

add_library(ReactCommon ${REACT_COMMON_SOURCE} ${REACT_COMMON_HEADERS})

target_include_directories(ReactCommon PUBLIC
    $<INSTALL_INTERFACE:${_ReactCommon_CMake_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${_ReactCommon_CMake_INCLUDE_DIR}/yoga>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/yoga>
)

target_link_libraries(ReactCommon PUBLIC
    Folly::folly
    double-conversion::double-conversion
    glog::glog
)

if (USE_JSC AND NOT APPLE)
    # matches the hunter_add_package above
    target_link_libraries(ReactCommon PUBLIC WebKit::JavaScriptCore)
endif() 

if (CMAKE_CXX_STANDARD GREATER_EQUAL 17)
    target_compile_definitions(ReactCommon
        PRIVATE _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
    )
endif()

if (MSVC)
    target_compile_definitions(ReactCommon
        PRIVATE _CRT_SECURE_NO_WARNINGS
    )
endif()

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/generated/${_ReactCommon_CMake_EXPORT_NAME}Config.cmake
    INSTALL_DESTINATION ${_ReactCommon_CMake_INSTALLDIR}
    NO_SET_AND_CHECK_MACRO
)

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/generated/${_ReactCommon_CMake_EXPORT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ExactVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/generated/${_ReactCommon_CMake_EXPORT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/generated/${_ReactCommon_CMake_EXPORT_NAME}ConfigVersion.cmake
    DESTINATION ${_ReactCommon_CMake_INSTALLDIR}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION ${_ReactCommon_CMake_INCLUDE_DIR}
    FILES_MATCHING 
    PATTERN "*.h*"
    PATTERN "${_EXCLUDE_MMAN_WIN32_PATTERN}" EXCLUDE
)

install(TARGETS ReactCommon EXPORT ${_ReactCommon_CMake_EXPORT_NAME}
    ARCHIVE DESTINATION ${_ReactCommon_CMake_LIBDIR}
    LIBRARY DESTINATION ${_ReactCommon_CMake_LIBDIR}
    INCLUDES DESTINATION ${_ReactCommon_CMake_INCLUDEDIR}
)

install(EXPORT ${_ReactCommon_CMake_EXPORT_NAME} NAMESPACE ${_ReactNative_EXPORTS_NAMESPACE}
    DESTINATION ${_ReactCommon_CMake_INSTALLDIR}
    FILE "${_ReactCommon_CMake_EXPORT_NAME}Targets.cmake"
)
