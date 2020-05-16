#include "module.h"

int main(int argc, char** argv) {
	Dr obj(1, 1);
	obj.put(14, 8);
	cout << "put: ";
	obj.put();
	cout << endl;

	Dr obj2;
	cout << "default: ";
	obj2.put();
	cout << endl;

	Dr obj3(1, 1);
	obj3.put(9, 3);

	Dr obj4(obj3);
	cout << "copy: ";
	obj4.put();
	cout << endl;

	Dr obj5(1, 1);
	obj5.put(25, 5);
	cout << "operatior + : ";
	Dr obj731;
	//obj731 = obj5.operator+(obj4);
	obj731.put();
	cout << endl;

	//cout « "a + b = " « obj5.operator+(obj4);

	Dr obj6(1, 1);
	obj6.put(25, 5);
	obj6.operator-(obj4);
	cout << "operatior - : ";
	obj6.put();
	cout << endl;

	Dr obj7(1, 1);
	obj7.put(25, 5);
	obj7.operator*(obj4);
	cout << "operatior * : ";
	obj7.put();
	cout << endl;

	Dr obj8(1, 1);
	obj8.put(25, 5);
	obj8.operator/(obj4);
	cout << "operatior / : ";
	obj8.put();
	cout << endl;

	Dr obj9(1, 1);
	obj9.put(10, 3);
	cout << "operator > : " << obj9.operator>(obj8) << endl;
	cout << "operator < : " << obj9.operator<(obj8) << endl;
	cout << "operator == : " << obj9.operator==(obj8) << endl;

	Dr obj10(1, 1);
	obj10 = obj8;
	cout << "operator = : " << obj10;
	obj10.put();
	cout << endl;

	Dr obj11(9, 3);
	//cout << "operator = : " << obj11;

	float fl = obj8;
	cout << "float: " << fl << endl;

	double dl = obj8;
	cout << "double: " << dl << endl;

	Dr a(1, 2);
	Dr b(4, 7);
	cout << a << endl;
	cout << b << endl;
	Dr c;
	c = a + b;
	cout << c << endl;
	cout << a + b << endl;
	return 0;
}
