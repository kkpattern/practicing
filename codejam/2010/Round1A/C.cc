#include <stdio.h>


bool check_win(int a, int b) {
  if (a == b) return false;
  if (a > b) {
    int temp = a;
    a = b;
    b = temp;
  }
  int alpha = b % a;
  if (alpha == 0) {
    return true;
  } else if (a % alpha == 0) {
    if (b/a == 1) {
      return false;
    } else {
      return true;
    }
  } else {
    if (b/a > 1 && check_win(a, alpha)) {
      return true;
    } else {
      return !check_win(a, alpha);
    }
  }
}

int main() {
  int T = 0;
  scanf("%d", &T);
  for (int case_index = 0; case_index < T; ++case_index) {
    int A1 = 0;
    int A2 = 0;
    int B1 = 0;
    int B2 = 0;
    scanf("%d%d%d%d", &A1, &A2, &B1, &B2);
    int win_count = 0;
    for (int a = A1; a <= A2; ++a) {
      for (int b = B1; b <= B2; ++b) {
        if (check_win(a, b)) ++win_count;
      }
    }
    printf("Case #%d: %d\n", case_index+1, win_count);
  }

  return 0;
}
