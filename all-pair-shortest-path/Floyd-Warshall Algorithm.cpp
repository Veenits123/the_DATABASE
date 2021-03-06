#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e4 + 5;
const int inf = 1e9;
int dis[N][N];
int par[N][N];
int n, m;

void floyd_warshall() {
	for (int k = 1; k <= n; k++) {//for generating n matrices;
		//matrices;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					par[i][j] = par[i][k];
				}
			}
		}
	}
}

void shortest_path(int u, int v) {
	if (!par[u][v]) {
		cout << "No Path";
		return ;
	}
	vector <int> path;
	path.pb(u);
	while (u != v) {
		u = par[u][v];
		path.pb(u);
	}
	for (auto x : path)
		cout << x << " ";
	cout << endl;
	return ;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		dis[u][v] = w;
		par[u][v] = v;
		//dis[v][u] = w;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dis[i][j] = 0;
				par[i][j] = i;
			}
			else if (!dis[i][j])
				dis[i][j] = inf;
		}
	}
	floyd_warshall();
	// for (int i = 1; i <= n; i++) {
	// 	cout << dis[1][i] << " ";
	// }
	shortest_path(1, 2);

	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}