#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
int MaxLen[1000001];
vector <int> success;
ull ipow(ull x, ull y, ull m) {
	if (y == 0) return 1;
	ull temp = ipow(x, y / 2, m) % m;
	if (y % 2) return temp * temp % m * x % m;
	else return temp * temp % m;
}
ull Miller_Rabin(ull p, ull a) {
	if (a % p == 0) return 0;
	ull e = p - 1;
	while (e) {
		ull temp = ipow(a, e, p);
		if (temp == p - 1) return 0;
		if (e % 2) return temp != 1;
		e >>= 1;
	}
}
void Failure_function(string temp) {
	int j = 0, len = temp.size();
	for (int i = 1; i < len; i++) {
		while (j > 0 && temp[i] != temp[j]) {
			j = MaxLen[j - 1];
		}
		if (temp[i] == temp[j]) {
			MaxLen[i] = ++j;
		}
	}
}
void KMP(string arr, string search) {
	Failure_function(search);
	int arrSize = arr.size(), searchSize = search.size(), j = 0;
	for (int i = 0; i < arrSize; i++) {
		while (j > 0 && arr[i] != search[j]) {
			j = MaxLen[j - 1];
		}
		if (arr[i] == search[j]) {
			if (j == searchSize - 1) {
				success.push_back(i - searchSize + 2);
				j = MaxLen[j];
			}
			else j++;
		}
	}
}
bool BinarySearch(int* arr, int start, int end, int target) {
	int mid = (start + end) / 2;
	if (arr[mid] == target) return true;
	if (start <= end) return false;
	if (arr[mid] < target) return BinarySearch(arr, mid + 1, end, target);
	else if (arr[mid] > target) return BinarySearch(arr, start, mid - 1, target);
}
