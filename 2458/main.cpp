// Failed
// Time out




#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    
    int src_idx, dest_idx;
    for (int edge_idx = 0; edge_idx < M; edge_idx++) {
        cin >> src_idx >> dest_idx;
        graph[src_idx].push_back(dest_idx);
    }


    stack<int> dfs_stack;
    vector<int> idx_cnt(N + 1, N - 1);

    for (int cur_idx = 1; cur_idx <= N; cur_idx++) {
        dfs_stack.push(cur_idx);
        while (!dfs_stack.empty()) {
            src_idx = dfs_stack.top();
            dfs_stack.pop();

            for (const auto& dest_idx : graph[src_idx]) {
                dfs_stack.push(dest_idx);
                idx_cnt[src_idx]--;
                idx_cnt[dest_idx]--;
            }
        }
    }


    int cnt = 0;
    for (int idx = 1; idx <= N; idx++) {
        if (idx_cnt[idx] == 0) {
            cnt++;
        }
    }
    cout << cnt;
}