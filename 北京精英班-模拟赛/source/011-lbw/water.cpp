#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct bottle{int high,r;}a[1010];
bool cmp(bottle x,bottle y){return x.r<y.r;}
int ans;
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf ("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf ("%d%d",&a[i].high,&a[i].r);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        ans+=a[i].r*a[i].r*(a[i].high-a[i+1].high);
    }
    printf("%d",ans);
    return 0;
}
