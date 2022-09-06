#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define limit 100010

int main() {
  int n, a[limit], lis[limit], st[limit], top = 1, in[limit], big[limit],
                                          num[limit];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (st[top - 1] < a[i]) {
      st[top] = a[i];
      lis[i] = top;
      top++;
    } else {
      int pos = lower_bound(st + 1, st + top, a[i]) - st;
      st[pos] = a[i];
      lis[i] = pos;
    }
  }
  top--;
  for (int i = n; i >= 1; i--) {
    if (lis[i] == top || big[lis[i] + 1] > a[i]) {
      in[i] = 1;
      num[lis[i]]++;
      big[lis[i]] = max(big[lis[i]], a[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (in[i]) {
      if (num[lis[i]] > 1)
        putchar('2');
      else
        putchar('3');
    } else
      putchar('1');
  }
  return 0;
}