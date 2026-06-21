#include "statistic.hpp"

#include <algorithm>
#include <vector>

int ReturnKth(int k, std::vector<int>& vec, int a, int b) {
  if (a == b) {
    return vec[a];
  }

  int pivot = vec[a + (b - a) / 2];
  int i = a;
  int j = b;

  while (i <= j) {
    while (vec[i] < pivot) {
      i++;
    }
    while (vec[j] > pivot) {
      j--;
    }
    if (i <= j) {
      std::swap(vec[i], vec[j]);
      i++;
      j--;
    }
  }

  int left_len = j - a + 1;

  if (k <= left_len) {
    return ReturnKth(k, vec, a, j);
  } else if (k > (i - a)) {
    return ReturnKth(k - (i - a), vec, i, b);
  } else {
    return vec[j + 1];
  }
}