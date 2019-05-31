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
    bool matrix[count + 1][sum + 1];
    
    //if sum = 0 then answer is true
    for(int i = 0; i <=count; i++)
        matrix[i][0] = true;
    
    //if sum is not 0, and the set is empty, then the answer is false
    for(int i = 0; i <= sum; i++)
        matrix[0][i] = false;
    
    for(int i = 1; i <= count; i++) {
        
        for(int j = 1; j <= sum; j++) {
            
            if(j < set[i - 1])
                matrix[i][j] = matrix[i - 1][j];
            
            if(j >= set[i - 1]) {
                matrix[i][j] = matrix[i - 1][j] || matrix[i - 1][j - set[i - 1]];
            }
            
        }
    }
    
    return matrix[count][sum];
    
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
