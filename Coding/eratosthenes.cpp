#include <stdio.h>
 
int main() {
  int N = 100;
  bool check[N + 1];

  //giả sử tất cả các ptu trong mảng đều là số nguyên tố
  for (int i = 2; i <= N; i++) {
    check[i] = true;
  }

  //sàng eratosthene
  //xoá các bội của các số nguyên tố
  for (int i = 2; i <= N; i++) {
    if (check[i] == true) {
      for (int j = 2 * i; j <= N; j += i) {
        check[j] = false;
      }
    }
  }

  //in ra các số nguyên toos
  for (int i = 2; i <= N; i++) {
    if (check[i] == true) {
      printf("%d ", i);
    }
  }
}