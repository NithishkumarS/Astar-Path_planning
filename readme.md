## Astar Path Planning

[![Build Status](https://travis-ci.org/NithishkumarS/Astar-Path_planning.svg?branch=master)](https://travis-ci.org/NithishkumarS/Astar-Path_planning)
[![Coverage Status](https://coveralls.io/repos/github/NithishkumarS/Astar-Path_planning/badge.svg?branch=master)](https://coveralls.io/github/NithishkumarS/Astar-Path_planning?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Group Information

Sprint 1

 - Driver : Nithish Sanjeev Kumar
 - Navigator : Nantha Kumar Sunder

## To Do List

 - [ ]  Add UML diagrams 
 - [ ]  Run cpplint, cppcheck
 - [ ]  Google C++ style and doxygen
 - [x]  Add google sheet link for the logs in readme
 - [X]  Add Collaborator


## OpenGL Installation

Run the following commands in the terminal
```
sudo apt-get update
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

To check if OpenGL is installed run the following

```
sudo apt install mesa-utils
glxinfo | grep OpenGL
```

## Notes after Discussion(Sprint 1)

 - Movement cost in the 3D grid are assigned as:
	- Distance between two nodes sharing a side is 10
	- Distance between two nodes sharing an edge is 14
	- Distance between two nodes sharing a vertex is 17
 - Include an option to select map.
 - Implement a path planning function to publish the path by comparing the total costs of each node.


