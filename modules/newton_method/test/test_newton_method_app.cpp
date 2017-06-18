// Copyright 2017 Buldakov Vlad

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/Newton_method_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NewtonMethodAppTest : public ::testing::Test {
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
    NewtonMethodApp app_;
    string output_;
};

TEST_F(NewtonMethodAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a newton method application\\..*");
}

TEST_F(NewtonMethodAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1"};

    Act(args);

    Assert("ERROR: Should be more than 2 arguments*");
}

TEST_F(NewtonMethodAppTest, Can_Check_Polynom_Coefficients) {
    vector<string> args = {"3", "1", "1"};

    Act(args);

    Assert("Number of coefficients not equal polynom size!");
}

TEST_F(NewtonMethodAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"pi", "2", "4"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NewtonMethodAppTest, Throw_When_Zero_Size) {
    vector<string> args = {"0", "1"};

    Act(args);

    Assert("Number of coefficients not equal polynom size!");
}

TEST_F(NewtonMethodAppTest, Can_Calculate_For_Leaned_Line) {
    vector<string> args = {"2", "-0.2", "0.5"};

    Act(args);

    Assert("Root = 0.4");
}

TEST_F(NewtonMethodAppTest, Can_Calculate_For_Horizontal_Line) {
    vector<string> args = {"1", "0.1"};

    Act(args);

    Assert("No roots");
}

TEST_F(NewtonMethodAppTest, Can_Calculate_For_Parabola) {
    vector<string> args = {"3", "-2", "1", "1"};

    Act(args);

    Assert("Root = 1");
}

TEST_F(NewtonMethodAppTest, Can_Calculate_For_One_Root_Parabola) {
    vector<string> args = {"3", "0.25", "-1", "1"};

    Act(args);

    Assert("Root = 0.5");
}

TEST_F(NewtonMethodAppTest, Can_Calculate_For_No_Root_Parabola) {
    vector<string> args = {"3", "1", "-1", "1"};

    Act(args);

    Assert("No roots");
}

TEST_F(NewtonMethodAppTest, Can_Calculate_For_Cubic_Parabola) {
    vector<string> args = { "4", "0", "0", "0", "1" };

    Act(args);

    Assert("Root = 0");
}
