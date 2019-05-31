//
//  Utilities.hpp
//  DynamicProgramming
//
//  Created by Harshavardhan K on 30/05/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef Utilities_hpp
#define Utilities_hpp

#include <iostream>
#include <stdio.h>

template<typename T> void print_array(const T (*array), int size) {
    
    for(int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    
    printf("\n");
}

template<typename T> void print_vector(const vector<T>& list) {
    
    for(auto element: list) {
        cout << element << " ";
    }
    
    printf("\n");
}

template<typename T> void print_matrix(const T* array, int rows, int cols) {
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            std::cout << array[i][j] << " ";
        
        printf("\n");
    }
}

template<typename T> void initialize_array(T** array, int size, T init_value) {
    
    *array = new T[size];
    
    for(int i = 0; i < size; i++)
        (*array)[i] = init_value;
}

template<typename T> void initialize_matrix(T*** matrix, int rows, int columns, T init_value) {
    
    *matrix = new T*[rows];
    
    for(int j = 0; j < columns; j++) {
        (*matrix)[j] = new T[columns];
    }
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            (*matrix)[i][j] = init_value;
}

template<typename T> void generate_random_list(T** array, int count, int range_upper) {
    
    *array = new T[count];
    
    for(int i = 0; i < count; i++) {
        (*array)[i] = std::rand() % range_upper + 1;
    }
}

template<typename T> vector<T>* generate_random_vector(int size, int range, int offset) {
    vector<T>* list = new vector<T>(size);
    
    for(int i = 0; i < size; i++) {

        list->push_back(rand() % range + offset);
    }
    
    return list;
}


#endif /* Utilities_hpp */
