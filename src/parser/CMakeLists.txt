set(HEADERS
    lexer.hpp
    parse_tree.hpp
    parser.hpp
    tokens_library.hpp
    token_type.hpp
    token.hpp
)

set(SOURCES
    lexer.cpp
    parse_tree.cpp
    parser.cpp
    token.cpp
)

target_sources(cppCAS PUBLIC ${HEADERS} ${SOURCES})
