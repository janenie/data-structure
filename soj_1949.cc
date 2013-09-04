#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAX_ 100010

using namespace std;

int father[MAX_];
int rank[MAX_];
int _max[MAX_][20];
int _min[MAX_][20];
bool flag;
int n;

void RMQ() {
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      _max[i][j] = max(_max[i][j-1], _max[i + (1 << (j-1))][j-1]);
      _min[i][j] = min(_min[i][j-1], _min[i + (1 << (j-1))][j-1]);
    }
  }
}

//nonrecursive
int find_set(int x) {
  int temp = x;
  while (x != father[x])
    x = father[x];
  father[temp] = x;
  return x;
}

void union_set(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) return;
  father[x] = y;
}

int find_max(int st, int ed) {
  int k = (int)(log((double)(ed - st + 1))/log(2.0));
  return max(_max[st][k], _max[ed - (1 << k) + 1][k]);
}

int find_min(int st, int ed) {
  int k = (int)(log((double)(ed - st + 1))/log(2.0));
  return min(_min[st][k], _min[ed - (1 << k) + 1][k]);
}

int main() {
  int edge_num, query_num;
  int case_num = 1;
  int st, ed;
  int u, v;
  bool first = 1;
  while (scanf("%d", &n) != EOF) {
    if (!first) printf("\n");
    first = 0;
    printf("Case %d\n", case_num++);
    for (int i = 1; i <= n; i++) {
      father[i] = i;
      scanf("%d", &_max[i][0]);
      _min[i][0] = _max[i][0];
    }
    RMQ();
    scanf("%d", &query_num);
    while (query_num--) {
      scanf("%d%d", &st, &ed);
      u = find_min(st, ed);
      v = find_max(st, ed);
      union_set(u, v);
    }
    scanf("%d", &query_num);
    while (query_num--) {
      scanf("%d%d", &st, &ed);
      if (find_set(st) == find_set(ed))
        printf("query num is %d YES\n", query_num);
      else printf("query num is %d NO\n", query_num);
    }
  }
  return 0;
}