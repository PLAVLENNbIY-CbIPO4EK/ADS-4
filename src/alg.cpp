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
        count += raz*(raz - 1)/2;
        break;
      } 
      else {
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
    } 
    else if (s < value) {
      left++;
    } 
    else {
      right--;
    }
  }

  return count;
}

int bpcP(int *arr, int l, int r, int x) {
  while (l <= r) {
    int gg = (l + r)/2;

    if (arr[gg] == x) 
      return 1;
    
    if (arr[gg] < x) 
      l = gg + 1;
    else 
      r = gg - 1;
  }

  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len; i++) {
    int n = value - arr[i];

    if (bpcP(arr, i + 1, len - 1, n)) {
      count++;
    }
  }

  return count;
}
