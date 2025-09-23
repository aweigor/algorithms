#pragma once

#include <vector>
#include <algorithm>
#include <cmath>

bool isBase(int num) {
  return num == 2 || num == 3 || num == 5;
}

bool isPrime(int num) 
{
  if (isBase(num)) {
    return true;
  }
  if (num <= 1 || num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
    return false;
  }
  int p5, p1;
  int maxn = sqrt(num) / 6;
  for (int i = 1; i <= maxn; i++) {
    p1 = i * 6 + 1;
    p5 = i * 6 + 5;
    if (num % p1 == 0 || num % p5 == 0)
      return false;
  }
  return true;
}

std::string sumOfDivided(std::vector<int> &lst) {
  int max = *std::max_element(lst.begin(), lst.end());
  //For each number find all prime dividers
  for (int i = 2; i <= max; i++) {
    if (isPrime(i)) {
      for (int j = 0; j < lst.size(); j++) {
        if (lst[j] % i == 0) {
          // Store dividers in table where column is prime number, dividers are the values
        } 
      }
    }
  }
  // Build final string
  return "";
}
