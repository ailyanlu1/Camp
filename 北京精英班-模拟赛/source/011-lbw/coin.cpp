#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
int n;
double ans;
double a[N],b[N];
double suma[N],sumb[N];
bool cmp(double a,double b){return a>=b;}
int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf ("%d",&n);
    for(int i=1;i<=n;i++)
    {
        //scanf("%f%f",&a[i],&b[i]);
        cin>>a[i]>>b[i];
        //printf("%f %f\n",a[i],b[i]);
        a[i]=a[i]-1;
        b[i]=b[i]-1;
    }
/*
    printf("\n");
    for(int i=1;i<=n;i++) printf("%f ",a[i]);
    printf("\n");
    for(int i=1;i<=n;i++) printf("%f ",b[i]);
    printf("\n");
*/
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
   /* printf("\n");
    for(int i=1;i<=n;i++) printf("%f ",a[i]);
    printf("\n");
    for(int i=1;i<=n;i++) printf("%f ",b[i]);
    printf("\n");
*/
    for(int i=1;i<=n;i++)
    {
        suma[i]=suma[i-1]+a[i];
        sumb[i]=sumb[i-1]+b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans=max(ans,min(suma[i]-j,sumb[j]-i));
        }
    }
    printf("%.4f",ans);
    return 0;
}
/**
4
1.4 3.7
1.2 2
1.6 1.4
1.9 1.5
*/
