#include<cstdio>
#include<algorithm>
using namespace std;
struct glass
{
    int h,r;
    friend bool operator <(glass a,glass b)
    {
        return a.h<b.h;
    }
}g[1006];
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&g[i].h,&g[i].r);
    sort(g+1,g+1+n);
    int sum=0;
    g[0].h=0;
    g[0].r=0;
    for(int i=1;i<=n;i++)
        sum+=(g[i].h-g[i-1].h)*g[i].r*g[i].r;
    printf("%d\n",sum);
    return 0;
}
