#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

const int kMaxN = 500;

long long table[kMaxN+1][kMaxN+1];

long long n_choose_r_table[kMaxN+1][kMaxN+1];

long long n_choose_r(int n, int r) {
  if (r > n) return 0;
  if (r*2 > n) r = n-r;
  if (r == 0) return 1;

  long long result = n;
  for (int i = 2; i <= r; ++i) {
    result *= (n-i+1);
    result /= i;
  }
      
  return result;
}


int main() {
  int T = 0;
  scanf("%d", &T);
  for (int i = 0; i <= kMaxN; ++i) {
    table[i][1] = 1;
  }
  for (int i = 0; i <= kMaxN; ++i) {
    for (int j = 0; j <= kMaxN; ++j) {
      n_choose_r_table[i][j] = -1;
    }
  }
  for (int ni = 2; ni <= kMaxN; ++ni) {
    for (int ki = 2; ki < ni; ++ki) {
      long long count = 0;
      for (int r = 1; r < ki; ++r) {
        count += n_choose_r(ni-ki-1, ki-r-1)*table[ki][r];
      }
      table[ni][ki] = count;
    }
  }
  for (int case_index = 0; case_index < T; ++case_index) {
    int n = 0;
    scanf("%d", &n);
    long long count = 0;
    for (int r = 1; r < n; ++r) {
      count += table[n][r];
    }
    printf("Case #%d: %lld\n", case_index+1, count % 100003);
  }
  return 0;
}
