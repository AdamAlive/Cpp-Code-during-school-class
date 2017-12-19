#include<iostream>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;

struct Man
{
	int AT, OT, rAT;
	string name;
	bool hasDone;
};
vector<Man*> tellers;
vector<Man> Peo;
vector<Man*> waitings;


bool allWorkDone()
{
	bool res = true;
	for (int i = 0; i < Peo.size(); i++)
	{
		if (!Peo[i].hasDone)
			res = false;
	}
	return res;
}

bool allTellersClear()
{
	bool res = true;
	for (int i = 0; i < tellers.size(); i++)
	{
		if (tellers[i] != NULL)
			res = false;
	}
	return res;
}

bool allTellersFull()
{
	bool res = true;
	for (int i = 0; i < tellers.size(); i++)
	{
		if (tellers[i] == NULL)
			res = false;
	}
	return res;
}

bool notInWaitings(Man *a)
{
	bool res = true;
	//cout << a << endl;
	for (int i = 0; i < waitings.size(); i++)
	{
		if (a == waitings[i])
			res = false;
	}
	return res;
}

bool alMostDone(int count)
{
	bool res = true;
	for (int i = 0; i < tellers.size(); i++)
	{
		if (tellers[i] != NULL)
		{
			if (tellers[i]->OT + tellers[i]->rAT > count)
				res = false;
		}
	}
	res = (waitings.empty() && res);
	return res;
}

int main()
{
	/*Man temp;*/
	
	//Peo.push_back(temp);
	//cout << &Peo[0] << endl;
	//waitings.push_back(&Peo[0]);
	//cout << waitings[0] << endl;
	//cout << notInWaitings(&Peo[0]) << endl;


	int teller_num;
	cin >> teller_num;
	Man tempMan; 
	for (int i = 0; i < teller_num; i++)
		tellers.push_back(NULL);
	//tempMan.AT = 10;
	//tempMan.OT = 10;
	//tempMan.name = "NULL";
	//for(int i = 0;i < 10;i++)
	//	waitings.push(tempMan);
	//int AT, OT;
	//string name;
	for (;;)
	{
		cin >> tempMan.AT;
		if (tempMan.AT == -1)
			break;
		cin >> tempMan.name >> tempMan.OT;
		tempMan.hasDone = false;
		Peo.push_back(tempMan);
	}
	for (int count = 1; !(allWorkDone()&&allTellersClear()); count++)
	{
		//更新tellers至空的
		for (int i = 0; i < tellers.size(); i++)
		{
			if (tellers[i] != NULL && tellers[i]->OT + tellers[i]->rAT <= count)
				tellers[i] = NULL;
		}

		//将可以进入tellers的加入tellers
		if (!waitings.empty())
		{
			while (!waitings.empty() && !allTellersFull())
			{
				if (waitings.front()->AT <= count )
				{
					bool beAccepted = false;
					for (int i = 0; i < tellers.size(); i++)
					{
						if (tellers[i] == NULL)
						{
							tellers[i] = waitings.front();
							tellers[i]->rAT = count;
							waitings.front()->hasDone = true;
							beAccepted = true;
							break;
						}
					}
					if (beAccepted)
						waitings.erase(waitings.begin());
				}
			}

			//查找有没有人能被推进waitings
			for (int j = 0; j < Peo.size(); j++)
			{
				if (!Peo[j].hasDone&&Peo[j].AT <= count && notInWaitings(&Peo[j]))
				{
					waitings.push_back(&Peo[j]);
				}
			}
		}
		else
		{
			//查找有没有人能去teller或者被推进waitings
			for (int j = 0; j < Peo.size(); j++)
			{
				if (!Peo[j].hasDone&&Peo[j].AT <= count)
				{

					bool beAccepted = false;
					for (int i = 0; i < tellers.size(); i++)
					{
						if (tellers[i] == NULL)
						{
							tellers[i] = &Peo[j];
							tellers[i]->rAT = count;
							Peo[j].hasDone = true;
							beAccepted = true;
							break;
						}
					}
					if (!beAccepted)
						waitings.push_back(&Peo[j]);
				}
			}
		}
		//cout <<endl<< tellers.size() << endl;
		if (!(allWorkDone()&&allTellersClear()))
		{
			//cout << allWorkDone() << endl;
			cout << count << ":" << endl;
			for (int i = 0; i < tellers.size(); i++)
			{
				cout << "Teller" << i + 1 << ":" << (tellers[i] == NULL ? " NULL" : " " + tellers[i]->name) << endl;
			}
			cout << "Waiting:";
			if (waitings.empty())
			{
				cout << " NULL";
			}
			else
			{
				for (int i = 0; i < waitings.size(); i++)
				{
					cout << " " << waitings[i]->name;
				}
			}
			cout << endl << endl;
		}
		//queue<Man>tempWaitings = waitings.;
		//for (int i = 0; i < waitings.size(); i++)
		//{
		//	cout << waitings << " ";
		//}
		
	}
	system("pause");
}