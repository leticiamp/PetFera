/*
# Disciplina: Linguagem de Programação I
# Professor: Silvio Sampaio
# Alunos:
# ANDRE VITOR MACEDO SOARES
# LETICIA MOURA PINHEIRO
# ODILON JULIO DOS SANTOS
# Projeto Final "PetFera"
===========================================================================
*/

#ifndef _DATA_H_
#define _DATA_H_

#include <iostream>
using namespace std;

class Date{
protected:
	int year_;
	int month_;
	int day_;
public:
	Date();
	Date(const int& d, const int& m, const int& y);

	bool valid(void) const;

	int day() const;
	int month() const;
	int year() const;

	void set_day (const int& day);
	void set_month (const int& month);
	void set_year (const int& year);

	Date operator ++(); // prefix
	Date operator ++(int); // postfix
	Date operator --(); // prefix
	Date operator --(int); // postfix
	friend ostream& operator << (ostream& o, const Date& d); //output operator
	friend istream& operator >> (istream& i, Date& d);
};

bool operator == (const Date&, const Date&); //comparison operators
bool operator != (const Date&, const Date&);
bool operator < (const Date&, const Date&);
bool operator > (const Date&, const Date&);
bool operator <= (const Date&, const Date&);
bool operator >= (const Date&, const Date&);

#endif // _DATA_H_
