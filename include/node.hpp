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

/** @brief class that stores and computes the total cost, heuristic cost 
 *         and movement cost
 * 
 *  @param fValue        total cost of each node
 *  @param gValue        movement cost of each node
 *  @param xIndex        xIndex of node
 *  @param yIndex        yIndex of nodde
 *  @param zIndex        zIndex of node 
 * 
 *  @return none
 */

class node {
 private:
  int xIndex;
  int yIndex;
  int zIndex;
  int gValue;
  int fValue;

 public:
    /**@brief function to set the private members start
   * @param xStart
   * @param yStart
   * @param zStart
   * @return none
   */
  node(int, int, int, int, int);
  /**@brief function to set the private members start
   * @param xStart
   * @param yStart
   * @param zStart
   * @param Value
   * @return none
   */
  int getxIndex();
    /**@brief function to get x IndexValue
   * @param none
   * @return xIndex
   */
  int getyIndex();
  /**@brief function to to get y IndexValue
   * @param none
   * @return yIndex
   */
   int getzIndex();
  /**@brief function to get z IndexValue
   * @param none
   * @return zIndex
   */
   int getgValue();
  /**@brief function to get gValue
   * @param none
   * @return int
   */
   int getfValue() const;
  /**@brief function to calculate fValue
   * @param xStart
   * @param yStart
   * @param zStart
   * @return none
   */
   void fValueCalculation(int, int, int);
  /**@brief function to calculate gValue
   * @param xCurrent
   * @param ycurrent
   * @param zcurrent
   * @return none
   */
  void gValueCalculation(int, int, int);
  /**@brief function to calculate hValue
   * @param xStart
   * @param yStart
   * @param zStart
   * @return none
   */
  int hValueCalculation(int, int, int);
  /**@Destructor
   * @param none
   * @return none
   */
   ~node();
};
