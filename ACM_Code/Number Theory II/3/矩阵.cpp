#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//vector<bool>col;
//vector<vector<bool> >matrix;
//bool m[1000000][1000000];
int num;
int n[1000000];
int main()
{
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n[i];
		int temp = 3 + n[i]*(n[i]-1);
		//cout << temp << " ";
		for (int j = 1; j < (n[i]+1); j++)
		{
			for (int w = 1; w < j; w++)
			{
				if ((n[i] + 1) / (j+1) != 0 && (n[i] + 1) / (w+1) != 0)
				{
					temp = temp - 2 * min(((n[i] + 1) / (j + 1)), ((n[i] + 1) / (w + 1))) + 2;
				}
			}
		}
		cout << temp << endl;
	}
	cin >> num;
}