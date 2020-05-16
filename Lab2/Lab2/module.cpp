#include "module.h"

Dr::Dr() {
	chisl = znam = 1;
}
Dr::Dr(int x, int y) {
	chisl = x;
	znam = y;
}
Dr::Dr(Dr& dr) {
	chisl = dr.getChisl();
	znam = dr.getZnam();
}

void Dr::put(int x, int y) {
	chisl = x;
	znam = y;
}

void Dr::sokr() {
	for (int i = 1; i <= chisl && i <= znam; i++)
	{
		int a = chisl % i;
		int b = znam % i;
		if (!a && !b)
		{
			chisl = chisl / i;
			znam = znam / i;
		}
	}
}

void Dr::put() {
	/*for(int i=1; i<=chisl && i<=znam; i++)
	{
	float a = chisl%i;
	float b = znam%i;
	if(!a && !b)
	{
	chisl=chisl/i;
	znam=znam/i;
	}
	}*/
	cout << chisl << "/" << znam;
}

int Dr::getChisl() const {
	return chisl;
}
int Dr::getZnam() const {
	return znam;
}

Dr Dr::operator+(Dr& arithm) {
	Dr temp;
	temp.chisl = chisl * arithm.znam + znam * arithm.chisl;
	temp.znam = znam * arithm.znam;
	//temp.sokr();
	return temp;
}

Dr Dr::operator-(Dr& arithm) {
	Dr temp;
	temp.chisl = chisl * arithm.znam - znam * arithm.chisl;
	temp.znam = znam * arithm.znam;
	temp.sokr();
	return temp;
}

Dr Dr::operator*(Dr& arithm) {
	Dr temp;
	temp.chisl = chisl * arithm.chisl;
	temp.znam = znam * arithm.znam;
	temp.sokr();
	return temp;
}

Dr Dr::operator/(Dr& arithm) {
	Dr temp;
	temp.chisl = chisl * arithm.znam;
	temp.znam = znam * arithm.chisl;
	temp.sokr();
	return temp;
}


bool Dr::operator>(Dr& sravn) {
	int a_chisl = chisl * sravn.znam;
	int b_chisl = sravn.chisl * znam;
	return (a_chisl > b_chisl);
}

bool Dr::operator<(Dr& sravn) {
	int a_chisl = chisl * sravn.znam;
	int b_chisl = sravn.chisl * znam;
	return (a_chisl < b_chisl);
}

bool Dr::operator==(Dr& sravn) {
	int a_chisl = chisl * sravn.znam;
	int b_chisl = sravn.chisl * znam;
	return (a_chisl == b_chisl);
}

Dr& Dr::operator=(const Dr& prisv) {
	chisl = prisv.chisl;
	znam = prisv.znam;
	return *this;
}

Dr::operator float() const {
	return chisl / (float)znam;
}

Dr::operator double() const {
	return chisl / (double)znam;
}

ostream& operator<<(ostream& out, const Dr& cout) {
	return out << cout.getChisl() << "/" << cout.getZnam() << endl;
}