#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define LL long long

using namespace std;

int e[505][505],book[505];
LL dis[505];
bool t[505][505];
int n,m,u,v,min1;
int t1,t2,t3; 
int cntn,tn;
const int inf=99999999;
LL ans;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		e[t1][t2]=t3;
	}
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&cntn);
		while(cntn--)
		{
			scanf("%d",&t1);
			t[i][t1]=true;
		}
	}
	
	for(int i=1; i<=n; i++)
		dis[i]=e[1][i];
	for(int i=1; i<=n; i++)
		book[i]=0;
	book[1]=1;

	for(int i=1; i<=n-1; i++)
	{
		min1=inf;
		LL dis1;
		for(int j=1; j<=n; j++)
		{
			if(book[j]==0&&dis[j]<min1)
			{
				min1=dis[j];
				u=j;
				dis1=dis[j];
			}
		}
		book[u]=1;
		LL dis2=dis1;
		for(int v=1; v<=n; v++)
		{
			if(e[u][v]<inf)
			{
				dis2=dis1;
				LL sum=0;
				sum+=dis[u]+e[u][v];
				while(t[u][dis2])
				{
					sum++;
					dis2++;
				}
				if(dis[v]>sum)
					dis[v]=sum;
			}
		}
	}
	
//	ans=dis[n];
	printf("%lld",dis[n]);
	
	


	return 0;
}
