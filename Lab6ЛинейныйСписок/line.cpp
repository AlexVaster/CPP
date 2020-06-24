#include <iostream>

using namespace std;
char* str = new char[100];
int i = 1;
struct List;
typedef List* pList;
struct List {
	pList next;
	int R;
	union{
		pList level;
		char atom;
	};
};
void Input_to_List(pList& p) {
	char c;
	c = str[0];
	str = str + 1;
	if (c != 0) {
		if (c == '(') {
			p = new List;
			Input_to_List(p->level);
			Input_to_List(p->next);
		} else if ((('a' <= c) && (c <= 'z')) || (c == '+') || (c == '-') || (c == '*') || (c == '/')) {
			p = new List;
			p->R = 1;
			p->atom = c;
			Input_to_List(p->next);
		} else if (c == ')') {
			p = NULL;
		}
	}
	else p = NULL;
}
void Print_of_List(pList& p) {
	pList q;
	if (p != NULL) {
		if (p->R == 1) {
			cout << p->atom;
		}else {
			cout << '(';
			q = p->level;
			while (q != NULL) {
				Print_of_List(q);
				q = q->next;
			}
			cout << ')';
		}
	}
	cout << endl;
}
void OLS(pList p) {
	if (p != NULL) {
		if (p->R == 0) {
			cout << '(';
			OLS(p->level);
			OLS(p->next);
			cout << ')';
		} else {
			cout << p->atom;
			OLS(p->next);
		}
	}
}
void head(pList& p) {
	pList q;
	if (p != NULL) {
		q = p;
		if (q->R == 1) {
			cout << q->atom << endl;
		}
		else {
			cout << "()";
		}
	}
}
void tail(pList& p) {
	pList q;
	if (p != NULL) {
		q = p;
		q = q->next;
		while (q != NULL) {
			cout << '(';
			cout << q->atom;
			q = q->next;
			cout << ')';
		}
	}	
}
int main() {
	pList p;
	cin >> str;
	Input_to_List(p);
	Print_of_List(p);
	OLS(p);
	Print_of_List(p);
	cout << "\nHEAD:\n";
	head(p);
	cout << "\nTAIL:\n";
	tail(p);
	cout << endl;
	return 0;
}