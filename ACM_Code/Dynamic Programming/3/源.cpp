#include<iostream>
#include<algorithm>
#include<random>
#include<ctime>
#include<string.h>
using namespace std;

int dp[1001][125001];
bool if_dp[1001][125001];

int dp2[1001][125001];
int dis(int M, int T)
{
	if (dp[M][T] >= 0)
		return dp[M][T];
	int total;
	if (T <= 0)
		total = 0;
	else
	{
		total = max(dis(M + 4, T - 1), dis(M, T - 1) + 17);
	}
	//else
	//{
	//	total = dis(M - 10, T - 1) + 60;
	//}
	if_dp[M][T] = 1;
	return dp[M][T] = total;
}

int min_time(int M, int D)
{
	if (dp2[M][D] >= 0)
		return dp2[M][D];
	int total;
	if (D <= 0)
		return 0;
	if (M >= 10)
		return min_time(M - 10, D - 60) + 1;
	total = min(min_time(M + 4, D)+1, min_time(M, D - 17)+1);
	return dp[M][D] = total;
}

int main()
{
	/*memset(dp, -1, sizeof(dp));
	memset(if_dp, 0, sizeof(if_dp));*/
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		memset(dp, -1, sizeof(dp));
		memset(if_dp, 0, sizeof(if_dp));
		memset(dp2, -1, sizeof(dp2));
		int d = 0;
		int t_feedback = 0;
		int s_feedback = 0;
		while (a >= 10 & b >= 60 & c > 0)
		{
			b = b - 60;
			a = a - 10;
			c--;
			t_feedback++;
			s_feedback = s_feedback + 60;
			//d = d + 60;
			/*b = b - (a % 10) * 60;
			a = a % 10;
			c = c - a / 10;*/
		}
		while (c >= 7 & b >= 120)
		{
			c = c - 7;
			t_feedback = t_feedback + 7;
			b = b - 120;
			s_feedback = s_feedback + 120;
		}
		//cout << a << ' ' << b << ' ' << c << endl;
		if (17 * c >= b)
		{
			int time = min_time(a, b);
			cout << "Yes" << endl;
			cout << time + t_feedback << endl;
			goto the_end;
		}
		//6 75 7
		//cout << a <<' '<< b <<' ' << c << endl;
		d = dis(a, c);
		if (d < b)
			cout << "No" << endl << d + s_feedback << endl;
		else
		{
			int minT = c;
			for (int i = 0; i < a+1; ++i)
			{
				
				for (int j = 0; j < c+1; ++j)
				{
					if (if_dp[i][j] & (dp[i][j] > b) & minT > (j-1))
					{
						minT = j - 1;
						//cout <<"now: "<< j - 1 << endl;
					}
				}
			}
			cout << "Yes" << endl << minT + t_feedback - 1 << endl;
			the_end : int dwaq = 0;//什么都没用的东西
		}
	}
}