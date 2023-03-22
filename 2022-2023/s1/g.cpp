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

bool resuelveCaso(){
    int l, r; cin >> l;
    if(l == 0) return false;
    cin >> r;
    int res; cin >> res;
    for (int i = 1; i < r; i++) {
        int aux; cin >> aux;
        res = __gcd(res, aux);
    }
    cout << (l % res == 0? "SI" : "NO") << '\n';
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}