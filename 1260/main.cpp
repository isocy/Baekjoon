#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>


using namespace std;


int main() {
    int N, M, V;
    cin >> N >> M >> V;

    vector<set<int, greater<int>>> graph(N + 1);

    int from, to;
    for (int edge_idx = 0; edge_idx < M; edge_idx++) {
        cin >> from >> to;
        graph[from].insert(to);
        graph[to].insert(from);
    }


    stack<int> dfs_temp;
    vector<bool> visited(N + 1, false);
    dfs_temp.push(V);

    int vertex;
    while (!dfs_temp.empty()) {
        vertex = dfs_temp.top();
        dfs_temp.pop();

        if (visited[vertex]) {
            continue;
        }
        else{
            visited[vertex] = true;
        }

        for (const auto &dest : graph[vertex]) {
            dfs_temp.push(dest);
        }

        cout << vertex << ' ';
    }
    cout << '\n';


    queue<int> bfs_temp;
    visited.assign(N + 1, false);
    bfs_temp.push(V);

    while (!bfs_temp.empty()) {
        vertex = bfs_temp.front();
        bfs_temp.pop();

        if (visited[vertex]) {
            continue;
        }
        else{
            visited[vertex] = true;
        }

        for (auto it = graph[vertex].rbegin(); it != graph[vertex].rend(); it++) {
            bfs_temp.push(*it);
        }

        cout << vertex << ' ';
    }
}