cmake_minimum_required(VERSION 3.5)
project(DesignPatternsWebinar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# made with the 'incboost' macro
find_package(Boost)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIR})
endif ()

#creational patterns

set(ABSTRACT_FACTORY_FILES creational/abstract_factory/abstract_factory.cpp)
add_executable(AbstractFactory ${ABSTRACT_FACTORY_FILES})

set(BUILDER_FILES creational/builder/builder.cpp)
add_executable(Builder ${BUILDER_FILES})

# structural patterns

set(ADAPTER_FILES structural/adapter/adapter.cpp)
add_executable(Adapter ${ADAPTER_FILES})

set(COMPOSITE_FILES structural/composite/composite.cpp)
add_executable(Composite ${COMPOSITE_FILES})

