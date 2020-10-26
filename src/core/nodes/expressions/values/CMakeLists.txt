set(HEADERS
    complex.hpp
    imaginary.hpp
    integer.hpp
    natural.hpp
    rational.hpp
    real.hpp
    unknown.hpp
    value.hpp
)

set(SOURCES
    complex.cpp
    imaginary.cpp
    real.cpp
    unknown.cpp
    value.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
