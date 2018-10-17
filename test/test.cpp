/**
 * MIT License

 * Copyright (c) 2018 Nithish Sanjeev Kumar, Nantha Kumar Sunder

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/** @file test.cpp
 * 
 * @brief To test Astar algorithm
 * 
 * @author Nithish Sanjeev Kumar
 * @navigator Nantha Kumar Sunder
 * @copyright 2018 , Nithish Sanjeev Kumar, Nantha Kumar Sunder All rights reserved

 */
#include <gtest/gtest.h>
#include "aStar.hpp"
#include "node.hpp"
#include <vector> 

/** @brief Test for checking the accessibility of class aStar's members
 *  @param none
 *  @return none
 */
TEST(classAStarCheck, testToFindVariableAccessibility) {

  aStar obj1; /*!< Object of the class aStar  */

  obj1.setStart(0, 0, 0);
  obj1.setGoal(3, 3, 3);
  EXPECT_EQ(0, obj1.getxStart());
  EXPECT_EQ(0, obj1.getyStart());
  EXPECT_EQ(0, obj1.getzStart());
  EXPECT_EQ(3, obj1.getzGoal());
}

/**
 * @brief Test for checking the accessibility of class Node's members
 * @param none
 * @return none
 */
TEST(classNodeCheck, testToFindVariableAccessibility) {

  node obj2;
  obj2.node(0, 1, 2, 5, 10);
  EXPECT_EQ(0, obj2.getxIndex());
  EXPECT_EQ(2, obj2.getzIndex());
  EXPECT_EQ(5, obj2.getgValue());
  EXPECT_EQ(10, obj2.getfValue());

}

/**
 * @brief Test for check cost computation of the algorithm
 * @param current node
 * @param target node
 * @return none
 */
TEST(nodesSetCost, testCost) {
  node node1;
  node1.gValueCalculation(0, 1, 0);
  node1.fValueCalculation(1, 1, 1);
  EXPECT_EQ(node1.getfValue(), 24);
}

