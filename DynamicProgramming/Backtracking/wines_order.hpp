//
//  wines_order.cpp
//  DynamicProgramming
//
//  Created by Harshavardhan K on 30/05/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//
#ifndef WINES_ORDER_HPP
#define WINES_ORDER_HPP

// Backtracking and naive solution to wine ordering

#include <iostream>

#include "Timer.hpp"
#include "Utilities.hpp"

using namespace std;


int wines_profit_naive(int* price, int year, int beginning, int end) {
    
    if(beginning > end) {
        return 0;
    }
    
    int profit_beginning = wines_profit_naive(price, year + 1, beginning + 1, end) + year * price[beginning];
    int profit_end = wines_profit_naive(price, year + 1, beginning, end - 1) + year * price[end];
    
    return max(profit_end, profit_beginning);
   
}

int wines_profit_memoization(int* price, int** cache, int beginning, int end, int total) {
    
    if(price == nullptr || cache == nullptr) {
        std::cout << "Invalid input\n";
        return -1;
    }
    
    if(beginning > end) {
        return 0;
    }
    
    if(cache[beginning][end] != -1)
        return cache[beginning][end];
    
    int year = total - (end - beginning + 1) + 1;
    
    int profit_beginning = wines_profit_memoization(price, cache, beginning + 1, end, total) + year * price[beginning];
    int profit_end = wines_profit_memoization(price, cache, beginning, end - 1, total) + year * price[end];
    
    cache[beginning][end] = max(profit_end, profit_beginning);
    
    return cache[beginning][end];

 }



//MARK:- Test wines order profits function naive
void test_wine_profits() {
    
    int* price = nullptr;
    int** cache = nullptr;
    
    int count = 30;
    
    generate_random_list(&price, count, 25);
//    print_array(price, 20);
//
//    int profit_naive = wines_profit_naive(price, 0, 0, 5); //start year from 0 to indicate fresh wine..
//
//    time_function_naive_wine_profit(wines_profit_naive, price, 0, 0, 24);
//
//
//    cout << "Profit naive is: " << profit_naive << endl;
    
    
    initialize_matrix(&cache, count, count, -1);
    
//    int profit_dynamic = wines_profit_memoization(price, cache, 0, 19, 20);
//    int profit_naive = wines_profit_naive(price, 0, 0, 19);
//
//    cout << profit_dynamic << endl;
//    cout << profit_naive << endl;
    
    time_function_dynamic_wine_profit(wines_profit_memoization, price, cache, 0, count - 1, count);
    time_function_naive_wine_profit(wines_profit_naive, price, 0, 0, count - 1);
    
}


#endif
