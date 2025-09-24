#include <sstream>
#include <iostream>
#include <string>
#include <vector>


class SumOfDivided
{
   static std::vector<long> primes(long n) {
      std::vector<long> result;
      std::vector<bool> sieve(n, true);
      for (long p = 2; p < n; p++ ) 
         if (sieve[p]) {
            result.push_back(p);
            for (long i = p*p; i < n; i+=p) sieve[i] = false;
         }
      return result;
   }
   
public:
   static std::string sumOfDivided(std::vector<int> &lst) {
      std::ostringstream result;
      
      if (lst.empty())
         return result.str();
      else {
         long max = lst[0];
         for(long x : lst) { if (x>max) max=x; if (-x>max) max=-x; }
         std::vector<long> prime_numbers = primes(max+1);
      
         for(auto p : prime_numbers) {
            long sum = 0;
            int count = 0;
            for(auto l : lst) if (l%p==0) { sum+=l; count++; }
            if (count>0) result << "(" << p << " " << sum << ")";
         }
      
         return result.str();
      }
   }
};
