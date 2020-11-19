// 2019054957_Lee Yongwoo_12838
#include <stdio.h>

int main(void) {
    int N, M, K, i, j, key, sum;
    scanf("%d %d %d", &N, &M, &K);

    int A[100001];
    int B[100001];
    int count[100001];

    for(i = 1; i <= K; i++) {
        scanf("%d %d", &A[i], &B[i]);
    }

    for(i = 1; i <= N; i++) {
        scanf("%d", &key);
        count[key]++;
    }
    
    for(i = 1; i <= M; i++) {
        count[i] += count[i - 1];
    }

    for(i = 1; i <= K; i++) {
        printf("%d\n", count[B[i]] - count[A[i] - 1]);
    }
    return 0;
}