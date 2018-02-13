#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;
#define N 10005
#define inf 100000000
#define For(i,l,r) for(int i=l;i<=r;i++)
int n,m;
pair<int,int> a[N];
int main(){
    freopen("water.in","w",stdout);
    srand(time(0));
    n = 999; For(i,1,n) a[i] = make_pair(i,n-i+1);
    random_shuffle(a+1,a+1+n);
	m = rand() * rand() % n + 1; printf("%d\n",m);
	sort(a+1,a+1+m);
	For(i,1,m) printf("%d %d\n",a[i].first,a[i].second);
	For(i,1,100000000);
}
