//Author: Ayhon
#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>;
using Graph = vector<vii>;
vector<int> dijkstra(int start, Graph const& g){
	vector<int> dist(g.size(), INT_MAX);
	priority_queue<ii, vii, greater<ii>> q;
	dist[start] = 0;
	q.push({dist[start],start});
	while(!q.empty()){
		auto [dist_act, curr] = q.top();
		q.pop();
		if(dist[curr] < dist_act) continue;
		for(auto&[neigh, cost_neigh] : g[curr]){
			if(dist[neigh] > dist_act + cost_neigh){
				dist[neigh] = dist_act + cost_neigh;
				q.push({dist[neigh], neigh});
			}
		}
	}
	return dist;
}

vector<int> bellman_ford(int start, vector<vector<pair<int,int>>> const& g){
	const int n = g.size();
	vector<pair<pair<int,int>,int>> edges;
	for(int curr = 0; curr < n; ++curr){
		for(auto&[neigh,cost]: g[curr]){
			edges.push_back({{curr,neigh}, cost});
		}
	}
	vector<int> dist(n, INT_MAX);
	dist[start] = 0;
	for(int i = 0; i < n-1; ++i){
		for(auto&[edge,cost] : edges){
		 	auto [from, to] = edge;
			if(dist[from] == INT_MAX) continue;
			dist[to] = min(dist[to], dist[from] + cost);
		}
	}
	return dist;
}
bool bellman_ford_ciclo_negativo(int start, vector<vector<pair<int,int>>> const& g){
	const int n = g.size();
	vector<pair<pair<int,int>,int>> edges;
	for(int curr = 0; curr < n; ++curr){
		for(auto&[neigh,cost]: g[curr]){
			edges.push_back({{curr,neigh}, cost});
		}
	}
	vector<int> dist(n, INT_MAX);
	dist[start] = 0;
	for(int i = 0; i < n-1; ++i){
		for(auto&[edge,cost] : edges){
		 	auto [from, to] = edge;
			if(dist[from] == INT_MAX) continue;
			dist[to] = min(dist[to], dist[from] + cost);
		}
	}
	for(auto&[edge,cost] : edges){
		auto [from, to] = edge;
		if(dist[from] != INT_MAX && dist[from] + cost < dist[to]) {
			return false;
		}
	}
	return true;
}
vector<int> bellman_ford_camino(int start, vector<vector<pair<int,int>>> const& g){
	const int n = g.size();
	vector<pair<pair<int,int>,int>> edges;
	for(int curr = 0; curr < n; ++curr){
		for(auto&[neigh,cost]: g[curr]){
			edges.push_back({{curr,neigh}, cost});
		}
	}
	vector<int> pred(n, -1);
	vector<int> dist(n, INT_MAX);
	dist[start] = 0;
	for(int i = 0; i < n-1; ++i){
		for(auto&[edge,cost] : edges){
		 	auto [from, to] = edge;
			if(dist[from] != INT_MAX && dist[to] > dist[from] + cost){
				dist[to] = dist[from] + cost;
				pred[to] = from;
			}
		}
	}
	return pred;
}
// https://arxiv.org/abs/1904.01210v1 KIJ = 3·IJK = 2·IKJ
vector<vector<int>> floyd_warshall(vector<vector<pair<int,int>>> const& g){
	int n = g.size();
	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
	for(int curr = 0; curr < n; ++curr){
		dist[curr][curr] = 0;
		for(auto&[neigh,cost]: g[curr]){
			dist[curr][neigh] = cost;
		}
	}
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
				if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
		}
	}
    return dist;
}
vector<vector<int>> floyd_warshall_pato(vector<vector<pair<int,int>>> const& g){
	/// Marca con -1 los caminos que tienen ciclos negativos
	int n = g.size();
	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
	for(int curr = 0; curr < n; ++curr){
		dist[curr][curr] = 0;
		for(auto&[neigh,cost]: g[curr]){
			dist[curr][neigh] = cost;
		}
	}
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
				if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
		}
	}
for(int k = 0; k < n; k++) {
	if(dist[k][k] < 0){
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++){
				if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
					dist[i][j] = -1;
			}
		}
	}
}
    return dist;
}
/*
	for(int thru = 0; thru < n; thru++) {
		for(int from = 0; from < n; from++) {
			for(int to = 0; to < n; to++){
				dist[from][to] = min(dist[from][to], dist[from][thru] + dist[thru][to]);
			}
		}
	}
*/

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

