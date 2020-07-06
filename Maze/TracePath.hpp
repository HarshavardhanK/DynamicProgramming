//
//  TracePath.hpp
//  DynamicProgramming
//
//  Created by Harshavardhan K on 05/08/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef TracePath_hpp
#define TracePath_hpp

#include <stdio.h>
#include "Utilities.hpp"

//MARK: Amazon test problem

int amazon_shelf(int maze[5][5], int rows, int cols, int target, int path, int obstacle, int x, int y);
void test_amazon_shelf();

void generate_maze(int path, int obstacles, int target, int** generated_maze);

//MARK: Rat in a maze
int rat_maze(int maze[5][5], int rows, int cols, int x, int y);
int rat_maze_all_directions(int maze[5][5], int rows, int cols, int x, int y);

void test_rat_maze();



//MARK:- Find path in maze using BFS


#endif /* TracePath_hpp */
