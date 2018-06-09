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
	common.h
	vec3.h
	vec3.c
	ray.h
	ray.c
	hitable.h
	hitable.c
	sphere.h
	sphere.c
	hitable_list.h
	hitable_list.c
)

set_property(TARGET path_tracer PROPERTY C_STANDARD 99)

target_link_libraries(path_tracer libfreeimage.a)

add_subdirectory(googletest-1.8.0)
add_subdirectory(tests)