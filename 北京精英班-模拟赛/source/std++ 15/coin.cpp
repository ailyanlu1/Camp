#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n;
float ma,mi,ans,a[MAXN],b[MAXN];

bool CMP(float x, float y)
{
	return x>y;
}

float maxn(float x, float y)
{
	if(x>y) return x;
	return y;
}

float minn(float x, float y)
{
	if(x<y) return x;
	return y;
}

int main()
{
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%f%f",&a[i],&b[i]);
	sort(a+1, a+1+n, CMP);
	sort(b+1, b+1+n, CMP);
	for(int i=1; i<=n; i++)
		a[i]+=a[i-1],b[i]+=b[i-1];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			ans=maxn(ans, minn(a[i]-j-i, b[j]-i-j));
	printf("%.4f\n",ans);
	return 0;
}

/*
4
1.4 3.7
1.2 2
1.6 1.4
1.9 1.5
*/
