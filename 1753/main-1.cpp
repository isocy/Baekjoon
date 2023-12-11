#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool pq_compare(int idx1, int idx2) {
    
}


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

    priority_queue<int, vector<int>, >
}