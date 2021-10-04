#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int V, vector<int> adj[]) {
	vector<int> bfs;
	vector<int> visit(V + 1, 0);

	for (int i = 1; i < V + 1; i++) {
		if (!visit[i]) {
			queue<int> q;
			q.push(i);
			visit[i] = 1;
			while (!q.empty()) {
				int node = q.front();
				q.pop();
				bfs.push_back(node);
				for (int it : adj[node]) {
					if (!visit[it]) {
						q.push(it);
						visit[it] = 1;
					}
				}
			}
		}
	}
	return bfs;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> bfs = BFS(n, adj);
	for (int i = 0; i < bfs.size(); i++) {
		cout << bfs[i] << " ";
	}
	cout << "\n";
	return 0;
}