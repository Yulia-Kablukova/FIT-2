cmake_minimum_required(VERSION 3.2)

project(Task1)

add_subdirectory(
	"${CMAKE_CURRENT_SOURCE_DIR}/googletest"
	"googletest"
)

add_executable(
	demo
	src/main.cpp
	src/linked_list.cpp
	src/iterator.cpp
	src/const_iterator.cpp
	src/linked_list.h
	test/test_list.cpp
)

target_include_directories(
	demo PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
	demo PRIVATE
	gtest gtest_main
)

if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

	target_compile_options(
		demo PRIVATE
		/W4
	)
else ()
	target_compile_options(
		demo PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
endif()
