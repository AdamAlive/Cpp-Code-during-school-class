#include<iostream>
using namespace std;

int x ;
long long b, temp3, temp, t, r;
int j;
int temp2;
int main()
{

	while (cin >> t)
	{
		for (int i = 0; i < t; i++)
		{
			cin >> x >> b;
			temp = x % b;
			temp3 = x;
			temp2 = 9973 % b;
			while (temp2 != 0)
			{
				r = (b - temp) / temp2;
				temp += r * temp2;
				if (temp == b)
				{
					temp3 += r * 9973;
					break;
				}
				temp += temp2;
				temp3 += (r + 1) * 9973;
				temp -= b;
			}
			cout << (temp3 / b) % 9973 << endl;
			//j = (int)(((double)(x) / (double)(b)-x / b)*b);
			//for (j = b/9973; (9973 * j + x) % b != 0; j++) {}
			//cout << j << endl;
			//cout << ((9973 * j + x)/b)%9973 << endl;
		}
	}
	
}