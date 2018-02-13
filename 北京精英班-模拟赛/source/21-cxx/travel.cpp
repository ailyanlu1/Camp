#include<bits/stdc++.h>

#define INF 99999999
#define MAXN 505
#define MAXM 1010
using namespace std;

int n,m,i,j,k,u,mn;
int edge[MAXN][MAXN];
int dst[MAXN];
bool book[MAXN];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			edge[i][j]=INF;
	
	for(i=1;i<=m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		edge[x][y]=edge[y][x]=z;
	}
	
	
	book[1] = 1;
	for(i = 1; i <= n; i++)
			dst[i] = edge[1][i];
	for(i = 1; i <= n-1; i++){
    	
    	mn = INF;
    	
    	for(j = 1; j <= n; j++){
        	if(book[j] == 0 && dst[j] < mn){
            	mn = dst[j];
            	u = j;
        	}
    	}
    book[u] = 1;
    
    for(k = 1; k <= n; k++){
        if(edge[u][k] < INF && book[k] == 0){
            if(dst[k] > dst[u] + edge[u][k])
                dst[k] = dst[u] + edge[u][k];
        }
    }
}
	cout<<dst[n];
	return 0;
}
