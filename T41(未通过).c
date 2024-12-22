#include <stdio.h>
typedef struct grade
{
   int a;
   int b;
   int c;
}grade;

int main(void){
    int m,n;
    scanf("%d %d",&m,&n);
    grade arr[m];
    for(int i=0; i<m; i++){
        scanf("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].c);
    }
    int sum[m];
    for(int i= 0; i<m; i++){
        sum[i] = arr[i].a+arr[i].b+arr[i].c;
    }
    for(int i=0; i<m-1; i++){
        for(int j=0; j<m-i-1; j++){
            int temp;
            if(sum[j] > sum[j+1]){
                temp = sum[j];
                sum[j] = sum[j+1];
                sum[j+1] = temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
        if(sum[m-1-i] == arr[j].a+arr[j].b+arr[j].c){
            printf("%d ",j+1);
        }
    }
    return 0;
    }

