#include "set.h"
Set::Set() :BoolVector(256) { M = 0; }
Set::Set(char *s) : BoolVector(256)
{
	for (int i = 0; s[i]; i++)
		SetUp1(int(s[i]));
	M = Weight();
}
Set::Set(Set& S) : BoolVector(S) { M = S.M; }
Set& Set::operator= (Set &S)
{
	if (this != &S)
	{
		for (int i = 0; i < 32; i++)
			bv[i] = S.bv[i];
		M = S.M;
	}
	return *this;
}
Set::Set(BoolVector& V) : BoolVector(V){
	M = Weight();
}
Set Set::operator+ (char ch) // V=*this+ch
{
	Set Res = *this;
	Res.SetUp1(int(ch));
	Res.M = Res.Weight();
	return Res;
}
Set& Set::operator+= (char ch) // *this=*this+ch
{
	return *this = *this + ch;
}
Set Set::operator-(char ch){
	Set Res = *this;
	Res.SetUp0(int(ch));
	Res.M = Res.Weight();
	return Res;
}
Set& Set::operator-=(char ch){
	return *this = *this - ch;
}
Set Set::operator+(Set S){
	Set Res(*this | S);
	return Res;
}
Set& Set::operator+=(Set S){
	return *this = *this + S;
}
Set Set::operator-(Set S) // Res=*this-S
{
	Set temp(*this & (*this & S).operator~());
	return temp;
}
Set& Set::operator-= (Set S){
	return *this = *this - S;
}
Set Set::operator*(Set S){
	Set Res(*this & S);
	return Res;
}
Set Set::operator*=(Set S){
	return *this = *this * S;
}
bool Set::operator== (Set S){
	for (int i = 0; i < 256; i++)
		if (operator[](i) != S.operator[](i))
			return false;
	return true;
}
bool Set::operator!=(Set S){
	return !(*this == S);
}
Set Set::operator~(){
	Set temp(this->BoolVector::operator~());
	return temp;
}
void Set::Scan() {
	char buf[100];
	std::cout << "Enter your set" << std::endl;
	gets_s(buf);
	for (int i = 0; buf[i]; i++)
		SetUp1(int(buf[i]));
	M = Weight();
}
std::ostream & operator<<(std::ostream& r, Set &S){
	for (int i = 0; i < 256; i++){
		if (S[i] == '1')
			r << char(i) << " ";
	}
	std::cout << std::endl;
	r << "Power of set = " << S.M << std::endl;
	return r;
}
void Set::Print(){
	std::cout << "power = " << M << std::endl;
	for (int i = 0; i < 256; i++)
		if (operator[](i) == '1')
			std::cout << char(i) << ' ';
	std::cout << std::endl;
}
std::istream & operator>>(std::istream& r, Set &S){
	S.Scan();
	return r;
}