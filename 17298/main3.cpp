// Failed




#include <iostream>
#include <array>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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


    int idx = 1;
    int inc_idx = 0;
    
    int cur_num;
    int cur_inc_idx;
    
    while (idx < N) {
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

        if (inc_idx != inc_size && inc[inc_idx] == idx) {  // exploit short-circuit evaluation
            inc_idx++;
        }

        idx++;
    }
    cout << -1;
}