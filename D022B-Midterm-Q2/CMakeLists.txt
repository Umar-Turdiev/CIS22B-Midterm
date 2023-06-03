cmake_minimum_required(VERSION 3.0)
project(D022B-Midterm-Q2)

set(CMAKE_CXX_STANDARD 17)

set(src_dir src)
set(include_dir src)

file(GLOB src_files "${src_dir}/*.cpp")
file(GLOB include_files "${include_dir}/*.hpp")

add_executable(Application
    ${src_files}
    ${include_files}
)

target_include_directories(Application PRIVATE "${include_dir}/")
target_link_libraries(Application ${ALL_LIBS})
