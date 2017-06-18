// Copyright 2017 Kalinin Vladimir
#include <gtest/gtest.h>

#include "include/Graph.h"


TEST(Kalinin_dijkstra_tests, Can_Create_Edge) {
  // Arrange
  Edge a1;
  Edge a2(1, 2);

  // Act

  // Assert
  EXPECT_EQ(a2.GetWeight(), 1);
  EXPECT_EQ(a2.GetKey(), 2);
  EXPECT_EQ(a1.GetWeight(), 0);
  EXPECT_EQ(a1.GetKey(), 0);
}

TEST(Kalinin_dijkstra_tests, Can_Set_Next) {
  // Arrange
  Edge a1;
  Edge a2;
  // Act
  a1.SetNext(&a2);

  // Assert
  EXPECT_EQ(a1.GetNext(), &a2);
}

TEST(Kalinin_dijkstra_tests, Can_Create_Graph) {
  // Arrange

  // Act
  Graph gr1;
  Graph gr2(5);

  // Assert
  EXPECT_EQ(gr1.GetSize(), 0);
  EXPECT_EQ(gr2.GetSize(), 5);
}

TEST(Kalinin_dijkstra_tests, IsConnect_Works) {
  // Arrange
  Graph gr(6);

  // Act
  gr.AddEdge(9, 1, 3);

  // Assert
  EXPECT_EQ(gr.IsConnect(1, 3), true);
  EXPECT_EQ(gr.IsConnect(3, 1), true);
  EXPECT_EQ(gr.IsConnect(1, 2), false);
}

TEST(Kalinin_dijkstra_tests, Can_Set_Edge_Weight) {
  // Arrange
  Graph gr(6);

  // Act
  gr.AddEdge(9, 1, 3);

  // Assert
  EXPECT_EQ(gr.GetNode(1)->GetWeight(), 9);
  EXPECT_EQ(gr.GetNode(3)->GetWeight(), 9);
}

TEST(Kalinin_dijkstra_tests, Diykstra_Result_Is_Correct) {
  // Arrange
  Graph gr(6);
  gr.AddEdge(7, 1, 2);
  gr.AddEdge(10, 2, 3);
  gr.AddEdge(9, 1, 3);
  gr.AddEdge(15, 2, 4);
  gr.AddEdge(11, 3, 4);
  gr.AddEdge(14, 1, 0);
  gr.AddEdge(2, 3, 0);
  gr.AddEdge(9, 5, 0);
  gr.AddEdge(6, 4, 5);
  int correct_answer[6] = { 11, 0, 7, 9, 20, 20 };

  // Act
  int* tmp = gr.Dijkstra(1);

  // Assert
  for (int i = 0; i < 6; i++)
    EXPECT_EQ(correct_answer[i], tmp[i]);
}
