#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
int speed1[4] = { 500,1000,1500,5000};
int speed;
void setcolor(unsigned short text, unsigned short back){

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
void Quick(int start, int end, int* arr, int max_num, int n,int compare,int change) {
	if (start >= end) {
		return;
	}

	int key = start;
	int i = start + 1, j = end, temp;
	while (i <= j) {
		printf("비교 횟수 = %d\n", compare);
		printf("교환 횟수 = %d\n\n", change);
		printf("Pivot = %d\n\n", arr[key]);
		for (int k = max_num - 1; k >= 0; k--) {
			for (int l = 0; l < n; l++) {
				if (arr[l] > k) {
					if (l == key) {
						setcolor(12, 0);
						printf("ㅁ");
						setcolor(15, 0);
					}
					else printf("ㅁ");
				}
				else printf("  ");
			}
			cout << endl;
		}
		for (int k = 0; k < n; k++) {
			if (k == i && k == j) printf("");
			else if (k == i) printf("L");
			else if (k == j) printf("H");
			else printf("  ");
		}
		Sleep(speed1[speed - 1]);
		system("cls");
		while (i <= end && arr[i] <= arr[key]) {
			printf("비교 횟수 = %d\n", compare);
			printf("교환 횟수 = %d\n\n", change);
			printf("Pivot = %d\n\n", arr[key]);
			for (int k = max_num - 1; k >= 0; k--) {
				for (int l = 0; l < n; l++) {
					if (arr[l] > k) {
						if (l == key) {
							setcolor(12, 0);
							printf("ㅁ");
							setcolor(15, 0);
						}
						else printf("ㅁ");
					}
					else printf("  ");
				}
				cout << endl;
			}
			for (int k = 0; k < n; k++) {
				if (k == i && k == j) printf("");
				else if (k == i) printf("L");
				else if (k == j) printf("H");
				else printf("  ");
			}
			Sleep(speed1[speed - 1]);
			system("cls");
			i++;
			compare++;
		}
		while (j > start && arr[j] >= arr[key]) {
			printf("비교 횟수 = %d\n", compare);
			printf("교환 횟수 = %d\n\n", change);
			printf("Pivot = %d\n\n", arr[key]);
			for (int k = max_num - 1; k >= 0; k--) {
				for (int l = 0; l < n; l++) {
					if (arr[l] > k) {
						if (l == key) {
							setcolor(12, 0);
							printf("ㅁ");
							setcolor(15, 0);
						}
						else printf("ㅁ");
					}
					else printf("  ");
				}
				cout << endl;
			}
			for (int k = 0; k < n; k++) {
				if (k == i && k == j) printf("");
				else if (k == i) printf("L");
				else if (k == j) printf("H");
				else printf("  ");
			}
			Sleep(speed1[speed - 1]);
			system("cls");
			j--;
			compare++;
		}
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[key];
			arr[key] = temp;
			change++;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			change++;
		}
	}
	Quick(start, j - 1, arr, max_num, n,compare,change);
	Quick(j + 1, end, arr, max_num, n,compare,change);

	
}
void Push(int* arr, int size, int idx, int data) {
	arr[idx + 1] = data;
}
int Pop(int* arr, int size, int idx) {
	return arr[idx];
}
int Top(int* arr, int size, int idx) {
	return arr[idx];
}
void PrintAll(int* arr, int size, int idx) {
	for (int i = size ; i > 0; i--) {
		printf(" |  [%d]  |\n",arr[i]);
	}
	printf("  -------- ");
}
int RandomArray(int* arr, int size) {
	int check[21] = {}, max_num = -1;
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		int r = rand() % 20 + 1;
		arr[i] = r;
		if (r > max_num) max_num = r;
	}
	return max_num;
}
int MakeArray(int* arr, int size) {
	int max_num = -1;
	for (int i = 0; i < size; i++) {
		printf("[%d] = ", i);
		cin >> arr[i];
		if (arr[i] > max_num) max_num = arr[i];
	}
	return max_num;
}
void BubbleSort() {
	int menu, n, max_num, speed, compare = 0, change = 0;
	int arr[11];
	printf("------------------\n");
	printf("| 1 : Random     |\n");
	printf("| 2 : Typing     |\n");
	printf("------------------\n");
	cin >> menu;
	system("cls");
	printf("데이터 갯수 = ");
	cin >> n;
	if (menu == 1) max_num = RandomArray(arr, n);
	else max_num = MakeArray(arr, n);
	system("cls");
	printf("정렬 속도\n");
	printf("------------------\n");
	printf("| 1 : 0.5s       |\n");
	printf("| 2 : 1.0s       |\n");
	printf("| 3 : 1.5s       |\n");
	printf("| 4 : 2.0s       |\n");
	printf("------------------\n");
	cin >> speed;
	system("cls");
	printf("red : 기준값\n");
	printf("green : 비교값\n");
	printf("gray : 정렬 완료\n");
	printf("비교 횟수 = %d\n", compare);
	printf("교환 횟수 = %d\n\n", change);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			compare++;
			for (int k = max_num - 1; k >= 0; k--) {
				for (int l = 0; l < n; l++) {
					if (arr[l] > k) {
						if (l < i) {
							setcolor(8, 0);
							printf("ㅁ");
							setcolor(15, 0);
						}
						else if (l == i) {
							setcolor(12, 0);
							printf("ㅁ");
							setcolor(15, 0);
						}
						else if (l == j) {
							setcolor(10, 0);
							printf("ㅁ");
							setcolor(15, 0);
						}
						else printf("ㅁ");
					}
					else printf("  ");
				}
				cout << endl;
			}
			Sleep(speed1[speed - 1]);
			system("cls");
			printf("red : 기준값\n");
			printf("green : 비교값\n");
			printf("gray : 정렬 완료\n");
			printf("비교 횟수 = %d\n", compare);
			if (arr[i] > arr[j]) {
				change++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			printf("교환 횟수 = %d\n\n", change);
		}
	}
	for (int k = max_num - 1; k >= 0; k--) {
		for (int l = 0; l < n; l++) {
			if (arr[l] > k) {
				printf("ㅁ");
			}
			else printf("  ");
		}
		cout << endl;
	}
	Sleep(2000);
	system("cls");
	
}
void Stack() {
	int menu = 1, arr[100] = { 0, }, idx = 0,data;
	while (menu) {
		printf("------------------\n");
		printf("| 1 : Push       |\n");
		printf("| 2 : Pop        |\n");
		printf("| 3 : Top        |\n");
		printf("| 4 : Print      |\n");
		printf("| 0 : Exit       |\n");
		printf("------------------\n");
		cin >> menu;
		system("cls");
		switch (menu) {
		case 1:
			printf("데이터를 입력하세요\n");
			cin >> data;
			Push(arr, idx, idx, data);
			idx++;
			break;
		case 2:
			if (idx == 0) {
				printf("Stack is empty\n");
				Sleep(2000);
				break;
			}
			printf("Pop 결과 = %d", Pop(arr, idx, idx));
			idx--;
			Sleep(2000);
			break;
		case 3:
			if (idx == 0) {
				printf("Stack is empty\n");
				Sleep(2000);
				break;
			}
			printf("Top 결과 = %d", Top(arr, idx, idx));
			Sleep(2000);
			break;
		case 4:
			if (idx == 0) {
				printf("Stack is empty\n");
				Sleep(2000);
				break;
			}
			PrintAll(arr, idx, idx);
			Sleep(2000);
			break;
		}
		system("cls");
	}
	
}
void QuickSort() {
	int menu, n, max_num;
	int arr[11];
	printf("------------------\n");
	printf("| 1 : Random     |\n");
	printf("| 2 : Typing     |\n");
	printf("------------------\n");
	cin >> menu;
	system("cls");
	printf("데이터 갯수 = ");
	cin >> n;
	if (menu == 1) max_num = RandomArray(arr, n);
	else max_num = MakeArray(arr, n);
	system("cls");
	printf("정렬 속도\n");
	printf("------------------\n");
	printf("| 1 : 0.5s       |\n");
	printf("| 2 : 1.0s       |\n");
	printf("| 3 : 1.5s       |\n");
	printf("| 4 : 2.0s       |\n");
	printf("------------------\n");
	cin >> speed;
	system("cls");

	Quick(0, n - 1, arr, max_num, n,0,0);
	for (int k = max_num - 1; k >= 0; k--) {
		for (int l = 0; l < n; l++) {
			if (arr[l] > k) {
				printf("ㅁ");
			}
			else printf("  ");
		}
		cout << endl;
	}
	Sleep(2000);

}

int main() {
	int menu = 1;
	while (menu) {
		printf("------------------\n");
		printf("| 1 : BubbleSort |\n");
		printf("| 2 : QuickSort  |\n");
		printf("| 3 : Stack      |\n");
		printf("| 0 : Exit       |\n");
		printf("------------------\n");
		cin >> menu;
		system("cls");
		if (menu == 1) BubbleSort();
		else if (menu == 2) QuickSort();
		else if (menu == 3) Stack();
		system("cls");
	}
	
}