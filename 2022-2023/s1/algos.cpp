//Author: Ayhon
#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<vector<int>> const& g, vector<bool> & vis){
	vis[curr] = true;
	for(auto&neigh : g[curr]){
		if(!vis[neigh])
			dfs(neigh, g, vis);
	}
}

bool dfs_search(int curr, int target, vector<vector<int>> const& g, vector<bool> & vis){
	vis[curr] = true;
	if(curr == target)
		return true;
	bool res = false;
	for(auto&neigh : g[curr]){
		if(!vis[neigh])
			 res |= dfs_search(neigh, target, g, vis);
	}
	return res;
}

int dfs_count(int curr, vector<vector<int>> const& g, vector<int> & vis){
	int res = 1;
	vis[curr] = true;
	for(auto&neigh : g[curr]){
		if(!vis[neigh])
			res += dfs_count(neigh, g, vis);
	}
	return res;
}

void bfs(int start, vector<vector<int>> const& g){
	vector<int> dist(g.size(), INT_MAX);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(auto&neigh:g[curr]){
			if(dist[neigh] == INT_MAX) {
				dist[neigh] = dist[curr] + 1;
				q.push(neigh);
			}
		}
	}
}
bool bfs_search(int start, int target, vector<vector<int>> const& g){
	vector<int> dist(g.size(), INT_MAX);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(auto&neigh:g[curr]){
			if(dist[neigh] == INT_MAX) {
				dist[neigh] = dist[curr] + 1;
				if(neigh == target) return true;
				q.push(neigh);
			}
		}
	}
	return false;
}
int bfs_count(int start, vector<vector<int>> const& g){
	int res = 1;
	vector<int> dist(g.size(), INT_MAX);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(auto&neigh:g[curr]){
			if(dist[neigh] == INT_MAX) {
				res++;
				dist[neigh] = dist[curr] + 1;
				q.push(neigh);
			}
		}
	}
	return res;
}

void resuelveCaso() {

}

int main() {
	int T; cin >> T;
	for(int caso = 1; caso <= T; caso++) {
		// cout << "Case #" << caso <<":\n";
		resuelveCaso();
	}
	return 0;
}

