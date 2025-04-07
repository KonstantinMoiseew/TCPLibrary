cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)
set(CMAKE_CXX_COMPILER clang++-15)
set(CMAKE_C_COMPILER clang-15)
set(CMAKE_CXX_EXTENSIONS OFF) #Use pure -std=c++, instead -std=gnu++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LINK_DEPENDS_NO_SHARED ON)
set(CMAKE_LINK_WHAT_YOU_USE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #generates a compile_commands.json

set(CMAKE_PREFIX_PATH "../Qt6.2.4.1")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)

set(this_target "TCPServer")
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release RelWithDebInfo)


set(OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../Build/${PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${OUTPUT_DIRECTORY})
set(CMAKE_PDB_OUTPUT_DIRECTORY      ${OUTPUT_DIRECTORY})

# https://stackoverflow.com/questions/7747857/in-cmake-how-do-i-work-around-the-debug-and-release-directories-visual-studio-2
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
  string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIRECTORY})
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIRECTORY})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIRECTORY})
  set(CMAKE_PDB_OUTPUT_DIRECTORY_${OUTPUTCONFIG}     ${OUTPUT_DIRECTORY})
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

set(${this_target}_SOURCE_FILES
        tcpserver.cpp
        conversion.cpp
        main.cpp

)

add_executable(${this_target} ${${this_target}_SOURCE_FILES})



target_include_directories(${this_target} PRIVATE

  "."

)


target_link_libraries(${this_target} PRIVATE
  Qt6::Core

)

target_link_directories(${this_target} PRIVATE

)

target_compile_options(${this_target} PRIVATE
#disabled
#"-fPIC"
"-Werror"
"-Wno-#pragma-messages"
"-Wno-bitfield-constant-conversion"
"-Wno-constant-conversion"
"-Wno-defaulted-function-deleted"
"-Wno-deprecated-anon-enum-enum-conversion"
"-Wno-deprecated-declarations"
"-Wno-deprecated-enum-compare"
"-Wno-deprecated-enum-compare-conditional"
"-Wno-deprecated-enum-enum-conversion"
"-Wno-deprecated-enum-float-conversion"
"-Wno-deprecated-volatile"
"-Wno-dynamic-class-memaccess"
"-Wno-enum-compare-switch"
"-Wno-extra-tokens"
"-Wno-ignored-attributes"
"-Wno-ignored-reference-qualifiers"
"-Wno-implicit-const-int-float-conversion"
"-Wno-int-to-pointer-cast"
"-Wno-int-to-void-pointer-cast"
"-Wno-logical-not-parentheses"
"-Wno-microsoft-cast"
"-Wno-microsoft-template-shadow"
"-Wno-missing-declarations"
"-Wno-multichar"
"-Wno-non-literal-null-conversion"
"-Wno-parentheses"
"-Wno-parentheses-equality"
"-Wno-pointer-bool-conversion"
"-Wno-pointer-to-int-cast"
"-Wno-potentially-evaluated-expression"
"-Wno-reinterpret-base-class"
"-Wno-return-type-c-linkage"
"-Wno-shift-negative-value"
"-Wno-sizeof-pointer-memaccess"
"-Wno-switch"
"-Wno-undefined-bool-conversion"
"-Wno-unused-comparison"
"-Wno-unused-value"
"-Wno-deprecated-builtins"
# enabled
"-Wdelete-non-virtual-dtor"
"-Wmove"
"-Warray-parameter"
"-Wframe-address"
"-Wimplicit"
"-Winfinite-recursion"
"-Wint-in-bool-context"
"-Wmismatched-tags"
"-Wmissing-braces"
"-Wrange-loop-construct"
"-Wself-assign"
# TODO: "-Wundefined-reinterpret-cast"
# TODO: "-Wweak-vtables"
"-Wloop-analysis"
"-Wunreachable-code"
"-Wunused-function"
"-Wold-style-cast"
"-Wgnu"
# TODO: "-Wextra-semi"

#ADDITIONAL_COMPILE_OPTIONS_CXX for UNIX !!! Kompas24 stoped crashing trying to add rtw
"-fms-extensions"
"-fvisibility-ms-compat"
"-fexperimental-library"
#"-stdlib=libc++"
"-D_LIBCPP_REMOVE_TRANSITIVE_INCLUDES"


"-fconstexpr-steps=10000000"
)


