#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	if(s=="LoveForest") cout << "Camon\n";
	else
	{
		int ans=0;
		for(int i=0;i<s.size()-3;i++)
		{
			if(s[i]=='r' && s[i+1]=='u' && s[i+2]=='n' && s[i+3]=='g') ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
