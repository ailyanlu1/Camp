#include<bits/stdc++.h>
using namespace std;

struct circle{
	int height;
	int r;
}cup[1002];

bool cmp(circle a,circle b){
	return a.height<b.height;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,v,delta;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cup[i].height>>cup[i].r;
	}
	sort(cup,cup+n,cmp);
	v=cup[0].r*cup[0].r*cup[0].height;
	for(int i=1;i<n;i++){
		v+=cup[i].r*cup[i].r*(cup[i].height-cup[i-1].height);
	}
	cout<<v<<endl;
	return 0;
}
