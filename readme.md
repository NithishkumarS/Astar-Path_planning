## Astar Path Planning

[![Build Status](https://travis-ci.org/NithishkumarS/Astar-Path_planning.svg?branch=master)](https://travis-ci.org/NithishkumarS/Astar-Path_planning)
[![Coverage Status](https://coveralls.io/repos/github/NithishkumarS/Astar-Path_planning/badge.svg?branch=master)](https://coveralls.io/github/NithishkumarS/Astar-Path_planning?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Overview

 A* algorithm is widely algorithms in pathfinding and graph traversal, which is the process of computing a path between different points, called "nodes". Its has been used extensively due to its performance and accuracy.

This github repository implements a path planning module that aids in providing the shortest path for a given initial position to target position in an known environment. By using Astar algorithm, it combines the best features of Dijkstra’s algorithm (favoring vertices that are closeto starting points) and data that Greedy Best-first-search uses (favoring vertices that are close to the goal).By considering the hueristic cost its able to provide efficient output.

Heuristic cost is the direct shortest distance between the current node and the target node. 

Here the 3D space is taken as grids. A 4x4x4 grid is taken and obstacles are randomly assigned.  Free spaces is taken as 0; Nodes with obstacles are taken as 1.  

Features:

If a known 3D map of the environment is provided as grids, best possible path is found in the static environment. This planned path could be used by aerial robots or manipulators.


## Group Information

Sprint 1

 - Driver : Nithish Sanjeev Kumar
 - Navigator : Nantha Kumar Sunder

Sprint 2

 - Driver : Nantha Kumar Sunder
 - Navigator : Nithish Sanjeev Kumar

## To Do List

 - [X]  Update UML diagrams 
 - [ ]  Run cpplint, cppcheck
 - [X]  Google C++ style and doxygen
 - [X]  Unit test cases
 - [ ]  Setting up demo


## Notes after Discussion(Sprint 1)

 - Movement cost in the 3D grid are assigned as:
	- Distance between two nodes sharing a side is 10
	- Distance between two nodes sharing an edge is 14
	- Distance between two nodes sharing a vertex is 17
 - Include an option to select map.
 - Implement a path planning function to publish the path by comparing the total costs of each node.

## Notes after Discussion(Sprint 2)
 - Develop small, repeatable and iterative functions
 - 
 -

## SIP Documentation

The link for the googledoc:

```
https://docs.google.com/spreadsheets/d/1Ef-vPpexzwGPBfQgoCBKfasl7S51SkOQiOGoCKZNjUk/edit?usp=sharing
```

## Standard install via command-line
```
git clone --recursive https://github.com/NithishkumarS/Astar-Path_planning.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Doxygen

To install Doxygen
```
sudo apt install doxygen
```
once the installation is over we can generate the Doxygen documentation by running
```
doxygen ./Doxygen
```

## Demo

To run the demo go to the project directory and enter
```
cd build
./app/shell-app
'''





