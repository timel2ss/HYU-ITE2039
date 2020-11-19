// 2019054957_Lee Yongwoo_12838
#include <stdio.h>

int main(void) {
    int N, e1, e2, x1, x2, i, j, final;
    int a[2][101];
    int t[2][100];
    int s[2][101];
    int l[2][101];
    int path[102];

    scanf("%d", &N);
    scanf("%d %d", &e1, &e2);
    scanf("%d %d", &x1, &x2);

    for(i = 0; i < 2; i++) {
        for(j = 1; j <= N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < 2; i++) {
        for(j = 1; j < N; j++) {
            scanf("%d", &t[i][j]);
        }
    }

    s[0][1] = e1 + a[0][1];
    s[1][1] = e2 + a[1][1];
    for(i = 2; i <= N; i++) {
        if(s[0][i - 1] <= s[1][i - 1] + t[1][i - 1]) {
            s[0][i] = s[0][i - 1] + a[0][i];
            l[0][i] = 0;
        }
        else {
            s[0][i] = s[1][i - 1] + a[0][i] + t[1][i - 1];
            l[0][i] = 1;
        }

        if(s[1][i - 1] <= s[0][i - 1] + t[0][i - 1]) {
            s[1][i] = s[1][i - 1] + a[1][i];
            l[1][i] = 1;
        }
        else {
            s[1][i] = s[0][i - 1] + a[1][i] + t[0][i - 1];
            l[1][i] = 0;
        }
    }

    if(s[0][N] + x1 <= s[1][N] + x2) {
        printf("%d\n", s[0][N] + x1);
        final = 0;
    }
    else {
        printf("%d\n", s[1][N] + x2);
        final = 1;
    }

    path[N + 1] = final;
    for(i = N; i > 1; i--) {
        path[i] = l[path[i+1]][i];
    }
    for(i = 2; i <= N + 1; i++) {
        printf("%d %d\n", path[i] + 1, i - 1);
    }
    return 0;
}