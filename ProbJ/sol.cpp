/*huypheu
97
*/

#include <bits/stdc++.h>
#define int long long
#define mod 100000007
using namespace std;

signed main()
{
	int n;
	cin >> n;
	int a=1;
	for(int i=1;i<=n-1;i++) a=(a*2)%mod;
		cout << a << endl;
	return 0;
}