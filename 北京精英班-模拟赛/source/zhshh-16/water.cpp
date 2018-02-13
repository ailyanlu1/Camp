#include <iostream>
#include <cstdio>
#include <algorithm>

#define LL long long

using namespace std;
struct node{
	int r;
	int h;
}q[1050];
int n;
bool operator <(node a,node b){
	return a.r>b.r;
}
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].h>>q[i].r;
	}
}
void work(){
	sort(q+1,q+n+1);
	q[0].r=0;
	q[0].h=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=q[i].r*q[i].r*(q[i].h-q[i-1].h);
	}
	cout<<ans;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	init();
	
	work();
	
	return 0;
}
