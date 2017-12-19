#include<iostream>
#include<algorithm>
using namespace std;

int steps[10000];
int true_steps[10000];

int main()
{
	int num;
cin >> num;
		for (int k = 0; k < num; ++k)
		{
			int num_2;
			cin >> num_2;
			for (int j = 0; j < num_2; ++j)
			{
				cin >> steps[j];
				true_steps[j] = steps[j];
			}
			int max =-1, min = 0;
			//sort(true_steps, true_steps + num_2);
			/*for (int i = 0; i < num_2; ++i)
			{
				cout << true_steps[i];
			}
			cout << endl;*/
			for (int i = 0; i < num_2 ; ++i)
			{
				
				if (i+1 != true_steps[i])
				{
					min = i;
					break;
				}
			}
			for (int i = num_2-1 ; i >= 0; --i)
			{
				if (i+1 != true_steps[i])
				{
					max = i;
					break;
				}
			}

				cout << max - min + 1 << endl;
		}
	
}