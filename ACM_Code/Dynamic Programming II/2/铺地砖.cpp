#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[100001];


long long int pudi(long long int a)
{
	if (a <= 3)
		return dp[a];
	if (dp[a] > 0)
		return dp[a];
	//if (dp[a] >= 0)
	//	return dp[a];
	int total;
	total = (pudi(a - 1) + pudi(a - 2)) % 1000000007;
	dp[a] = total;
	return total;
}

int main()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	//cout << pudi(4) << endl;
	while(cin >> n)
	{
		cout << pudi(n) << endl;
		//cout << pudi(n)% 1000000007 << endl;
	}

}
	 