#include<bits/stdc++.h>
using namespace std;

bool cmp(float x,float y){
	return x>y;
}

float a[100451],b[100451];
int main(){
	ios::sync_with_stdio(false);
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int n,i;
	float suma=0.0,sumb=0.0;
	cin>>n;
	for(int j=0;j<n;j++){
		cin>>a[j]>>b[j];
	}
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	int pa=0,pb=0;
	for(i=1;pa<n&&pb<n;i++){
		if(a[pa]<1.0&&b[pb]<1.0)	break;
		if(suma==sumb){
			if(pa==0&&pb==0){
				if(a[pa]<b[pb])	sumb+=b[pb++];
				else suma+=a[pa++];
			}else if(a[pa]<2.0&&b[pb]<2.0)	break;
			else if(a[pa]<b[pb]){
				suma+=a[pa++];  
			}else{
				sumb+=b[pb++];
			}
		}else if(suma>sumb){
			if(sumb+b[pb]<suma){
				sumb+=b[pb++];
			}else{
				if(suma+a[pa]>=sumb+b[pb]){
					if(b[pb]>=2.0)	sumb+=b[pb++];
					else break;
				}else{
					if(a[pa]>=2.0)	sumb+=b[pb++];
					else break;
				}
			}
		}else{
			if(suma+a[pa]<sumb){
				suma+=a[pa++];
			}else{
				if(sumb+b[pb]>=suma+a[pa]){
					if(a[pa]>=2.0)	suma+=a[pa++];
					else break;
				}else{
					if(b[pb]>=2.0)	suma+=a[pa++];
					else break;
				}
			}
		}
	}
	if(min(suma,sumb)<=0.0)	printf("0.0000\n");
	else	printf("%.4f\n",min(suma,sumb)-i+1);
	return 0;
}
