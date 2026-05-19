add_executable(test_srp
    test_srp.cpp
    ../Patterns/SOLID/SRP.cpp
)
target_include_directories(test_srp PRIVATE
    ${CMAKE_SOURCE_DIR}/Patterns/SOLID
    ${GTEST_INCLUDE_DIRS}
)
target_link_libraries(test_srp GTest::GTest GTest::Main)

add_test(NAME SRP_Test COMMAND test_srp)
