#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define N 100005
#define For(i,l,r) for(int i = l; i <= r; i++)
double a[N],b[N];
bool check(int na, int nb){
	if(a[na] - nb < b[nb] - na) return 1;
	return 0;
}
int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int n; scanf("%d",&n);
	For(i,1,n) scanf("%lf%lf",&a[i],&b[i]);
	For(i,1,n) a[i]--,b[i]--;
	sort(a+1,a+1+n); reverse(a+1,a+1+n);
	sort(b+1,b+1+n); reverse(b+1,b+1+n);
	For(i,1,n) a[i] += a[i-1];
	For(i,1,n) b[i] += b[i-1];
	
	double ans = 0;
	For(na,1,n){
		int l = 0, r = n, nb = -1;
		while(l<=r){
			int mid = (l+r) >> 1;
			if( check(na,mid) ){
				nb = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if(nb == -1) nb = n;
		
		ans = max(ans, min(a[na] - nb , b[nb] - na) );
		nb--;
		ans = max(ans, min(a[na] - nb , b[nb] - na) );
	}
	
	printf("%.4lf\n",ans);
}
