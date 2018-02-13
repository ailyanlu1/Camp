#include<iostream>
#include<cstdio>
using namespace std;
const int N=605;
int n,m,a,b,c;
int st[N],w[N][N],t[N];
bool arr[N][N],f[N][N*50];
void go(int xx,int tt){
	if(t[xx]>tt||t[xx]==-1)t[xx]=tt;
	if(xx==n)return;
	if(f[xx][tt]){
		go(xx,tt+1);
		return;
	}
	for(int i=1;i<=n;i++){
		if(arr[xx][i]&&(tt+w[xx][i]<t[i]||t[i]==-1)){
			arr[xx][i]=arr[i][xx]=false;
			go(i,tt+w[xx][i]);
			arr[xx][i]=arr[i][xx]=true;
		}
	}
return;}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		w[a][b]=w[b][a]=c;
		arr[a][b]=arr[b][a]=true;
	}
	for(int i=1;i<=n;i++){
		t[i]=-1;
		scanf("%d",&a);
		for(int j=1;j<=a;j++){
			scanf("%d",&b);
			f[i][b]=true;
		}
	}
	go(1,0);
	printf("%d\n",t[n]);
return 0;}
