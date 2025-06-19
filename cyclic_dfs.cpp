#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, vector<int>& path) {
    visited[node] = true;
    recStack[node] = true;
    path.push_back(node);

    for (int i = 0; i < adj.size(); ++i) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack, path)) return true;
            } else if (recStack[i]) {
                path.push_back(i);
                return true;
            }
        }
    }

    recStack[node] = false;
    path.pop_back();
    return false;
}

void detectCycleDFS(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false), recStack(n, false);
    vector<int> path;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack, path)) {
                cout << "Cycle detected: ";
                for (int v : path) cout << v << " ";
                cout << endl;
                return;
            }
        }
    }

    cout << "No cycle found." << endl;
}

int main() {
    vector<vector<int>> adj = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    detectCycleDFS(adj);
    return 0;
}