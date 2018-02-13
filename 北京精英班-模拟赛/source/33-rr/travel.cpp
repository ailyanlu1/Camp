#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
const int mn = 1005;
const int maxn = 505;
const int INF=2147483647;
inline int minn(int a,int b)
{
    return a>b ? b : a;
}
struct edge{
int to,next,s;
}e[mn];
struct point{
int na,s;
}dis[maxn];
struct cmp{
bool operator () (point &a,point &b)
{
    return a.s>b.s;
}
};
priority_queue<point,vector<point>,cmp> q;
int n,m,s,ans=INF;
int head[maxn];
bool vis[maxn];
int k[maxn][55];
int mm;
void add(int u,int v,int c)
{
    mm++;
    e[mm].to=v;
    e[mm].next=head[u];
    e[mm].s=c;
    head[u]=mm;
}
void dijkstra(int s)
{
    for(int i=1;i<=n;i++){
        dis[i].na=i;
        dis[i].s=INF;
    }
    dis[s].s=0;
    int now=0;
    vis[0]=1;
    q.push(dis[s]);
    for(int k=1;k<n;k++)
    {
        while(vis[now])
        {
            now=q.top().na;
            q.pop();
        }
        vis[now]=1;
        int c=head[now];
        while(c)
        {
            int mu=e[c].to;
            if(dis[mu].s>dis[now].s+e[c].s)
            {
                dis[mu].s=dis[now].s+e[c].s;
                q.push(dis[mu]);
            }
            c=e[c].next;
        }
    }
}
void push_off(int x,int &cost)
{
    int r=k[x][0],l=1;
    while(l<r)
    {
        //cout<<l<<" "<<r<<endl;
        int mid=l+r>>1;
        if(k[x][mid]>=cost)
            r=mid;
        else l=mid+1;
    }
    if(k[x][r]==cost)
        cost++;
    return ;
}
void dfs(int x,int cost)
{
    if(k[x][0]!=0)
        push_off(x,cost);
    if(cost>=ans)
        return ;
    if(x==n)
    {
       ans=minn(ans,cost);
       return ;
    }
   // cout<<x<<" "<<cost<<endl;
    for(int i=head[x];i;i=e[i].next)
    {
         if(!vis[i])
         {
             vis[i]=1;
             dfs(e[i].to,cost+e[i].s);
             vis[i]=0;
         }
    }
}
int main()
{
    int u,v,c,tot=0;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        add(u,v,c);
        add(v,u,c);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i][0]);
        if(k[i][0]==0)
         tot++;
        for(int j=1;j<=k[i][0];j++)
            scanf("%d",&k[i][j]);
    }
    if(tot==n)
    {
        dijkstra(1);
        printf("%d",dis[n].s);
    }
    else {
      dfs(1,0);
      printf("%d",ans);
    }
    return 0;
}
