#pragma once
#include <iostream>
typedef unsigned char UC;
class BoolVector{
protected:
	UC *bv;
	int n; //длина булева вектора
	int m; //размер масссива bv
public:
	int Input(char*, int, int, int); //формированием эл-та массива bv
	BoolVector();
	BoolVector(int);
	BoolVector(char*);
	BoolVector(char *s, int N); //strlen(s)!=N
	BoolVector(BoolVector &);
	virtual ~BoolVector(){
		delete[]bv;
	}
	BoolVector & operator=(BoolVector&);

	virtual void Print(){
		UC mask = 1;
		if (n % 8 == 0)
			mask <<= 7;
		else
			mask <<= (n % 8 - 1);

		for (int i = 0; i < m; i++, mask = 1 << 7)
		{
			for (; mask; mask >>= 1)
			{
				if (bv[i] & mask)
					std::cout << '1';
				else
					std::cout << '0';
			}
		}
		std::cout << std::endl;
	}
	virtual void Scan(int N){
		std::cout << "enter bool vector, length " << N << std::endl;
		std::cin.get();
		char *s;
		s = new char[N + 1];
		std::cin.getline(s, N + 1);
		BoolVector T(s);
		*this = T;
		delete[]s;
	}

	int Weight();
	BoolVector operator& (BoolVector); 
	BoolVector& operator&= (BoolVector); 
	BoolVector operator| (BoolVector); 
	BoolVector& operator|= (BoolVector); 
	BoolVector operator^ (BoolVector); 
	BoolVector & operator^= (BoolVector); 
	BoolVector& operator~ ();

	BoolVector operator>> (int); 
	BoolVector& operator>>= (int);
	BoolVector operator<< (int); 
	BoolVector& operator<<= (int); 
	BoolVector SetUp1(int);
	BoolVector SetUp0(int);
	BoolVector SetUp1(int kol, int pos);
	BoolVector SetUp0(int kol, int pos);
	BoolVector Invert(int);
	BoolVector Invert(int kol, int pos);
	UC operator[] (int);
	bool operator== (BoolVector);
	bool operator!= (BoolVector);
	bool operator< (BoolVector);  //x<y если x[i]<=y[i] для всех i
	bool operator> (BoolVector);  //x>y если x[i]>=y[i] для всех i

	friend std::ostream& operator<< (std::ostream &r, BoolVector &V);
	friend std::istream& operator>> (std::istream &r, BoolVector &V);
};
