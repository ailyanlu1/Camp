#include<bits/stdc++.h>
#define MAXN 100010
#define INF 99999999
using namespace std;

int n,tot;
double mbig,msmall,temp,mn,mx;
double big[MAXN],small[MAXN];
double val[MAXN][4];//0不买1买大2买小3都买 

double du(int x)
{
	for(int i=0;i<=3;i++) {
		if(i==0)if(x<n)du(x+1);
		if(i==1) {
			mbig+=big[x];
			tot++;
			if(x<n)du(x+1);
		}
		if(i==2) {
			msmall+=small[x];
			tot++;
			if(x<n)du(x+1);
		}
		if(i==3) {
			mbig+=big[x];
			msmall+=small[x];
			tot+=2;
			if(x<n)du(x+1);
		}
		if(x==n) {
			mn=min(mbig,msmall)-tot;
			mx=max(mx,mn);
		}
			if(i==1) {
				mbig-=big[x];
				tot--;
			}
			if(i==2) {
				msmall-=small[x];
				tot--;
			}
			if(i==3) {
				mbig-=big[x];
				msmall-=small[x];
				tot-=2;
			}
	}
}

int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>big[i]>>small[i];
		
	
	du(1);
	printf("%.4lf",mx);

	return 0;
}
