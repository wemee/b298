#include <stdio.h>
#include <stdlib.h>

int **ary; /*[ (0無問題,1有問題) , 上遊廠商編號 ], 位置0不使用*/

int check(int y){
    if(ary[y][0]==1) /* 有問題 */
        return 1;
    
    if(ary[y][1]!=0) /* 沒問題, 但有上游廠商 */
        return check(ary[y][1]);
    
    return 0; /* 沒問題, 也沒上游廠商 */
}

void init_ary(int N){
    int *pAry, i;
    ary = (int **)calloc(3*N, sizeof(int));
    for (i = 0, pAry = (int *)(ary+N); i < N; i++, pAry += 2)
        ary[i]=pAry;
}

int main(){
    int N,M,L,Q, i, a,b;
    while (scanf("%d%d%d%d", &N,&M,&L,&Q) != EOF) {
        init_ary(N+1); /*N+1: 位置0不使用*/
        
        for (i=0; i<M; i++) {
            scanf("%d%d", &a, &b);
            ary[b][1] = a;
        }
        for (i=0; i<L; i++) {
            scanf("%d", &a);
            ary[a][0] = 1;
        }
        for (i=0; i<Q; i++) {
            scanf("%d", &a);
            printf("%s\n", check(a)==1 ? "TUIHUOOOOOO" : "YA~~");
        }
        
        free(ary);
    }
    
    return 0;
}
