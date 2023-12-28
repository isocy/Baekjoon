#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;

    constexpr int MAX_N = 40;
    int fib_dp[MAX_N + 1];
    fib_dp[1] = 1;
    fib_dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        fib_dp[i] = fib_dp[i - 1] + fib_dp[i - 2];
    }

    cout << fib_dp[n] << ' ' << n - 2;
}