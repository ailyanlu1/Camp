#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,x,y,c,i,j,k=1,chart[110][110];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf ("%d%d",&n,&m);
    memset(chart,10e8,sizeof(chart));
    for(int i=1;i<=m;i++)
    {
        scanf ("%d%d%d",&x,&y,&c);
        chart[x][y]=chart[y][x]=c;
    }
    for(;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                chart[i][j]=min(chart[i][j],(chart[i][k]+chart[k][j]));

            }
        }
    }




    printf("%d",chart[1][n]);




    return 0;
}
