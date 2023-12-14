#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V + 1);

    int src_idx, dest_idx, weight;
    for (int edge_idx = 0; edge_idx < E; edge_idx++) {
        cin >> src_idx >> dest_idx >> weight;
        graph[src_idx].emplace_back(dest_idx, weight);
    }


    constexpr int MAX_DISTANCE = 200000;
    vector<int> min_dist(V + 1, MAX_DISTANCE);
    min_dist[K] = 0;

    auto cmp_dist = [&min_dist](int idx1, int idx2) {
        return min_dist[idx1] > min_dist[idx2];
    };
    priority_queue<int, vector<int>, decltype(cmp_dist)> idx_pq {cmp_dist};
    idx_pq.push(K);

    // vector<bool> is_relaxed(V + 1, false);

    int cur_idx;
    while (!idx_pq.empty()) {
        cur_idx = idx_pq.top();
        idx_pq.pop();
        
        // if (is_relaxed[cur_idx]) {
        //     continue;
        // }

        for (const auto& [first, second] : graph[cur_idx]) {
            if (min_dist[cur_idx] + second < min_dist[first]) {
                min_dist[first] = min_dist[cur_idx] + second;
                idx_pq.push(first);
            }
        }
        // is_relaxed[cur_idx] = true;
    }


    for (auto it = min_dist.begin() + 1; it != min_dist.end(); it++) {
        if (*it == MAX_DISTANCE) {
            cout << "INF" << '\n';
        }
        else {
            cout << *it << '\n';
        }
    }
}