#include <iostream>
#include <vector>
#include <algorithm>

const int LOG = 20;
std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> up;
std::vector<int> d;

void dfs(int u, int p, int depth_val) {
    d[u] = depth_val;
    up[u][0] = p;
    for (int j = 1; j < LOG; ++j) {
        if (up[u][j-1] != -1) {
            up[u][j] = up[up[u][j-1]][j-1];
        } else {
            up[u][j] = -1;
        }
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, depth_val + 1);
    }
}

int get_ancestor(int u, int k) {
    if (u == -1) return -1;
    for (int j = LOG - 1; j >= 0; --j) {
        if (u == -1) break;
        if ((k >> j) & 1) {
            u = up[u][j];
        }
    }
    return u;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q_count;
    std::cin >> n >> q_count;

    adj.assign(n + 1, std::vector<int>());
    up.assign(n + 1, std::vector<int>(LOG, -1));
    d.assign(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        int boss;
        std::cin >> boss;
        adj[boss].push_back(i);
    }

    dfs(1, -1, 0);

    for (int k_q = 0; k_q < q_count; ++k_q) {
        int u, v;
        std::cin >> u >> v;

        if (d[u] < d[v]) {
            std::swap(u, v);
        }

        u = get_ancestor(u, d[u] - d[v]);

        if (u == v) {
            std::cout << u << "\n";
            continue;
        }

        for (int j = LOG - 1; j >= 0; --j) {
            if (up[u][j] != -1 && up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        std::cout << up[u][0] << "\n";
    }

    return 0;
}
