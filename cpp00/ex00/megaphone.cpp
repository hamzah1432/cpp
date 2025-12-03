#include <iostream>
#include <string>
#include <cctype>

std::string toUpper(const std::string& s) {
    std::string result = s;
    for (size_t i = 0; i < result.size(); i++) {
        result[i] = std::toupper(static_cast<unsigned char>(result[i]));
    }
    return result;
}

std::string trim(const std::string& s) {
    size_t start = 0, end = s.size();
    while (start < end && isspace(static_cast<unsigned char>(s[start]))) start++;
    while (end > start && isspace(static_cast<unsigned char>(s[end - 1]))) end--;
    return s.substr(start, end - start);
}

std::string compressSpaces(const std::string& s) {
    std::string res;
    bool space = false;
    for (size_t i = 0; i < s.size(); i++) {
        if (isspace(static_cast<unsigned char>(s[i]))) {
            if (!space) { res += ' '; space = true; }
        } else {
            res += s[i];
            space = false;
        }
    }
    return toUpper(res);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        std::cout << compressSpaces(trim(argv[i]));
        if (i < argc - 1) std::cout << " ";
    }
    std::cout << "\n";
    return 0;
}
