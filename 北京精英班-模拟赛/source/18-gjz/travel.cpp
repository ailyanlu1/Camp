#include<bits/stdc++.h>
using namespace std;
#define int long long
int N,M;
int xx,yy,ww,front[5005],dis[5050],tcnt,inq[5005];
vector<int> P[5005];
struct tEdge{
	int v,next,w;
	tEdge(int v=0,int next =0,int w=0) : v(v) , next(next) ,w(w) {}
}e[20010];
inline void add(int u,int v,int w)
{
	e[++tcnt]=tEdge(v,front[u],w);front[u]=tcnt;
}
void spfa()
{
	queue<int>q;
	q.push(1);inq[1]=true;
	for(int i=2;i<=N;i++)dis[i]=INT_MAX;
	int T=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();inq[u]=false;
	//	cout<<u<<endl;
		if(u!=N){
		for(int i=0;i<P[u].size();i++)
		if(P[u][i]==dis[u])dis[u]++;
	}
		for(int i=front[u];i;i=e[i].next)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w>=dis[v])continue;
			
			dis[v]=dis[u]+w;
		
			if(!inq[v])q.push(v),inq[v]=true;
		}
	}
}
 main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%lld",&N,&M);
	for(int i=1;i<=M;i++)
	{
		scanf("%lld%lld%lld",&xx,&yy,&ww);
		add(xx,yy,ww);add(yy,xx,ww);
	}
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&ww);
		for(int j=0;j<ww;j++)
		{
			scanf("%lld",&xx);P[i].push_back(xx);
		}
	}
	spfa();
	cout<<dis[N];

}



