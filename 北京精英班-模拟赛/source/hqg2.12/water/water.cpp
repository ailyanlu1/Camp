#include <algorithm>
#include <cstdio>
#define N 1001
using namespace std ;
struct node{int h,r ;}a[N];
bool cmp(node a,node b){return a.r>b.r ;}
int n ;
long long ans=0 ;
int main()
{
	freopen("water.in","r",stdin) ;
	freopen("water.out","w",stdout) ;
	scanf("%d",&n) ;
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].h,&a[i].r) ;
	sort(a+1,a+n+1,cmp) ;
	int lastr=0,lasth=0 ;
	for (int i=1;i<=n;i++)
	{
		int higher=a[i].h-lasth ;
		ans+=higher*a[i].r*a[i].r ;
		lasth=a[i].h ;
	}
	printf("%lld",ans) ;
	return 0 ;
}
