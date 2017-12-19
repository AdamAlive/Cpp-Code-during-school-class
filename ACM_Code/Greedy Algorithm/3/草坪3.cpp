#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif

#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

int x[50001];
int r[50001];
//int index[50001];
//map<int, int>points[50001];


//bool if_out()
float distance_2(int x1, int y1, int x2, int y2)
{
	return(((float)(x1)-(float)(x2))*((float)(x1)-(float)(x2)) + ((float)(y1)-(float)(y2))*((float)(y1)-(float)(y2)));
}

void cal_height_2(int x1, int r1, int x2, int r2, int Y)
{

	//float p = (abs((float)(x1)-(float)(x2)) + (float)(r1)+(float)(r2))/2;
	//return (2 * pow((p*(p - (float)(r1))*(p - (float)(r2))*(p - abs((float)(x1)-(float)(x2)))), 0.5))/ abs((float)(x1)-(float)(x2));
}

bool if_good(int x1, int r1, int x2, int r2, int Y)
{
	if (r1 + r2 <= abs(x2 - x1))
		return false;
	return (sqrt((float(r1 * r1) - (float)(Y*Y) / 4)) + sqrt((float(r2 * r2) - (float)(Y*Y) / 4))) >= abs(x2 - x1);
}

int main()
{
	cout << if_good(7, 4, 12, 4, 3);
	//cout << cal_height_2(7, 4, 12, 4);
	int X, Y;
	while (cin >> X >> Y)
	{
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cin >> x[i] >> r[i];
			
		}
		//ÏÈÕÒ×î×ó±ßµÄ
		bool if_out = false;
		int i = num - 1;
		bool dead = false;
		bool win = false;
		//bool show = true;
		//sort(index, index + num);
		for (i = num - 1;i >= 0;--i)
		{

			if (((x[i] * x[i]) + Y*Y / 4) <= r[i] * r[i])
			{
				if (i == num - 1 & distance_2(x[i], Y / 2, X, Y) <= r[i] * r[i])
					win = true;
				break;
			}
			else if(i == 0)
			{
				dead = true;
				//show = false;
				//cout << "-1" << endl;
			}


			//{
			//	if (i == 0)
			//	{
			//		cout << "-1" << endl;
			//		dead = true;
			//		show = false;
			//		break;
			//	}
			//	else
			//	{
			//		//i--;
			//		continue;
			//	}
			//}
			//else
			//{
			//	//i++;
			//	continue;
			//}
		}
		//cout << cal_height_2(x[0],r[0],x[1],r[1]) << endl;
		int count = 1;
		int temp = i;
		//if (distance_2(x[index[num - 1]], Y / 2, X, Y) <= r[index[num - 1]] * r[index[num - 1]])
		//dead = false;
		//cout << distance_2(x[i], Y / 2, X, Y) << endl;
		//cout << i << endl;

		while (distance_2(x[i], Y / 2, X, Y) > r[i] * r[i] & dead == false & !win)
		{
			dead = true;
			for (int j = num - 1;j >= i; --j)
			{
				if (if_good(x[i], r[i], x[j], r[j], Y))
				{
					dead = false;
					count++;
					i = j;
					break;
				}
			}
			//goto fin;
			/*dead = true;
			for (int j = num - 1; j > i; j--)
			{
				if (if_good(x[i], r[i], x[j], r[j], Y))
				{
					i = j;
					count++;
					dead = false;
					break;
				}
				else
				{
					dead = true;
					continue;
				}
			}*/
			//continue;
			//cout << "dead in" << endl;

		}
		fin:if (win)
			cout << count << endl;
		else if(dead)
			cout << "-1" << endl;
		else
			cout << count << endl;
		//cout << "end" << endl;

	}
}