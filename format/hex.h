#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <format>
#include <numeric>

/**
 * RGB to hex
 */

std::string digit_to_hex(int digit, std::string result = "")
{
    static const char* numbers = "0123456789ABCDEF";
    if (digit != 0)
        result = digit_to_hex(digit / 16, result);
    return result + numbers[digit % 16];
}

std::string pad(std::string str, int w)
{
    if (str.size() > w)
        return str.substr(str.size() - w);
    std::stringstream ss;
    ss << std::setw(w) << std::setfill('0') << str;
    return ss.str();
}

int limit(int num, int from, int to) {
    return num < from ? from : num > to ? to : num;
}

std::string rgb_to_hex(int r, int g, int b)
{
    std::stringstream result{};
    result <<   pad(digit_to_hex(limit(r, 0, 255)), 2) <<
                pad(digit_to_hex(limit(g, 0, 255)), 2) <<
                pad(digit_to_hex(limit(b, 0, 255)), 2);
    return result.str();
}

class RGBToHex {
public:
  static std::string rgb(int r, int g, int b) {
    using namespace std;
    for(int& c : { ref(r), ref(g), ref(b) }) {
         c = max(0, min(255, c));
    }
    
    ostringstream oss;
    oss << uppercase << hex << setfill('0')
        << setw(6) << (r << 16) + (g << 8) + b;
    
    return oss.str();
  }
};

std::string rgb_to_hex_best(int r, int g, int b)
{
    return std::format("{:02X}{:02X}{:02X}", std::clamp(r, 0, 255), std::clamp(g, 0, 255), std::clamp(b, 0, 255));
}