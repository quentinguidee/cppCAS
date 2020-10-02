set(HEADERS
    node.hpp
    power.hpp
)

set(SOURCES
    node.cpp
    power.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})

add_subdirectory(values)
