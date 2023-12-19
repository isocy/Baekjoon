#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<pair<int, int>>> graph(N + 1);
    int idx1, idx2, weight;
    for (int edge_idx = 0; edge_idx < E; edge_idx++) {
        cin >> idx1 >> idx2 >> weight;
        graph[idx1].emplace_back(idx2, weight);
        graph[idx2].emplace_back(idx1, weight);
    }

    int u, v;
    cin >> u >> v;


    using pq_element = pair<int, int>;
    auto cmp_pair = [](pq_element e1, pq_element e2) {
        return e1.second > e2.second;
    };
    priority_queue<pq_element, vector<pq_element>, decltype(cmp_pair)> min_pq{cmp_pair};

    constexpr int MAX_DISTANCE = 800000;
    vector<int> min_dist(N + 1, MAX_DISTANCE);
    int dist_uto1, dist_utov, dist_utoN, dist_vto1, dist_vtoN;


    int cur_idx, cur_dist;
    int new_dist;

    min_dist[u] = 0;
    min_pq.push(make_pair(u, 0));

    while (!min_pq.empty()) {
        cur_idx = min_pq.top().first;
        cur_dist = min_pq.top().second;
        min_pq.pop();

        if (cur_dist > min_dist[cur_idx]) {
            continue;
        }

        for (const auto& [dest_idx, weight] : graph[cur_idx]) {
            new_dist = cur_dist + weight;
            if (new_dist < min_dist[dest_idx]) {
                min_dist[dest_idx] = new_dist;
                min_pq.push(make_pair(dest_idx, new_dist));
            }
        }
    }

    dist_uto1 = min_dist[1];
    dist_utov = min_dist[v];
    dist_utoN = min_dist[N];

    min_dist.assign(N + 1, MAX_DISTANCE);
    min_dist[v] = 0;
    min_pq.push(make_pair(v, 0));

    while (!min_pq.empty()) {
        cur_idx = min_pq.top().first;
        cur_dist = min_pq.top().second;
        min_pq.pop();

        if (cur_dist > min_dist[cur_idx]) {
            continue;
        }

        for (const auto& [dest_idx, weight] : graph[cur_idx]) {
            new_dist = cur_dist + weight;
            if (new_dist < min_dist[dest_idx]) {
                min_dist[dest_idx] = new_dist;
                min_pq.push(make_pair(dest_idx, new_dist));
            }
        }
    }

    dist_vto1 = min_dist[1];
    dist_vtoN = min_dist[N];


    if (dist_uto1 != MAX_DISTANCE && dist_utoN != MAX_DISTANCE && dist_utov != MAX_DISTANCE) {
        cout << min(dist_uto1 + dist_vtoN, dist_vto1 + dist_utoN) + dist_utov;
    }
    else {
        cout << -1;
    }
}