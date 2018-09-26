#include <iostream>
const int pair = 2;
double coefficient(double(*input)[pair], int total_k, int match_k);
double max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}
using std::cin;
using std::cout;

int main()
{
	int ka, kb;
	cin >> ka;//read a
	double(*pa)[pair] = new double[ka][pair];
	for (int i = 0; i < ka; i++)
		for (int j = 0; j < pair; j++)
		{
			cin >> pa[i][j];
		}
	cin >> kb;//read b
	double(*pb)[pair] = new double[kb][pair];
	for (int i = 0; i < kb; i++)
		for (int j = 0; j < pair; j++)
		{
			cin >> pb[i][j];
		}
	//output
	int match = 0;
	int zeropol = 0;
	int maxexp = int(max(pa[0][0], pb[0][0]));
	double sum = 0;
	for (int i = 0; i < maxexp + 1; i++)//loop for N1+1 times find match
	{
		if (coefficient(pa, ka, maxexp - i) != 0 && coefficient(pb, kb, maxexp - i) != 0)//重复项和零和项
		{
			match++;
			if (0 == (coefficient(pa, ka, maxexp - i) + coefficient(pb, kb, maxexp - i)))
				zeropol++;
		}
	}
	cout << ka + kb - match - zeropol;
	for (int i = 0; i < maxexp + 1; i++)//loop for N1+1 times find match
	{
		if ((sum = coefficient(pa, ka, maxexp - i) + coefficient(pb, kb, maxexp - i)) != 0)
		{
			cout << ' ';
			cout << maxexp - i << ' ';
			cout << std::fixed;//set_point
			cout.precision(1);
			cout << sum;
		}
	}
	return 0;
}
double coefficient(double(*input)[pair], int total_k, int match_k)
{
	for (int i = 0; i < total_k; i++)
	{
		if (int(input[i][0]) == match_k)
			return input[i][1];
	}
	return 0;
}