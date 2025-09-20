//
//  srtings.hpp
//  algorithms
//
//  Created by Igor on 05.05.2025.
//

#ifndef strings_hpp
#define strings_hpp

#include <stdio.h>
#include <string>
#include <map>

#endif /* strings_hpp */

std::string alphabet_position(const std::string &text);
std::string duplicate_encoder(const std::string& word);
std::string add_binary(uint64_t a, uint64_t b);
std::string to_camel_case(std::string text);
std::map<char, unsigned> count(const std::string& string);
std::vector<std::string> wave(std::string y);
std::string spinWords(const std::string &str); // https://www.codewars.com/kata/5264d2b162488dc400000001
std::string likes(const std::vector<std::string> &names); // https://www.codewars.com/kata/5266876b8f4bf2da9b000362/solutions/cpp
