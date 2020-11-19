// 2019054957_Lee Yongwoo_12838
#include <stdio.h>

int main(void) {
    int N, M, i, key, counting = 0;
    int count[100001];

    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++) {
        scanf("%d", &key);
        count[key]++;
    }
    for(i = 0; i < M; i++) {
        scanf("%d", &key);
        if(count[key] > 0) {
            counting++;
        }
    }
    printf("%d", counting);
    return 0;
}