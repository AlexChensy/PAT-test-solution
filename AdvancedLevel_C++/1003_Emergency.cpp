#include <iostream>
const int Size = 510;
const int Inf = 999999;
using namespace std;
int findmin_dist(int u[], int flag[], int num)
{


	int a = -1, minn = Inf;
	for (int j = 0; j < num; j++)
	{
		if (flag[j] != 0 && u[j] < minn)
		{
			a = j;
			minn = u[j];
		}
	}
	return a;
}


int main()
{
	int road[Size][Size]; int dist[Size]; int rescteam[Size]; int total_resc[Size]; int pathnum[Size]; int visit[Size];
	int citynum, roadnum, city_current, city_target;
	scanf("%i %i %i %i", &citynum, &roadnum, &city_current, &city_target);
	cin.get();

	//initiation
	dist[city_current] = 0;
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
		{
			if (i != city_current)
			{
				dist[i] = Inf;
			}
			visit[i] = 1;
			road[i][j] = Inf;
			rescteam[i] = 0;
			total_resc[i] = 0;
			pathnum[i] = 1;
		}
	for (int i = 0; i < citynum; i++)//read rescureteam
		cin >> rescteam[i];
	total_resc[city_current] = rescteam[city_current];
	for (int i = 0; i < roadnum; i++)//read every road
	{
		int a, b, c;
		cin >> a; cin >> b;
		cin >> c;
		road[a][b] = road[b][a] = c;
	}

	//

	int u;
	while ((u = findmin_dist(dist, visit, citynum)) != -1)
	{
		visit[u] = 0;
		if (u == city_target)
			break;
		for (int i = 0; i < citynum; i++)
		{
			if (visit[i] != 0 && road[u][i] != Inf)
			{
				int altd = dist[u] + road[u][i];
				int altr = total_resc[u] + rescteam[i];
				if (altd < dist[i])
				{
					dist[i] = altd;
					total_resc[i] = altr;
					pathnum[i] = pathnum[u];
				}
				else if (altd == dist[i])
				{
					pathnum[i] += pathnum[u];
					if (altr > total_resc[i])
						total_resc[i] = altr;
				}

			}
		}
	}
	cout << pathnum[city_target] << ' ' << total_resc[city_target];
	return 0;
}