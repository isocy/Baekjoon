// Failed
// Timeout




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


    int u, v, w;
    for (int edge_idx = 0; edge_idx < E; edge_idx++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }


    constexpr int MAX_WEIGHT = 200000;

    vector<int> min_weight(V + 1, MAX_WEIGHT);
    min_weight[K] = 0;

    queue<int> idx_queue;
    idx_queue.push(K);

    int cur_idx;
    int new_weight;
    while (!idx_queue.empty()) {
        cur_idx = idx_queue.front();
        idx_queue.pop();

        for (const pair<int, int> &edge : graph[cur_idx]) {
            int &prev_weight = min_weight[edge.first];
            new_weight = min_weight[cur_idx] + edge.second;
            if (new_weight < prev_weight) {
                prev_weight = new_weight;
                idx_queue.push(edge.first);
            }
        }
    }


    for (auto it = min_weight.begin() + 1; it != min_weight.end(); it++) {
        if (*it == MAX_WEIGHT) {
            cout << "INF" << '\n';
        }
        else {
            cout << *it << '\n';
        }
    }
}