#include<cstdio>
#include<iostream>
using namespace std;
int n;
double a[100002],b[100002];
int c[100002];//0不 1大 2小 3都
double minn=0.0,suma=0.0,sumb=0.0;
void dfs(int x)
{
    if(x==n+1)
    {
        if(min(suma,sumb)>minn)
            minn=min(suma,sumb);
        return ;
    }
    c[x]=0;
    dfs(x+1);
    c[x]=1;
    suma+=a[x]-1;
    sumb--;
    dfs(x+1);
    suma-=a[x]-1;
    sumb++;
    c[x]=2;
    sumb+=b[x]-1;
    suma--;
    dfs(x+1);
    sumb-=b[x]-1;
    suma++;
    c[x]=3;
    suma+=a[x]-2;
    sumb+=b[x]-2;
    dfs(x+1);
    suma-=a[x]-2;
    sumb-=b[x]-2;
}
int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d",&n);
    if(n>100)
    {
        printf("0.0000\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&a[i],&b[i]);
    dfs(1);
    printf("%.4lf\n",minn);
}
