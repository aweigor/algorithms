//
//  permutations.cpp
//  algorithms
//
//  Created by Igor on 31.05.2025.
//

#include "permutations.hpp"
#include <algorithm>
#include <numeric>

void heap(std::string &s, size_t n, std::vector<std::string> &acc) {
    if (n == 1) {
        acc.push_back(s);
        return;
    }
    for (int i = 0; i < n; ++i) {
        heap(s, n - 1, acc);
        if (n % 2 == 0) {
            std::swap(s[i], s[n - 1]);
        } else {
            std::swap(s[0], s[n - 1]);
        }
    }
}

std::vector<std::string> permutations(std::string s) {
    // can be done by std::next_permutation
    std::vector<std::string> every{};
    heap(s, s.size(), every);
    std::sort(every.begin(), every.end());
    every.erase(std::unique(every.begin(), every.end()), every.end());
    return every;
}

std::vector <int> josephus(std::vector <int> items, int k) {
    std::vector< int > result;
    int pos = k-1;
    
    while (items.size())
    {
        pos %= items.size();
        result.push_back(items[pos]);
        items.erase(items.begin()+pos);
        pos += k-1;
    }

    return result;
}


int josephusSurvivor(int n, int k) {
    int p = k - 1;
    std::vector<int> vec(n);
    std::iota (std::begin(vec), std::end(vec), 1);
    while (vec.size() > 1) {
        p %= vec.size();
        vec.erase(vec.begin() + p);
        p += k - 1;
    }
    return vec[0];
}
