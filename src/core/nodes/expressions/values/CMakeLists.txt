set(HEADERS
    value.hpp
    unknown.hpp
    integer.hpp
)

set(SOURCES
    value.cpp
    integer.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
