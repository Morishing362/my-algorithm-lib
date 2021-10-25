#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <map>
#include <stack>

#define N 1000

#define WHITE 0;
#define GRAY 1;
#define BLACK 2;

using namespace std;

int color[N];
int global_step = 0;
int discover_time[N];
int complete_time[N];
int G[N][N];
int child_index[N];

void dfs(int start)
{
	stack<int> dfs_stack;
	int cur = start;
	int next = start;

	for (int i = 0; i < N; i++)
	{
		color[i] = WHITE;
		child_index[i] = 0;
	}

	dfs_stack.push(cur);
	color[cur] = GRAY;
	discover_time[cur] = ++global_step;

	while (!dfs_stack.empty())
	{
		cur = dfs_stack.top();
		next = G[cur][child_index[cur]];

		if (next != NULL)
		{
			if (color[next] == 0)
			{
				dfs_stack.push(next);
				color[next] = GRAY;
				discover_time[next] = ++global_step;
			}
			child_index[cur]++;
		}
		else
		{
			dfs_stack.pop();
			color[cur] = BLACK;
			complete_time[cur] = ++global_step;
		}
	}
}

int main()
{
	int n;
	int node;
	int k;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> node >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> G[node][j];
		}
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
	{
		cout << i << " " << discover_time[i] << " " << complete_time[i] << endl;
	}

	return 0;
}
