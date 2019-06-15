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

