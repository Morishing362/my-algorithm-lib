#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define MAX 10000
#define INF 200000

#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[MAX];
int Weight[MAX][MAX];
int dist[MAX];
int p[MAX];

void dijkstra(int s, int n) {
  for (int i = 0; i < MAX; i++) {
    color[i] = WHITE;
    dist[i] = INF;
  }

  dist[s] = 0;
  color[s] = GRAY;

  while (true) {
    int min_cost = INF;
    int u = -1;

    for (int i = 0; i < n; i++) {
      if (color[i] != BLACK && dist[i] < min_cost) {
        min_cost = dist[i];
        u = i;
      }
    }

    if (u == -1) {
      break;
    }

    color[u] = BLACK;

    for (int v = 0; v < n; v++) {
      // visit v that has path from parent u and has not been visited
      if (color[v] != BLACK && Weight[u][v] != INF) {
        // set new v distance and paint v with GRAY
        if (dist[u] + Weight[u][v] < dist[v]) {
          dist[v] = dist[u] + Weight[u][v];
          color[v] = GRAY;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << dist[i] << endl;
  }
}

int main() {
  int n;
  cin >> n;

  int u, k, v, c;

  // initialize weight of graph
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      Weight[i][j] = INF;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int i = 0; i < k; i++) {
      cin >> v >> c;
      Weight[u][v] = c;
    }
  }
  dijkstra(0, n);
}
