//
//  GeeksForGeeks.cpp
//  DynamicProgramming
//
//  Created by Harshavardhan K on 30/05/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef gfg_hpp
#define gfg_hpp

#include <iostream>
#include <vector>
using namespace std;


//MARK:- BINOMIAL COEFFICIENT

int binomial_coefficient_naive(int n, int k);
int binomial_coefficient_dynamic(int n, int k);
int binomial_coefficient_dynamicA(int , int);

void test_binomial_coefficient(int, int);

//MARK:- SUBSET SUM PROBLEM
bool is_subset_sum(int* set, int count, int sum);
bool is_subset_sum_dynamic(int* set, int count, int sum);

void test_subset_sum_problem(int* set, int count, int sum);

//MARK:- ROD CUTTING PROBLEM
int rod_cutting_naive(vector<int>&, int count);
int rod_cutting_dynamic(vector<int>&, int count);
void test_rod_cutting();

//MARK:- LONGEST COMMON SUBSEQUENCE..
int longest_common_subsequence_naive(string first, string second, int m, int n);
int longest_common_subsequence_dynamic(string first, string second, int m, int n);
void test_lcs();

//MARK:- Maximum continous sum..
template<typename T> T maximum_continous_sum(vector<T> &);
template<typename T> T maximum_continous_sum(vector<T>& list, bool print, int& beginning_index, int& end_index);
void test_max_sum();

//MARK:- COIN CHANGE PROBLEM
int count_coin_change_naive(vector<int>, int, int);
void test_coin_change();

//MARK:- ASSEMBLY LINE
//int car_assembly_line(int**, int**, int, int);
void test_car_assembly_line();

//MARK:- FIBONACCI IN REVERSE ORDER
void fibonacci_reverse(int);


//MARK:- SMALLEST SUM CONTINGOUS SUB ARRAY
template<typename T> T smallet_sum_contigous_sub_array(vector<T> array);

//MARK:- Minimum steps to one
void min_steps_to_one(int num);
int min_steps_to_one_helper(int num);

//MARK:- No. of ways to climb
void no_of_ways_clim_stairs(int steps, int* step);

//MARK:- Different ways to express N as sum of 1,3, and 4
int different_ways_naive(int);
int different_ways(int);
void test_different_ways();

//MARK:- Count the number of binary trees of height h
long long int num_binary_trees_for(int);
void test_num_binary_trees_for();

//MARK:- No/of ways to reach right bottom from left bottom in a matrix
int number_of_paths_from_left_top_right_bottom_naive(int, int);
int number_of_paths_from_left_top_right_bottom_dynamic(int, int);
void test_number_of_paths_from_left_top_right_bottom();

#endif
