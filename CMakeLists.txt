cmake_minimum_required(VERSION 3.20)
project(TemplateApp LANGUAGES CXX C)
set(CMAKE_GENERATOR_PLATFORM x64)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the executable
add_executable(TemplateApp
    src/main.cpp
    # ADD ANY ADDITIONAL CPP FILES HERE
)

set(APP_TARGET "TemplateApp")

add_subdirectory(WillowVoxEngine)

# Include directories
target_include_directories(TemplateApp PRIVATE
    include
)

# Set output directories
set_target_properties(TemplateApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy assets to output directory
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:TemplateApp>/assets
    COMMENT "Copying assets"
)