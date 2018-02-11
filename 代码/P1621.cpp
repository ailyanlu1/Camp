#include<bits/stdc++.h>
using namespace std;
int A,B,n,i,j,p[100010],dad[100010],P,ans,vis[100010];
int find(int x){
	return dad[x]==x?x:dad[x]=find(dad[x]);
}
void merge(int x,int y){
	dad[find(x)]=find(y);
}
int main(){
	scanf("%d%d%d",&A,&B,&P);
	for(i=A;i<=B;i++)dad[i]=i;
	for(i=2;i<=B;i++)
	if(!vis[i]){
		p[++n]=i;
		for(j=i+i;j<=B;j+=i)
			vis[j]=1;
	}
	for(i=1;i<=n;i++)if(p[i]>=P)
		for(j=p[i]*2;j<=B;j+=p[i])
			if(j-p[i]>=A)merge(j,j-p[i]);
	for(i=A;i<=B;i++)
		if(dad[i]==i)ans++;
	printf("%d\n",ans);
}
