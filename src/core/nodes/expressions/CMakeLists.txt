set(HEADERS
    absolute_value.hpp
    addition.hpp
    cos.hpp
    differential.hpp
    division.hpp
    expression.hpp
    integral.hpp
    modulus.hpp
    multi_node.hpp
    multiplication.hpp
    opposite.hpp
    power.hpp
    sin.hpp
    tan.hpp
)

set(SOURCES
    absolute_value.cpp
    addition.cpp
    cos.cpp
    differential.cpp
    division.cpp
    expression.cpp
    integral.cpp
    modulus.cpp
    multi_node.cpp
    multiplication.cpp
    opposite.cpp
    power.cpp
    sin.cpp
    tan.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})

add_subdirectory(values)
