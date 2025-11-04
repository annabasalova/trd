//bridges
const int maxn = 1e5;

bool used[maxn];
int h[maxn], d[maxn];

void dfs(int v, int p = -1) {
    used[v] = true;
    d[v] = h[v] = (p == -1 ? 0 : h[p] + 1);
    for (int u : g[v]) {
        if (u != p) {
            if (used[u]) // если ребро обратное
                d[v] = min(d[v], h[u]);
            else { // если ребро прямое
                dfs(u, v);
                d[v] = min(d[v], d[u]);
                if (h[v] < d[u]) {
                    // если нельзя другим путем добраться в v или выше,
                    // то ребро (v, u) -- мост
                }
            }
        }
    }
}

//points_of_articulations

void dfs(int v, int p = -1) {
    used[v] = 1;
    d[v] = h[v] = (p == -1 ? 0 : h[p] + 1);
    int children = 0;
    for (int u : g[v]) {
        if (u != p) {
            if (used[u])
                d[v] = min(d[v], h[u]);
            else {
                dfs(u, v);
                d[v] = min(d[v], d[u]);
                if (h[v] <= d[u] && p != -1) { // корень (p == -1) обрабатываем отдельно
                    // v -- точка сочленения
                    // (это условие может выполниться много раз для разных детей)
                }
              	children++;
            }
        }
    }
    if (p == -1 && children > 1) {
        // v -- корень и точка сочленения
    }
}
