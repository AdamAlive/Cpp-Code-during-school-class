#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

int m, n;
float dp[1001][1001];
float dpS[1001][1001];

float P(int a, int b);

float S(int a, int b)//该敌方时的胜率
{
	if (b == 0)
		return 0;
	if (dpS[a][b] >= 0)
		return dpS[a][b];
	float m = (float)(a);
	float n = (float)(b);
	float total;
	if(b == 1)
		total = 1 - (m / (m + n) + (n / (m + n))*P(a - 1, b - 1));
	else
		total = 1-(m / (m + n) + (n / (m + n))*(P(a, b - 2)+P(a - 1, b - 1))/2);
	//cout << P(a, b - 1) + P(a - 1, b) << endl;
	//cout << m / (m + n) <<" "<< (n / (m + n))*(P(m, n - 1) + P(m - 1, n)) << endl;
	dpS[a][b] = total;
	return total;
}

float P(int a, int b)//该我方时的胜率
{
	if (a == 0)
		return dp[a][b] = 0;
	if (b == 0)
		return dp[a][b] = 1;
	
	if (dp[a][b] >= 0)
		return dp[a][b];
	float m = (float)(a);
	float n = (float)(b);
	if (b == 1)
		return m / (m + n);
	float total;
	if(b>=3)
		total = (m / (m + n) + (n / (m + n))*(((n-1)/(m+n-1)) * (((n-2)/(m+n-2))*P(a, b - 3) + ((m) / (m + n - 2))*P(a-1, b-2)) ));
	else
		total = (m / (m + n) + (n / (m + n))*(((n - 1) / (m + n - 1)) * P(a-1, b - 2) ));
	//cout << m<<" "<< n - 1 << endl;
	dp[a][b] = total;
	return total;
}



int main()
{
	//fill((float *)dp, (float*)dp + sizeof(dp), -1);
	memset(dp, -1, sizeof(dp));
	memset(dpS, -1, sizeof(dpS));
	//dp[1][1] = 0.5;
	//dpS[1][1] = 0;
	//cout << P(1,3) << endl;
	//cout << dp[5][5];
	//cout << S(1, 2) << endl;
	cout.setf(ios::fixed);
	while (cin >> m >> n)
	{
		//printf("%4f", P(m, n));
		cout << setprecision(5) << P(m, n) << endl;
		//cout << P(m, n) << endl;
	}
}