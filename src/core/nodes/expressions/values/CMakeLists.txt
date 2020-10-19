set(HEADERS
    value.hpp
    unknown.hpp
    integer.hpp
)

set(SOURCES
    value.cpp
    unknown.cpp
    integer.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
