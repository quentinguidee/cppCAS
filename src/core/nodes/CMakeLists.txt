set(HEADERS
    node.hpp
)

set(SOURCES
    node.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})

add_subdirectory(expressions)
