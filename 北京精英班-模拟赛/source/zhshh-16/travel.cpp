#include <iostream>
#include <cstdio>
#include <algorithm>
#define LL long long
#define maxm 1010
#define maxn 510
using namespace std;
//const string qwq="qwq";
struct node{
	int to;
	int w;
	int nxt;
}edge[maxm];
int head[maxn];
int cnt,n,m;
int k[maxm]; 
int if_in_point1_5=false;
int de[maxn][55];//第i个点是否拖延 ,,ci表示花费时间 
int ans=0x3f3f3f3f;
int mark[maxn]={0};
inline void add(const int from,const int to,const int w){
	cnt++;
	edge[cnt].to=to;
	edge[cnt].w=w;
	edge[cnt].nxt=head[from];
	head[from]=cnt;
}
void init(){
	cnt=0;
	int t1,t2;
	memset(head,-1,sizeof(head));
	memset(de,0,sizeof(de));
	cin>>n>>m;
	int q,w,e;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q,&w,&e);
		add(q,w,e);
	}
	if_in_point1_5=true;
	for(int i=1;i<=n;i++){ 
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){//如果能读到延迟，说明有，然后就在DFS中运行 
			if_in_point1_5=false;
			scanf("%d",&t2);
			de[i][t2]=1;
		}
	}
}
int dijkstra(){
	int dis[maxn],vis[maxn]={0};
	int mi,mindis,v;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	for(int qwq=1;qwq<=n;qwq++){
		mindis=0x3f3f3f3f; 
		for(int i=1;i<=n;i++){
			if(!vis[i] && dis[i]<mindis){
				mi=i;
				mindis=dis[i];
			}
		}
		vis[mi]=1;
		for(int i=head[mi];i!=-1;i=edge[i].nxt){
			v=edge[i].to;
			if(!vis[v] && mindis+edge[i].w<dis[v]){
				dis[v]=mindis+edge[i].w;
			}
		}
	}
	return dis[n];
}
inline void dfs(int const x,int cost){//似乎不用传递参数deep，deep作用类似于cost? 
	if(cost>ans)return ; 
//	cout<<deep<<endl;
	int v;
	int mindelay=0;
	for(int i=cost+1;i<=50;i++){
		if(de[x][i])mindelay++;//飞机停在这里的时候最小等待时间  
		if(mindelay==0)break;//如果没有延迟，break 
		if(!de[x][i])break;//如何亦延迟，最后读到没有延迟胡地方，然后继续 
	}
	for(int i=head[x];i!=-1;i=edge[i].nxt){
		if(edge[i].to==n){
			ans=min(ans,cost+edge[i].w+mindelay);
			continue;
		}else{
			if(!mark[edge[i].to] && cost+edge[i].w<ans){
				mark[edge[i].to]=1;
				dfs(edge[i].to,cost+edge[i].w+mindelay);
				mark[edge[i].to]=0;
			}
		}
	}
}
void work(){
	if(if_in_point1_5){
		cout<<dijkstra();
	}else{
		dfs(1,0);
		cout<<ans;
	}

}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	init();
	
	work();
	
	return 0;
}
