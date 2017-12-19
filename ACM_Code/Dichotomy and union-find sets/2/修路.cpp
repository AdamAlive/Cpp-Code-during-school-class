#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int l, m, n;
int L[50001];
int dis[50001];
vector<int> dis2;

int* find_min2(vector<int> a, int length)
{
	int min = std::min(a[0],a[1]);
	int min2 = std::max(a[0], a[1]);
	for (int i = 2; i < length-1; i++)
	{
		if (min2 >= a[i])
			min2 = a[i];
		if (min >= min2)
			swap(min, min2);
	}
	int min_2[2] = { min, min2 };
	return min_2;
}


int main()
{
	while (cin >> l >> n >> m)
	{
		memset(dis, 0, sizeof(dis));
		for (int i = 0; i < n; i++)
		{
			cin >> L[i];
		}
		for (int i = 0; i < n-1; i++)
		{
			dis[i] = L[i + 1] - L[i];
			dis2.push_back(dis[i]);
		}
		if(find_min2(dis2, n)[0] + find_min2(dis2, n)[1])
		cout << find_min2(dis2, n)[0] << "   " << find_min2(dis2, n)[1] << endl;
		//sort(dis2,dis2+n-1);
		//for (int i = 1; i <= m ; i++)
		//{
		//	//dis[n + i] = dis[i + 1] + dis[i + 2];
		//	dis[i + 2] = dis[i + 2] + dis[i + 1];
		//	sort(dis + 1 + i, dis + n + 1);
		//}
		//
		for (int i = 0; i < n-1; i++)
			cout << dis[i] << endl;

	}
}