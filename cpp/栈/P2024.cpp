#include<bits/stdc++.h> 
using namespace std;
int n,k,t,x,y,dad[100010],h[100010],X,Y,ans;
int find(int x){
	if(!dad[x])return x;
	int X=find(dad[x]);
	//h[x]表示x和dad[x]的关系
	//h[dad[x]]表示dad[x]和X的关系
	//要把h[x]变成x和X的关系 
	h[x]=(h[x]+h[dad[x]])%3;
	return dad[x]=X;
}
bool merge(int x,int y,int t){
	if(x>n||y>n)return 1;
	X=find(x);
	t-=h[x];
	Y=find(y);
	t+=h[y];
	t=(t+3)%3;
	if(X==Y)return t!=0;
	dad[X]=Y;
	h[X]=t;
	return 0;
}
int main(){
	scanf("%d%d",&n,&k);
	while(k--){
		scanf("%d%d%d",&t,&x,&y);
		ans+=merge(x,y,t-1);
	}
	printf("%d\n",ans);
}
