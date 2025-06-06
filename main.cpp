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
#include "asum.hpp"
#include "numbers.hpp"
#include "llist.hpp"
#include "functions.hpp"
#include "find_path.hpp"
#include "cyphers.hpp"
#include "permutations.hpp"
#include "decomp.hpp"
#include "calc_functions.hpp"

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

void testFindNb()
{
    assert(ASum::findNb(4183059834009) == 2022);
    assert(ASum::findNb(24723578342962) == -1);
    assert(ASum::findNb(135440716410000) == 4824);
    assert(ASum::findNb(40539911473216) == 3568);
    assert(ASum::findNb(26825883955641) == 3218);
}

void testMultiples35()
{
    assert(multiples35(10) == 23);
    assert(multiples35(18) == 60);
    //assert(multiples35(75) == 1320);
    assert(multiples35_slow(76) == 1350);
}

void testLoopSize()
{
    Node n1, n2, n3, n4;
    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n2);
    int actual = getLoopSize(&n1);
    assert(actual == 3);
}

void testUint32toIp()
{
    assert(uint32_to_ip(2154959208) == "128.114.17.104");
    assert(uint32_to_ip(0) == "0.0.0.0");
    assert(uint32_to_ip(32) == "0.0.0.32");
    assert(uint32_to_ip(2149583361) == "128.32.10.1");
}

void testChainFunction()
{
    add(1)(2);
}

void testJosephus()
{
    //assert(josephus({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1) == std::vector < int > ({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    //assert(josephus({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2) == std::vector < int > ({2, 4, 6, 8, 10, 3, 7, 1, 9, 5}));
    assert(josephus({1, 2, 3, 4, 5, 6, 7}, 3) == std::vector < int > ({3, 6, 2, 7, 5, 1, 4}));
    assert(josephus({}, 3) == std::vector < int > ({}));
}

void testFindPath()
{
    assert(path_finder(".W.\n.W.\n...") == true);
    assert(path_finder(".W.\n.W.\nW..") == false);
    assert(path_finder("......\n......\n......\n......\n......\n......") == true);
    assert(path_finder("......\n......\n......\n......\n.....W\n....W.") == false);
}

void testRgbToHex()
{
    assert(rgb_to_hex(0, 0, 0) == "000000");
    assert(rgb_to_hex(1, 2, 3) == "010203");
    assert(rgb_to_hex(255,255,255) == "FFFFFF");
    assert(rgb_to_hex(254,253,252) == "FEFDFC");
    assert(rgb_to_hex(-20,275,125) == "00FF7D");
}

void testPartitions()
{
    assert(partitions(5) == 7);
    assert(partitions(10) == 42);
    assert(partitions(25) == 1958);
    //uint32_t p = partitions(38);
}

void testRot13()
{
    assert(rot13("EBG13 rknzcyr.") == "ROT13 example.");
}

void testKnightPath()
{
    assert(knight("a1", "c1") == 2);
    assert(knight("a1", "f1") == 3);
    assert(knight("a1", "f3") == 3);
    assert(knight("a1", "f4") == 4);
    assert(knight("a1", "f7") == 5);
}

void testWaves()
{
    std::vector<std::string> test{"Hello", "hEllo", "heLlo", "helLo", "hellO"};
    assert(wave("hello") == test);
}

void testIsPrime()
{
    assert(isPrime6(1) == false);
    assert(isPrime6(3) == true);
    assert(isPrime6(5) == true);
    assert(isPrime6(9) == false);
    assert(isPrime6(293) == true);
    
}

void testSmallestSum()
{
    assert(smallest_sum({ 6, 9, 21 }) == 9);
    assert(smallest_sum({60,12,96,48,60,24,72,36,72,72,48}) == 132);
    assert(smallest_sum({71,71,71,71,71,71,71,71,71,71,71,71,71}) == 923);
}

void testPermutations()
{
    std::vector<std::string> t{"aabb", "abab", "abba", "baab", "baba", "bbaa"};
    //assert(permutations("abcd") == t);
}

void testFactorization()
{
    std::string f = PrimeDecomp::factors(7775460);
    assert(f == "(2**2)(3**3)(5)(7)(11**2)(17)");
}

void testCalcFunctions()
{
    assert(four(plus(nine())) == 13);
}

void testJosephusSurvivor()
{
    assert(josephusSurvivor(7, 3) == 4);
}

int main(int argc, const char * argv[])
{
    testAlphabetPosition();
    testDuplicateEncoder();
    testAddBinary();
    testToCamelCase();
    testProdFib();
    testFindNb();
    testMultiples35();
    testLoopSize();
    testUint32toIp();
    testJosephus();
    testFindPath();
    testRgbToHex();
    testPartitions();
    testRot13();
    testKnightPath();
    testWaves();
    testIsPrime();
    testSmallestSum();
    testPermutations();
    testFactorization();
    testCalcFunctions();
    testJosephusSurvivor();
    
    return 0;
}
