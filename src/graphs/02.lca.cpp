//prep

int up[maxn][logn];

void dfs(int v) {
    for (int l = 1; l < logn; l++)
        up[v][l] = up[up[v][l-1]][l-1];
    tin[v] = t++;
    for (int u : g[v]) {
        up[u][0] = v;
        dfs(u);
    }
    tout[v] = t;
}

//get

int lca(int v, int u) {
    if (a(v, u)) return v;
    if (a(u, v)) return u;
    for (int l = logn-1; l >= 0; l--)
        if (!ancestor(up[v][l], u))
            v = up[v][l];
    return up[v][0];
}

//O(1)

vector<vector<int>> gr; 
vector<int> a,fst,g;
 
void dfs(ll v, ll h){
    fst[v] = a.size();
    a.pb(h);
    g.pb(v);
    for(auto to : gr[v]){
        dfs(to,h+1);  
        a.pb(h);
        g.pb(v);
    }
}

solve(){
    dfs(0,0);
    sparse table(a);
    if(fst[u] > fst[v]) swap(u,v);
    ll lca = g[table.get_min(fst[u],fst[v])];
}


