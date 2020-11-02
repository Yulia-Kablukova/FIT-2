cmake_minimum_required(VERSION 2.8.8)

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
)

add_executable(
	test_list
	test/test_list.cpp
)

target_include_directories(
	demo PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
)

target_include_directories(
	test_list PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/googletest"
	"${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

	target_compile_options(
		demo PRIVATE
		/W4
	)
	target_compile_options(
		test_list PRIVATE
		/W4
	)
else ()
	target_compile_options(
		demo PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
	target_compile_options(
		test_list PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
endif()
