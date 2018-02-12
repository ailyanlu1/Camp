#include <bits/stdc++.h>
using namespace std;

const int maxn=1000000+15;
int n,m,r[maxn],d[maxn],s[maxn],t[maxn];
long long delta[maxn];
bool check(int ans)
{
	for (int i=1;i<=n;i++) delta[i]=0;
	for (int i=1;i<=ans;i++) delta[s[i]]+=d[i],delta[t[i]+1]-=d[i];
	for (int i=1;i<=n;i++) 
	{
		delta[i]+=delta[i-1];
		if (delta[i]>r[i]) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&r[i]);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&d[i],&s[i],&t[i]);
	int l=0,r=n+1,midd;
	while (l+1<r)
	{
		midd=(l+r)>>1;
		if (check(midd)) l=midd;
		 else r=midd;
	}
	if (l==n) printf("0\n");
	 else printf("-1\n%d\n",r);
	return 0;
}
