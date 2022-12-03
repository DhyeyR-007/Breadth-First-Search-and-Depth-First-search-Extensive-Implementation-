#pragma once
#include "maze.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include<list>

// ---

/** \brief Breadth First Search solver */
class BFS : public TreeSearch {
   public:
    BFS();

    /** \brief Solve the planning problem. Override TreeSearch::solve() */
    bool solve();

    /** \brief add node to the tree */
    bool addNode(const NodePtr& node);

   private:
    // we decide what data structure we need
 
    std::string name_{"BFS"};
    std::vector<State> path_;
    std::queue <NodePtr> q; 
    std::vector<std::vector<bool>> maze_;
    
    // ---
};
using BFSPtr = std::shared_ptr<BFS>;
