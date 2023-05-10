#include<bits/stdc++.h>

using namespace std;

int main() {
    string input;
    vector<char> v;
    cin >> input;
    int cnt = 1, sum = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            cnt = 2;
            v.push_back('(');
        }
        if (input[i] == '[') {
            cnt= 3;
            v.push_back('[');
        }
        if (input[i] == ')') {
            if (v.back() != '(' && v.empty()) {
                sum = 0;
                break;
            }
            if (input[i - 1] == '(') {
                sum += cnt;
            }
            cnt /= 2;
            v.pop_back();
        }
        if (input[i] == ']') {
            if (v.back() != '[' && v.empty()) {
                sum = 0;
                break;
            }
            if (input[i - 1] == '[') {
                sum += cnt;
            }
            cnt /= 3;
            v.pop_back();
        }
    }
    if (!v.empty()) sum = 0;

    cout << sum;
}