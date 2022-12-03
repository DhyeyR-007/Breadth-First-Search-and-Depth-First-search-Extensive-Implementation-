# Breadth-First-Search-and-Depth-First-search-Extensive-Implementation-

maze_main.cpp : This is the friver code which reads input, calls our solution and then prints the solution.

maze.h : declares the problem class and base tree classes

bfs.h : declares the BFS class;  here we need to decide what data structures to use and define any helper functions

dfs.h : declares the DFS class; here we need to decide what data structures to use and define any helper functions

maze_impl.cpp : This file implements some of the methods declared in maze.h , dfs.h and bfs.h

maze_impl_student.cpp : Here we implement the remaining methods that were not defined in maze_impl.cpp. This includes
    ProblemDefinition::validStates (which returns the successors of a state, dependent on if you allow for diagonal traversal),
    TreeSearch::extractPath (which extracts the actual path from start to goal from a solved goal node into path_ (solved using BFS or DFS), and
    BFS::solve , DFS::solve , BFS::addNode , and DFS::addNode (used to find the goal node w.r.t. corresponding search strategy)

And last bu not the least,
CMakeLists.txt : defines the project for CMake to link together all the executable files (since implementation is spread across multiple .cpp files)

This long-formed approach has been carried out in order to leverage and understand various concepts of advanced c++ programming, especially the concpet of smart pointers.

The input is given in input.txt for example:

The first line is starting x coordinate, starting y coordinate and allow_diagonal variable respectively. (allow_diagonal controls whether
the robot can take diagonal actions i.e. 1 means diagonal movement allowed and 0 means no diagonal movement allowed).

The second line is the x and y coordinates of the goal cell.

The following lines consitute the components of the maze (0 = free space; X = collision)
The output coordinates are displayed in the output.txt file
