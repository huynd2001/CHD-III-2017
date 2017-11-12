#include <bits/stdc++.h>
using namespace std;

bool f[102][10002];
int a[102],su[102];

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[n-i+1];
	for(int i=n;i>=1;i--) su[i]=su[i+1]+a[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j>=su[i])
			{
				f[i][j]=f[i][j]|f[i][j-su[i]];
				f[i][j]=f[i][j]|f[i-1][j-su[i]];
			}
		}
	}
	if(f[n][m]) cout << "HAI\n"; else cout << "IIE\n";
	return 0;
}
