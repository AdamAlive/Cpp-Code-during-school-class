#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int dp[11][11];

int count_num(int i, int j)
{
	if (i == 0 || j == 0)
		return 1;
	if (dp[i][j] >= 0)
		return dp[i][j];
	int count = 0;
	return dp[i][j] = (count_num(i - 1, j) + count_num(i, j - 1));
}

int main()
{
	int i, j;
	memset(dp, -1, sizeof(dp));
	while (cin >> i >> j)
	{
		cout << "I know!The answer is "<< count_num(i, j) <<"." << endl;
	}
}