#include <iostream>
#include <array>
#include <vector>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> seq(N);  // we can give size of a vector in runtime
    vector<bool> is_increased(N, false);

    cin >> seq[0];
    for (int idx = 1; idx < N; idx++) {
        cin >> seq[idx];
        if (seq[idx] > seq[idx - 1]) {
            is_increased[idx] = true;
        }
    }

    int nge, cand_idx;
    for (int idx = 1; idx < N; idx++) {
        if (is_increased[idx]) {
            cout << seq[idx] << ' ';
            continue;
        }
        
        nge = -1;
        cand_idx = idx + 1;
        while (cand_idx < N) {
            while (cand_idx < N && !is_increased[cand_idx]) {
                cand_idx++;
            }
            if (cand_idx == N) {
                break;
            }

            if (seq[cand_idx] > seq[idx - 1]) {
                nge = seq[cand_idx];
                break;
            }

            cand_idx++;
        }
        cout << nge << ' ';
    }
    cout << -1;
}