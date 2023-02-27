#include "probelib.h"
#include <cstdio>

int n;
int binarySearch(int start, int end) {
  int mid = (start + end) / 2;
  if(start == end) {
    return start;
  }
  if(probe_check(start, mid)) {
    return binarySearch(start, mid);
  } else {
    return binarySearch(mid+1, end);
  }
}
int main()
{
  int n = probe_init();
  int ans = binarySearch(0, n-1);
  probe_answer(ans);
  return 0;
}
