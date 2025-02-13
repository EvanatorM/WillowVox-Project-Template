cmake_minimum_required(VERSION 3.20)
project(TemplateGame LANGUAGES CXX C)
set(CMAKE_GENERATOR_PLATFORM x64)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the executable
add_executable(TemplateGame
    src/main.cpp
    # ADD ANY ADDITIONAL CPP FILES HERE
)

# set variables based on build type
if (CMAKE_CONFIGURATION_TYPES)
    set(WILLOWVOX_COPY_PATH ${CMAKE_BINARY_DIR}/bin/$<CONFIG>)
    set(WILLOWVOX_DLL ${CMAKE_SOURCE_DIR}/WillowVoxEngine/bin/$<CONFIG>/WillowVoxEngine${CMAKE_SHARED_LIBRARY_SUFFIX})
    set(WILLOWVOX_LIB ${CMAKE_SOURCE_DIR}/WillowVoxEngine/lib/$<CONFIG>/WillowVoxEngine${CMAKE_STATIC_LIBRARY_SUFFIX})
else()
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(WILLOWVOX_DLL ${CMAKE_SOURCE_DIR}/WillowVoxEngine/bin/debug/WillowVoxEngine${CMAKE_SHARED_LIBRARY_SUFFIX})
        set(WILLOWVOX_LIB ${CMAKE_SOURCE_DIR}/WillowVoxEngine/lib/debug/WillowVoxEngine${CMAKE_STATIC_LIBRARY_SUFFIX})
        set(WILLOWVOX_COPY_PATH $<TARGET_FILE_DIR:TemplateGame>)
    else()
        set(WILLOWVOX_DLL ${CMAKE_SOURCE_DIR}/WillowVoxEngine/bin/release/WillowVoxEngine${CMAKE_SHARED_LIBRARY_SUFFIX})
        set(WILLOWVOX_LIB ${CMAKE_SOURCE_DIR}/WillowVoxEngine/lib/release/WillowVoxEngine${CMAKE_STATIC_LIBRARY_SUFFIX})
        set(WILLOWVOX_COPY_PATH $<TARGET_FILE_DIR:TemplateGame>)
    endif()
endif()

message("WILLOWVOX_COPY_PATH: ${WILLOWVOX_COPY_PATH}")
message("WILLOWVOX_DLL: ${WILLOWVOX_DLL}")
message("WILLOWVOX_LIB: ${WILLOWVOX_LIB}")

# Set output directories
set_target_properties(TemplateGame PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Include directories
target_include_directories(TemplateGame PRIVATE
    include                     # Game-specific includes
    WillowVoxEngine/include     # WillowVox headers
    WillowVoxEngine/thirdparty  # WillowVox dependencies
)

# Link dependencies
target_link_libraries(TemplateGame PRIVATE 
    ${WILLOWVOX_LIB}
    ${CMAKE_SOURCE_DIR}/WillowVoxEngine/thirdparty/imgui${CMAKE_STATIC_LIBRARY_SUFFIX}
)

# Copy dynamic libraries to the output directory (Windows/Linux)
add_custom_command(TARGET TemplateGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${WILLOWVOX_DLL}
    ${WILLOWVOX_COPY_PATH}
)
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${WILLOWVOX_COPY_PATH}/assets
    COMMENT "Copying assets"
)

# Add platform-specific preprocessor definitions
if(WIN32)
    target_compile_definitions(TemplateGame PUBLIC PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(TemplateGame PUBLIC PLATFORM_MACOS)
elseif(UNIX)
    target_compile_definitions(TemplateGame PUBLIC PLATFORM_LINUX)
else()
    message(FATAL_ERROR "Unknown platform!")
endif()