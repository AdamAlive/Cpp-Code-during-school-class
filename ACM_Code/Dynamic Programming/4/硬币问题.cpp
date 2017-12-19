#include<iostream>
#include<algorithm>
using namespace std;

int coins[15];
int num_coin;

int recursion(int n)
{
	for (int i = 0; i < num_coin; i++)
	{
		if (n == coins[i])
			return 1;
	}
	if (n <= 0)
		return 0;
	int min_re = recursion(n - coins[0]);
	if (num_coin > 1)
	{
		for (int i = 0; i < num_coin - 1; i++)
		{
			min_re = min(recursion(n - coins[i]) + 1, recursion(n - coins[i + 1]) + 1);
		}
	}
	return min_re;
	
}

int main()
{
	int total;
	while (cin >> total >> num_coin)
	{
		for (int i = 0; i < num_coin; i++)
		{
			cin >> coins[i];
		}
		cout << recursion(total) << endl;
	}
}