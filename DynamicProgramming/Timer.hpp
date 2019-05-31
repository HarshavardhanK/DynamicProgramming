//
//  Timer.h
//  DynamicProgramming
//
//  Created by Harshavardhan K on 23/05/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <chrono>
using namespace std::chrono;
using namespace std;

void time_function_fibonacci(void (*function) (int), int arg) {
    
    auto start = high_resolution_clock::now();
    
    function(arg);
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Execution time is: " << double(duration.count() / 1000.0) << "ms" << endl;
}

void time_function_naive_wine_profit(int(*function) (int*, int, int, int), int* price, int year, int beg, int end) {
    
    auto start = high_resolution_clock::now();
    
    int profit = function(price, year, beg, end);
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Profit is: " << profit << endl;
    cout << "Execution time is: " << duration.count() / 1000.0 << "ms" << endl;
}

void time_function_dynamic_wine_profit(int(*function) (int*, int**, int, int, int), int* price, int** cache, int beg, int end, int total) {
    
    auto start = high_resolution_clock::now();
    
    int profit = function(price, cache, beg, end, total);
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Profit is: " << profit << endl;
    cout << "Dynamic Execution time is: " << duration.count() / 1000.0 << "ms" << endl;
}

void time_function_factorial(long long int (*function) (int), int arg) {
    
    auto start = high_resolution_clock::now();
    
    long long int factorial = function(arg);
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    cout << "Factorial of: " << arg << " is " << factorial << endl;
    cout << "Execution time is: " << duration.count() << "ns" << endl;
}

void time_function_factorial_dynamic(long long int (*function) (long long*, int), long long* cache, int arg) {
    
    auto start = high_resolution_clock::now();
    
    long long int factorial = function(cache, arg);
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    cout << "Factorial of " << arg << " is " << factorial << endl;
    cout << "Execution time is: " << duration.count() << "ns" << endl;
}

void time_function_subset_sum(bool (*function) (int*, int, int), int* set, int count, int sum) {
    
    auto start = high_resolution_clock::now();
    
    bool result = function(set, count, sum);
    
    auto stop = high_resolution_clock::now();
    
    if(result)
        cout << "Subset sum exists\n";
    
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    cout << "Subset sum duration is: " << duration.count() << "ns" << endl;
}

void time_function_rod_cutting(int (*function) (vector<int>&, int), vector<int>& price, int count) {
    
    auto start = high_resolution_clock::now();
    
    int value = function(price, count);
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Max price: " << value << endl;
    cout << "Execution time: " << duration.count() << endl;
}

void time_function(void (*function)()) {
    
    auto start = high_resolution_clock::now();
    function();
    auto stop = high_resolution_clock::now();
    
    cout << "Execution time: " << duration_cast<microseconds>(stop - start).count() << "us\n";
}

void print(void *(function)()) {
    function();
}


#endif /* Timer_h */
