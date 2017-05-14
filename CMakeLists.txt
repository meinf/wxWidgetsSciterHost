project(wxWidgetsSciterHost)

cmake_minimum_required(VERSION 3.5)

set(wxWidgets_USE_STATIC ON )
find_package(wxWidgets COMPONENTS base core REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SCITER_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/sciter/include")

include_directories(
    ${wxWidgets_INCLUDE_DIRS}
    ${SCITER_INCLUDE}
)


file(GLOB sources src/**.cpp src/**.h)

add_executable(DemoApp WIN32 ${sources})
target_link_libraries(DemoApp ${wxWidgets_LIBRARIES})
