#include<iostream>
#include<algorithm>
using namespace std;

void judge(int a, int b, int n)
{
	while (b / 2 * 2 == b && a < b)
	{
		b = b / 2;
		n++;
	}
}

int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		int num = 1;
		while (y / 2 * 2 == y && x < y)
		{
			y = y / 2;
			num++;
		}
		while (x < y)
		{
			if ((y - 1) % 10 == 0)
				y = (y - 1) / 10;
			else
				break;
			//cout << y << endl;
			num++;
			while (y / 2 * 2 == y && x < y)
			{
				y = y / 2;
				num++;
			}
		}
		//cout << x << " " << y << endl;
		if (x != y)
		{
			cout << "I am so sorry." << endl;
		}
		else
		{
			cout << "Yes,it takes " << num << " steps." << endl;
		}
	}
}