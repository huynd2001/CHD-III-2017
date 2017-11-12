#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int dem=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin >> a;
		dem+=(a%2)^(i%2);
	}
	cout << dem/2 << endl;
	return 0;
}
