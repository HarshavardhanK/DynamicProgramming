//
//  GeeksForGeeks.cpp
//  DynamicProgramming
//
//  Created by Harshavardhan K on 30/05/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#include "gfg.hpp"
#include "Utilities.hpp"


int binomial_coefficient_naive(int n, int k) {
    
    if(k == 0 || k == n) {
        return 1;
    }
    
    return binomial_coefficient_naive(n - 1, k - 1) + binomial_coefficient_naive(n - 1, k);
}

int binomial_coefficient_dynamicA(int n, int k) {
    
    int* cache = nullptr;
    //memset(*cache, 0, sizeof(**cache));
    initialize_array(&cache, k + 1, 0);
    
    cache[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = min(i, k); j > 0; j--) {
            (cache)[j] = (cache)[j] + (cache)[j - 1];
        }
    }
    
    return (cache)[k];
    
}

int binomial_coefficient_dynamic(int n, int k) {
    
    int** cache = nullptr;
    initialize_matrix(&cache, n + 1, k + 1, 0);
    //memset(cache, 0, sizeof(cache[0][0]) * k * n);
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            
            if(i == 0 || k == n) {
                (cache)[i][j] = 1;
                
            } else {
                (cache)[i][j] = (cache)[i - 1][j - 1] + (cache)[i - 1][j];
            }
        }
    }
    
    return (cache)[n][k];
}

//NOT WORKING !!! PROBLEMS IN initializa_matrix, and memeset in cache..

void test_binomial_coefficient(int n, int k) {
    
    //cout << binomial_coefficient_naive(n, k) << endl;
    cout << binomial_coefficient_dynamic(n, k) << endl;
}


bool is_subset_sum(int* set, int count, int sum) {
    
    if(sum == 0)
        return true;
    
    if(count == 0 && sum != 0)
        return false;
    
    if(set[count - 1] > sum) {
        return is_subset_sum(set, count - 1, sum);
    }
    
    return is_subset_sum(set, count - 1, sum) || is_subset_sum(set, count - 1, sum - set[count - 1]);
}

bool is_subset_sum_dynamic(int* set, int count, int sum) {
    
    //value of matrix[i][j] will be true if there is a subset set[0..j-1] with sum equal to i..
    bool memory[count + 1][sum + 1];
    
    //set all sum=0 values to true
    for(int i = 0; i <= count; i++)
        memory[i][0] = true;
    
    //set all other values to false to indicate such a sum cannot be formed YET
    for(int i = 1; i <= sum; i++)
        memory[0][i] = false;
    
    for(int i = 1; i <= count; i++) {
        
        for(int j = 1; j <= sum; j++) {
            
            if(j < set[i - 1]) {
                memory[i][j] = memory[i - 1][j];
                
            } else {
                memory[i][j] = memory[i - 1][j] || memory[i - 1][j - set[i - 1]];
            }
        }
    }
    
    //print_matrix<count + 1, sum + 1>(memory, count + 1, sum + 1);
    for(int i = 0; i <= count; i++) {
        
        for(int j = 0; j <= sum; j++) {
            cout << bool(memory[i][j]) << " ";
        }
        cout << '\n';
    }
    
    return memory[count][sum];
    
}

void test_subset_sum_problem(int* set, int count, int sum) {
    
    if(set == nullptr) {
        cout << "Invalid input\n";
        return;
    }
    
    bool naive_sum = is_subset_sum(set, count, sum);
    bool dynamic_sum = is_subset_sum_dynamic(set, count, sum);
    
    if(naive_sum || dynamic_sum)
        cout << "Subset sum exists\n";
    else
        cout << "Subset sum doesnt exist\n";
    
}

//MARK:- ROD CUTTING PROBLEM
 int rod_cutting_naive(vector<int>& price, int count) {
    
    int max_value = INT_MIN;
    
    if(count <= 0) {
        return 0;
    }
    
    for(int i = 0; i < count; i++) {
        max_value = max(max_value, price[i] + rod_cutting_naive(price, count - i - 1));
    }
    
    return max_value;
}

int rod_cutting_dynamic(vector<int>& price, int count) {
    
    int values[count + 1];
   // memset(values, 0, sizeof(values));
    values[0] = 0;
    
    
    for(int i = 1; i <= count; i++) {
        int max_value = INT_MIN;
        
        for(int j = 0; j < i; j++) {
            max_value = max(max_value, price[j] + values[i - j - 1]);
        }
        values[i] = max_value;

    }
    
    return values[count];
    
}

