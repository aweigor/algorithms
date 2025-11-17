#pragma once

#include <vector>
#include <string>
#include <format>

std::string likes(const std::vector<std::string> &names)
{
  switch(names.size())
  {
    case 0:
      return "no one likes this";
    case 1:
      return std::format("{} likes this", names[0]);
    case 2:
      return std::format("{} and {} like this", names[0], names[1]);
    case 3:
      return std::format("{}, {} and {} like this", names[0], names[1], names[2]);
    default:
      return std::format("{}, {} and {} others like this", names[0], names[1], names.size() - 2);
  }
}