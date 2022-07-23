#include <iostream>
#include <vector>
#include <cmath>
#define MOD 998244353LL

typedef long long Long;

std::vector<Long> squareSum, naiveSum;

Long getSum(std::vector<Long>& sum, int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return (sum[r] - sum[l-1] + MOD) % MOD;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    Long n, q;
    std::cin >> n >> q;

    squareSum.resize(n+1, 0);
    naiveSum.resize(n+1, 0);
    for (Long i = 1; i < squareSum.size(); ++i) {
        squareSum[i] = (i*i + squareSum[i-1]) % MOD;
        naiveSum[i] = (i + naiveSum[i-1]) % MOD;
    }

    Long answer = 0;
    std::vector<Long> tree(n, 0);

    for (Long qIdx = 0; qIdx < q; ++qIdx) {
        Long l, r, c;
        std::cin >> l >> r >> c;
        --l; --r;
    
        Long coeff = ((n-1)*getSum(naiveSum, l, r) - getSum(squareSum, l, r) + (r-l+1)*n + MOD) % MOD;
        answer += ((coeff * c) % MOD) * (qIdx+1);
        answer %= MOD;

        Long sum = 0;
        for (int i = 0; i < l; ++i) {
            sum += tree[i];
            sum %= MOD;
        }
        for (int i = r+1; i < n; ++i) {
            sum += tree[i];
            sum %= MOD;
        }

        answer += sum;
        answer %= MOD;

        for (int i = l; i <= r; ++i) {
            tree[i] = ((c*(qIdx+1) % MOD)*((i+1)*(n-i) % MOD)) % MOD;
        }
    }

    std::cout << answer;

    return 0;
}