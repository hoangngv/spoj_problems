#include <iostream>

using namespace std;

int number_arr[1000005];
int temp[1000005];

void mix_arr(int arr[1000005], int left, int mid, int right)
{
	int i = left, l_end = mid - 1;
	int const length = right - left;
	while (left <= l_end && mid <= right)
	{
		if (arr[left] <= arr[mid]) {
			temp[i++] = arr[left++];
		}
		else {
			temp[i++] = arr[mid++];
		}
	}
	while (left <= l_end) {
		temp[i++] = arr[left++];
	}
	while (mid <= right)
	{
		temp[i++] = arr[mid++];
	}
	for (i = 0; i <= length; i++, right--) {
		number_arr[right] = temp[right];
	}
}

void merge_sort(int arr[1000005], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		mix_arr(arr, left, mid + 1, right);
	}
}

int main()
{
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) cin >> number_arr[i];
	merge_sort(number_arr, 0, number - 1);
	for (int i = 0; i < number; i++) cout << temp[i] << endl;
	return 0;
}