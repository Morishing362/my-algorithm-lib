#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

static const int MAX = 1000000;
const int INF = (1 << 18);

int N;
int A[MAX], B[MAX];

vector<int> G[MAX];
int dist[MAX];
int maxDist = 0;
int maxDistIndex = 0;

void bfs(int start) {
  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
  }

  queue<int> Q;
  Q.push(start);
  dist[start] = 0;

  while (!Q.empty()) {
    int currentPosition = Q.front();
    Q.pop();
    for (int to : G[currentPosition]) {
      if (dist[to] == INF) {
        dist[to] = dist[currentPosition] + 1;
        Q.push(to);
      }
    }
  }
}

int main() {
  cin >> N;

  for (int i = 1; i < N; i++) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  bfs(1);

  for (int i = 1; i <= N; i++) {
    if (maxDist < dist[i]) {
      maxDist = dist[i];
      maxDistIndex = i;
    }
  }

  bfs(maxDistIndex);

  maxDist = 0;

  for (int i = 1; i < N; i++) {
    if (maxDist < dist[i]) {
      maxDist = dist[i];
    }
  }

  cout << maxDist + 1 << endl;

  return 0;
}