// Copyright 2017 Dryakhlov Dmitry

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/huffman_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class HuffmanAlgAppTest : public ::testing::Test {
 protected:
            // virtual void SetUp() {}
    void Act(vector<string> args_) {
       vector<const char*> options;
       options.push_back("appname");
            for (size_t i = 0; i < args_.size(); ++i) {
                options.push_back(args_[i].c_str());
            }
            const char** argv = &options.front();
            int argc = static_cast<int>(args_.size()) + 1;
            output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
     string output_;
     HuffmanAlgApp app_;
};

TEST_F(HuffmanAlgAppTest, _Do_Print_Help_Without_Arguments) {
    vector<string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("This is a huffman algoritm application\\..*");
}

TEST_F(HuffmanAlgAppTest, _Is_Checking_Number_Of_Arguments_1) {
    vector<string> args = { "encode" };
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Should be more than 1 arguments*");
}

TEST_F(HuffmanAlgAppTest, _Is_Checking_Number_Of_Arguments_3) {
    vector<string> args = { "asd", "sda", "asdasd" };
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Should be less than 3 arguments*");
}

TEST_F(HuffmanAlgAppTest, _Can_Detect_Wrong_Comand_Format) {
    vector<string> args = { "enacode", "it is my striiing" };
    // Act
    Act(args);
    // Assert
    Assert("command is uncorrect");
}

TEST_F(HuffmanAlgAppTest, _Can_Calculate_Huffman_Cod) {
    vector<string> args = { "encode", "it is my striiing" };
    // Act
    Act(args);
    // Assert
    Assert("10010111100011110111000111001010110110101011000110");
}

TEST_F(HuffmanAlgAppTest, _Can_Encode_And_Decode) {
    vector<string> args = { "encode_and_decode", "itismystriiing" };
    // Act
    Act(args);
    // Assert
    Assert("itismystriiing");
}
