#include <iostream>

void expand(int*** arr, size_t& oldSize) {

  size_t newSize = (oldSize == 0) ? 2 : oldSize * 2;
  int** newArr = new int* [newSize];
  for (size_t i = 0; i < oldSize; ++i) {
    newArr[i] = *arr[i];
  }
  delete[] *arr;
  *arr = newArr;
  oldSize = newSize;
}

int main(int argc, char** argv)
{

  size_t s = 0;
  int** arrs = nullptr;
  size_t cap = 0;
  int n = 0;

  while (std::cin >> n) {
    int* arr = new int[n];

    for (size_t i = 0; i < n; ++i) {
      std::cin >> arr[i];
    }
    if (cap <= s) {
      expand(&arrs, cap);
    }
    arrs[s] = arr;
    s++;
  }
}
