#include <iostream>
#include <array>
#include <vector>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> seq(N);  // we can give size of a vector in runtime
    vector<int> inc;

    cin >> seq[0];
    for (int idx = 1; idx < N; idx++) {
        cin >> seq[idx];
        if (seq[idx] > seq[idx - 1]) {
            inc.push_back(idx);
        }
    }
    int inc_size = inc.size();

    if (!inc.empty()) {
        int idx = 1;
        int inc_idx = 0;
        int inc_element = inc[inc_idx];

        bool inc_end = false;
        
        int cur_num;
        int cur_inc_idx;
        
        while (true) {
            while (idx == inc_element) {
                cout << seq[idx] << ' ';

                if (inc_idx == inc_size - 1) {
                    inc_end = true;
                    break;
                }

                idx++;
                inc_element = inc[++inc_idx];
            }
            if (inc_end) {
                break;
            }

            cur_num = seq[idx - 1];
            for (cur_inc_idx = inc_idx; cur_inc_idx < inc_size; cur_inc_idx++) {
                if (seq[inc[cur_inc_idx]] > cur_num) {
                    cout << seq[inc[cur_inc_idx]] << ' ';
                    break;
                }
            }
            if (cur_inc_idx == inc_size) {
                cout << -1 << ' ';
            }

            idx++;
        }

        for (int i = inc_element + 1; i < N; i++) {
            cout << -1 << ' ';
        }
        cout << -1;
    }
    else {
        for (int i = 0; i < N; i++) {
            cout << -1 << ' ';
        }
    }
}