#include<bits/stdc++.h>
using namespace std;
int mp[510][510];
int dl[510][60];
bool visit[510];
int dis[510];
const int inf=1000000;
void search(int a,int b)
{
	if(dl[a][b-1]==0)return;
	dl[a][b-1]+=dl[a][b];
	search(a,b-1);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%d",&mp[a][b]);
		mp[b][a]=mp[a][b];
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[1][i])dis[i]=mp[1][i];
		else dis[i]=inf;
		int a;
		scanf("%d",&a);
		while(a--)
		{
			int b;
			scanf("%d",&b);
			dl[i][b]++;
			if(dl[i][b+1])dl[i][b]+=dl[i][b+1];
			search(i,b);
		}
	}
	for(int i=1;i<=n;i++)
		if(dis[i]!=inf)dis[i]+=dl[i][dis[i]];
	visit[1]=1;
	while(1)
	{
		bool flag=1;
		int mx=inf;
		int node=0;
		for(int i=2;i<=n;i++)
		{
			if(visit[i]==0&&dis[i]<mx)mx=dis[i],node=i,flag=0;
		}
		if(flag)break;
		visit[node]=1;
		for(int i=2;i<=n;i++)
		{
			if(mp[node][i]+dl[i][dis[node]+mp[node][i]]+dis[node]<dis[i])dis[i]=mp[node][i]+dl[i][dis[node]+mp[node][i]]+dis[node];
		}
	}
	printf("%d",dis[n]);
	return 0;
}
