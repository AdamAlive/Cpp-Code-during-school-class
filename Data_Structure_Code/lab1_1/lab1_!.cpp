#include<iostream>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		for (int i = 0; i < b; i++)
		{
			if (i == 0 || i == b - 1)
			{
				cout << "+";
				for (int j = 1; j < a - 1; j++)
				{
					cout << "-";
				}
				cout << "+" << endl;
			}
			else
			{
				cout << "|";
				for (int j = 1; j < a - 1; j++)
				{
					cout << "a";
				}
				cout << "|" << endl;
			}
		}
	}
	system("pause");
}