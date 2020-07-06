//
//  TracePath.cpp
//  DynamicProgramming
//
//  Created by Harshavardhan K on 05/08/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#include "TracePath.hpp"


//Do generatig maze later

void generate_maze(int path, int obstacles, int target, int** maze, int rows, int cols) {
    
    initialize_matrix(&maze, rows, cols, obstacles);
}

int is_valid(int maze[5][5], int rows, int cols, int target, int path, int x, int y) {
    
    if(x < rows && y < cols && maze[x][y] == path) {
        return 1;
    }
    
    return 0;
}

int amazon_shelf(int maze[5][5], int rows, int cols, int target, int path, int obstacle, int x, int y) {
    
    if(maze[x][y] == target) {
        return 1;
    }
    
    if(is_valid(maze, rows, cols, target, path, x, y)) {
        
        maze[x][y] = -1;
        
        if(amazon_shelf(maze, rows, cols, target, path, obstacle, x + 1, y))
            return 1;
        
        if(amazon_shelf(maze, rows, cols, target, path, obstacle, x - 1, y))
            return 1;
        
        if(amazon_shelf(maze, rows, cols, target, path, obstacle, x, y + 1))
            return 1;
        
        if(amazon_shelf(maze, rows, cols, target, path, obstacle, x, y + 1))
            return 1;
        
        return 0;
    }
    
    return 0;
}

void test_amazon_shelf() {
    
    int maze[5][5] = {{1, 0, 0, 0, 0},
                      {1, 0, 0, 0, 0},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                      {1, 1, 10, 0, 0}};
    
    int path = 1; int obstacle = 0; int target = 9;
    
    if(amazon_shelf(maze, 5, 5, target, path, obstacle, 0, 0)) {
        std::cout << "Target found\n";
        
    } else {
        std::cout << "Target not found\n";
    }
    
}

//MARK: Rat maze

int rat_maze(int maze[5][5], int rows, int cols, int x, int y) {
    
    if(maze[x][y] == 1 && x == 4 && y == 4) {
        return 1;
    }
    
    if(is_valid(maze, rows, rows, 1, 1, x, y)) {
        
        if(rat_maze(maze, rows, cols, x + 1, y))
            return 1;
        
        if(rat_maze(maze, rows, cols, x, y + 1))
            return 1;
        
        return 0;
    }
    
    return 0;
}

int rat_maze_all_directions(int maze[5][5], int rows, int cols, int x, int y) {
    
    if(maze[x][y] == 1 && x == rows - 1 && y == rows - 1) {
        return 1;
    }
    
    if(is_valid(maze, rows, cols, 1, 1, x, y)) {
        
        //maze[x][y] = -1;
        
        if(rat_maze_all_directions(maze, rows, cols, x + 1, y))
            return 1;
        
        if(rat_maze_all_directions(maze, rows, cols, x - 1, y))
            return 1;
        
        if(rat_maze_all_directions(maze, rows, cols, x, y + 1))
            return 1;
        
        if(rat_maze_all_directions(maze, rows, cols, x, y - 1))
            return 1;
        
        return 0;
    }
    
    return 0;
}

void test_rat_maze() {
    
    int maze[5][5] =    {{1, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0},
                        {1, 1, 1, 0, 1}};
    
    if(rat_maze_all_directions(maze, 5, 5, 0, 0)) {
        std::cout << "Path found\n";
    } else {
        std::cout << "Path not found\n";
    }
    
}
