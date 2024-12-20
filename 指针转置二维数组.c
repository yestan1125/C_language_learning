#include <stdio.h>

void transpose(int *src, int *dst, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            *(dst + j * rows + i) = *(src + i * cols + j);
        }
    }
}

void printMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

int main() {
	int m,n,i,j;
	printf("please enter the row and the col:");
	scanf("%d %d",&m,&n);
	    
    int src [m][n] ;

    
    int dst [n][m];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&src[i][j]);
		}
	}
     
    transpose((int *)src, (int *)dst, m, n);

    printf("Original Matrix:\n");
    printMatrix((int *)src, m, n);

    printf("\nTransposed Matrix:\n");
    printMatrix((int *)dst, n, m);

    return 0;
}

