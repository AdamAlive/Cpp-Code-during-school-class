#include<iostream>
#include<algorithm>
#include<random>
#include<ctime>
#include<string.h>
using namespace std;


int random(int a, int b)
{
	if (b > a)
		return a + rand() % (b - a);
	else return 0;
}
const int MAX_N = 1000;
int n, W;
int w[MAX_N], v[MAX_N];

int dp[MAX_N + 1][MAX_N + 1];

int rec(int i, int j)
{
	if (dp[i][j] >= 0)
		return dp[i][j];
	int res;
	if (i == n)
		res = 0;
	else if (j < w[i])
		res = rec(i + 1, j);
	else
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);

	return dp[i][j] = res;
}

void slove()
{
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(0, W));
}

int main()
{

	while (cin >> W >> n)
	{
		for (int i = 0; i < 110; i++)
		{
			for (int j = 0; j < 110; j++)
			{
				dp[i][j] = -1;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cin >> w[i] >> v[i];
			
		}
		slove();
	}
	/*srand(time(0));
	cin >> n >> W;
	for (int i = 0; i < n; ++i)
	{
		w[i] = random(0, 100);
		v[i] = random(0, 100);
	}
	slove();*/
}


//#include <iostream>
//
//#include <string.h>
//
//using namespace std;
//
//
//
//int n, W;
//
//int w[1000], v[1000];
//
//int dp[1001][1001];
//
//
//
//int rec(int I, int j) {
//
//	if (dp[I][j] >= 0)
//
//		return dp[I][j];
//
//
//
//
//
//	int res;
//
//	if (I == n) {
//
//		res = 0;
//
//	}
//
//
//
//	else if (j < w[I]) {
//
//		res = rec(I + 1, j);
//
//
//
//	}
//	else {
//
//		res = max(rec(I + 1, j), rec(I + 1, j - w[I]) + v[I]);
//
//	}
//
//	return dp[I][j] = res;
//
//}
//
//
//
//void solve() {
//
//	memset(dp, -1, sizeof(dp));
//
//
//
//	printf("%d\n", rec(0, W));
//
//}
//
//
//
//int main() {
//
//	cin >> W >> n;
//
//	for (int I = 0; I < n; ++I) {
//
//		cin >> w[I] >> v[I];
//
//
//
//	}solve();
//
//}
