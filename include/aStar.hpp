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
#include <vector>

/** @brief Class to implement each node
 *  @param start Start node
 *  @param goal Goal node
 * 
 *  @return none
 */

class aStar {
 public:
  /** Identifiers for start and goal nodes
   */
  std::vector<int> start, goal;

  /**@brief Constructor to set the start and goal nodes from input 
   * @param  start
   * @param goal
   * @return none
   */
  aStar(std::vector<int>, std::vector<int>);

  /**@brief function to compute the path from the the fValue
   * @param fValue
   * @return void
   */
  void pathPlanning(std::vector<std::vector<std::vector<int> > >);

  /**@brief Destructor of the class
   * @param none
   * @return none 
   */
  ~aStar();
};
