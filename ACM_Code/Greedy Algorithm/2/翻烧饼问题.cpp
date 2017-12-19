#include<iostream>
#include<string>
using namespace std;

int judge(bool *a, int len)
{
	int sum = 0;
	for (size_t i = 1; i <= len; i++)
	{
		sum += a[i];
	}
	return sum;
}

int main()
{
	int global_num = 1;
	string bings;
	int num, chan;
	cin >> num;
	

	for (int i = 0; i < num; i++)
	{
		bool bing[1001];
		/*for (int i = 0; i < 1001; i++)
			bing[i] = 0;*/
		cin >> bings >> chan;
		for (int i = 0; i < bings.length(); i++)
		{
			if (bings[i] == '+')
				bing[i + 1] = 0;
			else if(bings[i] == '-')
				bing[i + 1] = 1;
			else
				break;
		}
		//cout << "³¤¶È"<< bings.length() <<endl;
		int count = 0;
		for (int i = 1; i <= bings.length() - chan + 1; ++i)
		{
			if (bing[i] == 1)
			{
				for (int j = 0; j < chan; j++)
				{
					bing[i + j] = !bing[i + j];

				}
				count++;
			}
		}

		if (judge(bing, bings.length()) == 0)
		{
			cout << "Case #" << global_num << ": " << count << endl;
			global_num++;
		}
		else
		{
			cout << "Case #" << global_num << ": " << "IMPOSSIBLE" << endl;
			global_num++;
		}
		//cout << judge(bing, bings.length()) << endl;
	}
}