#include <bits/stdc++.h>
using namespace std;

using vi    = vector<int>;
using ii    = pair<int,int>;
using vii   = vector<ii>;
using ll    = long long;
using vll   = vector<ll>;
using pll   = pair<ll,ll>;
using vpll  = vector<pll>;
using vvi   = vector<vi>;
using vvll  = vector<vll>;
using vvii  = vector<vii>;
using vvpll = vector<vpll>;

vi dijkstra(int start, vvii const& g){
    vi dist(g.size(), INT_MAX);
    dist[start] = 0;
    priority_queue<ii, vii, greater<ii>> q;
    q.push({0, start});
    while(!q.empty()){
        int dist_act = q.top().first;
        int curr = q.top().second;
        q.pop();
        if(dist[curr] < dist_act) continue;
        for(auto& p: g[curr]){
            int neigh = p.first;
            int cost_neigh = p.second;
            if(dist[neigh] > dist_act + cost_neigh){
                dist[neigh] = dist_act + cost_neigh;
                q.push({dist[neigh], neigh});
            }
        }
    }
    return dist;
}

bool resuelveCaso(){
    int N, S, T, P; cin >> N >> S >> T >> P;
    if(!cin) return false;
    S--; // Importante decrementar este nodo!

    vvii g(N);
    for (int i = 0; i < P; i++)
    {
        int a, b, cost; cin >> a >> b >> cost;
        a--; --b;
        g[b].push_back({a,cost}); // Se cargan al revés
    }

    vi dist = dijkstra(S, g);
    int res = 0;
    for(auto& d : dist)
        if(d <= T) res++;
    cout << res - 1 << '\n'; // No hay ratones inicialmente en la salida

    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}