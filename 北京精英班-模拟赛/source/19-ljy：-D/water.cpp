#include<bits/stdc++.h>
using namespace std;

int h[1010],r[1010];
int n;
long long ans;
bool maxx(int a,int b)
{
	return a>b;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&h[i],&r[i]);
	sort(r+1,r+n+1);
	sort(h+1,h+n+1,maxx);
	r[0]=h[0]=0;
	for(int i=n;i>=1;i--)
	{
		ans+=(r[i]*r[i])*h[i]-(r[i-1]*r[i-1])*h[i];
	}
	printf("%lld",ans);
return 0;
}
