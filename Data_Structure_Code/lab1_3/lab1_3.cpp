#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct man
{
	string name, ID;
	int sub1, sub2, sub3;
}man;

bool comparison(man a, man b)
{
	if (a.sub1 + a.sub2 + a.sub3 != b.sub1 + b.sub2 + b.sub3)
		return (a.sub1 + a.sub2 + a.sub3) > (b.sub1 + b.sub2 + b.sub3);
	else
	{
		return atoi(a.ID.c_str()) < atoi(b.ID.c_str());
	}
}

int main()
{
	int t;
	//string name, ID;
	//int sub1, sub2, sub3;
	cin >> t;
	man tempMan;
	vector<man> mans;
	for (int i = 0; i < t; i++)
	{
		cin >> tempMan.name >> tempMan.ID >> tempMan.sub1 >> tempMan.sub2 >> tempMan.sub3;
		mans.push_back(tempMan);
	}
	sort(mans.begin(), mans.end(), comparison);
	for (int i = 0; i < t; i++)
	{
		cout << mans[i].name << " " << mans[i].ID << " " << mans[i].sub1 << " " << mans[i].sub2 << " " << mans[i].sub3 << endl;
	}
	system("pause");
}