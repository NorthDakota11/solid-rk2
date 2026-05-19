#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

extern void test_srp();

class SRPTest : public ::testing::Test {
protected:
    std::stringstream buffer;
    std::streambuf* old_cout;

    void SetUp() override {
        old_cout = std::cout.rdbuf(buffer.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(old_cout);
    }
};

TEST_F(SRPTest, FunctionDoesNotCrashAndProducesOutput) {
    EXPECT_NO_THROW(test_srp());
    std::string output = buffer.str();
    EXPECT_FALSE(output.empty()) << "No output from test_srp()";
}
