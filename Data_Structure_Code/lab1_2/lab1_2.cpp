#include<iostream>
using namespace std;

int C(int m, int n)
{
	long long int temp = 1;
	for (int i = m; i >= m+1-n ; i--)
		temp = temp * i;
	for (int i = n; i >0 ; i--)
		temp = temp / i;
	return int(temp);
}

//int main()
//{
//	int m, n, t;
//	cin >> t;
//	for (int i = 0; i < t; i++)
//	{
//		int result = 0;
//		cin >> m >> n;
//		for (int j = n - 1; j >= 0; j--)
//		{
//			result += C(m - 1, j);
//		}
//		//for (int i = n; i > 0; i--)
//		//{
//		//	result = result / i;
//		//}
//		cout << result << endl;
//	}
//	//cout << C(8, 0);
//	system("pause");
//}

int dp[200][200];
int m, n;

int func(int n, int m)
{
	if (dp[n][m] > 0)
		return dp[n][m];
	if (m != 0 & n == 0)
		return 0;
	else if (m == 0)
	{
		return 1;
	}
	else if (m >= n)
	{
		return dp[n][m] = func(n, m - n) + func(n - 1, m);
	}
	else
		return dp[m][m] = func(m, m);
}

int main()
{
	dp[0][0] = 0;
	//memset(dp, 0, sizeof(dp));
	int a, b, t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		cout << func(b, a) << endl;
	}
	system("pause");
	//while (cin >>a>>b)
	//{
	//	cout << func(b, a) << endl;
	//}
}