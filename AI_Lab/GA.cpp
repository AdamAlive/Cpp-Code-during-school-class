#include<iostream>
#include<random>
#include<ctime>
#include<iomanip>
#include<algorithm>
using namespace std;

double random(double start, double end)
{
	
	return start + (end - start) * rand() / (RAND_MAX + 1);
}

double func(double x1, double x2, double x3, double x4)
{
	return abs(1 / (x1 * x1 + x2 * x2 + x3 * x3 + x4 * x4 + 1));
}

int main()
{
	srand(time(0));
	int n,t;
	cout << "请输入个体数量： ";
	//cin >> n;
	//cout << endl << "请输入个体选择次数： ";
	cin >> t;
	if (t / 2 * 2 != t)
	{
		t++;
		cout << "由于为了两两交配，您输入的个体数被添加了一个" << endl;
	}

	double P[20000][4];
	//double Per[9999];
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			P[i][j] = random(-5, 5);
		}
		
	}//初始化染色体

	double best[4] = {9999, 9999, 9999, 9999};
	int total = 0;
	do {
		double sum = 0;
		for (int i = 0; i < t; i++)
		{
			sum += func(P[i][0], P[i][1], P[i][2], P[i][3]);
			if (func(best[0], best[1], best[2], best[3]) < func(P[i][0], P[i][1], P[i][2], P[i][3]))
				for (int j = 0; j < 4; j++)
				{
					best[j] = P[i][j];
				}
		}

		
		//↓RWS步骤
		double m;
		double r;
		int choosen[20000];
		vector<double *>survive;
		//cout << "经过轮盘赌选择算法，剩下的个体有：" << endl;
		for (int j = 0; j < t; j++)
		{
			m = 0;
			r = random(0, 1);
			for (int i = 0; i < t; i++)
			{

				m += func(P[i][0], P[i][1], P[i][2], P[i][3]) / sum;
				if (r <= m)
				{
					choosen[j] = i;
					break;
				}
			}
			//cout << setw(10) << P[choosen[j]][0] << " " << setw(10) << P[choosen[j]][1] << " " << setw(10) << P[choosen[j]][2] << " " << setw(10) << P[choosen[j]][3] << endl;
			survive.push_back(P[choosen[j]]);
		}

		for (int i = 0; i < (int)(random(1, 100)); i++)
		{
			random_shuffle(survive.begin(), survive.end());
		}//打乱顺序

		for (int i = 0; i < t - 1; i = i + 2)
		{
			int num = (int)(random(0, 3));
			double temp;
			temp = survive[i][num];
			survive[i][num] = survive[i + 1][num];
			survive[i + 1][num] = temp;
		}//随机交换一组基因

		int cnum = 0;
		for (int i = 0; i < t - 1; i = i + 2)
		{
			for (int j = 0; i < 4; i++)
			{
				if (random(0, 1) < 0.1)//这里是突变率
				{
					survive[i][j] = random(-1, 1);
					cnum++;
				}
			}
		}
		//cout << "突变过程结束，突变了" << cnum << "个染色体。" << endl;
		for (int i = 0; i < t; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				P[i][j] = survive[i][j];
			}

		}

		total++;
		cout << setw(5) << total <<"代时最优解为： " << func(best[0], best[1], best[2], best[3]) << endl;
	} while (func(best[0], best[1], best[2], best[3]) < 0.9);

	cout << "经过了" << total << "代遗传进化，最后最符合条件的个体：" << endl;
	cout << setw(10) << best[0] << " " << setw(10) << best[1] << " " << setw(10) << best[2] << " " << setw(10) << best[3] << endl;
	cout << "此时它的解为： " << func(best[0], best[1], best[2], best[3]) << endl;
	/*int maked[9999][2];
	int makedlen = 0;
	for (int i = 0; i < t; i++)
	{
		for (int j = 1; j < t - 1; j++)
		{
			maked[makedlen][0] = choosen[i];
			maked[makedlen][1] = choosen[j];
		}
	}*/

	//cout << sizeof(choosen);
}