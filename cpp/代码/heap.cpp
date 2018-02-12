#include<bits/stdc++.h>
using namespace std;
int heap[100010],x,y,n,i,a,b,m;
long long ans;
void pushup(int x){
	for(;heap[x]<heap[x>>1]&&x>1;x>>=1)
		swap(heap[x],heap[x>>1]);
}
void pushdown(int x){
	for(;x<<1<=n;x=y){
		y=x<<1;
		if(y<n&&heap[y|1]<heap[y])y|=1;
		if(heap[x]>heap[y])swap(heap[x],heap[y]);
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
	for(i=1;i<=m;i++)
		scanf("%d",&x),add(x);
	for(m--;m--;){
		a=heap[1];
		del(1);
		b=heap[1];
		del(1);
		add(a+b);
		ans+=a+b;
	}
	printf("%lld\n",ans);
}
