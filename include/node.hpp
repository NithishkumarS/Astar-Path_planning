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

/** @file node.hpp
 * 
 * @brief Class declaration for the node
 * 
 * @author Nithish Sanjeev Kumar
 * @navigator Nantha Kumar Sunder
 * @copyright 2018 , Nithish Sanjeev Kumar, Nantha Kumar Sunder All rights reserved

 */

#pragma once
#include <vector>

/** @brief class that stores and computes the total cost, heuristic cost 
 *         and movement cost
 * 
 *  @param parentNode    Parent node 3D vector 
 *  @param fValue        3D vector to hold the total cost of each node
 *  @param gValue        3D vector to hold the movement cost of each node
 *  @param hValue        3D vector to hold the heuristic cost of each node
 *  @param openList      Contains nodes in the open list 
 *  @param closedList    Contains nodes in the closed list
 * 
 *  @return none
 */

class node {
 public:
  /** Identifiers for fValue, gValue, hValue, lists and parentNodes
   */
  std::vector<std::vector<std::vector<int> > > parentNode;
  std::vector<std::vector<std::vector<int> > > fValue;
  std::vector<std::vector<std::vector<int> > > gValue;
  std::vector<std::vector<std::vector<int> > > hValue;
  std::vector<std::vector<int> > openList, closedList;

  /**@brief function to compute the total cost
   * @param movement cost
   * @param heuristic cost
   * @return a int value containing the total cost
   */
  int fValueCalculation(int, int);

  /**@brief function to compute the heuristic cost
   * @param object of class environment
   * @param current position vector
   * @param goal vector
   * @return a int value containing the heuristic cost
   */
  int hValueCalculation(environment, std::vector<int>, std::vector<int>);

  /**@brief function to compute the movement cost
   * @param object of the class environment
   * @param current node
   * @return a int value which is the movement cost
   */
  int gValueCalculation(environment, std::vector<int>);
};
