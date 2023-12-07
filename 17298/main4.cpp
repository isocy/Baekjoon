#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> seq(N);
    vector<int> nge(N, -1);
    stack<int> left_idx;

    cin >> seq[0];
    left_idx.push(0);

    for (int idx = 1; idx < N; idx++) {
        cin >> seq[idx];

        while (!left_idx.empty() && seq[idx] > seq[left_idx.top()]) {
            nge[left_idx.top()] = seq[idx];
            left_idx.pop();
        }
        left_idx.push(idx);
    }

    for (int idx = 0; idx < N; idx++) {
        cout << nge[idx] << ' ';
    }
}