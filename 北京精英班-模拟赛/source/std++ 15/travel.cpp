#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 1005
using namespace std;
int dis[MAXN],vis[MAXN],head[MAXN],t[MAXN][MAXN];
struct Edge {int next,to,dis;} edge[MAXN];
struct Node {int time,num;} temp,to;
int cnt,n,m,s,f,g,w,k,ti;

void addedge(int from, int to, int dis)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}

void SPFA()
{
    queue <Node> q;
    temp.num=1; temp.time=0;
    q.push(temp); dis[1]=0; vis[1]=1;
    while(!q.empty()){
        temp=q.front(); q.pop();
		int id=temp.num;
		vis[id]=0;
        for(int i=head[id]; i; i=edge[i].next){
            to.num=edge[i].to;
            if(dis[to.num]>temp.time+edge[i].dis){
            	dis[to.num]=temp.time+edge[i].dis;
            	while(t[to.num][dis[to.num]]) dis[to.num]++;
                if(vis[to.num]==0){
                    vis[to.num]=1;
                    to.time=dis[to.num];
					q.push(to);
                }
            }
        }
    }
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1; i<=m; i++){
        scanf("%d %d %d",&f,&g,&w);
        addedge(f,g,w);
    }
    for(int i=1; i<=n; i++)
	{
		scanf("%d",&k);
		for(int j=1; j<=k; j++){scanf("%d",&ti);t[i][ti]=1;}
	}
    for(int i=1; i<=n; i++){
        dis[i]=1e9;
        vis[i]=0;
    }
    SPFA();
    printf("%d ",dis[n]);
    return 0;
}

