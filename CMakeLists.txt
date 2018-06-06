cmake_minimum_required(VERSION 3.10)

project(path_tracer)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_definitions(
    -DOPJ_STATIC 
    -DFREEIMAGE_LIB
    -DLIBRAW_NODLL
)

add_executable(path_tracer
	main.c
)

target_link_libraries(path_tracer libfreeimage.a)