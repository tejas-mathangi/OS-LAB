#include <stdio.h>

int main(){
    int n = 3,m =4;
    int need[n][m];
    int alloc[3][4] = {
        {1, 2, 2, 1},
        {1, 0, 3, 3},
        {0, 2, 1, 2}
    };

    int max[3][4] = {
        {3, 3, 2, 2},
        {1, 2, 3, 4},
        {1, 3, 5, 2}
    };

    int avail[4] = {3, 2, 2, 1};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    int finish[n] , safeSeq[n];
    for (int i = 0; i < n; i++){
        finish[i] = 0;
    }

    int count = 0;
    while(count < n){
        int found = 0;
        for(int i = 0;i < n;i++){
            if (finish[i]==0){
                int canAllocate = 1;
                for(int j = 0;j < m;j++){
                    if(need[i][j] > avail[j]){
                        canAllocate = 0;
                        break;
                    }
                }
                if(canAllocate){
                    for (int j = 0; j < m; j++)
                    {
                        avail[j]+=alloc[i][j];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
            
        }
        if(found == 0){
            printf("not in safe state");
            return 0;
        }
    }

    printf("in safe state , the safe seq is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d ->",safeSeq[i]);
    }
    
    return 0;
}