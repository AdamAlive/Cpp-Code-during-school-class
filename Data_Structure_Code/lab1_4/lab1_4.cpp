#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char sen[500];
int counts[26];
int main()
{
	memset(counts, 0, sizeof(counts));
	//string sen;
	cin.getline(sen, 500);
	char *p = sen;
	for (int i = 0; i < sizeof(sen); i++)
	{
		if (65 <= int(*p) && int(*p) <= 90)
		{
			counts[int(*p) - 65]++;
		}
		else if (97 <= int(*p) && int(*p) <= 122)
		{
			counts[int(*p) - 97]++;
		}
		p++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (counts[i] > 0)
		{
			cout << char(i + 65) << " " << counts[i] << endl;
		}
	}
	//cout << sen << endl;
	system("pause");
}