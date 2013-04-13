#include <stdio.h>
#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

bool palindrome(long long n) {
  long long old_n = n;
  long long new_n = 0;
  while (n > 0) {
    new_n = new_n*10+n%10;
    n /= 10;
  }
  if (new_n == old_n)
    return true;
  else
    return false;
  
}

int main() {
  int T = 0;
  scanf("%d", &T);
  long long A = 1;
  long long B = 1000000000000000LL;
  vector<long long> palindromes;
  palindromes.push_back(0);
  for (long long i = 1; i*i <= B; ++i) {
    if (palindrome(i) && palindrome(i*i)) {
      palindromes.push_back(i);
    }
  }
  for (int ti = 0; ti < T; ++ti) {
    long long ans = 0;
    long long A = 0;
    long long B = 0;
    scanf("%lld%lld", &A, &B);
    for (int i = 0; i < palindromes.size(); ++i) {
      if (A <= palindromes[i] && B >= palindromes[i])
        ++ans;
    }
    printf("Case #%d: %lld\n", ti+1, ans);
  }
  return 0;
}
