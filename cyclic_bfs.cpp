#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void detectCycleBFS(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> inDegree(n, 0);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (adj[i][j]) inDegree[j]++;

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (inDegree[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;

        for (int i = 0; i < n; ++i) {
            if (adj[node][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0) q.push(i);
            }
        }
    }

    if (count != n)
        cout << "Cycle detected in graph." << endl;
    else
        cout << "No cycle found." << endl;
}

int main() {
    vector<vector<int>> adj = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    detectCycleBFS(adj);
    return 0;
}