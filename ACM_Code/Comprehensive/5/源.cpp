#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int x[3];
int y[3];
//vector<int> xs;
//vector<int> ys;
int xs[2];
int ys[2];
int main()
{
	cin >> x[0] >> y[0]>>x[1]>>y[1]>>x[2]>>y[2];
	memset(xs, 0, sizeof(xs));
	memset(ys, 0, sizeof(ys));
	xs[0] = 1;
	ys[0] = 1;
	int not_x0;
	int not_y0;
	for (int i = 1; i < 3; i++)
	{
		if (x[i] == x[0])
			xs[0]++;
		else
		{
			xs[1]++;
			not_x0 = x[i];
		}
		if (y[i] == y[0])
		ys[0]++;
		else
		{
			ys[1]++;
			not_y0 = y[i];
		}
			
	}
	int answer_x, answer_y;
	if (xs[0] == 2)
		answer_x = not_x0;
	else
		answer_x = x[0];
	if (ys[0] == 2)
		answer_y = not_y0;
	else
		answer_y = y[0];

	cout << "The final location is (" << answer_x << "," << answer_y << ")!" << endl;
		//for (int i = 1; i < 3; i++)
		//{
		//	cin >> x[i] >> y[i];
		//}

		//int x_[2], y_[2];
		//int c1[2] = { -999, -999 }, c2[2] = { -999, -999 };
		//for (int i = 0; i < 2; i++)
		//{
		//	x_[0] = max(x[i], x[i + 1]);
		//	y_[0] = max(y[i], y[i + 1]);
		//	x_[1] = min(x[i], x[i + 1]);
		//	y_[1] = min(y[i], y[i + 1]);
		//}
		//for (int i = 0; i < 3; i++)
		//{
		//	if (x[i] == x_[0])
		//		c1[0]++;
		//	else
		//		c1[1]++;
		//	if (y[i] == y_[0])
		//		c2[0]++;
		//	else
		//		c2[1]++;
		//}
		//if (c1[0] > c1[1])
		//{
		//	cout << "The final location is (" << x_[1] << ",";
		//}
		//else
		//{
		//	cout << "The final location is (" << x_[0] << ",";
		//}
		//if (c2[0] > c1[1])
		//{
		//	cout << y_[1] << ")!" << endl;
		//}
		//else
		//{
		//	cout << y_[0] << ")!" << endl;
		//}
	

	//cin >> x[0];
}