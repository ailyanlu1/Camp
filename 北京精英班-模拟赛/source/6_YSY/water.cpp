#include<iostream>
#include<cstdio>
using namespace std;
const int N=1030;
int n,r[N],ht,ans;
bool h[N];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	int mn=1005,mx=0;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		h[a]=true;r[a]=b;
		if(a<mn)mn=a;
		if(a>mx)mx=a;
	}
	for(int i=mn;i<=mx;i++){
		if(h[i]){
			ans+=r[i]*r[i]*(i-ht);
			ht=i;
		}
	}
	printf("%d\n",ans);
return 0;}
