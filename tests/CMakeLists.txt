find_package(Catch2 CONFIG REQUIRED)

add_executable(tests test_nodes.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2)
target_link_libraries(tests PRIVATE cppCAS)

include(CTest)
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(tests)
