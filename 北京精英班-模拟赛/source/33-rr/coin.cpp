# include<iostream>
# include<cstdio>
# include<algorithm>
# include<cmath>
using namespace std;
const int mn = 100005;
inline double minn(double x,double y)
{
    return x>y ? y : x;
}
inline double maxx(double x,double y)
{
    return x>y ? x : y;
}
bool cmp(double x,double y)
{
    return x>y;
}
double big[mn],small[mn];
double a[mn],b[mn];
double ans,sum;
int n;
int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&big[i],&small[i]);
    sort(big+1,big+n+1,cmp);
    sort(small+1,small+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+big[i];
        b[i]=b[i-1]+small[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
          sum=minn(a[i]-i-j,b[j]-i-j);
          ans=maxx(ans,sum);
             if(a[i]-i-j<b[j]-i-j)
            break;
        }
    }
    printf("%.4lf",ans);
    return 0;
}
