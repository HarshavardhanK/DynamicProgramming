//
//  Basics.hpp
//  DynamicProgramming
//
//  Created by Harshavardhan K on 23/05/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef Basics_hpp
#define Basics_hpp

#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int num) {
    
    if(num < 2)
        return 1;
    
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int fibonacci_dynamic(int num) {
    
    int fibonacci_array[100];
    fibonacci_array[0] = 0; fibonacci_array[1] = 1;
    
    for(int i = 2; i < num; i++) {
        fibonacci_array[i] = fibonacci_array[i-1] + fibonacci_array[i-2];
    }
    
    return fibonacci_array[num-1];
}

void number_0f_ways_form_num(int num) {
    int P[10];
    
    P[0] = P[1] = P[2] = 1; P[3] = 2;
    
    for(int i = 4; i <= num; i++) {
        P[i] = P[i-1] + P[i-3] + P[i-4];
    }
    
    cout << P[num] << " ways\n";
}

void number_0f_ways_form_num_SECOND(int num) {
    int P[10];
    
    P[0] = P[1] = 1; P[2] = 2; P[3] = 4; //P[4] = 5;
    
    for(int i = 3; i <= num; i++) {
        P[i] = P[i-1] + P[i-3] + P[i-2];
    }
    
    cout << P[num] << " ways\n";
}

long long int factorial_naive(int num) {
    
    if(num <= 1)
        return 1;
    
    return factorial_naive(num - 1) * num;
}

long long int factorial_dynamic(long long int* cache, int num) {
    
    if(num <= 1)
        return 1;
    
    if(cache[num] != -1)
        return cache[num];
    
    cache[num] = factorial_dynamic(cache, num - 1) * num;
    
    return cache[num];
}

long long int factorial(int num) {
    
    long long int fact = 1;
    
    for(int i = 1; i <= num; i++) {
        fact *= i;
    }
    
    return fact;
}


#endif /* Basics_hpp */
