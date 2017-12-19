#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
ll a, b, c, d;
ll times, temp;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

ll mcn(ll a, ll b)
{
	return  a * b / gcd(a, b);
}

int main()
{
	//cin >> times;
	times = 0;
	while (true)
	{
		cin >> a >> b >> c >> d;
		if (a == -1 && b == -1 && c == -1 && d == -1)
			break;
		ll n = (5544 * a + 14421 * b + 1288 * c) % mcn(mcn(23, 28), 33);
		ll ans;
		if (n > d)
			ans = n - d;
		else
			ans = 21252 + n - d;
		times++;
		cout << "Case " << times << ": the next triple peak occurs in " << ans << " days." << endl;
	}
	//cout << endl;
	system("pause");
}