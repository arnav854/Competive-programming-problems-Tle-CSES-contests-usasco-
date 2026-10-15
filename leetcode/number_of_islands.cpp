#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<char>>& g, vector<vector<int>>& v, int i, int j) {
    if (v[i][j] == 1) {
        return;
    }
    v[i][j] = 1;

    for (int l = -1; l <= 1; l++) {
        for (int u = -1; u <= 1; u++) {
            if (abs(u) + abs(l) != 1)
                continue;

            int n1 = i + u;
            int n2 = j + l;
            int n = g.size();
            int m = g[0].size();

            if (n1 < n && n1 >= 0 && n2 < m && n2 >= 0 &&
                g[n1][n2] == '1' && v[n1][n2] != 1) {
                dfs(g, v, n1, n2);
            }
        }
    }
}

int numIslands(vector<vector<char>>& g) {
    int n = g.size();
    int m = g[0].size();

    vector<vector<int>> v(n, vector<int>(m));
    int comp = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '1' && v[i][j] != 1) {
                dfs(g, v, i, j);
                comp++;
            }
        }
    }
    return comp;
}



