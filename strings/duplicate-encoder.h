#pragma once 

#include <string>

std::string duplicate_encoder(const std::string& word){
    std::string r = "";
    int map[128] = {};
    for (auto &c : word) map[tolower(c)]++;
    for (auto &c : word) r += map[tolower(c)] > 1 ? ")" : "(";
    return r;
}