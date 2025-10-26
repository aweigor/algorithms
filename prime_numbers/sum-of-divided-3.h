#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#define SSTRING(x)(std::ostringstream() << std::dec << x ).str()

class SumOfDivided
{
public:
    static std::string sumOfDivided(std::vector<int> &lst);
};

std::string SumOfDivided::sumOfDivided(std::vector<int> &lst)
{
    std::vector<int> rem(lst.size());
    int max = 0;
    std::string result = "";
    for (unsigned int i = 0; i < lst.size(); ++i)
    {
        rem[i] = std::abs(lst[i]);
        max = std::max(max, std::abs(lst[i]));
    }
    for (int fac = 2; fac <= max; ++fac)
    {
        bool isFactor = false;
        int tot = 0;
        for (unsigned int i = 0; i < lst.size(); ++i)
        {
            if (rem[i] % fac == 0)
            {
                isFactor = true;
                tot += lst[i];
                while (rem[i] % fac == 0)
                    rem[i] /= fac;
            }
        }
        if (isFactor)
            result += "(" + SSTRING(fac) + " " + SSTRING(tot) + ")";
    }
    return result;
}
