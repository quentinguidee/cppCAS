set(HEADERS
    complex.hpp
    constant.hpp
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
    constant.cpp
    imaginary.cpp
    integer.cpp
    natural.cpp
    rational.cpp
    real.cpp
    unknown.cpp
    value.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
