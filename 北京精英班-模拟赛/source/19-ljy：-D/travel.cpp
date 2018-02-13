#include<bits/stdc++.h>
using namespace std;

int n,m,cnt=1;
int k[510],tx,t[60][510],book[510],head[510];
int ans=10000000,tn[510]; 
struct node
{
	int w,next,to;
}q[2020];

void add(int u,int v,int w)
{
	q[cnt].w=w;
	q[cnt].to=v;
	q[cnt].next=head[u];
	head[u]=cnt++;
}

int time(int ttt,int uu)
{	
    int aans=0;
	while(t[ttt][uu])
	{
		aans+=t[ttt][uu];
		ttt++;
	}
	return aans;
}

void dfs(int u,int tt)//tt到u的用时 
{	
	int x,ttt;

	if(u==n&&ans>tt)
	{
		ans=tt;
		return;
	}
	if(book[u]==1)return;
	
	for(int i=head[u];i!=-1;i=q[i].next)
	{	
		ttt=time(tt,u);
		if(tt+q[i].w+ttt>=ans)continue;
		dfs(q[i].to,tt+q[i].w+ttt);
		book[q[i].to]=1;
		x=q[i].w+ttt+tn[q[i].to];
		if(tn[u]>x)tn[u]=x;
	}
	if(tt+tn[u]<ans)ans=tn[u];
}
int main()
{
	int i,u,v,w;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	memset(book,0,sizeof(book));
	memset(t,0,sizeof(t));
	memset(tn,5,sizeof(tn));
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d",&tx);
			t[tx][i]++;
		}
	}
	dfs(1,0);
	printf("%d",ans);
return 0;
}
