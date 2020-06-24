#include <iostream>
using namespace std;
const int numbers = 6;
int i, j;

int graph[numbers][numbers] = {
{0, 1, 1, 0, 0, 1},
{0, 0, 1, 1, 0, 0},
{1, 0, 0, 1, 0, 0},
{0, 1, 1, 0, 0, 0},
{0, 1, 0, 0, 0, 1},
{1, 1, 1, 0, 0, 0},
};

void searchInWidth(bool* entered, int unit) {
	int* queue = new int[numbers];
	int count, head;
	for (i = 0; i < numbers; i++) queue[i] = 0;
	count = 0; head = 0;
	queue[count++] = unit;
	entered[unit] = true;
	while (head < count) {
		unit = queue[head++];
		cout << unit + 1 << " ";
		for (i = 0; i < numbers; i++)
			if (graph[unit][i] && !entered[i]) {
				queue[count++] = i;
				entered[i] = true;
			}
	}
	delete[]queue;
}

int main() {
	int inputHeight;
	cout << "Start height:";
	cin >> inputHeight;
	bool* entered = new bool[numbers];
	cout << "Matrix: " << endl;
	for (i = 0; i < numbers; i++) {
		entered[i] = false;
		for (j = 0; j < numbers; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << "Output: ";
	searchInWidth(entered, inputHeight - 1);
	delete[]entered;
	return 0;
}