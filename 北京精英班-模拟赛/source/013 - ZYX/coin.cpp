#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
int n,cost;float ans;
float a[maxn],b[maxn],aw,bw;
float f[maxn][3];
bool vice[maxn],vic[maxn];
void violence(int v){
	if (v>n){
		float aw=0,bw=0,cos=0;
		for (int i=1;i<=n;i++){
			if (vice[i]) aw+=a[i],cos++;
			if (vic[i]) bw+=b[i],cos++;
		}
		float temp=min(aw-cos,bw-cos);
		ans=max(ans,temp);
		return;
	}
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++){
		if (a[v]<1&&i==1||b[v]<1&&j==1) continue;
		vice[v]=i;vic[v]=j;
		violence(v+1);
		vice[v]=0;vic[v]=0;
	}
}
bool cmp(float a,float b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>a[i]>>b[i];
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	//±©Á¦Ê®·Ö 
	if (n<=10){
		violence(1);
		printf("%.4f",ans);
		return 0;
	}
	for (int i=1;i<=n;i++)
	a[i]--,b[i]--;
	//for (int i=1;i<=n;i++)
	//cout<<a[i]<<" "<<b[i]<<endl;
	for (int i=1;i<=n;i++){
		aw+=a[i];bw=0;
		for (int j=1;j<=n;j++){
			bw+=b[j];
			//cout<<i<<" "<<j<<" "<<aw<<" "<<bw<<endl;
			ans=max(ans,min(aw-j,bw-i));
		}
	}
	printf("%.4f",ans);
	return 0;
}
