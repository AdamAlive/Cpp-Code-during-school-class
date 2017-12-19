#include<iostream>
#include<algorithm>
using namespace std;

int a[1000001];

int main()
{
	int num;
	while (cin >> num)
	{
		for (int i = 0; i < num; i++)
		{
			cin >> a[i+1];
		}
		int temp = 0;
		int n,num_2;
		num_2 = 1;
		while (num_2 < num)
		{
			int i;
			for (i = num_2, n = 1; i < num&&a[i + 1]>a[i]; i++)
			{
				n++;
			}
			 num_2++;
			temp = max(n, temp);
		}
		cout << "WOW,I can eat "<<temp<<" hour(s)."<< endl;;
	}
}