#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
#define ll long long
using namespace std;
struct edge
{
	int f,t,next,v;
}e[3000];
int head[1000],dis[1000],vi[1000],cnt=1;
void add(int f,int t,int v)
{
	e[cnt].f=f;
	e[cnt].t=t;
	e[cnt].v=v;
	e[cnt].next=head[f];
	head[f]=cnt++;
}
struct node
{
	int k[60],num;
}p[1000];
int n,m,t1,t2,t3;
int baole(int sp,int t)
{
	for(int i=1;i<=p[sp].num;i++)
	if(p[sp].k[i]==t)
	return 1;
	return 0;
}
void spfa()
{
	queue<int>q;
	int sp=1;
	q.push(sp);
	while(!q.empty())
	{
		sp=q.front();
		q.pop();
		for(int i=head[sp];i;i=e[i].next)
		{
			int t=e[i].t;
			int tmp=dis[sp]+e[i].v;
			if(t!=n)
			tmp+=baole(t,tmp);
			if(dis[t]>tmp)
			{
				dis[t]=tmp;
				if(!vi[t])
				{
					vi[t]=1;
					q.push(t);
				}
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		add(t1,t2,t3);
		add(t2,t1,t3);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].num;
		if(p[i].num)
		for(int j=1;j<=p[i].num;j++)
		cin>>p[i].k[j];
	}
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	if(p[1].num&&p[1].k[1]==0)
	dis[1]++;
	spfa();
	cout<<dis[n];
	return 0;
}
