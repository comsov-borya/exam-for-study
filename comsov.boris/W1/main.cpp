#include <iostream>
#include <cstring>

void expandLengths(size_t **lengths, size_t size) {
  size_t newSize = (size == 0) ? 2 : size * 2;
  size_t *newLengths = new size_t [newSize];
  for (size_t i = 0; i < size; ++i) {
    newLengths[i] = (*lengths)[i];
  }
  delete[] *lengths;
  *lengths = newLengths;
}

void expand(int*** arr, size_t& oldSize) {
  size_t newSize = (oldSize == 0) ? 2 : oldSize * 2;
  int** newArr = new int* [newSize];
  for (size_t i = 0; i < oldSize; ++i) {
    newArr[i] = (*arr)[i];
  }
  delete[] *arr;
  *arr = newArr;
  oldSize = newSize;
}

int main(int argc, char** argv)
{
  size_t s = 0;
  int **arrs = nullptr;
  size_t cap = 0;
  size_t *lengths = nullptr;
  int n = 0;

  while (std::cin >> n) {
    int* arr = new int[n];
    for (size_t i = 0; i < n; ++i) {
      std::cin >> arr[i];
    }
    if (cap <= s) {
      size_t capCoppy = cap;
      expand(&arrs, cap);
      expandLengths(&lengths, capCoppy);
    }
    arrs[s] = arr;
    lengths[s] = n;
    s++;
  }

  if (std::strcmp(argv[1], "size") == 0) {
    size_t totalSize = 0;
    for (size_t i = 0; i < cap; ++i) {
      for (size_t j = 0; j < lengths[i]; ++j) {
        ++totalSize;
      }
    }
    std::cout << totalSize << "\n";
  }

  else if (std::strcmp(argv[1], "maxln") == 0) {
    size_t maxln = 0;
    for (size_t i = 0; i < cap; ++i) {
      if (maxln < lengths[i]) {
        maxln = lengths[i];
      }
    }
    std::cout << maxln << "\n";
  }

  else if (std::strcmp(argv[1], "maxseq") == 0) {
    size_t maxln = 0;
    size_t ind = 0;
    int *maxarr = nullptr;
    for (size_t i = 0; i < cap; ++i) {
      if (maxln < lengths[i]) {
        maxln = lengths[i];
        maxarr = arrs[i];
        ind = i;
      }
    }
    std::cout << maxln;
    for (size_t i = 0; i < lengths[ind]; ++i) {
      std::cout << maxarr[i];
    }
    std::cout << "\n";
  }

  else if (std::strcmp(argv[1], "minln") == 0) {
    size_t minln = lengths[0];
    for (size_t i = 0; i < cap; ++i) {
      if (minln > lengths[i]) {
        minln = lengths[i];
      }
    }
    std::cout << minln << "\n";
  }

  else if (std::strcmp(argv[1], "minseq") == 0) {
    size_t minln = lengths[0];
    size_t ind = 0;
    int *minarr = nullptr;
    for (size_t i = 0; i < cap; ++i) {
      if (minln > lengths[i]) {
        minln = lengths[i];
        minarr = arrs[i];
        ind = i;
      }
    }
    std::cout << minln;
    for (size_t i = 0; i < lengths[ind]; ++i) {
      std::cout << minarr[i];
    }
    std::cout << "\n";
  }

  else if (std::strcmp(argv[1], "negative") == 0) {
    size_t negative = 0;
    for (size_t i = 0; i < cap; ++i) {
      for (size_t j = 0; j < lengths[i]; ++j) {
        if (arrs[i][j] < 0) {
          negative++;
        }
      }
    }
    std::cout << negative << "\n";
  }

  else if (std::strcmp(argv[1], "positive") == 0) {
    size_t positive = 0;
    for (size_t i = 0; i < cap; ++i) {
      for (size_t j = 0; j < lengths[i]; ++j) {
        if (arrs[i][j] > 0) {
          positive++;
        }
      }
    }
    std::cout << positive << "\n";
  }

}
