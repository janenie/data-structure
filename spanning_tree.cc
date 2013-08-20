#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int graph[100][100];
bool visit[100];
int disdant[100];
int neighbor[100];
int ans;
void prim(int n) {
  ans = 0;
  int min = -1;
  int source = 0;
  for (int i = 0; i < n; i++) {
    visit[i] = false;
    disdant[i] = graph[source][i];
    neighbor[i] = source;
  }
  disdant[source] = 0;
  visit[source] = true;
  for (int i = 1; i < n; i++) {
    int min_node, min;
    min = -1;
    for (int j = 0; j < n; j++) {
      if (!visit[j] && disdant[j] != -1) {
       if (min == -1 || min > disdant[j]) {
        min = disdant[j];
        min_node = j;
       }
      } 
    }
    if (min != -1) {
      visit[min_node] = true;
      ans += disdant[min_node];
      //cout << min_node << " ";
      for (int j = 0; j < n; j++) {
        if (!visit[j] && graph[min_node][j] != -1) {
          if (disdant[j] == -1 || disdant[j] > graph[min_node][j]) {
            disdant[j] = graph[min_node][j];
            neighbor[j] = min_node;
          }
        }
      }
    }
  }
}

int main() {
  int row, length, start, end;
  cout << "please enter the node number" << endl;
  cin >> row;
  memset(graph, -1, sizeof(graph));
  
  cout << "please endter the edge, -1 to terminate" << endl;
  while (cin >> start && start != -1) {
    cin >> end >> length;
    graph[start][end] = length;
    graph[end][start] = length;
  }
  prim(row);
  
  cout << ans << endl;
  return 0;
}