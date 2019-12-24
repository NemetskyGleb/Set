#pragma once
#include <iostream>
#include "BoolVector.h"

class Set : public BoolVector {
private:
	int M;  //кол-во элементов мн-ва
public:
	Set();
	Set(char* s);
	Set(Set&);
	Set& operator=(Set&);
	Set(BoolVector& V);
	virtual ~Set() {};
	/* operations*/
	Set operator+ (char ch); // V = *this + ch
	Set& operator+= (char ch); // *this=*this+ch
	Set operator+ (Set S); // V=*this+S
	Set& operator+= (Set S); // *this=*this+S
	Set operator- (char ch); // V=*this-ch
	Set& operator-= (char ch); // *this=*this-ch
	Set operator- (Set S); // V=*this-S
	Set& operator-= (Set S); // *this=*this-S
	Set operator* (Set S); //intersection, new set
	Set  operator*= (Set S); //intersection, change *this

	Set operator~(); //addition to Univers

	bool operator==(Set S);
	bool operator!= (Set S);
	
	int Number() { return M; };
	void Scan();
	void Print() override;

	friend std::ostream & operator<<(std::ostream& r, Set &S);
	friend std::istream & operator>>(std::istream& r, Set &S);
}; 