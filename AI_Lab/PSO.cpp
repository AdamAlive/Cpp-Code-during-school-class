#include<iostream>
#include<random>
#include<ctime>
#include<vector>
#include<iomanip>
using namespace std;

double func(double x1, double x2)
{
	return (abs(x1 * (x1 + 0.7) + x2 * x2 * (x2 - 0.8)));
}

double random(double start, double end)
{
	return start + (end - start)*rand() / (RAND_MAX + 1.0);
}

int main()
{
	srand(time(0));
	int n,m;
	double ac;
	cout << "��������Ⱥ������ " ;
	cin >> n;
	//cout << "��������������� " ;
	//cin >> m;
	cout << "�����뾫ȷ�ȣ���0.01���� ";
	cin>>ac;
	srand(int(time(0)));
	vector<vector<double>>P;
	vector<vector<double>>V;
	vector<double>tempP;
	vector<double>tempV;
	for (int i = 0; i < n; i++)
	{
		
		
		for (int j = 0; j < 2; j++)
		{
			
			tempP.push_back(random(-10, 10));
			tempV.push_back(random(-3, 3));
			//P[i][j] = int(random(-10, 10));
		}
		P.push_back(tempP);
		V.push_back(tempV);
		cout << "���λ�ã�" << setw(8) << P[i][0] << " " << setw(8) << P[i][1] ;
		cout << "   ����ٶȣ�" << setw(8) << V[i][0] << " " << setw(8) << V[i][1] << endl;
		tempP.clear();
		tempV.clear();
	}
	//����ʼ������ٶȺ�λ��
	double gBest[2] = { 9999, 9999 };
	double pBest[9999][2];
	for (int i = 0; i < 9999; i++)
	{
		pBest[i][0] = pBest[i][1] = 9999;
	}

	double w = random(0.4, 0.8);
	double c1 = 2.0;
	double c2 = 2.0;


	int t = 0;
	//for (int j = 0; j < m; j++)
	do{
		t++;
		//cout << "��" << j << "�ε�����" << endl;
		for (int i = 0; i < n; i++)
		{
			if (func(P[i][0], P[i][1]) < func(pBest[i][0], pBest[i][0]))
			{
				pBest[i][0] = P[i][0];
				pBest[i][1] = P[i][1];
			}//�������ӵ���ʷ���Ž�

			if (func(P[i][0], P[i][1]) < func(gBest[0], gBest[1]))
			{
				gBest[0] = pBest[i][0];
				gBest[1] = pBest[i][1];
			}//����ȫ�����Ž�
			double r1 = random(0, 1);
			double r2 = random(0, 1);
			V[i][0] = w * V[i][0] + c1 * r1 * (pBest[i][0] - P[i][0]) + c2 * r2 * (gBest[0] - P[i][0]);
			V[i][1] = w * V[i][1] + c1 * r1 * (pBest[i][1] - P[i][1]) + c2 * r2 * (gBest[1] - P[i][1]);
			P[i][0] = ((P[i][0] + V[i][0] <= 10 ? P[i][0] + V[i][0]:10) <= -10? -10: P[i][0] + V[i][0]);
			P[i][1] = ((P[i][1] + V[i][1] <= 10 ? P[i][1] + V[i][1] : 10) <= -10 ? -10 : P[i][1] + V[i][1]);
			//P[i][0] = P[i][0] + V[i][0];
			//P[i][1] = P[i][1] + V[i][1];

			if (func(P[i][0], P[i][1]) < func(pBest[i][0], pBest[i][0]))
			{
				pBest[i][0] = P[i][0];
				pBest[i][1] = P[i][1];
			}//�������ӵ���ʷ���Ž�

			if (func(P[i][0], P[i][1]) < func(gBest[0], gBest[1]))
			{
				gBest[0] = pBest[i][0];
				gBest[1] = pBest[i][1];
			}//����ȫ�����Ž�
			//cout << "���λ�ã�" << setw(8) << P[i][0] << " " << setw(8) << P[i][1];
			//cout << "   ����ٶȣ�" << setw(8) << V[i][0] << " " << setw(8) << V[i][1] << endl;
		}
		
	} while (abs(func(gBest[0], gBest[1])) > ac);

	cout << "����" << t << "�ε�����... ..." << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "���λ�ã�" << setw(8) << P[i][0] << " " << setw(8) << P[i][1];
		cout << "   ����ٶȣ�" << setw(8) << V[i][0] << " " << setw(8) << V[i][1] << endl;
	}
	cout << "ȫ�����ŵ�Ϊ�� " << setw(8) << gBest[0] << " " << setw(8) << gBest[1] <<endl;
	

}