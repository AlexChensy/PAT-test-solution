#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long a, b;
	cin >> a >> b;
	long c = a + b;
	int first, second, third;
	first = c / long(1e6);
	second = c % long(1e6) / long(1e3);
	third = c % long(1e3);
	if (first != 0)
	{
		cout << first << ',';
		second = abs(second);
		third = abs(third);
		if (second / 100 != 0)
			cout << second << ',';
		else if (second % 100 / 10 != 0)
			cout << '0' << second << ',';
		else cout << "00" << second << ',';

		if (third / 100 != 0)
			cout << third;
		else if (third % 100 / 10 != 0)
			cout << '0' << third;
		else cout << "00" << third;
	}
	else
	{
		if (second != 0)
		{
			cout << second << ',';
			third = abs(third);
			if (third / 100 != 0)
				cout << third;
			else if (third % 100 / 10 != 0)
				cout << '0' << third;
			else cout << "00" << third;
		}
		else
			cout << third;
	}
	return 0;
}