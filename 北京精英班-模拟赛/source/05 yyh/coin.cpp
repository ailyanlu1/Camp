#include<bits/stdc++.h>
#define N 100099
int n;
struct A{
	double a,b;
	bool operator < (const A &m) const {
		return m.a<a;
	}
}a[N];
struct B{
	double a,b;
	bool operator < (const B &m) const {
		return m.b<b;
	}
}b[N];
double D[N],X[N];
int main (){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		printf("0.0000");
		return 0;
	}
	for(int i=1;i<=n;++i){
		scanf("%lf %lf",&a[i].a,&a[i].b);
		b[i].a=a[i].a,b[i].b=a[i].b;
	}
	std::sort(a+1,a+1+n),std::sort(b+1,b+1+n);
	for(int i=1;i<=n;++i)
		D[i]=D[i-1]+a[i].a;
	for(int j=1;j<=n;++j)
		X[j]=X[j-1]+b[j].b; 
	double ans=0.0;
	for(int i=2;i<=n*2;i++){
		for(int d=1;d<i;d++){//Âò´ó  
			double sum=0.0-1.0*(i*1.0);
			int x=i-d;
			sum+=std::min(D[d],X[x]);
			ans=std::max(sum,ans);
		}
	}
	printf("%.4lf",ans);
}
