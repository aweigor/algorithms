#pragma once

#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>


/*
 * Algorithms of finding n as a sum of positive integers
 * https://en.wikipedia.org/wiki/Integer_partition
 *
 * Katas:
 * https://www.codewars.com/kata/52ec24228a515e620b0005ef
 *
 */

/*
 * Approximation
 * https://en.wikipedia.org/wiki/Integer_partition
 * */
uint32_t partitions_approx(uint32_t n) 
{
  uint32_t result = 1 / (4 * n * sqrt(3)) * exp(M_PI * sqrt((2 * n) / 3));
  return result;
}

uint32_t find_paritions_basic(uint32_t n) 
{
   // array of coefficients of X^0 ... X^n
  std::vector<unsigned long long int> vector(n + 1, 0);
  vector[0] = 1; // start with 1X^0  
  for (int i = 1; i <= n; i++)
  { // multiply by 1/(1-X^k)
    for (int j = i; j <= n; j++)
    {
      vector[j] += vector[j - i];
    }
  }
  return vector[n];
}

