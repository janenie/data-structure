#include <iostream>
#include <string>
#include <vector>

#define MAX_ 10000

using namespace std;

int father[MAX_];
int rank[MAX_]; //express the children node number with x
//basic disjoint set data structure

void make_set(int n) {
  for (int i = 0; i < n; i++) {
    father[i] = i; //initial the father itself
    rank[i] = 0;
  }
}

int find_set(int x) {
  if (x != father[x])
    father[x] = find_set(father[x]); //backtracking to compact the path
  return father[x];
}

void union_set(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) return; //already together
  if (rank[x] > rank[y]) {
    father[y] = x;
  } else {
    if (rank[x] == rank[y])
      rank[y]++;
    father[x] = y;
  }
}

int main() {
  return 0;
}