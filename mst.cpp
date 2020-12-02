// 2019054957_Lee Yongwoo_12838
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, pair<int, int> > > pq;
vector<pair<int, pair<int, int> > > answer;
int parent[1000];

int kruskal();
int find(int x);

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int i;
    for(i = 1; i <= N; i++) {
        parent[i] = i;
    }

    while(M--) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        pq.push(make_pair(-w, make_pair(-min(x, y), -max(x, y))));
    }

    int count = kruskal();
    printf("%d\n", count);

    for(i = 0; i < answer.size(); i++) {
        printf("%d %d %d\n", answer[i].second.first, answer[i].second.second, answer[i].first);
    }

    return 0;
}

int kruskal() {
    int x, y, w, result = 0;
    while(!pq.empty()) {
        w = -pq.top().first;
        x = -pq.top().second.first;
        y = -pq.top().second.second;
        pq.pop();

        int repX, repY;
        repX = find(x);
        repY = find(y);

        if(repX != repY) {
            parent[repX] = repY;
            result++;
            answer.push_back(make_pair(w, make_pair(x, y)));
        }
    }
    return result;
}

int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}