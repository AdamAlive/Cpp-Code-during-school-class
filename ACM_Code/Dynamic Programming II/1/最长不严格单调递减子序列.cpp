#include<iostream>
#include<algorithm>
using namespace std;

int n, a[1001];
int dp[1001];

void slove()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[j] >= a[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		res = max(res, dp[i]);
	}
	printf("%d\n", res);

}

int main()
{
	while (cin >> n)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		slove();
	}
}