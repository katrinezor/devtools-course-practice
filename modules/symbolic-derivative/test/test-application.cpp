// Copyright 2017 Zorina Ekaterina

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "../include/application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ApplicationTest : public ::testing::Test {
protected:
    void Act(vector<string> args_) {
        vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

private:
    Application app_;
    string output_;
};

TEST_F(ApplicationTest, Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a derivative application*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Of_Arguments) {
    vector<string> args = {"x", "cos(x)", "2*x"};

    Act(args);

    Assert("ERROR: Should be 2 arguments.*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Expression_Format) {
    vector<string> args = { "x", "פטû(x)" };

    Act(args);

    Assert("ERROR. Wrong expression format.*");
}


TEST_F(ApplicationTest, Can_Take_A_Simple_Derivative) {
    vector<string> args = { "x", "2.0*x" };

    Act(args);

    Assert("2.0");
}

TEST_F(ApplicationTest, Can_Take_A_Complex_Derivative) {
    vector<string> args = { "x", "2.0*x+x^3.0+sin(x)" };

    Act(args);

    Assert("2.0 + cos(x)");
}
