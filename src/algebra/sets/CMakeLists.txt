set(HEADERS
    finite_set.hpp
    infinite_set.hpp
    set.hpp
)

set(SOURCES
    finite_set.cpp
    infinite_set.cpp
    set.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