void test_rod_cutting() {
    
    vector<int> price {1,5,8,9,10,17,17,20};
    
   // cout << "Max price: " << rod_cutting_naive(price, 8) << endl;
    cout << "Max price: " << rod_cutting_dynamic(price, 8) << endl;
    
    //time_function_rod_cutting(rod_cutting_dynamic, price, 8);
    
}

//MARK:- LONGEST COMMON SUBSEQUENCE

int longest_common_subsequence_naive(string first, string second, int m, int n) {
    
    if(m == 0 || n == 0) {
        return 0;
    }
    
    if(first[m - 1] == second[n - 1]) {
        return 1 + longest_common_subsequence_naive(first, second, m - 1, n - 1);
    }
    
    return max(longest_common_subsequence_naive(first, second, m, n - 1), longest_common_subsequence_naive(first, second, m - 1, n));
}

int longest_common_subsequence_dynamic(string first, string second, int m, int n) {
    
//    int** LCS = nullptr;
//    initialize_matrix(&LCS, m + 1, n + 1, 0);
//    //print_matrix(LCS, m + 1, n + 1);
    
    int LCS[m + 1][n + 1];
    
    for(int i = 0; i <= m; i++) {
        
        for(int j = 0; j <= n; j++) {
            
            if(i == 0 || j == 0) {
                LCS[i][j] = 0;
                
            } else if (first[m - 1] == second[n - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    
    return LCS[m][n];
}

int lcs( string X, string Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;
    
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
     that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}
//NOTWORK:- ^^ABOVE CODE

void test_lcs() {
    
    string first = "AGGTAB";
    string second = "GXTXAYB";
    
    cout << "LCS is " << longest_common_subsequence_naive(first, second, (int)first.size(), (int)second.size()) << endl;
    
    cout << "LCS is " << longest_common_subsequence_dynamic(first, second, (int)first.size(), (int)second.size()) << endl;
    
    cout << "LCS is " << lcs(first, second, (int)first.size(), (int)second.size()) << endl;
}


//MARK:- MAXIMUM LONGEST SUM..
template<typename T> T maximum_continous_sum(vector<T> &list) {
    
    T current_max = list[0];
    T max_global = list[0];
    
    int length = (int) list.size();
    
    for(int i = 1; i < length; i++) {
        current_max = max(list[i], current_max + list[i]);
        max_global = max(max_global, current_max);
    }
    
    return max_global;
}

//MARK:- MAXIMUM LONGEST SUM WITH PRINTING THE INDICES..

template<typename T> T maximum_continous_sum(vector<T>& list, bool print, int& beginning_index, int& end_index) {
    
    if(print) {
        
        T global_max = INT_MIN;
        T max_end_here = 0;
        
        beginning_index = 0; end_index = 0;
        int start = 0;
        
        int length = (int) list.size();
        
        for(int i = 0; i < length; i++) {
            max_end_here += list[i];
            
            if(max_end_here > global_max) {
                global_max = max_end_here;
                
                //Set indices
                end_index = i;
                beginning_index = start;
                
            }
            
            if(max_end_here < 0) {
                max_end_here = 0;
                start = i + 1;
            }
        }
        
        return global_max;
        
    } else {
        return maximum_continous_sum(list);
    }
}

void test_max_sum() {
    vector<int> *list = generate_random_vector<int>(5, 10, -3);
    print_vector(*list);
   // cout << "Max sum: " << maximum_continous_sum(*list) << endl;
    
    int beg = 0; int end = 0;
    
    cout << maximum_continous_sum(*list, true, beg, end) << endl;
    print_vector(*list, beg, end + 1); // end + 1 since the end_index in the function is EXACTLY till the last element contributing to the maximum sum..
    
}

//MARK:- COIN CHANGE PROBLEM
int count_coin_change_naive(vector<int> S, int m, int n) {
    
    if(n == 0)
        return 1;
    
    if(n < 0)
        return 0;
    
    if(m <= 0 && n >= 1)
        return 0;
    
    return count_coin_change_naive(S, m - 1, n) + count_coin_change_naive(S, m, n - S[m - 1]);
    //didn't understand shit here...
}

void test_coin_change() {
    
    vector<int> coins = {1,2,5};
    int change = 12;
    
    cout << "No of ways for change: " << count_coin_change_naive(coins, (int)coins.size(), change) << endl;
}

//MARK:- CAR ASSEMBLY LINE
int car_assembly_line(int price_station[][4], int price_change_line[][4], int* entry, int* exit, int num_stations, int num_lines) {
    
    int timeA[num_stations];
    int timeB[num_stations];
    
    timeA[0] = price_station[0][0] + entry[0];
    timeB[0] = price_station[1][0] + entry[1];
    
    for(int i = 1; i < num_stations; i++) {
        
        timeA[i] = min(timeA[i - 1] + price_station[0][i], timeB[i - 1] + price_change_line[1][i] + price_station[0][i]);
        
        timeB[i] = min(timeB[i - 1] + price_station[1][i], timeA[i - 1] + price_change_line[0][i] + price_station[1][i]);
    }
    
    return min(timeA[num_stations - 1] + exit[0], timeB[num_stations - 1] + exit[1]);
}

void test_car_assembly_line() {
    
    const int num_station = 4;
    const int line = 2;
    
    int price_station[][num_station] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    int price_change_line[][num_station] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
    int entry[] = {10, 12};
    int exit[] = {18, 7};
    
    int cost = car_assembly_line(price_station, price_change_line, entry, exit, num_station, line);
    
    cout << "Cost of car in assembly: " << cost << endl;
    
}

//MARK:- FIBONACCI IN REVERSE ORDER..
void fibonacci_reverse(int num) {
    
    int fibonacci[num + 1];
    fibonacci[0] = 0; fibonacci[1] = 1;
    
    for(int i = 2; i < num; i++) {
        fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
    }
    
   // print_array(fibonacci, num);
    
    reverse_array(fibonacci, num);
    
    print_array(fibonacci, num);
    
}

//MARK:- SMALLEST SUM CONTIGOUS SUB ARRAY
template<typename T> T smallet_sum_contigous_sub_array(vector<T> array) {
    
    T min_global = INT_MAX;
    T min_local = INT_MAX;
    
    for(auto element: array) {
        
        if(min_local > 0) {
            min_local = element;
            
        } else {
            min_local += element;
        }
        
        min_global = min(min_global, min_local);
    }
    
    return min_global;
    
}

//MARK:-Min steps to one

int min_steps_to_one_helper(int* memory, int num) {
    
    if(num == 1)
        return 0;
    
    if(memory[num] != -1) {
        return memory[num];
    }
    
    int r = 1 + min_steps_to_one_helper(memory, num - 1);
    
    if(num % 2 == 0) {
        r = min(r, 1 + min_steps_to_one_helper(memory, num / 2));
    }
    
    if(num % 3 == 0) {
        r = min(r, 1 + min_steps_to_one_helper(memory, num / 3));
    }
    
    memory[num] = r;
    
    return r;
    
}

void min_steps_to_one(int num) {
    
    int memory[num + 1];
    
    for(int i = 0; i <= num; i++)
        memory[i] = -1;
    
    //initialize_array(&memory, size, -1);
    
    cout << min_steps_to_one_helper(memory, num) << endl;
    
}

//MARK:- Count no of ways to step
void no_of_ways_clim_stairs(int steps, int* step, int size) {
    
    if(!step) {
        std::cout << "Enter valid step\n";
        return;
    }
    
    int* result;
    initialize_array(&result, size, 0);
}


int different_ways(int num) {
    
    int result[num + 1];
    
    result[0] = 1;
    result[1] = 1;
    result[2] = 1;
    
    for(int i = 1; i <= num; i++) {
        result[i] = result[i - 1] + result[i - 3] + result[i - 4];
    }
    
    return result[num];
    
}

int different_ways_naive(int num) {
    
    if(num <= 2)
        return 1;
    
    if(num == 3)
        return 2;

    return different_ways_naive(num - 1) + different_ways_naive(num - 3) + different_ways_naive(num - 4);
}

void test_different_ways() {
    
    cout << different_ways_naive(10) << '\n';
}

long long int num_binary_trees_for(int height) {
    
    int memory[height + 1];
    memory[0] = memory[1] = 1;
    
    for(int i = 2; i <= height; i++) {
        memory[i] = memory[i - 1] * (2 * memory[i - 2] + memory[i - 1]);
    }
    
    return memory[height];
}

void test_num_binary_trees_for() {
    
    cout << num_binary_trees_for(15) << '\n';
}

//MARK:- No/of ways to reach right bottom from left bottom in a matrix
int number_of_paths_from_left_top_right_bottom_naive(int rows, int cols) {
    
    if(cols == 1 || rows == 1)
        return 1;
    
    return number_of_paths_from_left_top_right_bottom_naive(rows - 1, cols) + number_of_paths_from_left_top_right_bottom_naive(rows, cols - 1);
    
}

int number_of_paths_from_left_top_right_bottom_dynamic(int rows, int cols) {
    
    
    int **memory;
    initialize_matrix(&memory, rows, cols, 0);
    
    //count of paths to reach any cell in the 1st col
    for(int i = 0; i < rows; i++) {
        memory[i][0] = 1;
    }
    
    //count of paths to reach any cell in the 1st row
    for(int i = 0; i < cols; i++) {
        memory[0][i] = 1;
    }
    
    for(int i = 1; i < rows; i++) {
        
        for(int j = 1; j < cols; j++) {
            
            memory[i][j] = memory[i - 1][j] + memory[i][j - 1];
        }
    }
    
    return memory[rows - 1][cols - 1];
    
}


void test_number_of_paths_from_left_top_right_bottom() {
    
    cout << number_of_paths_from_left_top_right_bottom_dynamic(3, 3) << '\n';
}

//MARK:- 0-1 Knapsack
int knapsack_naive(int weights[], int value[], int max_weight, int num) {
    
    if(num == 0 || max_weight == 0)
        return 0;
    
    if(weights[num - 1] > max_weight) {
        return knapsack_naive(weights, value, max_weight, num - 1);
    }
    
    return max(value[num - 1] + knapsack_naive(weights, value, max_weight - weights[num - 1], num - 1), knapsack_naive(weights, value, max_weight, num - 1));
    
}

int knapsack_dynamic(int weights[], int values[], int max_weight, int num) {
    
    int memory[num + 1][max_weight + 1];
    
    for(int i = 0; i <= num; i++) {
        memory[0][i] = 0;
        memory[i][0] = 0;
    }
    
    for(int i = 1; i <= num; i++) {
        
        for(int j = 1; j <= max_weight; j++) {
            
            if(weights[j - 1] <= j) {
                memory[i][j] = max(values[i] + memory[i - 1][j - weights[i - 1]], memory[i - 1][j]);
                
            } else {
                memory[i][j] = memory[i - 1][j];
            }
        }
    }
    
    return memory[num][max_weight];
    
}

void test_knapsack() {
    
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    
    int max_weight = 50;
    
    cout << knapsack_naive(weights, values, max_weight, 3) << '\n';
    cout << knapsack_dynamic(weights, values, max_weight, 3) << '\n';
}


float maximum_average_path(int cost[3][3]) {
    
    int memory[3][3];
    memory[0][0] = cost[0][0];
    
    for(int i = 1; i < 3; i++) {
        memory[i][0] = memory[i - 1][0] + cost[i][0];
        memory[0][i] = memory[0][i - 1] + cost[0][i];
    }
    
    for(int i = 1; i < 3; i++) {
        for(int j = 1; j < 3; j++) {
            memory[i][j] = max(memory[i - 1][j], memory[i][j - 1]) + cost[i][j];
        }
    }
    
    return memory[2][2] / (float)(2 * 3 - 1);
    
}

void test_maximum_average_path() {
    
    int cost[][3] = {{1,2,3}, {6,5,4}, {7,3,9}};
    
    std::cout << maximum_average_path(cost) << '\n';
}

//MARK:- No. of unique path in GRID with obstacles
int unique_grid_path(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<int>> path(rows, vector<int>(cols, 0));
    
    for(int i = 0; i < rows; i++) {
        if(grid[i][0] != 1) {
            path[i][0] = 1;
        }
    }
    
    for(int i = 0; i < cols; i++) {
        if(grid[0][i] != 1) {
            path[0][i] = 1;
        }
    }
    
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            
            if(grid[i][j] == 0) {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
    }
    
    return path[rows - 1][cols - 1];
}

void test_unique_grid_paths() {
    vector<vector<int>> grid = {{0,0,0}, {0,1,0}, {0,0,0}};
    cout << "Number of unique paths = " << unique_grid_path(grid) << '\n';
}
