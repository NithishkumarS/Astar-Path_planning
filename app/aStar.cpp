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

/**@file aStar.cpp
 *
 * @brief To find the shortest path using Astar algorithm
 *
 * @author Nantha Kumar Sunder
 * @navigator Nithish Sanjeev Kumar
 * @copyright 2018 , Nithish Sanjeev Kumar, Nantha Kumar Sunder All rights reserved

 */
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "../include/aStar.hpp"
#include "../include/node.hpp"
#
/**@brief function to set the value of the private member start
 * @param  start
 * @return none
 */
void aStar::setStart(int _xStart, int _yStart, int _zStart) {
  xStart = _xStart;
  yStart = _yStart;
  zStart = _zStart;
}
/**@brief function to get the value of the private member start
 * @param  none
 * @return vector<int>
 */
int aStar::getxStart() {
  return xStart;
}
/**@brief function to get the value of the private member start
 * @param  none
 * @return vector<int>
 */
int aStar::getyStart() {
  return yStart;
}
/**@brief function to get the value of the private member start
 * @param  none
 * @return vector<int>
 */
int aStar::getzStart() {
  return zStart;
}
/**@brief function to set the value of the private member goal
 * @param  goal
 * @return none
 */
void aStar::setGoal(int _xGoal, int _yGoal, int _zGoal) {
  xGoal = _xGoal;
  yGoal = _yGoal;
  zGoal = _zGoal;
}
/**@brief function to get the value of the private member goal
 * @param  start
 * @return none
 */
int aStar::getxGoal() {
  return xGoal;
}
/**@brief function to get the value of the private member goal
 * @param  start
 * @return none
 */
int aStar::getyGoal() {
  return yGoal;
}
/**@brief function to get the value of the private member goal
 * @param  start
 * @return none
 */
int aStar::getzGoal() {
  return zGoal;
}
/**@brief Constructor to set the start and goal nodes from input
 * @param start
 * @param goal
 * @return none
 */
aStar::aStar() {
  xStart = 0;
  yStart = 0;
  zStart = 0;
  xGoal = 3;
  yGoal = 3;
  zGoal = 3;
}
bool operator<(const node & a, const node & b) {
  int fA = a.getfValue();
  int fB = b.getfValue();
  return fA > fB;
}
/**@brief function to do pathPlanning
 * @param possibleMovement Physically possible movements
 * @return void
 */
