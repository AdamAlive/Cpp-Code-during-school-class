#include<list>
#include<string>
#include<iostream>
using namespace std;

list<int> LISTINT;

void insertList(int a)
{
	LISTINT.push_back(a);
}

void show()
{
	list<int>::iterator i;
	for (i = LISTINT.begin(); i != LISTINT.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void rshow()
{
	list<int>::reverse_iterator i;
	for (i = LISTINT.rbegin(); i != LISTINT.rend(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void deleteList(int a)
{
	list<int>::iterator i;
	for (i = LISTINT.begin(); i != LISTINT.end(); )
	{
		if (*i == a)
		{
			if (i== LISTINT.end())
				LISTINT.erase(i--);
			else
				LISTINT.erase(i++);
		}
		else
		{
			i++;
		}
	}
}

int main()
{
	string order;
	int num;
	int insertnum;
	for (; order != "END";)
	{
		cin >> order;
		if (order == "insert")
		{
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				cin >> insertnum;
				insertList(insertnum);
			}
		}
		else if (order == "delete")
		{
			cin >> num;
			deleteList(num);
		}
		else if (order == "show")
		{
			show();
		}
		else if (order == "rshow")
		{
			rshow();
		}
	}
}