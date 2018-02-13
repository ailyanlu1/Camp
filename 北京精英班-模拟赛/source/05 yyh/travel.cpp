#include<bits/stdc++.h>
#define N 501
#define M 2020
int x,y,z,n,m,ans;
int dis[N],last[N],sum=0,cnt=0,v[N];
struct edge{
	int to,v,next;
}e[M];
struct heap{
	int name,v;
	bool operator < (const heap&m) const {
		return v>m.v;
	}
};
inline void add(int x,int y,int z){
	e[++cnt].next=last[x];last[x]=cnt;
	e[cnt].to=y,e[cnt].v=z;
}
inline void work1(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	std::priority_queue<heap> q;
	q.push((heap){1,0});
	while(!q.empty()){
		heap x=q.top();q.pop();
		int f=x.name;
		if(v[f]) continue;
		v[f]=1;
		for(int i=last[f];i;i=e[i].next){
			if(dis[e[i].to]>dis[f]+e[i].v){
				dis[e[i].to]=dis[f]+e[i].v;
				q.push((heap){e[i].to,dis[e[i].to]});
			}
		}
	}
	ans=dis[n];
	return ;
}
inline void work2(){
	return ;
}
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		if(x==0) sum++;
	}
		work1();

	printf("%d",ans);
}
