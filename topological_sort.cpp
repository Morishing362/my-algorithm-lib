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

static const int MAX = 100000;
const int INF = (1 << 18);

int N;                // number of isVisiteds
vector<int> G[MAX];   // graph (DAG)
bool isVisited[MAX];  // if the visited is visited or not
vector<int> out;      // result to output

int inDegree[MAX];  // indegree count at theisVisited

void bfs(int start) {
  queue<int> Q;
  Q.push(start);
  isVisited[start] = true;

  while (!Q.empty()) {
    int currentPosition = Q.front();
    Q.pop();
    out.push_back(currentPosition);
    for (int to : G[currentPosition]) {
      inDegree[to]--;
      if (isVisited[to] == false && inDegree[to] == 0) {
        isVisited[to] = true;
        Q.push(to);
      }
    }
  }
}

void topological_sort() {
  // initialize inDegree
  for (int i = 0; i < N; i++) inDegree[i] = 0;

  // calculate inDegree
  for (int i = 0; i < N; i++) {
    // vector<int> node = G[i];
    for (int to : G[i]) {
      inDegree[to]++;
    }
  }

  for (int i = 0; i < N; i++) {
    if (inDegree[i] == 0 && isVisited[i] == false) bfs(i);
  }

  for (int i = 0; i < out.size(); i++) cout << out[i] << endl;
}

int main(int argc, char const *argv[]) {
  int V, E;
  cin >> V >> E;
  N = V;

  int node, to;
  for (int i = 0; i < E; i++) {
    cin >> node >> to;
    G[node].push_back(to);
  }

  for (int i = 0; i < N; i++) isVisited[i] = false;

  topological_sort();

  return 0;
}
