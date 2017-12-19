#include<iostream>
#include<algorithm>
using namespace std;

int l[1000];
int r[1000];
int index[1000];
int gold[1000];

//void find_2_in_3(int i, int j, int k)
//{
//	int max = i;
//	int min = j;
//	if (j > max)
//		max = j;
//	if (k > max)
//		max = k;
//	if (j < min)
//		min = j;
//	if (k <min)
//		min = k;
//	i = max;
//	if (j == min)
//		j = k;
//}
//
//int main()
//{
//	int q = 4, w = 1, e = 3;
//	find_2_in_3(q, w, e);
//	cout << q << " " << w << endl;
//}

int main()
{
	int num, L, R;
	while (cin >> num >> L >> R)
	{
		int total = L;
		for (int i = 0; i < num; i++)
		{
			cin >> l[i] >> r[i];
			total *= l[i];
			index[i] = i;
			gold[i] = 1;
		}

		int max_rl = r[0]*l[0];
		int max_l = l[0], max_r = r[0];
		int max2_l = l[0], max2_r = r[0];
		int max2_rl = r[0] * l[0];
		for (int i = 1; i < num;++i)
		{
			int temp, temp_r, temp_l;
			if (max2_rl < r[i] * l[i])
			{
				max2_rl = r[i] * l[i];
				max2_l = l[i];
				max2_r = r[i];
			}
			if (max_rl < max2_rl)
			{
				temp = max_rl;
				temp_l = max_l;
				temp_r = max_r;
				max_rl = max2_rl;
				max_l = max2_l;
				max_r = max2_r;
				max2_rl = temp;
				max2_l = temp_l;
				max2_r = temp_r;
			}
		}

		if (max2_r * max_l < max_r)
			cout << total / max_l / max2_r << endl;
		else
			cout << total / max_rl << endl;
		//int min_all = 99999;
		//do
		//{
		//	int max_in;
		//	gold[index[0]] = L / R;
		//	for (int i = 1; i < num; i++)
		//	{
		//		for (int j = 0; j < num; j++)
		//			gold[j] = 1;
		//		max_in = gold[index[0]];
		//		for (int j = 0; j < i; j++)
		//		{
		//			gold[index[i]] = l[index[j]] * gold[index[i]];
		//		}
		//		gold[index[i]] = gold[index[i]] / r[index[i]];
		//		//cout << gold[index[i]] << endl;
		//		if (max_in < gold[index[i]])
		//		{
		//			max_in = gold[index[i]];
		//			//cout << "maxÎª£º" << max_in << endl;
		//			
		//		}
		//	}
		//	if (min_all > max_in)
		//	{
		//		min_all = max_in;
		//		for (int i = 0; i < num; i++)
		//			cout << index[0];
		//	}
		//	} while (next_permutation(index, index + num));
		//cout << min_all << endl;
	}
}