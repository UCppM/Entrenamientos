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

bool es_bipartito(vvi const& g){
    vi color(g.size(), -1);
    
    for (int i = 0; i < (int)g.size(); i++)
    {
        if(color[i] == -1){
            queue<int> q;
            q.push(i);
            color[i] = false;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(auto&neigh : g[curr]){
                    if(color[neigh] == color[curr])
                        return false;
                    if(color[neigh] == -1){
                        color[neigh] = !color[curr];
                        q.push(neigh);
                    }
                }
            }
        }
    }
    return true;
}

bool resuelveCaso(){
    int V; cin >> V;
    if(!cin) return false;    
    int A; cin >> A;
    vvi g(V);
    for (int i = 0; i < A; i++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    cout << (es_bipartito(g)? "SI" : "NO" ) << '\n';
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}