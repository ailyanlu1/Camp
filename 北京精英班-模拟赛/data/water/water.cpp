#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1005
#define inf 100000000
#define sqr(x) ((x)*(x))
#define For(i,l,r) for(int i=l;i<=r;i++)
pair<int, int> a[N];
int n,ans;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1, a+1+n);
	For(i,1,n) ans += (a[i].first-a[i-1].first) * sqr(a[i].second);
	printf("%d\n",ans);
}
