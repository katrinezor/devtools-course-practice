// Copyright 2017 Zemlyanskiy Nikita

#include <gtest/gtest.h>
#include "include/Demand.h"

TEST(Demand, Can_Return_Value_Of_Check) {
  Demand dem(2.3, 3.2, 4.4, 8.9);

  ASSERT_NO_THROW(dem.CheckForElasticity());
}

TEST(Demand, Can_Return_Same_Values_Of_Check) {
  Demand dem1(13.0, 16.4, 6.4, 3.4);
  Demand dem2(13.0, 16.4, 6.4, 3.4);

  ASSERT_EQ(dem1.CheckForElasticity(), dem2.CheckForElasticity());
}

TEST(Demand, Can_Return_Same_Values_Of_Revenue) {
  Demand dem1(13.0, 16.4, 6.4, 3.4);
  Demand dem2(13.0, 16.4, 6.4, 3.4);

  ASSERT_EQ(dem1.RevenueChange(65.0), dem2.RevenueChange(65.0));
}

TEST(Demand, Can_Create_Obj_With_Positive_Values) {
  ASSERT_NO_THROW(Demand dem(13.0, 16.4, 6.4, 3.4));
}

TEST(Demand, Can_Not_Create_Obj_With_One_Negative_Value) {
  ASSERT_ANY_THROW(Demand dem(-1.0, 3.4, 5.6, 9.0));
}

TEST(Demand, Can_Change_Revenue) {
  Demand dem1(13.0, 16.4, 6.4, 3.4);
  Demand dem2(17.3, 6.5, 8.7, 8.4);

  ASSERT_NE(dem1.RevenueChange(120.0), dem2.RevenueChange(120.0));
}

TEST(Demand, Can_Create_Obj_With_Null_Values) {
  // oldprice != newprice
  ASSERT_NO_THROW(Demand dem(0.0, 3.0, 0.0, 0.0));
}

TEST(Demand, Can_Not_Create_Obj_Oldp_Eq_Newp) {
  ASSERT_ANY_THROW(Demand dem1(13.0, 13.0, 6.4, 3.4));
}

TEST(Demand, Can_Return_Diff_Values_Of_Check) {
  Demand dem1(13.0, 14.0, 6.4, 3.4);
  Demand dem2(10.0, 8.0 , 5.6, 3.2);

  ASSERT_NE(dem1.CheckForElasticity(), dem2.CheckForElasticity());
}

TEST(Demand, Can_Return_Value_Of_Revenue) {
  Demand dem(12.2, 10.3, 6.7, 2.3);

  ASSERT_NO_THROW(dem.RevenueChange(12.2));
}

TEST(Demand, Can_Not_Create_Obj_With_ALL_Negative_Values) {
  ASSERT_ANY_THROW(Demand dem1(-13.0, -9.0, -6.4, -3.4));
}

TEST(Demand, Inc_And_Red_Revenue_No_Elastic) {
  Demand dem1(5.0, 2.5, 2.3, 3.3);
  Demand dem2(5.0, 7.5, 2.3, 3.3);

  ASSERT_TRUE(dem1.RevenueChange(12.2) < dem2.RevenueChange(12.2));
}

TEST(Demand, Inc_And_Red_Revenue_Elastic) {
  Demand dem1(5.0, 2.5, 16.3, 10.3);
  Demand dem2(5.0, 7.5, 5.3, 10.3);

  ASSERT_TRUE(dem1.RevenueChange(12.2) > dem2.RevenueChange(12.2));
}

TEST(Demand, Same_Revenue_No_Elastic) {
  Demand dem1(5.0, 8.5, 2.3, 3.3);
  Demand dem2(5.0, 7.5, 2.3, 3.3);

  ASSERT_TRUE(dem1.RevenueChange(12.2) == dem2.RevenueChange(12.2));
}

TEST(Demand, Same_Revenue_Elastic) {
  Demand dem1(2.5, 5.0, 10.3, 15.3);
  Demand dem2(7.5, 10.5, 5.3, 10.3);

  ASSERT_TRUE(dem1.RevenueChange(12.2) == dem2.RevenueChange(12.2));
}

TEST(Demand, Inc_And_Red_Revenue_Unit_Elastic) {
  Demand dem1(5.0, 4.0, 10.3, 9.3);
  Demand dem2(5.5, 7.5, 8.3, 10.3);

  ASSERT_TRUE(dem1.RevenueChange(12.2) > dem2.RevenueChange(12.2));
}

TEST(Demand, Same_Revenue_Unit_Elastic) {
  Demand dem1(2.5, 3.5, 10.3, 11.3);
  Demand dem2(7.5, 8.5, 5.3, 6.3);

  ASSERT_TRUE(dem1.RevenueChange(12.2) == dem2.RevenueChange(12.2));
}

TEST(Demand, Test_Of_Return_Value_Check_Unit) {
  Demand dem(2.5, 3.5, 10.3, 11.3);

  ASSERT_EQ(dem.CheckForElasticity(), 1);
}

TEST(Demand, Test_Of_Return_Value_Check_No) {
  Demand dem(5.0, 8.5, 2.3, 3.3);

  ASSERT_EQ(dem.CheckForElasticity(), 2);
}

TEST(Demand, Test_Of_Return_Value_Check_Ela) {
  Demand dem(2.5, 5.0, 10.3, 15.3);

  ASSERT_EQ(dem.CheckForElasticity(), 0);
}
