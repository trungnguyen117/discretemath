// Counting sort 

#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {

  int final[10];
  int count[10];
  

  // Tìm giá trị lớn nhất trong mảng
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max)
      max = arr[i];
  }

  // Tạo mảng tạm để đếm số lần xuất hiện của mỗi giá trị
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Đếm số lần xuất hiện của mỗi giá trị
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }

  // Tính số lượng các giá trị nhỏ hơn hoặc bằng mỗi giá trị
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Tạo mảng kết quả và đặt các phần tử vào vị trí thích hợp
  for (int i = n - 1; i >= 0; i--) {
    final[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  // Sao chép mảng kết quả vào mảng ban đầu
  for (int i = 0; i < n; i++) {
    arr[i] = final[i];
  }
}

// Hàm in ra mảng
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// 
int main() {
  int arr[] = {4, 2, 5, 8, 3, 7, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  countingSort(arr, n);
  printArray(arr, n);
}
