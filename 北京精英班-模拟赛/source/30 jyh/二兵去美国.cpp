#include<bits/stdc++.h>
using namespace std;

#define maxn 1000+15
#define maxx 10000000+15 
int n,m,edge_num,bol,k;
int f[maxn][maxn],head[maxn],stop[maxn][maxn];
struct node{int to;int next;int val;}edge[maxn];
inline int read_()
{
int x1=0,w1=1;register char ch1;
ch1=getchar();
while(ch1 < '0'||ch1 > '9'){if(ch1 == '-') w1=-1; ch1=getchar(); } 
while(ch1 >= '0'&&ch1 <= '9'){x1=(x1 << 3)+(x1 << 1)+ch1-'0';ch1=getchar();}
return x1*w1; 
}
void add(int a,int b,int c)
{
	edge[++edge_num].next=head[a];
	edge[edge_num].to=b;
	edge[edge_num].val=c;
	head[a]=edge_num;
}
int spfa()
{
	int check[maxn],dis[maxn];queue <int> q;
	memset(check,0,sizeof(check));
	for (int i=1;i<=n;i++)
	dis[i]=maxx;
	dis[1]=0;q.push(1);check[1]=1;
	do
	{
		int k=q.front();q.pop();check[k]=0;
		for (int i=head[k];i;i=edge[i].next)
		if (dis[edge[i].to]>edge[i].val+dis[k]&&!check[edge[i].to]){
			q.push(edge[i].to);
			dis[edge[i].to]=edge[i].val+dis[k];
			check[edge[i].to]=1;
		}
	}while(!q.empty());
	return dis[n];
}
void dfs(int x,int time)
{
	int now;
	if (stop[x][time]) dfs(x,time+1);
	else for (int i=head[x];i;i=edge[i].next)
	{
		int k=edge[i].to;
		now=time+edge[i].val;
		if (k==n) 
		f[k][0]=min(f[k][0],now);
		//else f[k][stop[k][now]]=min(f[k][stop[k][now]],now+stop[k][now]);
		if (now>f[n][0]||now>1000000) return;
		dfs(k,now);	
}
}
void function1()
{
    printf("%d",spfa());	
}
void function2()
{
	for (int i=1;i<=n;i++)
	for (int j=0;j<=1;j++)
	f[i][j]=maxx;
	f[1][0]=f[1][1]=0;
	dfs(1,0);
	printf("%d",f[n][0]);
}
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		a=read_();b=read_();c=read_();
		add(a,b,c);
		add(b,a,c);
}
	for (int i=1;i<=n;i++)
	{
		k=read_();
		for (int j=1;j<=k;j++)
		{
		int c;
		c=read_();
		stop[i][c]=1;
	}
		if (k!=0) bol=1;
	}
	if (!bol) function1();
	else function2();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
