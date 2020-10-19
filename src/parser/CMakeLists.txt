set(HEADERS
    lexer.hpp
    parser.hpp
    token_type.hpp
    token.hpp
)

set(SOURCES
    lexer.cpp
    parser.cpp
    token.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
