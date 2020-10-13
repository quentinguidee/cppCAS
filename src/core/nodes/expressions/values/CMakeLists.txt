set(HEADERS
    value.hpp
    integer.hpp
)

set(SOURCES
    value.cpp
    integer.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
