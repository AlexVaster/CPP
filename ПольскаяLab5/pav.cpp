#include <iostream>
using namespace std;

class Elem {
public:
	double inf;
	Elem* next;
	Elem() {
		inf = NULL;
		next = NULL;
	}
	Elem(double i) {
		inf = i;
		next = NULL;
	}
};
class PAV {
private:
	Elem* head;
	double pop() {
		if (head != NULL) {
			Elem* temp = head;
			double k;
			head = temp->next;
			k = temp->inf;
			delete temp;
			return k;
		}
	}
	void push(char i) {
		if (i == 44);				// Пропуск символа ','
		else {
			if (i == 43) {			//	+
				double b = pop();
				double a = pop();
				a += b;
				Elem* elem = new Elem(a);
				elem->next = head;
				head = elem;
			}
			else if (i == 45) {   //	-
				double b = pop();
				double a = pop();
				a -= b;
				Elem* elem = new Elem(a);
				elem->next = head;
				head = elem;
			}
			else if (i == 42) {   //	*
				double b = pop();
				double a = pop();
				a *= b;
				Elem* elem = new Elem(a);
				elem->next = head;
				head = elem;
			}
			else if (i == 47) {   //	/
				double b = pop();
				double a = pop();
				a /= b;
				Elem* elem = new Elem(a);
				elem->next = head;
				head = elem;
			} else {
				Elem* elem = new Elem(i - 48);
				elem->next = head;
				head = elem;
			}
		}
	}
public:
	PAV(char* s) {
		head = NULL;
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			push(s[i]);
		}
	}
	void print() {
		Elem* temp = head;
		while (temp != NULL) {
			cout << temp->inf << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
// Возможные варианты ввода:
// 1,2,3,5,-,*,4,6,+,/,+,1,2,*,/,3,/
// 1235-*46+/+12*/3/

int main() {
	char* stroka = new char[128];
	cout << "Enter PAV" << endl;
	cin >> stroka;
	PAV str1(stroka);
	str1.print();
	return 0;
}
