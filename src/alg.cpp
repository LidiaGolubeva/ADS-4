// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        pairs += 1;
      }
    }
  }
  return pairs;
}
int countPairs2(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        pairs += 1;
      }
    }
  }
  return pairs;
}
int countPairs3(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i, right = len;
    while (left < right - 1) {
      int center = (left + right) / 2;
      if (arr[i] + arr[center] == value) {
        pairs += 1;
        int newCenter = center + 1;
        while (arr[i] + arr[newCenter] == value && newCenter < right) {
          pairs += 1;
          newCenter += 1;
        }
        newCenter = center - 1;
        while (arr[i] + arr[newCenter] == value && newCenter > left) {
          pairs += 1;
          newCenter -= 1;
        }
        break;
      }
      if (arr[i] + arr[center] > value) {
        right = center;
      } else {
        left = center;
      }
    }
  }
  return pairs;
}
