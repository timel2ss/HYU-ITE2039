// 2019054957_Lee Yongwoo_12838
#include <stdio.h>

void parentheses(int i, int j);

int s[101][101];

int main(void) {
    int N, i, j, k, l, q;
    int p[101];
    int m[101][101];


    scanf("%d", &N);
    for(i = 0; i <= N; i++) {
        scanf("%d", &p[i]);
    }

    for(i = 1; i <= N; i++) {
        m[i][i] = 0;
    }

    for(l = 2; l <= N; l++) {
        for(i = 1; i <= N - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = ~(1 << 31);
            for(k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("%d\n", m[1][N]);
    parentheses(1, N);
    return 0;
}

void parentheses(int i, int j) {
    if(i == j) {
        printf("%d", i);
    }
    else {
        printf("%c", '(');
        parentheses(i, s[i][j]);
        parentheses(s[i][j] + 1, j);
        printf("%c", ')');
    }
}