#include <bits/stdc++.h>
#define maxn 501
#define maxm 1001
#define INF 2147483647
#define loc(i,j) ((i-1)*maxn+j)
using namespace std;
struct Edge{
	int from,to,next,value;
}l[maxm];
int head[maxn],n,m,cnt,tim[maxn][maxn];
int taged[maxn*maxn];int fa[maxn*maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if (fx!=fy) fa[fx]=fy;
}
void add(int x,int y,int z){
	l[++cnt]=(Edge){x,y,head[x],z};
	head[x]=cnt;
}
bool vis[maxn];int dis[maxn];
void SPFA(){
	queue<int>q;
	q.push(1);vis[1]=0;
	for (int i=1;i<=n;i++) dis[i]=INF;
	dis[1]=tim[1][0];
	while(!q.empty()){
		int qh=q.front();q.pop();vis[qh]=0;
		for (int i=head[qh];i;i=l[i].next){
			//cout<<l[i].to<<" "<<dis[qh]+l[i].value<<" ";
			//cout<<taged[find(fa[loc(l[i].to,dis[qh]+l[i].value)])];
			if (dis[qh]+l[i].value+taged[find(fa[loc(l[i].to,dis[qh]+l[i].value)])]<dis[l[i].to]){
				dis[l[i].to]=dis[qh]+l[i].value+taged[find(fa[loc(l[i].to,dis[qh]+l[i].value)])];
				if (!vis[l[i].to]){
					vis[l[i].to]=1;
					q.push(l[i].to);
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;int x,y,z;
	for (int i=1;i<=m;i++)
	cin>>x>>y>>z,add(x,y,z);
	for (int i=1;i<n;i++){
		int th,tx;cin>>th;
		for (int j=1;j<=th;j++)
		cin>>tx,tim[i][tx]=1,taged[(i-1)*n+tx]=1;
	}
	int temp;
	for (int i=1;i<=maxn*maxn;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		int j=0;for (j;j<=maxn;j++){
		if (!tim[i][j]) {temp=1;continue;}
			while(tim[i][j+1]){
				//cout<<"i "<<i<<" j "<<j<<" "<<endl;
				merge(loc(i,j),(loc(i,j))+1);
				temp++;j++;
				//cout<<"dealing with "<<(i-1)*maxn+j<<" temp="<<temp<<endl;
				//cout<<temp<<" temp ";
			}
			taged[loc(i,j)]=temp;
			//cout<<"i "<<i<<" j "<<j<<" "<<fa[loc(i,j)]<<" is dealed with value "<<taged[fa[loc(i,j)]]<<endl;
		}
	}
	//cout<<find(fa[loc(2,5)])<<" ";
	//cout<<taged[find(fa[loc(2,5)])]<<endl;
	SPFA();
	cout<<dis[n];
}
