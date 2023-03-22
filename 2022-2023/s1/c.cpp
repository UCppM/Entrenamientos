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

bool es_euleriano(vvi const& g){
    int num_odd = 0;
    for(auto& v : g){
        num_odd += (v.size() % 2 == 1);
    }
    return num_odd == 2  // Camino euleriano
        || num_odd == 0; // Cilo   euleriano
}

bool resuelveCaso(){
    int n, I; cin >> n;
    if(n == 0) return false;
    cin >> I;

    vvi g(I);
    for (int i = 0; i < n; i++){
        int a, b;  cin >> a >> b;
        a--; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    cout << (es_euleriano(g)? "SI" : "NO") << '\n';

    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}