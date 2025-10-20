#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string trim(const string& s) {
    size_t start = 0, end = s.size();
    while (start < end && isspace(static_cast<unsigned char>(s[start]))) start++;
    while (end > start && isspace(static_cast<unsigned char>(s[end - 1]))) end--;
    return s.substr(start, end - start);
}

string compressSpaces(const string& s) {
    string res;
    bool space = false;
    for (size_t i = 0; i < s.size(); i++) {
        if (isspace(static_cast<unsigned char>(s[i]))) {
            if (!space) { res += ' '; space = true; }
        } else {
            res += s[i];
            space = false;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        cout << compressSpaces(trim(argv[i]));
        if (i < argc - 1) cout << " ";
    }
    cout << "\n";
    return 0;
}
