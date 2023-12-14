// Failed
// I tried to implement Dijkstra algorithm as similar to the psudo-code as possible, but it had a
// pitfall that the priority queue doesn't sort its content completely when pop() method is executed




#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V + 1);

    // construct graph
    int src_idx, dest_idx;
    int weight;
    for (int edge_idx = 0; edge_idx < E; edge_idx++) {
        cin >> src_idx >> dest_idx >> weight;
        graph[src_idx].emplace_back(dest_idx, weight);
    }


    // upper limit of distance = 10 * (20000 - 1)
    constexpr int MAX_DISTANCE = 200000;

    vector<int> min_dist(V + 1, MAX_DISTANCE);
    min_dist[K] = 0;

    // lambda expression to compare two vertices by distance
    auto comp_dist = [&min_dist](int idx1, int idx2) {
        return min_dist[idx1] > min_dist[idx2];
    };
    // min priority queue
    priority_queue<int, vector<int>, decltype(comp_dist)> idx_pq {comp_dist};

    for (int idx = 1; idx <= V; idx++) {
        idx_pq.push(idx);
    }

    // Dijkstra algorithm
    int cur_idx;
    int new_dist;
    while (!idx_pq.empty()) {
        cur_idx = idx_pq.top();

        // if it (and all other vertices in the queue) is unreachable vertex
        if (min_dist[cur_idx] == MAX_DISTANCE) {
            break;
        }

        // relax
        for (const auto& [first, second] : graph[cur_idx]) {
            new_dist = min_dist[cur_idx] + second;
            if (new_dist < min_dist[first]) {
                min_dist[first] = new_dist;
            }
        }

        idx_pq.pop();
    }

    // print the result
    for (vector<int>::iterator it = min_dist.begin() + 1; it != min_dist.end(); it++) {
        if (*it == MAX_DISTANCE) {
            cout << "INF" << '\n';
        }
        else {
            cout << *it << '\n';
        }
    }
}