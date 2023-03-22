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


pi DIRS[]= {
    {-1,0}, {0,1},{1,0},{0,-1}
    // ↑     →      ↓     ←
};
void dump_mat(vvc const& m){
    cerr << "DUMP\n";
    for(auto&row:m){
        for(auto&c:row){
            cerr << c;
        }
        cerr << '\n';
    }
}

bool in_bounds(vvc const& m, int x, int y){
    return 0 <= x && x < (int)m.size()
        && 0 <= y && y < (int)m.back().size();
}

int bfs(pi start, vvc const& m){
    vvi dist(m.size(), vi(m.front().size(), INT_MAX));
    dist[start.first][start.second] = 0;

    queue<pi> q;
    q.push(start);
    while(!q.empty()){
        pi curr = q.front();
        q.pop();
        if(m[curr.first][curr.second] == 'T')
            return dist[curr.first][curr.second];
        for(auto&d: DIRS){
            int nx = curr.first  + d.first,
                ny = curr.second + d.second;
            if(in_bounds(m, nx, ny) && m[nx][ny] != '#' && dist[nx][ny] == INT_MAX){
                dist[nx][ny] = dist[curr.first][curr.second] + 1;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}

int rhs(pi start, vvc const& m){
    int steps = 1;
    int x = start.first-1,
        y = start.second;
    int i = 0; // Up
    while(m[x][y] != 'T' && !(x == start.first && y == start.second))
    {
        for(int k = 0; k < 4; ++k){
            int d = (4+i+1-k)%4;
            int nx = x + DIRS[d].first,
                ny = y + DIRS[d].second;
            if(in_bounds(m,nx,ny) && m[nx][ny] != '#'){
                x = nx;
                y = ny;
                i = d;
                break;
            }
        }
        steps++;
    }
    if(m[x][y] == 'T'){
        return steps;
    } else {
        return -1;
    }
}

bool resuelveCaso(){
    int tx, ty; cin >> tx >> ty;
    if(!cin) return false;
    vvc m(ty, vc(tx,'.'));
    pi start, target;
    for (int i = 0; i < ty; i++)
    {
        for (int j = 0; j < tx; j++)
        {
            cin >> m[i][j];
            if(m[i][j] == 'T'){
                target = {i,j};
            }
            if(i == ty-1 && m[i][j] == '.'){
                start = {i,j};
            }
        }
    }
    // fprintf(stderr, "Yendo de %i,%i a %i,%i\n",
    //     start.first, start.second,
    //     target.first, target.second);
    // dump_mat(m);
    int r1 = bfs(start, m);
    int r2 = rhs(start, m);
    // fprintf(stderr, "Con bfs tenemos %i, con rhs tenemos %i\nVeredicto: ",r1,r2);
    if(r1 == -1 && r2 == -1){
        cout << "IMPOSIBLE\n";
    } else if (r2 == -1){
        cout << "INF\n";
    } else if (r1 == r2){
        cout << "IGUAL\n";
    } else {
        cout << r2 - r1 << '\n';
    }
    

    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}