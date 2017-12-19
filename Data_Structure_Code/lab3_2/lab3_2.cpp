#include<list>
#include<iostream>
#include<vector>
using namespace std;

vector<bool>people;

bool if_empty()
{
	bool res = true;
	for (int i = 0; i < people.size(); i++)
	{
		if (people[i])
			res = false;
	}
	return res;
}

int main()
{
	int num, count;
	cin >> count >> num;
	for (int i = 0; i < num; i++)
		people.push_back(true);
	vector<bool>::iterator ptr = people.begin();
	//for (int i = 0;;)
	//{
	//	cout << *ptr << endl;
	//			if (ptr == --people.end())
	//			{
	//				ptr = people.begin();
	//			}
	//			else
	//			{
	//				ptr++;
	//			}
	//}
	for (int i = 1; !if_empty(); )
	{
		//cout << i << endl;
		if (*ptr == 1 && i%count == 0)
		{
			cout << ptr - people.begin() + 1 << " ";
			*ptr = 0;


			i++;
			if (ptr == --people.end())
			{
				ptr = people.begin();
			}
			else
			{
				ptr++;
			}
		}
		else if (*ptr == 1)
		{
			i++;
			if (ptr == --people.end())
			{
				ptr = people.begin();
			}
			else
			{
				ptr++;
			}
		}
		else if (*ptr == 0)
		{
			if (ptr == --people.end())
			{
				ptr = people.begin();
			}
			else
			{
				ptr++;
			}
		}
	}
	system("pause");
}