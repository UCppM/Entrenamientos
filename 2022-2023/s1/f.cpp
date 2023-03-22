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
using vc   = vector<char>;
using vvc   = vector<vc>;

pi DIRS[] = {
    {1,0},{0,1},{-1,0},{0,-1}
};

bool in_bounds(vvc const& m, int x, int y){
    return 0 <= x && x < (int)m.size()
        && 0 <= y && y < (int)m.front().size();
}

void dump_mat(vvc const& m){
    cerr << "DUMP\n";
    for(auto&row:m){
        for(auto&c:row){
            cerr << c;
        }
        cerr << '\n';
    }
}

int T = -1, casos = 0;
bool resuelveCaso(){
    if(!T--) return false;

    // READ INPUT
    int w, h; cin >> w >> h;
    vvc m(h,vc(w,'.'));
    pi start;
    pi target;
    vector<pair<int, pi>> cats;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> m[i][j];
            switch(m[i][j]){
                case 'P':
                    target = {i,j};
                    m[i][j] = '.';
                    break;
                case 'E':
                    start = {i,j};
                    m[i][j] = '.';
                    break;
                case '#':
                case '.':
                    break;
                default:
                    cats.push_back({
                        m[i][j] - '0', {i,j}
                    });
            }
        }
    }

    // dump_mat(m);

    for(auto& p1 : cats){
        int k = p1.first,
            x = p1.second.first,
            y = p1.second.second;
        
        for(auto&d: DIRS){
            int nx = x;
            int ny = y;
            for(int i = 0; i < k; ++i){
                nx += d.first;
                ny += d.second;
                if(in_bounds(m, nx, ny) && m[nx][ny] != '#'){
                    m[nx][ny] = '@';
                } else break;
            }
        }
    }
    // dump_mat(m);

    queue<pi> q;
    if(m[start.first][start.second] != '@'){
        q.push(start);
        vvi dist(h, vi(w, INT_MAX));
        dist[start.first][start.second] = 0;
        while(!q.empty()){
            pi p = q.front();
            int x = p.first,
                y = p.second;
            q.pop();
            if(target.first == x && target.second == y) break;
            for(auto&d:DIRS){
                int nx = x + d.first;
                int ny = y + d.second;
                if(in_bounds(m,nx,ny) && m[nx][ny] == '.' && dist[nx][ny] == INT_MAX){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        int res = dist[target.first][target.second];
        if(res != INT_MAX){
            cout << res << '\n';
        } else cout << "NO\n";
    } else {
        cout << "NO\n";
    }
    
    return true;
}

int main(){
    cin >> T;
    while(resuelveCaso());
    return 0;
}