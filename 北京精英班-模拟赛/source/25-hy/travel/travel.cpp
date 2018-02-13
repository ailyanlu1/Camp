#include<iostream>
#include<cstdio>
using namespace std;

const int inf = 1073741823;
int e[510][510];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			e[i][j] = e[j][i] = inf;
	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		e[u][v] = e[v][u] = w;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				if (e[i][j] + e[i][k] < e[j][k])
					e[j][k] = e[i][j] + e[i][k];
	cout << e[1][n] << endl;
	return 0;
}
