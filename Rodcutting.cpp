// 2019054957_Lee Yongwoo_12838
#include <stdio.h>

int main(void) {
    int N, i, j, max;
    int prices[101];
    int revenue[101];
    int cutting[101];
    revenue[0] = 0;

    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &prices[i]);
    }

    for(i = 1; i <= N; i++) {
        max = -1;
        for(j = 1; j <= i; j++) {
            if(max < prices[j] + revenue[i - j]) {
                max = prices[j] + revenue[i - j];
                cutting[i] = j;
            }  
        }
        revenue[i] = max;  
    }
    printf("%d\n", revenue[N]);
    while(N > 0) {
        printf("%d ", cutting[N]);
        N -= cutting[N];
    }
    return 0;
}