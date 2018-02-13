#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define ll long long 
using namespace std;

const int maxn=510;
const int maxm=1015;
struct Edge
{
	int ne,to,dis;
}edge[maxm];
int n,m;
ll ans=1926081792;
int num_edge=0,h[maxm];
//int f[maxn][60];
int ok[maxn][60];

void add_edge(int f,int t,int dist)
{
	edge[++num_edge].ne=h[f];
	edge[num_edge].to=t;
	edge[num_edge].dis=dist;
	h[f]=num_edge;
}
void bfs()
{
	int que[20000000][2];//int que[2000][2];
	int head=0,tail=1;
	que[1][0]=1,que[1][1]=0;
    //if(head==1889)head=1;
	while(head!=tail)
	{
		int u=que[++head][0];
		int t=que[head][1];
		if(u==n)
	    {  //cout<<ans<<endl;
	    	ans=min(ans,(ll)t);
	    	continue;
	    }
	    if(ok[u][t])t+=ok[u][t];
	    if(t>ans)continue;
	   
		
		for(int i=h[u];i;i=edge[i].ne)
		{
			int s=edge[i].to;
			int d=edge[i].dis;
			//cout<<s<<' '<<d<<endl;
				que[++tail][0]=s;
				que[tail][1]=t+d;
			//if(tail==1889)tail=1;
		}
		
	}
	
}
void spfa()
{
	int que[19260817+92];//int que[1926];
	int dis[maxn];
	bool vis[maxn];
	for(int i=1;i<=n;i++)dis[i]=999999999;
	int head=0,tail=1;
	que[1]=1;dis[1]=0;vis[1]=1;
   // if(head==1889)head=1;
   
	while(head!=tail)
	{
		int u=que[++head];		
		for(int i=h[u];i;i=edge[i].ne)
		{
			int s=edge[i].to;
			int d=edge[i].dis;
			if(!vis[s])
			{
			  if(dis[s]>dis[u]+d)
			  {
			  	dis[s]=dis[u]+d;
				que[++tail]=s;
				vis[s]=1;
			  }
		    }
	    }
	}
	ans=dis[n];
}
int main()
{
	bool flag=1;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//+1s
	cin>>n>>m;
	if(n==1||n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	
	for(int i=1;i<=n;i++)
	{
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			int ti;
			flag=0;
			scanf("%d",&ti);
			ok[i][ti]=ti;
		}
	}
	
    if(flag)spfa();
	else bfs();
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
