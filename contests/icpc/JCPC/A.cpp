#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

typedef long long Long;

std::vector<Long> getName() {
    std::string raw;
    std::cin >> raw;
    std::vector<Long> conv;
    conv.reserve(raw.size());

    bool readingNumber = false;
    int number = 0;
    for (int i = 0; i < raw.size(); ++i) {
        if (readingNumber) {
            if (isalpha(raw[i])) {
                readingNumber = false;
                conv.push_back(number);
                number = 0;
                conv.push_back(Long(raw[i])+INT32_MAX);
            } else {
                number = 10*number + (raw[i]-'0');
            }
        } else {
            if (isalpha(raw[i])) {
                conv.push_back(Long(raw[i])+INT32_MAX);
            } else {
                readingNumber = true;
                number = raw[i]-'0';
            }
        }
    }
    if (readingNumber) {
        conv.push_back(number);
    }
    return conv;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;

    auto pivot = getName();
    for (int i = 0; i < n; ++i) {
        auto curr = getName();
        if (pivot <= curr) {
            std::cout << "+\n";
        } else {
            std::cout << "-\n";
        }
    }

    return 0;
}