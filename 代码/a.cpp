#include<bits/stdc++.h> 
using namespace std;
int n,i,a[100010],Stack[100010],top;
int main(){
	scanf("%d",&n);
	Stack[0]=n+1;
	for(i=n;i>=1;i--){
		scanf("%d",&a[i]);
		for(;a[i]>a[Stack[top]]&&top;top--);
		printf("%d\n",Stack[top]-i-1);
		Stack[++top]=i;
	}
}
