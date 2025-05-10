//
//  main.cpp
//  algorithms
//
//  Created by Igor on 04.05.2025.
//

#include <iostream>
#include <cassert>
#include "strings.hpp"
#include "prod_fib.hpp"

void testAlphabetPosition()
{
    std::cout << alphabet_position("The sunset sets at twelve o' clock.") << "\n";
    assert(alphabet_position("The sunset sets at twelve o' clock.") == "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11");
    assert(alphabet_position("The narwhal bacons at midnight.") == "20 8 5 14 1 18 23 8 1 12 2 1 3 15 14 19 1 20 13 9 4 14 9 7 8 20");
    assert(alphabet_position("0123456789") == "");
    assert(alphabet_position(",./<>?-_=+ ") == "");
    assert(alphabet_position("") == "");
}

void testDuplicateEncoder()
{
    assert(duplicate_encoder("din") == "(((");
    assert(duplicate_encoder("recede") == "()()()");
    assert(duplicate_encoder("Success") == ")())())");
    assert(duplicate_encoder("CodeWarrior") == "()(((())())");
    assert(duplicate_encoder("Supralapsarian") == ")()))()))))()(");
    assert(duplicate_encoder("(( @") == "))((");
    assert(duplicate_encoder(" ( ( )") == ")))))(");
}

void testAddBinary()
{
    assert(add_binary(1, 1) == "10");
    assert(add_binary(0, 1) == "1");
    assert(add_binary(1, 0) == "1");
    assert(add_binary(2, 2) == "100");
    assert(add_binary(51, 12) == "111111");
}

void testToCamelCase()
{
    assert(to_camel_case("") == "");
    assert(to_camel_case("the_stealth_warrior") == "theStealthWarrior");
    assert(to_camel_case("The-Stealth-Warrior") == "TheStealthWarrior");
    assert(to_camel_case("A-B-C") == "ABC");
}

void testProdFib()
{
    std::vector<ull> expected = {};
    expected = {89, 144, false};
    //assert(ProdFib::productFib(5895) == expected);
    expected = {55, 89, true};
    assert(ProdFib::productFib(4895) == expected);
    expected = {6765, 10946, 1ULL};
    assert(ProdFib::productFib(74049690) == expected);
    expected = {10946, 17711, 0ULL};
    assert(ProdFib::productFib(84049690) == expected);
}

int main(int argc, const char * argv[])
{
    testAlphabetPosition();
    testDuplicateEncoder();
    testAddBinary();
    testToCamelCase();
    testProdFib();
    return 0;
}
