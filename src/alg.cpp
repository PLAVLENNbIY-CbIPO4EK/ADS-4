// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }

  return count;
}

int countPairs2(int *arr, int len, int value) {
  int left = 0;
  int right = len - 1;
  int count = 0;

  while (left < right) {
    int sm = arr[left] + arr[right];

    if (sm == value) {
      if (arr[left] == arr[right]) {
        int raz = right - left + 1;
        count += raz * (raz - 1) / 2;
        break;
      } else {
        int lft = 1;
        int rght = 1;

        while (left + 1 < right && arr[left] == arr[left + 1]) {
          lft++;
          left++;
        }

        while (right - 1 > left && arr[right] == arr[right - 1]) {
          rght++;
          right--;
        }

        count += lft * rght;
        left++;
        right--;
      }
    } else if (sm < value) {
      left++;
    } else {
      right--;
    }
  }

  return count;
}

int bpcP(int *arr, int l, int r, int x) {
  int first = -1;

  int L = l, R = r;
  while (L <= R) {
    int m = (L + R) / 2;
    if (arr[m] == x) {
      first = m;
      R = m - 1;
    } else if (arr[m] < x) {
      L = m + 1;
    } else {
      R = m - 1;
    }
  }

  if (first == -1) return 0;

  int last = first;
  L = first;
  R = r;

  while (L <= R) {
    int m = (L + R) / 2;
    if (arr[m] == x) {
      last = m;
      L = m + 1;
    } else if (arr[m] < x) {
      L = m + 1;
    } else {
      R = m - 1;
    }
  }

  return last - first + 1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len; i++) {
    int n = value - arr[i];
    count += bpcP(arr, i + 1, len - 1, n);
  }

  return count;
}




