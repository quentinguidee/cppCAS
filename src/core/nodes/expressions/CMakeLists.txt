set(HEADERS
    absolute_value.hpp
    expression.hpp
    opposite.hpp
    power.hpp
)

set(SOURCES
    absolute_value.cpp
    expression.cpp
    opposite.cpp
    power.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})

add_subdirectory(values)