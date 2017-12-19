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
	cout << "��������������� ";
	//cin >> n;
	//cout << endl << "���������ѡ������� ";
	cin >> t;
	if (t / 2 * 2 != t)
	{
		t++;
		cout << "����Ϊ���������䣬������ĸ������������һ��" << endl;
	}

	double P[20000][4];
	//double Per[9999];
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			P[i][j] = random(-5, 5);
		}
		
	}//��ʼ��Ⱦɫ��

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

		
		//��RWS����
		double m;
		double r;
		int choosen[20000];
		vector<double *>survive;
		//cout << "�������̶�ѡ���㷨��ʣ�µĸ����У�" << endl;
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
		}//����˳��

		for (int i = 0; i < t - 1; i = i + 2)
		{
			int num = (int)(random(0, 3));
			double temp;
			temp = survive[i][num];
			survive[i][num] = survive[i + 1][num];
			survive[i + 1][num] = temp;
		}//�������һ�����

		int cnum = 0;
		for (int i = 0; i < t - 1; i = i + 2)
		{
			for (int j = 0; i < 4; i++)
			{
				if (random(0, 1) < 0.1)//������ͻ����
				{
					survive[i][j] = random(-1, 1);
					cnum++;
				}
			}
		}
		//cout << "ͻ����̽�����ͻ����" << cnum << "��Ⱦɫ�塣" << endl;
		for (int i = 0; i < t; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				P[i][j] = survive[i][j];
			}

		}

		total++;
		cout << setw(5) << total <<"��ʱ���Ž�Ϊ�� " << func(best[0], best[1], best[2], best[3]) << endl;
	} while (func(best[0], best[1], best[2], best[3]) < 0.9);

	cout << "������" << total << "���Ŵ��������������������ĸ��壺" << endl;
	cout << setw(10) << best[0] << " " << setw(10) << best[1] << " " << setw(10) << best[2] << " " << setw(10) << best[3] << endl;
	cout << "��ʱ���Ľ�Ϊ�� " << func(best[0], best[1], best[2], best[3]) << endl;
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