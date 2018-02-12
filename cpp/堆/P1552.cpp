#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,m,dad[N],a[N],b[N],rs[N],ls[N],dist[N],root[N];
int size[N],i,rt;
long long sum[N],ans;
vector<int>vec[N];
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(a[x]<a[y])swap(x,y);
	rs[x]=merge(rs[x],y);
	if(dist[rs[x]]>dist[ls[x]])swap(ls[x],rs[x]);
	dist[x]=dist[rs[x]]+1;
	return x;
}
void dfs(int x){
	root[x]=x;
	sum[x]=a[x];
	size[x]=1;//��һ��ֻ��һ���ڵ�Ŀɲ��� 
	for(int i=0;i<vec[x].size();i++){
		dfs(vec[x][i]);//�������� 
		sum[x]+=sum[vec[x][i]];//�ѵ�ǰ�ڵ�Ŀɲ��ѺͶ��ӵĺϲ� 
		size[x]+=size[vec[x][i]];
		root[x]=merge(root[x],root[vec[x][i]]);
	}
	while(sum[x]>m){//��֤�ɲ����������� 
		size[x]--;
		sum[x]-=a[root[x]];
		root[x]=merge(ls[root[x]],rs[root[x]]);
	}
	ans=max(ans,1ll*size[x]*b[x]);//���´� 
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&dad[i],&a[i],&b[i]);
		if(!dad[i])rt=i;//ȷ���� 
		else vec[dad[i]].push_back(i);//���� 
	}
	dfs(rt);//dfs
	printf("%lld\n",ans);
}
