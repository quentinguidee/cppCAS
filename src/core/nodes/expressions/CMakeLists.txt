set(HEADERS
    expression.hpp
    power.hpp
)

set(SOURCES
    expression.cpp
    power.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})

add_subdirectory(values)