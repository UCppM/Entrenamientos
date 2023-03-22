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

pi DIRS[]= {
    {1,0},{0,1},{-1,0},{0,-1}
};
bool in_bound(vvi const& m, int x, int y){
    return 0 <= x && x < m.size()
        && 0 <= y && y < m.front().size();
}
bool resuelveCaso(){
    int C, F; cin >> C >> F;
    if(!cin) return false;
    vvi m(F, vi(C,0));
    for(auto&row:m){
        for(auto&e:row){
            cin >> e;
        }
    }
    queue<pi> q;
    q.push({F/2,0});
    int covered = 0;
    int lim = 0;
    vvi seen(F, vi(C,false));
    seen[F/2][0] = true;
    queue<pi> not_yet;
    while(covered <= (C*F)/2){
        while(!q.empty()){
            pi curr = q.front();
            q.pop();
            covered++;
            for(auto&d: DIRS){
                int nx = curr.first  + d.first,
                    ny = curr.second + d.second;
                if(in_bound(m, nx, ny) && !seen[nx][ny]){
                    seen[nx][ny] = true;
                    if(m[nx][ny] <= lim){
                        q.push({nx,ny});
                    } else {
                        // We can't access yet with the current lim
                        not_yet.push({nx,ny});
                    }
                }
            }
        }
        if(covered <= (C*F/2)){
            lim++;
            int k = not_yet.size();
            for(int i = 0; i < k; ++i){
                pi curr = not_yet.front();
                not_yet.pop();
                if(m[curr.first][curr.second] == lim){
                    q.push(curr);
                } else {
                    not_yet.push(curr);
                }
            }
        } else {
            break;
        }
    }
    cout << lim << " " << covered <<'\n';

    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}