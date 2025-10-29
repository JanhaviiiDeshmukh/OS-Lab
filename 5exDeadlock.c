#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[10][10], req[10][10], avail[10], finish[10];
   
    printf("Enter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&req[i][j]);

    printf("Enter Available Resources:\n");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);

    for(i=0;i<n;i++)
        finish[i]=0;

    int done, flag;
    do {
        done=0;
        for(i=0;i<n;i++) {
            if(finish[i]==0) {
                flag=0;
                for(j=0;j<m;j++)
                    if(req[i][j]>avail[j])
                        flag=1;
                if(flag==0) {
                    for(k=0;k<m;k++)
                        avail[k]+=alloc[i][k];
                    finish[i]=1;
                    done=1;
                }
            }
        }
    } while(done);

    printf("\nDeadlocked Processes: ");
    for(i=0;i<n;i++)
        if(finish[i]==0)
            printf("P%d ",i);
    printf("\n");

    return 0;
