#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V + 1);

    int src_idx, dest_idx;
    int weight;
    for (int edge_idx = 0; edge_idx < E; edge_idx++) {
        cin >> src_idx >> dest_idx >> weight;
        graph[src_idx].emplace_back(dest_idx, weight);
    }


    constexpr int MAX_DISTANCE = 200000;

    vector<int> min_dist(V + 1, MAX_DISTANCE);
    min_dist[K] = 0;

    auto comp_dist = [min_dist](int idx1, int idx2) {
        return min_dist[idx1] > min_dist[idx2];
    };
    priority_queue<int, vector<int>, decltype(comp_dist)> idx_pq {comp_dist};

    for (int idx = 1; idx <= V; idx++) {
        idx_pq.push(idx);
    }

    int cur_idx;
    int new_dist;
    while (!idx_pq.empty()) {
        cur_idx = idx_pq.top();
        cout << cur_idx << ' ';

        if (min_dist[cur_idx] == MAX_DISTANCE) {
            break;
        }

        for (const auto& [first, second] : graph[cur_idx]) {
            new_dist = min_dist[cur_idx] + second;
            if (new_dist < min_dist[first]) {
                min_dist[first] = new_dist;
            }
        }

        idx_pq.pop();
    }

    for (vector<int>::iterator it = min_dist.begin() + 1; it != min_dist.end(); it++) {
        if (*it == MAX_DISTANCE) {
            cout << "INF" << '\n';
        }
        else {
            cout << *it << '\n';
        }
    }
}