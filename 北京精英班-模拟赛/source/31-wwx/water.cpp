#include<bits/stdc++.h>
using namespace std;
int B[1011][2],N;
long long v;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&N);
	for(int i=N;i>0;i--){					//从矮到高 
		scanf("%d%d",&B[i][0],&B[i][1]);	//0为高度；1为半径； 
	}
	for(int i=N;i>=1;i--){
		for(int j=1;j<i;j++){
			if(B[j][0]<B[i][0]){
				int temp=B[i][0];
				B[i][0]=B[j][0];
				B[j][0]=temp;
				temp=B[i][1];
				B[i][1]=B[j][1];
				B[j][1]=temp;
			}
		}
	}
	for(int i=1;i<=N;i++){
		v+=(B[i][1]*B[i][1]-B[i-1][1]*B[i-1][1])*B[i][0];
	}
	printf("%lld",v);
	return 0;
}
