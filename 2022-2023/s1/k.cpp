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

int bfs(int start, vvi const& g){
    int res = 0;
    queue<int> q;
    q.push(start);
    vi dist(g.size(), INT_MAX);
    dist[start] = 0;
    while(!q.empty()){
        int curr = q.front();
        res++;
        q.pop();
        for(auto&neigh: g[curr]){
            if(dist[neigh] == INT_MAX){
                dist[neigh] = dist[curr] + 1;
                q.push(neigh);
            }
        }
    }
    return res;
}

bool resuelveCaso(){
    int n, m; cin >> n >> m;
    if(!cin) return false;
    vvi g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int count = bfs(0, g);
    // cerr << count << '\n';
    cout << (m == n-1 && count == n? "SI" : "NO") << '\n';
        
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}