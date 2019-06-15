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

#endif
