# Breadth-First-Search-and-Depth-First-search-Extensive-Implementation-

Note:This long-formed approach has been carried out in order to leverage and understand various concepts of advanced c++ programming, especially the concept of smart pointers.

File Functions:

    1. maze_main.cpp : This is the friver code which reads input, calls our solution and then prints the solution.
       
    2. maze.h : declares the problem class and base tree classes
       
    3. bfs.h : declares the BFS class;  here we need to decide what data structures to use and define any helper functions
       
    4. dfs.h : declares the DFS class; here we need to decide what data structures to use and define any helper functions
       
    5. maze_impl.cpp : This file implements some of the methods declared in maze.h , dfs.h and bfs.h
       
    6. maze_impl_student.cpp : Here we implement the remaining methods that were not defined in maze_impl.cpp. This includes
       
    7. ProblemDefinition::validStates (which returns the successors of a state, dependent on if you allow for diagonal traversal),
       
    8. TreeSearch::extractPath (which extracts the actual path from start to goal from a solved goal node into path_ (solved using BFS or DFS), and
       
    9. BFS::solve , DFS::solve , BFS::addNode , and DFS::addNode (used to find the goal node w.r.t. corresponding search strategy)
       
    10. CMakeLists.txt : defines the project for CMake to link together all the executable files (since implementation is spread across multiple .cpp    files)
    

Input, Output and Maze

    • The first line is starting x coordinate, starting y coordinate and allow_diagonal variable respectively. (allow_diagonal controls whether
      the robot can take diagonal actions i.e. 1 means diagonal movement allowed and 0 means no diagonal movement allowed).
    • The second line is the x and y coordinates of the goal cell.
    • The following lines constitute the components of the maze (0 = free space; X = collision)
    • The output coordinates are displayed in the output.txt file.
    
    
In order to visualize the input and output trajectories "visualize_maze.py" file comes into play.
The final graphical plots from the python file are as follows: 
(BFS trajectory is blue; DFS trajectory is red; obstacles represented as X in input files are represented as black patches)

When allow diagonal = 0 (no diagonal movement allowed)  (Input: "input.txt" ; Output: "output.txt")
![image](https://user-images.githubusercontent.com/86003669/205467222-92c5f1e8-bab6-4361-ae79-9356edcdc5fe.png)



When allow diagonal = 1 (diagonal movement allowed)(Input: "input_diagonal.txt" ; Output: "output_diagonal.txt")
![image](https://user-images.githubusercontent.com/86003669/205467261-092c4273-f61a-4a4c-9f6c-69a981e5c2d5.png)








