// 2019054957_Lee Yongwoo_12838
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> adjacencyList[1000];
bool visit[1000];

int dfs(int N);
void dfsAct(int start);

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int i;
    while(M--) {
        int x, y;
        scanf("%d %d", &x, &y);
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }
    
    printf("%d", dfs(N));
    return 0;
}

int dfs(int N) {
    int i;
    int componentNum = 0;

    for(i = 1; i <= N; i++) {
        if(!visit[i]) {
            dfsAct(i);
            componentNum++;
        }
    }
    return componentNum;
}

void dfsAct(int start) {
    int i;
    visit[start] = true;
    for(i = 0; i < adjacencyList[start].size(); i++) {
        if(!visit[adjacencyList[start][i]]) {
            dfsAct(adjacencyList[start][i]);
        }
    }
}