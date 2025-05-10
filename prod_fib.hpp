//
//  prod_fib.hpp
//  algorithms
//
//  Created by Igor on 10.05.2025.
//

#ifndef prod_fib_hpp
#define prod_fib_hpp

#include <stdio.h>
#include <vector>

#endif /* prod_fib_hpp */

typedef unsigned long long ull;
class ProdFib
{
public:
    static std::vector<ull> productFib(ull prod);
    static std::vector<ull> productFibBp(ull prod)
    {
        ull a = 0, b = 1;
        while (a * b < prod) {
            std::swap(a, b);
            b += a;
        }
        return {a, b, ((a*b == prod) ? true : false)};
    }
};
