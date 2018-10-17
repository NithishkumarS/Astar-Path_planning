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

/** @file aStar.hpp
 * 
 * @brief Class declaration for Astar
 * @detail  
 *
 * @author    Nithish Sanjeev Kumar
 * @navigator Nantha Kumar Sunder
 * @copyright 2018 , Nithish Sanjeev Kumar, Nantha Kumar Sunder All rights reserved

 */

#pragma once
#include "node.hpp"
#include <string.h>

/** @brief Class to implement each node
 *  @param xStart  x coordinate of start node
 *  @param yStart  y coordinate of start node
 *  @param zStart  z coordinate of start node
 *  @param xGoal   x coordinate of the goal node
 *  @param yGoal   y coordinate of the goal node
 *  @param zGoal   z coordinate of the goal node
 *  @param dir_map Direction to neighbouring node
 *  @param dir     Number of possible directions to go at any position
 *  @return none
 */
class aStar {

  int xStart, yStart, zStart;
  int xGoal, yGoal, zGoal;
  int directoryGrid[4][4][4];
  int dir = 26;

 public:

  /**@brief function to set the private members start
   * @param xStart
   * @param yStart
   * @param zStart
   * @return none
   */
  void setStart(int, int, int);

  /**@brief function to set the private members goal
   * @param xGoal
   * @param yGoal
   * @param zGoal
   * @return none
   */
  void setGoal(int, int, int);

  /**@brief function to get the xStart 
   * @param none
   * @return xStart
   */
  int getxStart();
  /**@brief function to get the yStart 
   * @param none
   * @return yStart
   */
  int getyStart();
  /**@brief function to get the zStart 
   * @param none
   * @return zStart
   */
  int getzStart();
  /**@brief function to get the xGoal 
   * @param none
   * @return xGoal
   */
  int getxGoal();
  /**@brief function to get the yGoal 
   * @param none
   * @return yGoal
   */
  int getyGoal();

  /**@brief function to get the zGoal 
   * @param none
   * @return zGoal
   */
  int getzGoal();
  friend bool operator<(const node&, const node&);
  void pathPlanning();

  /**@brief constructor to initialize the class aStar 
   * @param none
   * @return none
   */
  aStar();

  /**@brief Destructor
   * @param none
   * @return none 
   */
  ~aStar();

};
