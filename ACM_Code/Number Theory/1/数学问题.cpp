#include<iostream>
#include<algorithm>
using namespace std;

bool a[100001];

bool isCoprime(int a, int b)
{
	if (a == b | a <= 1 | b <= 1)
		return false;
	//cout << endl;
	if (max(a, b) % min(a, b) == 0)
		return false;
	for (int i = 2; i * i <= min(a, b); i++)
	{
		//cout << i << endl;
		if (a%i == 0 & b%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int b, c;
	//cout << isCoprime(6, 4);
	while (cin >> b >> c)
	{
		int d = b / c;
		//cout << d;
		a[0] = true;
		for (int i = 2; ; i++)
		{
			//cout << i << endl;
			if (isCoprime(i, d))
			{
				cout << i * c << endl;
				break;
			}
				 
		}
	}
	//cout << a[0];
	//system("pause");
}