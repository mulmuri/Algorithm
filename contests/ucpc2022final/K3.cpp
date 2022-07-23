#include <iostream>
#include <vector>
#include <map>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> history(1<<n - 2);
    std::vector<int> appeared(1<<n+1);
    for (int i = 0; i < (1<<n - 2); ++i) {
        int win, lose;
        std::cin >> win >> lose;
        appeared[win]++;
        appeared[lose]++;
        history[i] = { win, lose };
    }

    std::vector<int> need(n+1, 0);
    need.back()++;
    for (int i = n; i >= 1; --i) {
        need[i] += 1<<(i-n);
    }
    
    std::map<int, std::vector<int>> appearedMap;
    for (int i = 1; i <= (1<<n); ++i) {
        appearedMap[appeared[i]].push_back(i);
    }

    std::vector<int> needMore;
    for (int i = 0; i <= n; ++i) {
        if (need[i] > appearedMap[i].size()) {
            needMore.push_back(i);
        }
    }

    if (needMore.size() == 1) {
        std::vector<int> answer;
        if (appearedMap[0].size()) {
            
        } else {
            int pos = needMore.front();
            for (auto [win, lose] : history) {
                if (appeared[win] == pos-1) {
                    answer.push_back(win);
                }
            }
            
        }
        std::sort(answer.begin(), answer.end());
        std::cout << answer[0] << " " << answer[1] << "\n";
        std::cout << answer[1] << " " << answer[0] << "\n";
        
    } else {
        
    }


    return 0;
}