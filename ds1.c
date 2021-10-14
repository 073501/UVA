#include<stdio.h>
#include<stdlib.h>

int main() {
	int m, n, tmp, arr[10005] = {}, count = 0, k = 0;
	scanf("%d %d",&m, &n);
	while((scanf("%d",&arr[k]))!=EOF){
        if(arr[k]) count++;
        k++;
        if (k > m * n){
        printf("Input matrix has wrong size. Please input again.");
        return 0;
        }
	}
	printf("Sparse matrix by triplet form:\n%d %d %d\n", m, n, count);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i * m + j] != 0) printf("%d %d %d\n", i, j, arr[i * m + j]);
		}
	}
	printf("Transpose of the sparse matrix:\n%d %d %d\n", n, m, count);
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i + n * j] != 0) printf("%d %d %d\n", i, j, arr[i + n * j]);
		}
	}
	return 0;
}
