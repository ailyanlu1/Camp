# include<iostream>
# include<cstdio>
# include<cmath>
# include<algorithm>
using namespace std;
const int mn = 1005;
struct cup{
int r,h;
};
cup a[mn];
int n;
long long ans;
bool cmp(cup x,cup y)
{
    return x.r<y.r;
}
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].h,&a[i].r);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        ans+=(a[i].r*a[i].r-a[i-1].r*a[i-1].r)*a[i].h*1ll;
    }
    printf("%lld",ans);
    return 0;
}
