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

const int MOD = 10000;

bool resuelveCaso(){
    int start, target; cin >> start >> target;
    if(!cin) return false;

    queue<int> q;
    q.push(start);

    vi dist(MOD, INT_MAX);
    dist[start] = 0;

    while(!q.empty()){
        int curr = q.front(); q.pop();
        int neigh[3] = {
            (curr + 1)%MOD, 
            (curr * 2)%MOD, 
             curr / 3
        };
        if(curr == target)
            break;
        for(int i = 0; i < 3; ++i){
            if(dist[neigh[i]] == INT_MAX){
                dist[neigh[i]] = dist[curr] + 1;
                q.push(neigh[i]);
            }
        }
    }
    cout << dist[target] << '\n';
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}