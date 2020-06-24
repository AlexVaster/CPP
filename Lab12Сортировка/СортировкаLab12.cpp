#include <iostream>
using namespace std;

const int N = 5;
struct mem {
	int key;
	int inf;
};
typedef mem Mass[N + 1];
Mass a;
mem x;

void sortByInsert(Mass a, int N) {
	int countSwap = 0;
	int countCompare = 0;
	for (int i = 1; i < N; i++) {
		int value = a[i].key;
		int index = i;
		while ((index > 0) && (a[index - 1].key > value)) {
			++countCompare;
			a[index].key = a[index - 1].key;
			++countSwap;
			index--;
		}
		a[index].key = value;
		++countSwap;
	}
	cout << "count of swap = " << countSwap << endl;
	cout << "count of compare = " << countCompare << endl;
}
void sortBySelection(Mass a, int N) {
	int countSwap = 0;
	int countCompare = 0;
	int i, j, k;
	for (i = 0; i < N; i++) {
		k = i;
		x.key = a[i].key;
		for (j = i + 1; j < N; j++)
			if (a[j].key < x.key) {
				++countCompare;
				k = j;
				x.key = a[j].key;
			}
		a[k].key = a[i].key;
		++countSwap;
		a[i].key = x.key;
		++countSwap;
	}
	cout << "count of swap = " << countSwap << endl;
	cout << "count of compare = " << countCompare << endl;
}

void show(Mass a, int N) {
	for (int i = 0; i < N; i++) {
		cout << a[i].key << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 12, 4, 15, 17, 20 };
	for (int i = 0; i < N; i++) {
		a[i].key = arr[i];
	}
	Mass temp;
	for (int i = 0; i < N; i++) {
		temp[i].key = a[i].key;
	}
	cout << "Output massiv a\n";
	show(a, N);
	cout << "SortBySimple\n";
	sortByInsert(a, N);
	show(a, N);

	cout << "Output massiv b\n";
	show(temp, N);
	cout << "SortBySelect\n";
	sortBySelection(temp, N);
	show(temp, N);
	system("pause");
	return 0;
}