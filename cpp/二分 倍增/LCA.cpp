#include <bits/stdc++.h>
using namespace std;

const int maxn=100000+15;
struct Edge
{
	int x,y,next;
	Edge(int x=0,int y=0,int next=0):x(x),y(y),next(next) {}
}edge[maxn*2];
int sumedge,head[maxn];
int n,m;
int ins(int x,int y)
{
	edge[++sumedge]=Edge(x,y,head[x]);
	return head[x]=sumedge;
}
int dep[maxn],fa[maxn];
int dfs(int now)
{
	dep[now]=dep[fa[now]]+1;
	for (int u=head[now];u;u=edge[u].next)
	 if (edge[u].y!=fa[now])
	 {
	 	fa[edge[u].y]=now; 
	 	dfs(edge[u].y);
	 }
	return 0;
}
int lca[20][maxn]; //lca[i][j]，j往上跳2^i步到达的节点 
int foundlca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);   //跳到相同深度节点 
	for (int i=18;i>=0;i--)
	 if (dep[lca[i][x]]>=dep[y])
	  x=lca[i][x];
	if (x==y) return x;  //特殊情况 
	for (int i=18;i>=0;i--) //一起往上跳，找到深度最小的两个不同的祖先节点 
	  if (lca[i][x]!=lca[i][y])
	   x=lca[i][x],y=lca[i][y];  
	return fa[x];    //父亲即为lca 
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	dep[0]=-1;
	dfs(1);   //建树，求出dep与fa 
	for (int i=1;i<=n;i++) lca[0][i]=fa[i];
	for (int i=1;i<=18;i++)  //往上跳2^i步 
	 for (int j=1;j<=n;j++)
	  lca[i][j]=lca[i-1][lca[i-1][j]];  
	while (m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",foundlca(x,y));
	 } 
	return 0;
}
