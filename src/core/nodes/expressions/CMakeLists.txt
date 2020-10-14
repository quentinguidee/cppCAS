set(HEADERS
    expression.hpp
    power.hpp
    absolute_value.hpp
)

set(SOURCES
    expression.cpp
    power.cpp
    absolute_value.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})

add_subdirectory(values)