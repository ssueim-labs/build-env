cmake_minimum_required(VERSION 3.6)

# Project Information
project(bryllite-core)

# 헤더 디렉토리 추가 ( -I )
include_directories( ${PROJECT_SOURCE_DIR}/include )

# 라이브러리 디렉토리 추가 ( -L )
link_directories( ${PROJECT_SOURCE_DIR}/lib )

# 실행 바이너리 출력 디렉토리
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin )

# configure version
set(BRYLLITE_VERSION_MAJOR 0)
set(BRYLLITE_VERSION_MINOR 1)
set(BRYLLITE_VERSION_PATCH 0)

configure_file(
	${PROJECT_SOURCE_DIR}/include/version.h.in
	${PROJECT_SOURCE_DIR}/include/version.hpp
)

# Verbose Makefile 작성 여부 ( 켜 두는 편이 좋다 )
set( CMAKE_VERBOSE_MAKEFILE true )

# CMake C++11
set(CMAKE_CXX_STANDARD 11)

#링크 옵션 추가 ( 라이브러리 파일명 )
#link_libraries( Boost.a )

# Boost 1.60 패키지
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.60 REQUIRED COMPONENTS system program_options )
if ( Boost_FOUND )
	include_directories( SYSTEM ${Boost_INCLUDE_DIRS} )
endif()


# utils library
add_subdirectory( utils )

# bryllite core
add_subdirectory( bryllite-core )

# bryllite test
add_subdirectory( bryllite-test )
