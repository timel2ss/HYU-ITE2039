// 2019054957_Lee Yongwoo_12838
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adjacencyList[1000];
int visit[1000];
int topo[1000];

void dfs(int N);
void dfsAct(int start, int N);

int j;
bool flag = true;

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int i;
    while(M--) {
        int x, y;
        scanf("%d %d", &x, &y);
        adjacencyList[x].push_back(y);
    }

    dfs(N);

    printf("%d\n", flag);

    if(flag) {
        for(i = 0; i < N; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}

void dfs(int N) {
    int i;
    for(i = 1; i <= N; i++) {
        sort(adjacencyList[i].begin(), adjacencyList[i].end());
    }

    for(i = 1; i <= N; i++) {
        if(!visit[i]) {
            dfsAct(i, N);
        }
    }
}

void dfsAct(int v, int N) {
    int i;
    visit[v] = 1;

    for(i = 0; i < adjacencyList[v].size(); i++) {
        if(!visit[adjacencyList[v][i]]) {
            dfsAct(adjacencyList[v][i], N);
        }
        else if(visit[adjacencyList[v][i]] == 1) {
            flag = false;
        }
    }
    topo[N - ++j] = v;
    visit[v] = 2;
}