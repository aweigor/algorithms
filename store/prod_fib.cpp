//
//  prod_fib.cpp
//  algorithms
//
//  Created by Igor on 10.05.2025.
//

#include "prod_fib.hpp"


std::vector<ull> ProdFib::productFib(ull prod) {
    ull f0 = 0;
    ull f1 = 1;
    ull f2 = f0 + f1;
    ull f3 = f1 + f2;
    while (f2 * f3 < prod) {
        f0 = f1;
        f1 = f2;
        f2 = f0 + f1;
        f3 = f1 + f2;
    }
    return std::vector<ull> {f2, f3, f2 * f3 == prod};
}
