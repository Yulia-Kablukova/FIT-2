cmake_minimum_required(VERSION 2.8.8)

project(Task1)

add_subdirectory(
	"${CMAKE_CURRENT_SOURCE_DIR}/googletest"
	"googletest"
)

add_executable(
	demo
	main.cpp
	linked_list.cpp
	iterator.cpp
	const_iterator.cpp
	linked_list.h
)

add_executable(
	test_list
	test_list.cpp
)

target_include_directories(
	demo PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

target_include_directories(
	test_list PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}"
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
