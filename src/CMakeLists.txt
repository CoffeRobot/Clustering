project(Clustering)

cmake_minimum_required(VERSION 2.8.7)
set(cmake_test_VERSION_MAJOR 0)
set(cmake_test_VERSION_MINOR 1)
set(cmake_test_VERSION_PATCH 0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(exe_name "Clustering")

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")


################################################################
#                   ADDITIONAL LIBRARIES                       #
################################################################
if(MSVC)
  set(BOOST_ROOT "C:/Libraries/boost_1_55_0")
  set(BOOST_LIBRARYDIR "C:/Libraries/boost_1_55_0/lib64-msvc-12.0")
  set(Boost_USE_STATIC_LIBS        ON)
  set(Boost_USE_MULTITHREADED      ON)
  set(Boost_USE_STATIC_RUNTIME    OFF)
endif()

find_package(BOOST COMPONENTS heap REQUIRED)

if(Boost_FOUND)
      message(status "-: -> Boost Includes dir: ${Boost_INCLUDE_DIRS}")
endif()


INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

################################################################
#                   ENVIRONMENT SETTINGS                       #
################################################################
set(dir ${CMAKE_CURRENT_SOURCE_DIR}../../build)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)

################################################################
#                   ADD PROJECT FILES                          #
################################################################
file( GLOB  source_files *.cpp )
file( GLOB  header_files *.hpp *.h )

ADD_EXECUTABLE("${exe_name}" ${source_files} ${header_files})



