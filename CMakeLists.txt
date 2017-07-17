cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(gq
        VERSION 0.1.0
        LANGUAGES CXX)
set(GLOBAL PROPERTY SONAME 0)
set(GLOBAL PROPERTY PROJECT_BRIEF "An experimental generic query library for modern C++.")

# For C++14 support
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Various safety checks
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message( FATAL_ERROR "In-source builds not allowed. To build, create a folder and run CMake from there." )
endif()

# Build flags
add_definitions(-Dgq__BUILDING)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-Dgq__DEBUG)
    add_definitions(-Dgl__MACRODEBUG)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    add_definitions(-Dgq__STRIPPED)
endif()


#
# [ TARGETS ]
#


# Third-party header-only dependency target
set(ext_iapi ${PROJECT_NAME}-ext-iapi)
set(ext_iapi_dir_root "${CMAKE_CURRENT_SOURCE_DIR}/ext/include")
add_library(${ext_iapi} INTERFACE)
target_include_directories(${ext_iapi} INTERFACE ${ext_iapi_dir_root})
target_sources(${ext_iapi} INTERFACE
    "${ext_iapi_dir_root}/catch.hpp"
    )


# Public API target
set(api ${PROJECT_NAME}-api)
set(api_dir_root "${CMAKE_CURRENT_SOURCE_DIR}/include")
add_library(${api} INTERFACE)
target_include_directories(${api} INTERFACE ${api_dir_root})
target_link_libraries(${api} INTERFACE ${ext_iapi})
target_sources(${api} INTERFACE
    # gq (config)
    "${api_dir_root}/gq.cfg.hpp"
    "${api_dir_root}/gq.def.hpp"

    # gq (core)
    "${api_dir_root}/gq/gq.fwd.hpp"
    )


# Internal API target
set(iapi ${PROJECT_NAME}-iapi)
set(iapi_dir_root "${CMAKE_CURRENT_SOURCE_DIR}/src/include")
add_library(${iapi} INTERFACE)
target_include_directories(${iapi} INTERFACE ${iapi_dir_root})
target_link_libraries(${iapi} INTERFACE ${api})


# Test-only internal API target
set(test_iapi ${PROJECT_NAME}-test-iapi)
set(test_iapi_dir_root "${CMAKE_CURRENT_SOURCE_DIR}/test/include")
add_library(${test_iapi} INTERFACE)
target_include_directories(${test_iapi} INTERFACE ${test_iapi_dir_root})
target_link_libraries(${test_iapi} INTERFACE ${iapi})
#target_sources(${test_iapi} INTERFACE
#    "${test_iapi_dir_root}/gq_catch.hpp"
#    )


# Main binary/library/executable target
#set(main ${PROJECT_NAME}) # Main target
#    set(main_dir_root ${CMAKE_CURRENT_SOURCE_DIR}/src)
#    set(main_objs ${PROJECT_NAME}-api-objs)
#    set(main_deps ${api} ${iapi} ${ext_iapi})
#    set(main_sharedlib ${PROJECT_NAME})
#    set(main_staticlib ${PROJECT_NAME}-static)

# Test target
set(test ${PROJECT_NAME}-test)
set(test_dir_root "${CMAKE_CURRENT_SOURCE_DIR}/test")
set(test_dir_unit "${CMAKE_CURRENT_SOURCE_DIR}/test/unit")
add_executable(${test}
    "${test_dir_unit}/main.unit.cpp"
)
target_link_libraries(${test} ${test_iapi})
enable_testing()
add_test(NAME ${test} COMMAND "./${test}")


#
# [ DOCUMENTATION GENERATION ]
#


find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(${PROJECT_NAME}-doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif(DOXYGEN_FOUND)


#
# [ CMAKE DEBUGGING ]
#


#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()
