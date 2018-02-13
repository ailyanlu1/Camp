#include<bits/stdc++.h>
using namespace std;

const int maxn=902,maxm=1874;
const int INF=1<<30;
struct Edge{
	int v,w,next;
}e[maxm*2];
int en,front[maxn],k[maxn];
int n,m,s,t;

inline void AddEdge(int u,int v,int w){
	en++;
	e[en].v=v;
	e[en].w=w;
	e[en].next=front[u];
	front[u]=en;
}

struct HeapNode{
	int u,d;
	bool operator<(const HeapNode& rhs) const{
		return d>rhs.d;
	}
};

void Dijkstra(){
	int d[maxn];
	priority_queue<HeapNode> q;
	for(int i=1;i<=n;i++)	d[i]=INF;
	d[s]=0;
	q.push((HeapNode){s,d[s]});
	while(!q.empty()){
		HeapNode x=q.top();
		q.pop();
		int u=x.u;
		if(x.d!=d[u])	continue;
		for(int i=front[u];i>=0;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push((HeapNode){v,d[v]});
			}
		}
	}
	printf("%d\n",d[t]);
}

int main(){
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(front,-1,sizeof(front));
	cin>>n>>m;
	s=1;
	t=n;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		AddEdge(u,v,w);
		AddEdge(v,u,w);
	}
	Dijkstra();
	return 0;
}
