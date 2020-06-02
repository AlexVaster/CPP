#include <iostream>
using namespace std;

class Operations {
public:
	char inf;
	Operations* next;
	Operations() {
		inf = NULL;
		next = NULL;
	}
	Operations(char operation) {
		inf = operation;
		next = NULL;
	}
};
class PAV {
private:
	char* result;
	int size = 0;
	Operations* h; 

	char popOperation() {
		if (h != NULL) {
			Operations* temp = h;
			char symbol = temp->inf;
			h = temp->next;
			delete temp;
			return symbol;
		}
	}
	void pushChar(char symbol) {
		char* temp = new char[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = result[i];
		}
		temp[size] = symbol;
		size += 1;
		result = temp;
	}
	void pushOperation(char symbol) {
		Operations* temp = new Operations(symbol);
		temp->next = h;
		h = temp;
	}
	void postfix(char* s) {
		if (!s) exit(777);
		int len = strlen(s);		
		for (int i = 0; i < len; i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				pushChar(s[i]);
			}
			else if ((s[i] == '+')||(s[i] == '-') || (s[i] == '*') || (s[i] == '/') || (s[i] == '(') || (s[i] == ')')) {
				enterOperators(s[i]);
			} 
		}
		while (!operationsIsEmpty()) {
			pushChar(popOperation());
		}
	}
	void enterOperators(char operationB) {
		if (operationsIsEmpty()) pushOperation(operationB);
		else if(operationB == '(') {
			pushOperation(operationB);
		}
		else if (operationB == ')') {
			char top = popOperation();
			while (top != '(') {
				pushChar(top);
				top = popOperation();
			}
		} else {
			while ((!operationsIsEmpty()) && (calculateOperator(h->inf) >= calculateOperator(operationB))) {
				pushChar(popOperation());
			}
			pushOperation(operationB);
		}
	}
	bool operationsIsEmpty() {
		return h == NULL;
	}
	int calculateOperator(char operation) {
		if ((operation == '+') || (operation == '-')) { 
			return 2;
		} else if ((operation == '*') || (operation == '/')) { 
			return 3;
		} else if (operation == '(') {
			return 1;
		} 
		return -1;
	}
public:
	PAV(char* s) {
		h = NULL;
		int len = strlen(s);
		postfix(s);
	}
	void print() {
		cout << "Postfix: ";
		for (int i = 0; i < size; i++) {
			cout << result[i] << "";
		}
		cout << endl;
	}
};
// примеры ввода:
// (a+b)*(c+d)                           
// ((a+b*(c-e)/(d+f))/(a*b))/c
// a+(b-c)*d

int main() {
	char* s = new char[128];
	cout << "Enter infix: " << endl;
	cin >> s;
	PAV str1(s);
	str1.print();
	return 0;
}
