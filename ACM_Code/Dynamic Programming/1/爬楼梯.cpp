#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int num;
int dp[40];
int pa(int i)
{
	if (dp[i] > 0)
		return dp[i];
	return dp[i] = pa(i - 1) + pa(i - 2);
}
int main()
{
	//memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	/*int a;
	cin >> a;
	cout << pa(a) << endl;*/
	while (cin >> num)
	{
		for (int q = 0; q < num; ++q)
		{
			int a;
			cin >> a;
			cout << pa(a - 1) << endl;
		}
	}
}