#pragma once
#include "maze.h"
// other includes
// --- Your code here

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include<list>



// ---

/** \brief Depth First Search solver */
class DFS : public TreeSearch {
   public:
    DFS();

    /** \brief Solve the planning problem. Override TreeSearch::solve() */
    bool solve();

    /** \brief add node to the tree */
    bool addNode(const NodePtr& node);

   private:
    // we decide what data structure we need

    std::string name_{"DFS"};
    std::vector<State> path_;
    std::stack <NodePtr> q; 
    std::vector<std::vector<bool>> maze_;

    // ---
};
using DFSPtr = std::shared_ptr<DFS>;