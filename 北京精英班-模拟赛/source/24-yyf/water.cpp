#include <fstream>
#include <algorithm> 

using namespace std;

ifstream fin("water.in");
ofstream fout("water.out");

struct yz
{
	int h,r; 
	yz():h(0),r(0){} 
}  cup[1010]; 

bool px(yz& a,yz& b)
{
	return a.r>b.r; 
} 

int main()
{
	long long ans=0; 
	int i,n,th=0;
	
	fin>>n; 
	
	for (i=0;i<n;++i)
	{
		fin>>cup[i].h>>cup[i].r; 
	} 
	
	sort(cup,cup+n,px);
	
	for (i=0;i<n;++i)
	{
		ans+=cup[i].r*cup[i].r*(cup[i].h-th);
		th=cup[i].h; 
	} 
	
	fout<<ans; 
	
	return 0; 
} 
