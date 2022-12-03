#include "maze.h"
#include "bfs.h"
#include "dfs.h"


/** \brief Return the valid next states from a given state */
std::vector<State> ProblemDefinition::validStates(const State &state) const
{
   

    std::vector<int> dcol;
    dcol.push_back(-1);
    dcol.push_back(0);
    dcol.push_back(1);
    dcol.push_back(0);


    std::vector<int> drow;
    drow.push_back(0);
    drow.push_back(1);
    drow.push_back(0);
    drow.push_back(-1);

    std::vector<State> FilterState;

    State statetemp;
      
    if (allow_diagonal_ == false){



        for (int i = 0; i < 4; i++)
        {

            statetemp.x = state.x + dcol[i];
            statetemp.y = state.y + drow[i];

            
            if (isStateValid(statetemp) == true)
            {
                FilterState.push_back(statetemp);
            }
        }

        return FilterState;
    } 
  
    else if (allow_diagonal_ == true){




            dcol.push_back(-1);
            drow.push_back(1);

            dcol.push_back(1);
            drow.push_back(-1);


            dcol.push_back(1);
            drow.push_back(1);



            dcol.push_back(-1);
            drow.push_back(-1);




        for (int i = 0; i < 8; i++)
        {

            statetemp.x = state.x + dcol[i];
            statetemp.y = state.y + drow[i];

            
            if (isStateValid(statetemp) == true)
            {
                FilterState.push_back(statetemp);
            }
        }

        return FilterState;

    }


    // ---
}

/** \brief Given a node, extract the path from it to the root */
void TreeSearch::extractPath(NodePtr node)
{
   
    // Intuition of using parent based shared pointer

    // node->state
    // node->parent->state
    // node->parent->parent->state
    // node->parent->parent->parent->state

    // ...

    
    while (node->parent != nullptr)
    {
        
        path_.push_back(node->state);
        node = node->parent;

        
    }

    path_.push_back(pdef_.startState());
    std::reverse(path_.begin(),path_.end());
    // ---
}

/** \brief Solve the planning problem. Override TreeSearch::solve() */
bool BFS::solve()
{
    // check start and goal are valid
    if (!pdef_.isStateValid(pdef_.startState()) ||
        !pdef_.isStateValid(pdef_.goalState()))
    {

        return false;
    }

    // if start and goal coincide, terminate
    auto start = pdef_.startState();
    if (pdef_.isGoal(start))
    {
        // std::cout << "Start and goal are equal\n";
        return true;
    }

    NodePtr solution;
    // --- Your code here

    Node nh;
    NodePtr solution2;

    Node nt;
   // NodePtr solution;

    Node ee;
    ee.state = pdef_.startState();
    NodePtr pointer1 = std::make_shared<Node>(ee);

    State current = pointer1->state;

    visited_.push_back(current);
    addNode(pointer1);

    std::vector<State> k;

    int flag = 0;
    while (!q.empty())
    {

        auto y = q.front();
        auto yk = pdef_.validStates(y->state);

        q.pop();
        

        for (int i = 0; i < yk.size(); i++)
        {
            
            nt.state = yk[i];

            solution = std::make_shared<Node>(nt);
            solution->parent = y;

            if (pdef_.isStateValid(solution->state))
            {
                if (pdef_.isGoal(solution->state))
                {

                    visited_.push_back(solution->state);
                    flag = 1;
                    break;
                }
                else if (!isVisited(solution))
                {

                    addNode(solution); // q.push(solution);
                    visited_.push_back(solution->state);
                }
            }

        }

        if (flag == 1){
                break;
        }
            

    }


    //---

    // get the path from last node to root
    if(!(solution->state == pdef_.goalState())){
        
        return false;
    } 
    else {
    extractPath(solution);

    return true;

    }
}

/** \brief add node to the tree */
bool BFS::addNode(const NodePtr &node)
{

    q.push(node);
    return true;
}






// /** \brief Solve the planning problem. Override TreeSearch::solve() */
bool DFS::solve()
{
    // check start and goal are valid
    if (!pdef_.isStateValid(pdef_.startState()) ||
        !pdef_.isStateValid(pdef_.goalState()))
    {
        return false;
    }

    // if start and goal coincide, terminate
    auto start = pdef_.startState();
    if (pdef_.isGoal(start))
    {
        std::cout << "Start and goal are equal\n";
        return true;
    }

    NodePtr solution;
    
        Node nh;
    NodePtr solution2;

    Node nt;
   // NodePtr solution;

    Node ee;
    ee.state = pdef_.startState();
    NodePtr pointer1 = std::make_shared<Node>(ee);

    State current = pointer1->state;

    visited_.push_back(current);
    addNode(pointer1);

    std::vector<State> k;

    int flag = 0;
    while (!q.empty())
    {

        auto y = q.top();
        auto yk = pdef_.validStates(y->state);

        q.pop();
        

        for (int i = 0; i < yk.size(); i++)
        {
            
            nt.state = yk[i];

            solution = std::make_shared<Node>(nt);
            solution->parent = y;

            if (pdef_.isStateValid(solution->state))
            {
                if (pdef_.isGoal(solution->state))
                {

                    visited_.push_back(solution->state);
                    flag = 1;
                    break;
                }
                else if (!isVisited(solution))
                {

                    addNode(solution); // q.push(solution);
                    visited_.push_back(solution->state);
                }
            }

        }

        if (flag == 1){
                break;
        }
            

    }


    // get the path from last node to root


    if(!(solution->state == pdef_.goalState())){
        
        return false;
    } 
    else {
    extractPath(solution);

    return true;

    }

}

/** \brief add node to the tree */
bool DFS::addNode(const NodePtr &node)
{
    

     q.push(node);
     return true;

    // ---
}