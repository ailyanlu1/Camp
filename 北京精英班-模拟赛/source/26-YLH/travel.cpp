#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define maxn 1000
#define maxm 2000
#define inf 214748364

int head[maxn];
int dis[maxn]; 
int vis[maxn]={0};
int hold[maxn][52]={0};
int holv[maxn][52]={0};
struct edge {
	int next, v, w;
} edges[maxm+10];
int tail = 0;
int n, m;

void add_edge(int u, int v, int w) {
	edges[++tail].next=head[u];
	head[u]=tail;
	edges[tail].v=v;
	edges[tail].w=w;
	return; 
} void spfa1() {
	queue <int> q;
	for (int i = 1; i <= n; ++i) dis[i]=inf;
	dis[1]=0; vis[1]=1; q.push(1);
	int u, v;
	while (!q.empty()){
		u=q.front(); q.pop();
		for (int i = head[u]; i; i=edges[i].next) {
			v=edges[i].v;
			if (dis[v]>dis[u]+edges[i].w) {
				dis[v]=dis[u]+edges[i].w;
				if (vis[v]==0) {
					vis[v]=1;
					q.push(v);
				}
			}vis[u]=0;
		} 
	} return;
}void spfa2() {
	queue <int> q;
	for (int i = 1; i <= n; ++i) dis[i]=inf;
	dis[n]=0; vis[n]=1; q.push(n);
	int u, v;
	while (!q.empty()){
		u=q.front(); q.pop();
		for (int i = head[u]; i; i=edges[i].next) {
			v=edges[i].v;
			if (dis[v]>dis[u]+edges[i].w) {
				dis[v]=dis[u]+edges[i].w;
				if (vis[v]==0) {
					vis[v]=1;
					q.push(v);
				}
			}vis[u]=0;
		} 
	} return;
} int dfs(int p, int f, int time) {
	//printf("%d %d %d>", p, f, time);
	if (p==n) return 0;
	int u, v, w;
	int sel = 0; int Min = inf;
	int wei = 0;
	for (int i = head[p]; i&&edges[i].v<=n; i=edges[i].next) {
		v=edges[i].v; w=edges[i].w;
		if (dis[v]+w<Min&&v!=f) {
			sel=v; Min=dis[v]+w; wei = w;
		} 
	} if (time+wei<=50&&hold[sel][time+wei]==1) {
		//printf("|%d|", p);
		int Min2 = inf;
		for (int i = head[p]; i&&edges[i].v<=n; i=edges[i].next) {
			v=edges[i].v; w=edges[i].w;
			if (v!=f&&time+w<=50) 
				Min2=min(dfs(v, p, time+w+holv[v][time+w])+holv[v][time+w]+w, Min2);
		} return Min2;
	} else {
		return dfs(sel, p, time+wei)+wei;
	}
}
int main() {
	int a, b, c, wait, now; int flag = 0;
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		add_edge(a, b, c);
		add_edge(b, a, c);
	} scanf("%d", &wait);
	for (int i = 0; i < wait; ++i) scanf("%d", &b);
	for (int i = 2; i < n; ++i) {
		scanf("%d", &a);
		if (a>0) flag=1;
		for (int j = 0; j < a; ++j) {
			scanf("%d", &b);
			hold[i][b]=1;
		} now = 0;
		for (int j = b; j >=0; --j) {
			if (hold[i][j]==1) {
				now+=1;
				holv[i][j]=now;
			} else now = 0;
		}
	}
	if (flag==0) {
		spfa1();
		printf("%d", dis[n]);
	} else {
		spfa2();
		printf("%d", dfs(1, -1, holv[a][0]));
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
