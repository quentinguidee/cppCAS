add_executable(tests test_nodes.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2)
target_link_libraries(tests PRIVATE cppCAS)
