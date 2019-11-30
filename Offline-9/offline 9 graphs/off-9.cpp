#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v;
	edge(int _u=0, int _v=0) : u(_u), v(_v) { }
};

// Zero indexed graph
vector<int> approx_rand(int nodes, const vector< edge > &E) {
	vector<int> order;
	for(int i=0; i<(int) E.size(); ++i) order.push_back(i);
	random_shuffle(order.begin(), order.end());

	vector<int> ret;
	vector<bool> vis(nodes, false);
	for(int i=0; i<(int) order.size(); ++i) {
		int who = order[i];
		int u = E[who].u, v = E[who].v;
		if(vis[u] or vis[v]) continue;

		ret.push_back(u);
		ret.push_back(v);
		vis[u] = true;
		vis[v] = true;
	}

	return ret;
}

vector<int> approx_deg(int nodes, vector< edge > E) {
	vector<int> g[nodes];
	vector<int> deg(nodes, 0);

	for(int i=0; i<(int) E.size(); ++i) {
        edge e = E[i];
		g[e.u].push_back(e.v);
		g[e.v].push_back(e.u);
		++deg[e.u];
		++deg[e.v];
	}

	vector<int> ret;
	while(!E.empty()) {
		edge cur;
		int maxx = -1;
		for(int i=0; i<(int) E.size(); ++i) {
            edge e = E[i];
			int temp = deg[e.u] + deg[e.v];
			if(temp > maxx) cur = e, maxx = temp;
		}
		ret.push_back(cur.u);
		ret.push_back(cur.v);

		// cout << "Picked " << cur.u << " " << cur.v << "\n";
		// for(auto e : E) cout << e.u << " - " << e.v << "; "; cout << "\n";

		vector<edge> temp;
		for(int i=0; i<(int) E.size(); ++i) {
            edge e = E[i];
			int cnt = 0;

			if(e.u == cur.u) --deg[e.v];
			else if(e.u == cur.v) --deg[e.u];
			else ++cnt;

			if(e.v == cur.u) --deg[e.v];
			else if(e.v == cur.v) --deg[e.u];
			else ++cnt;

			if(cnt == 2) temp.push_back(e);
		}
		E = temp;
	}

	return ret;
}

int main() {
	srand(time(NULL));

	 freopen("graph 4.txt", "r", stdin);
	 freopen("report.txt", "a", stdout);

	int n, m;
	cin >> n >> m;

	vector<edge> E(m);
	for(int i=0; i<m; ++i) {
		cin >> E[i].u >> E[i].v;
		 --E[i].u, --E[i].v;	// zero indexed
	}

	int res_rand[5];
	for(int i=0; i<5; ++i) res_rand[i] = (approx_rand(n, E).size());
	sort(res_rand, res_rand+5);
	double avg = 0;
	for(int i=0; i<5; ++i) avg += res_rand[i];
	avg /= 5.0;

	int res_deg = approx_deg(n, E).size();

	cout << "Report\n";
	cout << "Random: \n";
	cout << "\tBest: " << res_rand[0] << "\n";
	cout << "\tAvg: " << avg << "\n";
	cout << "\tWorst: " << res_rand[4] << "\n";
	cout << "Deg: " << res_deg << "\n";
	cout << "\n";

	return 0;
}

/*

9 11
0 1
0 3
2 3
1 4
3 4
3 8
4 5
4 7
5 6
5 7
6 8

*/
