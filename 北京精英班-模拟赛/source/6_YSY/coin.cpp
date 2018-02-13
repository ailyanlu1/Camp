#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+6;
int n;
double a[N],b[N],ans,g;
bool c;
bool l=true,ls=true;
bool cmp(double xx,double yy){
	return xx>yy;
}
int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		//printf("a%d=%0.4f,b%d=%0.4f\n",i,a[i],i,b[i]);
		if(a[i]>2||b[i]>2)c=true;
	}
	ans=-100;
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	//for(int i=1;i<=n;i++)printf("a%d=%0.4f,b%d=%0.4f\n",i,a[i],i,b[i]);
	int x=0;
	if(c){
		int ld=1,rd=1;
		double lft=0,rgt=0;
		while(1){
			x++;
			if(l){lft+=a[ld];ld++;}
			else {rgt+=b[rd];rd++;}
			g=(lft<rgt?lft:rgt)-x;
			if(lft<rgt)l=true;else l=false;
			//printf("x=%d,l=%0.4f,r=%0.4f,g=%0.4f,",x,lft,rgt,g);
			//printf("<%d>l<%d>\n",ls,l);
			if(g<=ans&&ls==l)break;
			else if(g>ans)ans=g;
			ls=l;
		}
	}
	else ans=0;
	if(ans<0)ans=0;
	printf("%0.4f\n",ans);
return 0;}
