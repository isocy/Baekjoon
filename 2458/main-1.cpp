#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    constexpr int MAX_DISTANCE = 1;

    vector<vector<int>> matrix(N + 1, vector<int> (N + 1, MAX_DISTANCE));
    vector<vector<int>> new_matrix(N + 1, vector<int> (N + 1));

    for (int i = 1; i <= N; i++) {
        matrix[i][i] = 0;
    }

    int src_idx, dest_idx;
    for (int edge_idx = 0; edge_idx < M; edge_idx++) {
        cin >> src_idx >> dest_idx;
        matrix[src_idx][dest_idx] = 0;
    }


    for (int k = 1; k < N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                new_matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
        matrix.assign(new_matrix.begin(), new_matrix.end());
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            new_matrix[i][j] = min(matrix[i][j], matrix[i][N] + matrix[N][j]);
        }
    }

    int cnt = 0;
    bool is_known;
    for (int i = 1; i <= N; i++) {
        is_known = true;
        for (int j = 1; j <= N; j++) {
            if (new_matrix[i][j] != 0 && new_matrix[j][i] != 0) {
                is_known = false;
                break;
            }
        }

        if(is_known) {
            cnt++;
        }
    }
    cout << cnt;
}