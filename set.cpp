#include "set.h"
Set::Set() :BoolVector(256) { M = 0; }
//Set::Set():BoolVector(256), M(0) {}

Set::Set(char *s)
{
	n = 256; m = 32;
	bv = new UC[m];
	int i;
	for (i = 0; i<m; i++)
		bv[i] = 0;
	for (i = 0; s[i]; i++)
		SetUp1((UC)s[i]);
	M = Weight();
}

Set::Set(Set &S) : BoolVector(S) { M = S.M; }

Set & Set::operator= (Set &S)
{
	if (this != &S)
	{
		for (int i = 0; i<32; i++)
			bv[i] = S.bv[i];
		M = S.M;
	}
	return *this;
}

Set Set::operator+ (char ch) // V=*this+ch
{
	Set Res = *this;
	Res.SetUp1((UC)ch);
	Res.M = Res.Weight();
	return Res;
}

Set & Set::operator+= (char ch) // *this=*this+ch
{
	SetUp1((UC)ch);
	M = Weight();
	return *this;
}

Set Set::operator- (Set S) // Res=*this-S
{
	Set Res = *this, V = Res*S;
	Res ^= V;
	Res.M = Res.Weight();
	return Res;
}

Set Set::operator~ (); //addition to Univers

bool Set::operator== (Set S);
void Set::Scan(int) {}
istream & operator>> (istream &r, Set &S)