set(HEADERS
    lexer.hpp
    token_type.hpp
    token.hpp
)

set(SOURCES
    lexer.cpp
    token.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
