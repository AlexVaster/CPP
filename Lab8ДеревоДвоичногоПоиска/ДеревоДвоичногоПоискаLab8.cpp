#include <iostream>
using namespace std;

struct Node;
typedef Node* pNode;
int elements = 0;
struct Node {
	int inf;
	pNode left, right;
};

void show(pNode& Tree, int elements) {
	if (Tree != NULL) {
		show(Tree->right, elements + 1);
		for (int i = 0; i < elements; i++) cout << "   ";
		cout << Tree->inf << endl;
		show(Tree->left, elements + 1);
	}
}
void inOrder(pNode MyTree) {
	if (MyTree) {
		inOrder(MyTree->left);
		cout << MyTree->inf << " ";
		inOrder(MyTree->right);
	}
}

void del(pNode& Tree) {
	if (Tree != NULL) {
		del(Tree->left);
		del(Tree->right);
		delete Tree;
		Tree = NULL;
	}
}

void add(int x, pNode& MyTree) {
	if (NULL == MyTree) {
		MyTree = new Node;
		MyTree->inf = x;
		MyTree->left = MyTree->right = NULL;
	}
	if (x < MyTree->inf) {
		if (MyTree->left != NULL) add(x, MyTree->left);
		else {
			MyTree->left = new Node;
			MyTree->left->left = MyTree->left->right = NULL;
			MyTree->left->inf = x;
		}
	}
	if (x > MyTree->inf) {
		if (MyTree->right != NULL) add(x, MyTree->right);
		else {
			MyTree->right = new Node;
			MyTree->right->left = MyTree->right->right = NULL;
			MyTree->right->inf = x;
		}
	}
}
pNode search(int k, pNode& MyTree) {
	if ((MyTree == NULL) || (k == MyTree->inf)) return MyTree;
	if (k < MyTree->inf) return search(k, MyTree->left);
	else return search(k, MyTree->right);
}
int main() {
	pNode Tree = NULL;
	int row[] = { 22, 10, 3, 5, 13, 26, 18, 19, 17, 2, 4, 12 };
	for (int i = 0; i < 12; i++) {
		add(row[i], Tree);
	}
	cout << "Binary Tree \n";
	show(Tree, elements);
	cout << "\nSearch element 5 \n";
	pNode result = search(5, Tree);
	show(result, elements);
	cout << "Output in order\n";
	inOrder(Tree);
	del(Tree);

	int count = 0;
	int temp = 0;
	cout << "\nInput count of numbers:\n";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "Input number " << i + 1 << " : ";
		cin >> temp;
		add(temp, Tree);
	}
	cout << "Binary Tree \n";
	show(Tree, elements);
	cout << "Output in order\n";
	inOrder(Tree);
	del(Tree);
}