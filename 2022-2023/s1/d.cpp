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
using vc    = vector<char>;
using vvc   = vector<vc>;

void dump_matr(vvc const& m){
    cerr << "DUMP\n";
    for(auto&row: m){
        for(auto& c : row){
            cerr << c;
        }
        cerr << '\n';
    }
}

pi DIRS[4] = {
    {1,0},{0,1},{-1,0},{0,-1}
};
bool in_bounds(vvc const& m, int x, int y){
    return 0 <= x && x < (int)m.size()
        && 0 <= y && y < (int)m.back().size();
}
int dfs_matr_count(int x, int y, vvc const& m, vvi & vis){
    int res = 1;
    vis[x][y] = true;
    for(auto&d : DIRS){
        int nx = x + d.first;
        int ny = y + d.second;
        if(in_bounds(m, nx, ny) &&  m[nx][ny] == '#' && !vis[nx][ny]){
            res += dfs_matr_count(nx, ny, m, vis);
        }
    }
    return res;
}

bool resuelveCaso(){
    int F, C; cin >> F >> C;
    cin.ignore(1);
    if(!cin) return false;

    vvc m(F, vc(C));
    for(auto&row : m){
        for(auto&c : row){
            cin.get(c);
        }
        cin.ignore(1);
    }
    // dump_matr(m);
    vvi vis(F, vi(C, false));
    int res = 0;
    for (int i = 0; i < F; i++){
        for (int j = 0; j < C; j++){
            if(m[i][j] == '#' && !vis[i][j]){
                res = max(res, dfs_matr_count(i, j, m, vis));
            }
        }
    }
    cout << res << '\n';
    
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}