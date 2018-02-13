#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;
int n,ans;
struct Cup{int h,r;}cup[MAXN];


bool CMP(Cup x, Cup y)
{
	return x.h>y.h;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&cup[i].h,&cup[i].r);
	sort(cup+1, cup+n+1, CMP);
	for(int i=1; i<=n; i++)
		ans+=(cup[i].r*cup[i].r-cup[i-1].r*cup[i-1].r)*cup[i].h;
	printf("%d\n",ans);
	return 0;
}
