//
//  main.cpp
//  DynamicProgramming
//
//  Created by Harshavardhan K on 23/05/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#include "Basics.hpp"
//#include "Timer.hpp"
#include "wines_order.hpp"
#include "Utilities.hpp"
#include "gfg.hpp"


void test_fibonacci(int num) {

    cout << "Testing fibonacci\n";
   // cout << fibonacci(num) << endl;
    cout << fibonacci_dynamic(num) << endl;
}

void test_factorial(int num) {
    
    long long int* cache = nullptr;
    initialize_array(&cache, num + 1, (long long int)-1);
    //print_array(cache, num);
    
    time_function_factorial(factorial, num);
    time_function_factorial_dynamic(factorial_dynamic, cache, num);
    
}

void print_hello() {
    printf("Hello\n");
}

int main(int argc, const char * argv[]) {

    fibonacci_reverse(5);
    return 0;
}