void aStar::pathPlanning() {
  int possibleMovement = 26;  // it is constant to move in an 3D environment
  int movementInX[possibleMovement] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0 };
  int movementInY[possibleMovement] = { 0, 0, 1, 1, 1, 0, -1, -1, -1, 0, 1, 1,
      1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, -1, -1 };
  int movementInZ[possibleMovement] = { 0, 1, 0, 1, -1, -1, 0, -1, 1, 1, 0, 1,
      -1, 0, -1, 0, -1, 1, 1, 0, 1, -1, -1, 0, -1, 1 };
  int closedListMatrix[4][4][4];
  int openListMatrix[4][4][4];

  static std::priority_queue<node> openList[3];
  int openListIndex = 0;
  node* tempNode1;
  node* tempNode2;
  int xPos, yPos, zPos, i, j;
  int movedInX, movedInY, movedInZ;
  char tempChar;
  int length = 4;
  int breadth = 4;
  int height = 4;
  int grid[4][4][4];
  int completed = 0;
  std::string pathString = "";
  // Creating 3D map
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < breadth; j++) {
      for (int k = 0; k < length; k++) {
        grid[k][j][i] = 0;
      }
    }
  }
  for (int xPos = 1; xPos < length - 1; xPos++) {
    grid[xPos][xPos][xPos] = 1;
  }
  std::vector<int> size = { length, breadth, height };
  for (zPos = 0; zPos < size[2]; zPos++) {
    for (yPos = 0; yPos < size[1]; yPos++) {
      for (xPos = 0; xPos < size[0]; xPos++) {
        closedListMatrix[xPos][yPos][zPos] = 0;
        openListMatrix[xPos][yPos][zPos] = 0;
      }
    }
  }

  tempNode1 = new node(xStart, yStart, zStart, 0, 0);
  tempNode1->fValueCalculation(xGoal, yGoal, zGoal);
  openList[openListIndex].push(*tempNode1);
  openListMatrix[xPos][yPos][zPos] = tempNode1->getfValue();

  while (!openList[openListIndex].empty()) {
    node tempnode1 = openList[openListIndex].top();
    xPos = tempNode1->getxIndex();
    yPos = tempNode1->getyIndex();
    zPos = tempNode1->getzIndex();

    openList[openListIndex].pop();
    openListMatrix[xPos][yPos][zPos] = 0;
    closedListMatrix[xPos][yPos][zPos] = 1;

    if (xPos == xGoal && yPos == yGoal && zPos == zGoal) {
      while (!(xPos == xStart && yPos == yStart && zPos == zStart)) {
        j = directoryGrid[xPos][yPos][zPos];
        tempChar = '0' + (j + possibleMovement / 2) % possibleMovement;
        pathString = tempChar + pathString;
        xPos += movementInX[j];
        yPos += movementInY[j];
        zPos += movementInZ[j];
      }

      delete tempNode1;
      while (!openList[openListIndex].empty())
        openList[openListIndex].pop();
      completed = 1;
      break;
    }

    for (int i = 0; i < possibleMovement; i++) {
      movedInX = xPos + movementInX[i];
      movedInY = yPos + movementInY[i];
      movedInZ = zPos + movementInZ[i];
      if (!(movedInX < 0 || movedInX > size[0] - 1 || movedInY < 0
          || movedInY > size[1] - 1 || movedInZ < 0 || movedInZ > size[2] - 1
          || grid[movedInX][movedInY][movedInZ] == 1
          || closedListMatrix[movedInX][movedInY][movedInZ] == 1)) {
        tempNode2 = new node(movedInX, movedInY, movedInZ,
                             tempNode1->getgValue(), tempNode1->getfValue());
        tempNode2->gValueCalculation(movementInX[i], movementInY[i],
                                     movementInZ[i]);
        tempNode2->fValueCalculation(xGoal, yGoal, zGoal);

        if (openListMatrix[movedInX][movedInY][movedInZ] == 0) {
          openListMatrix[movedInX][movedInY][movedInZ] = tempNode2->getfValue();
          openList[openListIndex].push(*tempNode2);
          directoryGrid[movedInX][movedInY][movedInZ] = (i
              + possibleMovement / 2) % possibleMovement;
        } else if (openListMatrix[movedInX][movedInY][movedInZ]
            > tempNode2->getfValue()) {
          openListMatrix[movedInX][movedInY][movedInZ] = tempNode2->getfValue();
          directoryGrid[movedInX][movedInY][movedInZ] = (i
              + possibleMovement / 2) % possibleMovement;
          node tempNode3 = openList[openListIndex].top();
          while (!(tempNode3.getxIndex() == movedInX
              && tempNode3.getxIndex() == movedInY
              && tempNode3.getxIndex() == movedInZ)) {
            openList[1 - openListIndex].push(openList[openListIndex].top());
            openList[openListIndex].pop();
          }
          openList[openListIndex].pop();

          if (openList[openListIndex].size()
              > openList[1 - openListIndex].size())
            openListIndex = 1 - openListIndex;
          while (!openList[openListIndex].empty()) {
            openList[1 - openListIndex].push(openList[openListIndex].top());
            openList[openListIndex].pop();
          }
          openListIndex = 1 - openListIndex;
          openList[openListIndex].push(*tempNode2);
        } else {delete tempNode2;}
      }
    }
    delete tempNode1;
  }
  // printing the pathString
  if (pathString.length() > 0) {
    int j;
    char tempChar;
    int xPos = xStart;
    int yPos = yStart;
    int zPos = zStart;
    grid[xPos][yPos][zPos] = 2;
    for (int i = 0; i < pathString.length(); i++) {
      tempChar = pathString.at(i);
      j = atoi(&tempChar);
      xPos = xPos + movementInX[j];
      yPos = yPos + movementInY[j];
      zPos = zPos + movementInZ[j];
      grid[xPos][yPos][zPos] = 3;
    }
    grid[xPos][yPos][zPos] = 4;

    // display the grid with the path
    for (int zPos = 0; zPos < height; zPos++) {
      std::cout << " For Z plane " << zPos + 1 << std::endl;
      for (int yPos = 0; yPos < breadth; yPos++) {
        for (int xPos = 0; xPos < length; xPos++)
          if (grid[xPos][yPos][zPos] == 0)
            std::cout << ".";
          else if (grid[xPos][yPos][zPos] == 1)
            std::cout << "X";
          else if (grid[xPos][yPos][zPos] == 2)
            std::cout << "Start";
          else if (grid[xPos][yPos][zPos] == 3)
            std::cout << "*";
          else if (grid[xPos][yPos][zPos] == 4)
            std::cout << "Goal";
        std::cout << std::endl;
      }
      std::cout << "\n" << std::endl;
    }
  } else {
    std::cout << "Path not found!!!" << std::endl;
  }
}
aStar::~aStar() {}

