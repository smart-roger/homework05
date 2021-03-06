﻿cmake_minimum_required(VERSION 3.2)

project(vector_editor VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Doxygen)
 if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT ${CMAKE_SOURCE_DIR})
    configure_file(${CMAKE_SOURCE_DIR}/doxygen.conf.in ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
    add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
 else(DOXYGEN_FOUND)
    message(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
endif(DOXYGEN_FOUND)

add_executable(vector_editor 
	main.cpp Controller.h Controller.cpp
	TShapeBuilder.h TShapeBuilder.cpp
	UI.h UI.cpp
	DocHelper.h
	Document.h
	Shape.h TShapeContainer.h)

set_target_properties(vector_editor PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

install(TARGETS vector_editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT __shurik@list.ru)

include(CPack)
