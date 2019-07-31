//
//  string_manip.cpp
//  DynamicProgramming
//
//  Created by Harshavardhan K on 30/07/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#include "string_manip.hpp"

int make_anagrams(std::string str1, std::string str2) {
    
    std::vector<int> freq(26, 0);
    int count = 0;
    
    for(auto c: str1) {freq[c - 'a']++;}
    for(auto c: str2) {freq[c - 'a']--;}
    
    for(auto val: freq) {count += abs(val);}
    
    return count;
    
}

void test_make_anagrams() {
    
    std::string str1 = "cde";
    std::string str2 = "abc";
    
    std::cout << make_anagrams(str1, str2) << std::endl;
}

int alternating_characters(std::string word) {
    
    int count = 0;
    
    size_t length = word.size();
    bool delete_index[length];
    
    for(int i = 0; i < length; i++) {
        delete_index[i] = false;
    }
    
    for(size_t i = 0; i < length - 1; i++) {
        
        if(word[i] == word[i + 1])
            delete_index[i] = true;
    }
    
    for(int i = 0; i < length; i++) {
        
        if(delete_index[i]) {
            count++;
        }
    }
    
    return count;
}

void test_alternating_characters() {
    
    std::string word = "AAAA";
    
    std::cout << alternating_characters(word) << '\n';
}
