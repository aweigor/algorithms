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

/**
 * Method using Euler's pentagonals 
 */

std::vector<uint32_t> pentagonals;

uint32_t pentagonal(uint32_t n) {
  if (n >= pentagonals.size()) {
    for (uint32_t i = pentagonals.size(); i <= n; ++i) {
      int32_t k = (i + 1) / 2;
      if (i % 2 == 0) {
        k = -k;
      }
      pentagonals.push_back((3 * k * k - k) / 2);
    }
  }
  return pentagonals[n];
}

std::vector<uint32_t> ps{1, 1};

uint32_t find_partitions_pentagonal(uint32_t n) {
  if (n >= ps.size()) ps.resize(n + 1, 0);
  if (ps[n] == 0) {
    int32_t res = 0;
    for (uint32_t i = 1; i <= n; ++i) {
      auto pent = pentagonal(i);
      auto prev = ((int32_t) n) - ((int32_t) pent);
      if (prev < 0) break;
      int32_t p = find_partitions_pentagonal(prev);
      if (i % 4 == 0 || i % 4 == 3) {
        p = -p;
      }
      res += p;
    }
    ps[n] = res;
  }
  return ps[n];
}

/**
 * TODO: description 
 */

uint32_t find_partitions_reverse(uint32_t n, uint32_t k) {
  if(n==1 || k==1)  return 1;
  if(n<=k)  return find_partitions_reverse(n,n-1)+1;
  return find_partitions_reverse(n,k-1)+find_partitions_reverse(n-k,k);
}

uint32_t find_partitions_reverse(uint32_t n) {
    return find_partitions_reverse(n, n);
}