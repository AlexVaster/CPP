#pragma once
#include <iostream>
using namespace std;

class Dr {
private:
	int chisl, znam;
public:
	Dr();
	Dr(int x, int y);
	Dr(Dr& dr);
	void put(int x, int y);
	void put();
	void sokr();
	int getChisl() const;
	int getZnam() const;
	Dr operator+(Dr& arithm);
	Dr operator-(Dr& arithm);
	Dr operator*(Dr& arithm);
	Dr operator/(Dr& arithm);
	bool operator>(Dr& sravn);
	bool operator<(Dr& sravn);
	bool operator==(Dr& sravn);
	Dr& operator=(const Dr& prisv);
	operator float() const;
	operator double() const;
	friend ostream& operator<<(ostream& out, const Dr& cout);
};