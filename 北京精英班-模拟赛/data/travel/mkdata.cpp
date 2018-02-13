#include<cstdio>
#include<cstdlib>
#include<map>
#include<ctime>
using namespace std;
map<int,int> f;
int n,m;
int main(){
	freopen("travel.in","w",stdout);
	srand(time(0));
	n=100; m=55;
	printf("%d %d\n",n,m+n-1);
	for (int i=2;i<=n;i++) printf("%d %d %d\n",rand()%(i-1)+1,i,rand()%1000+1);
	for (int i=1;i<=m;i++){
		printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()%1000+1);
	}
	for (int i=1;i<=n;i++){
		f.clear();
		int k=rand()%50+1; k = 0;
		printf("%d ",k);
		for (int i=1;i<=k;i++){
			int x;
			for (x=rand()%300+1;f[x];x=rand()%300+1);
			f[x]=1;
			printf("%d ",x);
		}
		printf("\n");
	}
}
