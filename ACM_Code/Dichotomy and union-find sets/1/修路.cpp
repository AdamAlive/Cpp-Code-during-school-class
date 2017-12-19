#include<iostream>
#include<string.h>
using namespace std;
bool road[1001][1001];
int n;
int cal()
{
	int total = 0;
	for (int i = 2; i <= n; i++)
	{
		int flag = 0;
		for (int j = 1; j < i; j++)
		{
			flag += (int)(road[i][j] | road[j][i]);
		}
		if (flag==0)
			total++;
	}
	return total;
}

int main()
{
	int m, a, b;
	while(cin >>n)
	{
		//cout << "zzz" << endl;
		if (n == 0)
			break;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			road[a][b] = 1;
		}
		cout << cal() << endl;
		memset(road, 0, sizeof(road));
	}


	
	//system("pause");
}