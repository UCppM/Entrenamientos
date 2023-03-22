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

const int RAD = 10;

double dist(pi a, pi b){
    double x = abs(a.first - b.first);
    double y = abs(a.second - b.second);
    return hypot(x, y);
}
        // if(dfs(start, g, targets, vis)){

bool dfs(int curr, vvi const& g, vi const& targets, vi & vis){
    vis[curr] = true;
    if(targets[curr]) return true;
    bool res = false;
    for(auto&neigh: g[curr]){
        if(!vis[neigh]){
            if(dfs(neigh, g, targets, vis)){
                res = true;
                break;
            }
        }
    }
    return res;
}

bool resuelveCaso(){
    int w, h, N; cin >> w;
    if(w == 0) return false;
    cin >> h >> N;
    vpi guard(N);
    vi starts;
    vi targets(N,false);;
    int idx = 0;
    for(auto&e: guard){
        cin >> e.first >> e.second;
        if(e.first <= RAD){
            starts.push_back(idx);
        } else if (w- e.first <= RAD) {
            targets[idx] = true;
        }
        idx++;
    }
    vvi g(N);
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            if(dist(guard[i],guard[j]) <= 2*RAD){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    bool res = false;
    vi vis(N, false);
    for(auto start: starts){
        if(dfs(start, g, targets, vis)){
            res = true;
            break;
        }
    }
    cout << (res? "NO" : "SI") << '\n';
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}