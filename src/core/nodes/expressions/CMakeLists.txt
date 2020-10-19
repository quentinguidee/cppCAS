set(HEADERS
    absolute_value.hpp
    addition.hpp
    cos.hpp
    differential.hpp
    division.hpp
    expression.hpp
    multi_node.hpp
    multiplication.hpp
    opposite.hpp
    power.hpp
    sin.hpp
    tan.hpp
)

set(SOURCES
    absolute_value.cpp
    cos.cpp
    differential.cpp
    division.cpp
    expression.cpp
    multi_node.cpp
    opposite.cpp
    power.cpp
    sin.cpp
    tan.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})

add_subdirectory(values)
