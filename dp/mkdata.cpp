#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define For(i,l,r) for(int i=l;i<=r;i++)
int main(){
	freopen("coin.in","w",stdout);
	srand(time(0));
	int n = 1000; 
	printf("%d\n",n);
	For(i,1,n) printf("%lf %lf\n",(rand()%200+100)/100.0,(rand()%200+100)/100.0);
}
