#include <bits/stdc++.h>
using namespace std;

int a[500007];

int join(int x,int y)
{
	int k=0;
	if(y<10) return x*10+y;
	if(y<100) return x*100+y;
	if(y<1000) return x*1000+y;
	if(y<10000) return x*10000+y;
}

bool cmp(int x,int y)
{
	return (join(x,y)>join(y,x));
}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout << a[i] ;
		cout << "\n";
	return 0;
}
