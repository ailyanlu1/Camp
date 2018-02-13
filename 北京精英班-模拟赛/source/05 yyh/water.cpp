#include<bits/stdc++.h>
#define N 3000
int n;
inline int f(int x){
	return x*x;
}
struct cup{
	int h,r;
	bool operator < (const cup&m) const{
		return r<m.r; 
	} 
} a[N]; 
int main (){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d %d",&a[i].h,&a[i].r);
	std::sort(a,a+n); 
	int sum=0;
	sum+=f(a[0].r)*a[0].h;
	for(int i=1;i<=n;++i){
		sum+=(f(a[i].r)-f(a[i-1].r))*a[i].h;
	}
	printf("%d",sum);
}
