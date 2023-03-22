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

pi DIRS[]= {
    {1,0},{0,1},{-1,0},{0,-1}
};

bool in_bounds(vvc const& m, int x, int y){
    return 0 <= x && x < (int)m.size()
        && 0 <= y && y < (int)m.front().size();
}

int num_mines(int x, int y, vvc const& m){
    int res = 0;
    for(int i = x-1; i <= x +1; ++i){
        for(int j = y-1; j <= y+1; ++j){
            if(!(i == x && j == y) && in_bounds(m, i, j)){
                res += m[i][j] == '*';
            }
        }        
    }
    return res;
}

bool desvelar(int x, int y, vvc const& m, vvc & res){
    if(m[x][y] == '*') return true;
    int mines = num_mines(x,y,m);
    if(mines == 0){
        res[x][y] = '-';
        for(int i = x-1; i <= x +1; ++i){
            for(int j = y-1; j <= y+1; ++j){
                if(!(i == x && j == y) && in_bounds(m, i, j) && res[i][j] == 'X'){
                    desvelar(i, j, m, res);
                }
            }        
        }   
    } else {
        res[x][y] = mines + '0';
    }
    return false;
}

bool resuelveCaso(){
    int F, C; cin >> F >> C;
    if(!cin) return false;
    vvc m(F, vc(C, '-'));
    for(auto&row: m){
        for(auto&e:row){
            cin >> e;
        }
    }
    vvc res(F, vc(C, 'X'));
    int K; cin >> K;
    bool game_over = false;
    for (int i = 0; i < K && !game_over; i++){
        int x, y; cin >> x >> y;
        x--; --y;
        game_over = desvelar(x, y, m, res);
    }

    if(game_over){
        cout << "GAME OVER\n";
    } else {
        for(auto&row: res){
            for(auto&e:row){
                cout << e;
            }
            cout << '\n';
        }
    }
    
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}