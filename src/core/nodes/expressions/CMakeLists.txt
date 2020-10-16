set(HEADERS
    absolute_value.hpp
    cos.hpp
    division.hpp
    expression.hpp
    opposite.hpp
    power.hpp
    sin.hpp
    tan.hpp
)

set(SOURCES
    absolute_value.cpp
    cos.cpp
    division.cpp
    expression.cpp
    opposite.cpp
    power.cpp
    sin.cpp
    tan.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})

add_subdirectory(values)
