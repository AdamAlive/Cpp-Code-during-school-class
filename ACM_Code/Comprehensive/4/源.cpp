#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int a[100001];

int main()
{
	int n, q;
	while (cin >> n >> q)
	{
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		//cout << endl;
		char command[4];
		int c1, c2, c3;
		int temp;
		for (int i = 1; i <= q; i++)
		{
			cin >> command;
			if (command[0] == 'A'|| command[0] == 'a')
			{
				cin >> c1 >> c2 >>c3;
				for (int j = c1; j <= c2; j++)
				{
					a[j] += c3;
				}
			}
			else if (command[0] == 'Q'|| command[0] == 'q')
			{
				cin >> c1 >> c2;
				for (int j = c1; j < c2; j++)
				{
					temp = max(a[j], a[j + 1]);
				}
				cout << "The answer is " << temp << "." << endl;
			}
		}
		
		//cout << command << c1*2 << c2*2 << endl;
	}
}