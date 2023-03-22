#include <bits/stdc++.h>
using namespace std;

using vi    = vector<int>;
using pi    = pair<int,int>;
using vpi   = vector<pi>;
using ll    = long long;
using vll   = vector<ll>;
using pll   = pair<ll,ll>;
using vpll  = vector<pll>;
using vvi   = vector<vi>;
using vvll  = vector<vll>;
using vvpi  = vector<vpi>;
using vvpll = vector<vpll>;

int dfs_count(int curr, vvi const& g, vi & vis){
    int res = 1;
    vis[curr] = true;
    for(auto&neigh:g[curr]){
        if(!vis[neigh]){
            res += dfs_count(neigh, g, vis);
        }
    }
    return res;
}

int T = -1, casos = 0;
bool resuelveCaso(){
    if (!T--) return false;
    int n, m; cin >> n >> m;
    vvi g(n);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res = 0;
    vi vis(n,false);
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            res = max(res, dfs_count(i, g, vis));
        }
    }
    cout << res << '\n';
    return true;
}

int main(){
    cin >> T;
    while(resuelveCaso());
    return 0;
}