#include<random>
#include<iostream>
#include<ctime>
using namespace std;


const int INPUT_NUM = 3;
const int LAY1_NUM = 2;
const int OUTPUT_NUM = 1;
const float EXPECTED_OPTPUT = 5;
const float LEARNING_RATE = 0.9;
const float ACCURACY_REQUEST = 0.1;

float w_layer1[INPUT_NUM][LAY1_NUM];
float w_layer2[LAY1_NUM][1];
float x[INPUT_NUM];
float layer_1[LAY1_NUM] = { 0, 0 };
float layer_1_bias[LAY1_NUM] = {-0.4, 0.2};
float y[OUTPUT_NUM] = { 0 };
float y_bias[OUTPUT_NUM] = { 0.1 };



float error_cal_out(float a)
{
	return a * (1 - a) * (EXPECTED_OPTPUT - a);
}

float error_cal_layer(float a, float b, float c)//a,b,c�ֱ���layer�ڵ������ֵ�������������layer�ڵ��Ȩ��
{
	return a * (1 - a) * b * c;
}

float func(float x)
{
	return 1 / (1 + exp(-x));
}

int random(int a, int b)
{
	if (b <= a)
	{
		cout << "�����Χ����" << endl;
		return a;
	}
	return a + rand() % (b - a);
}

float random_f(int a, int b)//���ɲ�Ϊ0�����������
{
	if (b <= a)
	{
		cout << "�����Χ����" << endl;
		return a;
	}
	rand:float re = a + rand() % (b - a) + float(rand() % 101) / 101;
	if (re != 0)
		return re;
	else
		goto rand;
}

int main()
{
	//////�����������
	//for(int i = 0;i < 100; i++)
	//cout << random_f(-1, 1) << endl;

	cout << "������" << INPUT_NUM << "���������" << endl;

	float err_out = 0;
	float err_layer1[LAY1_NUM] = {0, 0};

	for (int i = 0; i < INPUT_NUM; i++)//��ʼ����һ��Ȩ��
	{
		for (int j = 0; j < LAY1_NUM; j++)
		{
			w_layer1[i][j] = random_f(-1, 1);
		}
	}

	for (int i = 0; i < LAY1_NUM; i++)//��ʼ���ڶ���Ȩ��
	{
		for (int j = 0; j < OUTPUT_NUM; j++)
		{
			w_layer2[i][j] = random_f(-1, 1);
		}
	}

	for (int i = 0; i < INPUT_NUM; i++)
	{
		cin >> x[i];
	}

	//ѭ������
	do
	{


	for (int j = 0; j < LAY1_NUM; j++)
	{
		for (int i = 0; i < INPUT_NUM; i++)
		{
			layer_1[j] = x[i] * w_layer1[i][j] ;
		}
		layer_1[j] += layer_1_bias[j];
	}

	for (int j = 0; j < OUTPUT_NUM; j++)
	{
		for (int i = 0; i < LAY1_NUM; i++)
		{
			y[j] = layer_1[i] * w_layer2[i][j] ;
		}
		y[j] += y_bias[j];
	}

	

		//cout << layer_1[0] << " " << layer_1[1] << endl;
		//cout << y[0] << endl;

		err_out = error_cal_out(func(y[0]));
		for (int i = 0; i < LAY1_NUM; i++)
		{
			err_layer1[i] = error_cal_layer(func(layer_1[i]), err_out, w_layer1[i][0]);
		}



		for (int i = 0; i < LAY1_NUM; i++)//���¼���ڶ���Ȩ��
		{
			for (int j = 0; j < OUTPUT_NUM; j++)
			{
				w_layer2[i][j] = w_layer2[i][j] + LEARNING_RATE * func(layer_1[i]) * err_out;
			}
		}

		for (int i = 0; i < INPUT_NUM; i++)//���¼����һ��Ȩ��
		{
			for (int j = 0; j < LAY1_NUM; j++)
			{
				w_layer1[i][j] = w_layer1[i][j] + LEARNING_RATE * x[i] * err_layer1[j];
			}
		}

		for (int i = 0; i < OUTPUT_NUM; i++)//���¼���������bias
		{
			y_bias[i] = y_bias[i] + LEARNING_RATE * err_out;
		}

		for (int i = 0; i < LAY1_NUM; i++)//���¼������ز��bias
		{
			layer_1_bias[i] = layer_1_bias[i] + LEARNING_RATE * err_layer1[i];
		}

	} while (!(y[0] > EXPECTED_OPTPUT - ACCURACY_REQUEST & y[0] < EXPECTED_OPTPUT + ACCURACY_REQUEST));

	cout << "������Ȩ�ص������" << endl;
	cout << "����������ز�Ȩ��Ϊ��" << endl;
	for (int j = 0; j < LAY1_NUM; j++)
	{
		for (int i = 0; i < INPUT_NUM; i++)
		{
			cout << w_layer1[i][j] << " ";
		}
		cout << "bias: " << layer_1_bias[j] << endl;
	}

	cout << "���ز��������Ȩ�غ�biasΪ��" << endl;
	for (int i = 0; i < LAY1_NUM; i++)
	{
		cout << w_layer2[i][0] << " ";
	}
	cout << "bias: " << y_bias[0] << endl;
	cout << "����Ԥ����Ϊ�� " << y[0] << endl;



}