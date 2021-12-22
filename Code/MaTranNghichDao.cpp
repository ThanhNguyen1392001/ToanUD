#include <conio.h>
#include <stdio.h>


int det(float matrix[10][10], int n) {
	int s, sum = 0;
		
	if (n == 1) return matrix[0][0];
	
	if (n == 2) return (matrix[0][0] * matrix[1][1] 
					- matrix[0][1] * matrix[1][0]);
		
	for (int k = 0; k < n; k++) {
		float smaller[10][10];
		
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (i < k) smaller[i][j-1] = matrix[i][j];
				else if (i > k) smaller[i-1][j-1] = matrix[i][j];
			}
		}
			
		if (k % 2 == 0) s = 1;
		else s = -1;
					
		sum += matrix[k][0] * s * det(smaller, n-1);
	}
	
	return sum;
}




void nhap(float a[][10], int& n) {
	printf("Nhap n = ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("a[%d][%d] = ", i+1, j+1);
			scanf("%f",&a[i][j]);
		}
	}
	
}

void xuat(float a[][10], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.2f\t", a[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}


float elementOfTransposeMatrix(float matrix[][10], int n, int row, int column) {
	float smallMatrix[10][10];
	int x = 0;
	int y;
	for (int i = 0; i < n; i++) {
		y =0;
		if (i == row) continue;
		for (int j = 0; j < n; j++) {
			if (j == column) continue;
			smallMatrix[x][y] = matrix[i][j];
			y++;
		}
		x++;
	}
	if ((row + column) % 2 == 0) return det(smallMatrix, n - 1); 
	else return -det(smallMatrix, n - 1);
}
void inverseMatrix(float matrix[][10], int n) {
	int k = det(matrix, n);
	float iMatrix[10][10];
	if (k == 0) printf("Khong ton tai ma tran nghich dao !!!");
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				iMatrix[j][i] = elementOfTransposeMatrix(matrix, n, i, j) / k;
			}
		}
		xuat(iMatrix, n);
	}
}

int main() {
	float a[10][10];
	int n;
	nhap(a, n);
	xuat(a, n);
	int k = det(a, n);
	printf("KQ = %d\n", k);
	inverseMatrix(a, n);
}




