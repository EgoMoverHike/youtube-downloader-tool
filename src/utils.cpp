#include "utils.h"
#include <regex>

std::string extractVideoId(const std::string& url) {
    std::regex pattern(R"((?:youtube\.com\/(?:[^\/]+\/.+\/|(?:v|e(?:mbed)?)\/|.*[?&]v=)|youtu\.be\/)([^"&?\/\s]{11}))");
    std::smatch matches;
    if (std::regex_search(url, matches, pattern) && matches.size() > 1) {
        return matches[1].str();
    }
    return "";
}