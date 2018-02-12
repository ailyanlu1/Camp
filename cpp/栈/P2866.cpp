#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b>d)d+=60,c--;
	cout<<c-a<<' '<<d-b<<endl;
	return 0;
}
