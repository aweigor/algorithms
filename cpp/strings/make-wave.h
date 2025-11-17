#include <vector>

std::vector<std::string> wave(std::string y){
    std::vector<std::string> frames;
    for (auto &c: y) {
        if (!isalpha(c))
            continue;
        c = toupper(c);
        frames.push_back(y);
        c = tolower(c);
    }
    return frames;
}
