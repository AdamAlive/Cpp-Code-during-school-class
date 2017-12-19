#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<cmath>
using namespace std;

//int flow[201][201];

const int MAX_V = 200;

struct edge
{
	int to, cap, rev;
};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap)
{
	G[from].push_back(edge{ to, cap, (int)G[to].size() });
	G[to].push_back(edge{ from, 0, (int)G[from].size() - 1});
}

int dfs(int v, int t, int f)
{
	if (v == t)
		return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0)
		{
			int d = dfs(e.to, t, min(f, e.cap));
			
			if (d > 0)
			{
				e.cap -= d;
				//cout << "e.cap: " << e.cap << endl;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	int flow = 0;
	for (;;)
	{
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, 2147483647);
		if (f == 0) return flow;
		flow += f;
	}
}

int main()
{
	//cout << INFINITY << endl;
	int N, M;
	while (cin >> N >> M)
	{
		int from, to, cap;
		for (int i = 0; i < N; i++)
		{
			cin >> from>>to>> cap;
			add_edge(from-1, to-1, cap);
		}
		cout << max_flow(0, M-1) << endl;
	}
}

//#include<iostream>
//using namespace std;
//
//class myClass
//{
//public :
//	myClass(int i) {}
//};
//
//int main()
//{
//	myClass m(1);
//	myClass ma[3] = { 1,1,1 };
//}