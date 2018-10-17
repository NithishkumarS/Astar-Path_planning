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

/**@file node.cpp
 *
 * @brief To find the shortest path using Astar algorithm
 *
 * @author Nantha Kumar Sunder
 * @navigator Nithish Sanjeev Kumar
 * @copyright 2018 , Nithish Sanjeev Kumar, Nantha Kumar Sunder All rights reserved

 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <node.hpp>
#include "../include/aStar.hpp"

node::node(int _xIndex_, int _yIndex_, int _zIndex_, int _gValue_,
           int _fValue_) {
  xIndex = _xIndex_;
  yIndex = _yIndex_;
  zIndex = _zIndex_;
  gValue = _gValue_;
  fValue = _fValue_;
}

int node::getxIndex() {
  return xIndex;
}
int node::getyIndex() {
  return yIndex;
}
int node::getzIndex() {
  return zIndex;
}
int node::getgValue() {
  return gValue;
}
int node::getfValue() const {
  return fValue;
}
void node::fValueCalculation(int xTarget, int yTarget, int zTarget) {
  fValue = gValue + hValueCalculation(xTarget, yTarget, zTarget) * 10;
}
void node::gValueCalculation(int xValue, int yValue, int zValue) {
  gValue += (sqrt(xValue * xValue + yValue * yValue + zValue * zValue) * 10);
}
int node::hValueCalculation(int xTarget, int yTarget, int zTarget) {
  int xDiff, yDiff, zDiff, totalDiff;
  xDiff = xTarget - xIndex;
  yDiff = yTarget - yIndex;
  zDiff = zTarget - zIndex;
  totalDiff = (sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff));
  return (totalDiff);
}
node::~node() {}
