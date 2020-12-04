// 2019054957_Lee Yongwoo_12838
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > adjacencyList[5001];
priority_queue<pair<int,  int> > pq;
int dist[5001];

void dijkstra(int start);

int N, M;

int main(void) {
    scanf("%d %d", &N, &M);

    while(M--) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        adjacencyList[x].push_back(make_pair(y, w));
    }

    dijkstra(1);
    
    int i, max = dist[1];
    for(i = 1; i < N; i++) {
        if(max < dist[i]) {
            max = dist[i];
        }
    }
    printf("%d", max);
    return 0;
}

void dijkstra(int start) {
    int i;
    for(i = 2; i < N; i++) {
        dist[i] = ~(1 << 31);
    }

    dist[start] = 0;
    pq.push(make_pair(0, start));
    
    while(!pq.empty()) {
        int currentDistance = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if(dist[v] < currentDistance) {
            continue;
        }

        for(i = 0; i < adjacencyList[v].size(); i++) {
            int destination = adjacencyList[v][i].first;
            int w = adjacencyList[v][i].second;

            int newDistance = currentDistance + w;
            if(dist[destination] > newDistance) {
                dist[destination] = newDistance;
                pq.push(make_pair(-newDistance, destination));
            }
        }
    }
}