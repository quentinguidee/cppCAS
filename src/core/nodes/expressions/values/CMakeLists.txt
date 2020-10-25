set(HEADERS
    integer.hpp
    natural.hpp
    rational.hpp
    real.hpp
    unknown.hpp
    value.hpp
)

set(SOURCES
    real.cpp
    unknown.cpp
    value.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
