#pragma once

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void print_vector(std::vector<int> vec) {
  for (auto &it: vec) {
    std::cout << it << ",";
  }
  std::cout << "\n";
}

int sumVector(std::vector<int> vec) 
{
  int result = 0;
  for (auto &i: vec) {
    result += i*i;
  }
  return result;
}

/* Decompose target number's square into possible unique integer squares
 * Finding path problem, where edges are the field of integers
 * The final state is the path with edges with sum equals to target's value
 * */
void decompose_recursive(int target, int current, std::vector<int> &path, std::vector<std::vector<int>> &result) 
{
  int currentSum = sumVector(path);
  if (currentSum == target * target) {
    result.push_back(path);
    return;
  }
  if (currentSum > target * target) {
    return;
  }
  while (current < target) {
    path.push_back(current);
    decompose_recursive(target, current + 1, path, result);
    path.pop_back();
    current += 1;
  }
}


/* Same as decompose_recursive, but returns first(!) discovered sequence from end
 *
 * */
void decompose_recursive_first_from_end(int target, int current, std::vector<int> &path, std::vector<std::vector<int>> &result) {
  if (!result.empty()) {
    return;
  }
  int currentSum = sumVector(path);
  if (currentSum == target * target) {
    result.push_back(path);
    return;
  }
  if (currentSum > target * target) {
    return;
  }
  while (current > 0) {
    path.push_back(current);
    decompose_recursive_first_from_end(target, current - 1, path, result);
    path.pop_back();
    current -= 1;
  }
}

static void decompose_iterative_first_from_end(int target, std::vector<std::vector<int>> &result) {
    struct State {
        int current;
        std::vector<int> path;
    };
    
    std::stack<State> stack;
    stack.push({target - 1, {}});
    
    while (!stack.empty()) {
        State state = stack.top();
        stack.pop();
        
        int current = state.current;
        std::vector<int> path = state.path;

        print_vector(path);
        
        int currentSum = sumVector(path);
        
        if (currentSum == target * target) {
            result.push_back(path);
            return;
        }
        if (currentSum > target * target) {
            continue;
        }
        
        for (int i = 1; i <= current; i++) {
            std::vector<int> new_path = path;
            new_path.push_back(i);
            stack.push({i - 1, new_path});
        }
    }
}

class Decomp
{
  public:
  static std::vector<long long> decompose(long long n);
};

/*
 * What we want to do is loop backwards through the integers 1 to n 
 * (using a for loop, variable 'i') and deduct i*i from 'remaining',
 * which starts at n*n.
 *
 * Whenever we hit a 1, if 'remaining' is not 0, we have to take a step
 * back and retry the last index, but with the previous index being 
 * deducted by one.
 *
 * When we hit a 1 and remaining is 0, the correct solution is found.
 * 
 */
vector<long long> Decomp::decompose(long long n)
{
  vector<long long> v;

  long long nsquared = pow(n, 2);  // total value to achieve with our squared numbers
  long long remaining = nsquared;  // remaining value to get there
  
  for(int i = n-1; i > 0; i--)
  { 
    if(pow(i, 2) <= remaining)
    {
      // number (squared) fits in 'remaining' value, add to vector
      v.insert(v.begin(), i);
      remaining -= pow(i, 2);
    }
    
    while(i == 1 && remaining > 0)
    {
      // reached a 1 and 'nsquared' is still not reached
      // erase index and try again with preceding value -1
      v.erase(v.begin());
      v[0] -= 1;
      i = v[0];
      
      // recalculate 'remaining'
      remaining = nsquared;
      for(auto j : v)
        remaining -= pow(j, 2);    
    }

  }
    
  return v;
}

class Decomp2
{
  public:
  static std::vector<long long> decompose(long long n);
  private:
  static bool Divide(std::vector<long long> &numbers, double remain, long long last);
};

std::vector<long long> Decomp2::decompose(long long n)
{
  auto list = std::vector<long long>();
  if (Divide(list, n * n, n))
      return list;
  return std::vector<long long>() = {};
}

bool Decomp2::Divide(std::vector<long long> &numbers, double remain, long long last)
{
    if (remain <= 0)
        return remain == 0;
    for (long long i = last - 1; i > 0; i--)
    {
        if (Divide(numbers, remain - (i * i), i))
        {
            numbers.push_back(i);
            return true;
        }
    }
    return false;
}



std::vector<int> decompose(int n) {
  std::vector<std::vector<int>> result;
  //decompose_recursive(n, 1, path, result);
  //decompose_recursive_first_from_end(n, n-1, path, result);
  decompose_iterative_first_from_end(n, result);


  for (auto & seq: result) {
    print_vector(seq);
  }

  std::vector<int> output{};
  if (!result.empty()) {
    output = result.at(0);
  }

  std::reverse(output.begin(), output.end());
  return output;
}
