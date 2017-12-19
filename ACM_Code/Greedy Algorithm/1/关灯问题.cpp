#include<iostream>
#include<string>
using namespace std;
const int LIGHT_NUM = 1001;
bool Lights[LIGHT_NUM];


int judge(bool *a, int len)
{
	int sum = 0;
	for (size_t i = 1; i <= len; i++)
	{
		sum += a[i];
	}
	return sum;
}

void switchLights(int a, int len)
{
	for (int i = a; i <= len; i += a)
	{
		Lights[i] = !Lights[i];
	}
}

int switch_and_judge(int a, int len)
{
	bool Temp[LIGHT_NUM];
	for (int i = 1; i <= len; ++i)
	{
		Temp[i] = Lights[i];
	}//复制灯状态到缓存
	for (int i = a; i <= len; i += a)
	{
		Temp[i] = !Temp[i];
	}
	return judge(Temp, len);
}

int main()
{
	string inputs;

	while (cin >> inputs)
	{

		int read = 0;
		char input;
		int num = 0;
		while (inputs[read] != EOF)
		{
			input = inputs[read];
				read++;
			if (input != EOF)
			{
				if (input == 'Y') { num++; Lights[num] = 1; }
				else if (input == 'N') { num++; Lights[num] = 0; }
				else if (input == 10)
				{
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}

		}
		int steps = 0;
		//while (judge(Lights, num) != 0)
		//{
		//	int best_siwtch = 1;
		//	int temp_judge = judge(Lights, num);
		//	for (int i = 1; i <= num; i++)
		//	{
		//		if (temp_judge > switch_and_judge(i, num)
		//		{
		//			best_siwtch = i;

		//		}
		//	}
		//}//理解错意思了，想复杂了，想成最优化的了，哎。。。

		for (int i = 1; i <= num; ++i)
		{
			if (Lights[i] == 1)
			{
				switchLights(i, num);
				steps++;
			}
		}

		if (judge(Lights, num) == 0)
		{
			cout << steps << endl;
		}
		else
		{
			cout << "-1" << endl;
		}



		//for (int i = 1; i <= num; ++i)
		//	cout << Lights[i];
		//cout << endl;
		//cout << judge(Lights, num) << endl;
		//switchLights(3, num);
		//for (int i = 1; i <= num; ++i)
		//	cout << Lights[i];



	}
	
}