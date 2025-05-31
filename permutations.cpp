//
//  permutations.cpp
//  algorithms
//
//  Created by Igor on 31.05.2025.
//

#include "permutations.hpp"
#include <algorithm>

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
