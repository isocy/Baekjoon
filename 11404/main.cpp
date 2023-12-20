#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    constexpr int MAX_DISTANCE = 10000000;
    vector<vector<int>> graph(n + 1, vector<int> (n + 1, MAX_DISTANCE));
    vector<vector<int>> new_graph(n + 1, vector<int> (n + 1, MAX_DISTANCE));

    for (int idx = 1; idx <= n; idx++) {
        graph[idx][idx] = 0;
    }

    int src_idx, dest_idx, weight;
    for (int bus_idx = 0; bus_idx < m; bus_idx++) {
        cin >> src_idx >> dest_idx >> weight;
        if (weight < graph[src_idx][dest_idx]){
            graph[src_idx][dest_idx] = weight;
        }
    }


    for (int k = 1; k < n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                new_graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }

        graph.assign(new_graph.begin(), new_graph.end());
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            new_graph[i][j] = min(graph[i][j], graph[i][n] + graph[n][j]);
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (new_graph[i][j] == MAX_DISTANCE) {
                cout << 0 << ' ';
            }
            else {
                cout << new_graph[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}