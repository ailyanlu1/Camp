#include<bits/stdc++.h> 
using namespace std;
int heap[1000010],x,y,n,i,m,j;
long long ans;
vector<int>a[1000010];
void pushup(int x){
	for(;heap[x]>heap[x>>1]&&x>1;x>>=1)
		swap(heap[x],heap[x>>1]);
}
void pushdown(int x){
	for(;x<<1<=n;x=y){
		y=x<<1;
		if(y<n&&heap[y|1]>heap[y])y|=1;
		if(heap[x]<heap[y])swap(heap[x],heap[y]);
		else return;
	}
}
void del(int x){
	swap(heap[x],heap[n--]);
	pushup(x);
	pushdown(x);
}
void add(int x){
	heap[++n]=x;
	pushup(n);
}
int main(){
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[min(x,m)].push_back(y);
	}
	for(i=m;i>=1;i--){
		for(j=0;j<a[i].size();j++)
			add(a[i][j]);
		if(n)ans+=heap[1],del(1);
	}
	printf("%lld\n",ans);
}
