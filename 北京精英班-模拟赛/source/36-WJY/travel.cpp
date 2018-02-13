#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
struct Edge
{
    int e,t;
};
vector<Edge> v[506];
int q[250005],dis[506];
int n,m;
int head=125000,tail=125000;//head²»´æ¶«Î÷
void pushback(int x)
{
    q[++tail]=x;
}
void pushfront(int x)
{
    q[head]=x;
    head--;
}
void pop()
{
    q[++head]=0;
}
bool used[506],stop[506][56];
int spfa(int s,int e)
{
    dis[s]=0;
    int u;
    Edge t;
    pushback(s);
    used[s]=true;
    while(tail>head)
    {
        u=q[head+1];
        pop();
        used[u]=false;
        for(vector<Edge>::iterator it=v[u].begin();it!=v[u].end();it++)
        {
            t=*it;
            if(dis[u]+t.t<dis[t.e]&&!stop[t.e][dis[u]+t.t])
            {
                dis[t.e]=dis[u]+t.t;
                if(dis[q[head]]>dis[t.e]&&!used[t.e])
                {
                    pushfront(t.e);
                    used[t.e]=1;
                }
                if(dis[q[head]]<dis[t.e]&&!used[t.e])
                {
                    pushback(t.e);
                    used[t.e]=1;
                }
            }
        }
    }
    return dis[e];
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    memset(used,false,sizeof(used));
    memset(dis,0x3f,sizeof(dis));
    memset(stop,false,sizeof(stop));
    int a,b,c;
    Edge e;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        e.e=b;
        e.t=c;
        v[a].push_back(e);
        e.e=a;
        v[b].push_back(e);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(int j=1;j<=a;j++)
        {
            scanf("%d",&b);
            stop[i][b]=true;
        }
    }
    printf("%d\n",spfa(1,n));
    return 0;
}
