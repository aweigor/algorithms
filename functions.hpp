//
//  functions.hpp
//  algorithms
//
//  Created by Igor on 15.05.2025.
//

#ifndef functions_hpp
#define functions_hpp
#include <iostream>

#include <stdio.h>

#endif /* functions_hpp */

class Yoba
{
public:
   Yoba(int n) : _n(n) {}
   Yoba operator() (int n) { return Yoba(_n + n); }
   bool operator== (int n) { return _n == n; }
   int operator+ (int n) { return _n + n; }
   int operator- (int n) { return _n - n; }
   friend bool operator== (int n, const Yoba & y) { return n == y._n; }
   
private:
   int _n;
};

auto add_f(int n);

class add
{
public:
    add (int x) : _x( x ) { }
    operator int() { return _x; }
    add operator() (int y) { return add(_x + y); }
    friend bool operator==(const int& a, const add& b) { return a == b._x; }

private:
    int _x;
};
