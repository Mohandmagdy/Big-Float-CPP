// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 1
// Program Name: BigDecimalInt
// Last Modification Date: 13/10/2022
// Author1 and ID and Group: Basmala Mohamed Sayed Gad  ID: 20210090 (a, b, c)
// Author2 and ID and Group: Aya Ali Hassan  ID: 20210083 (d, e)
// Author3 and ID and Group: Mohamed Ashraf Fahim  ID: 20210329 (f, i, j , k)
/*
description: In this problem we developed a new C++ type (class).
that can hold unlimited decimal integer values and performs arithmetic operations on them.
such as: +, -, <, and >.
 */

#ifndef BIGDECIMALINT_BIGDECIMALINTCLASS_H
#define BIGDECIMALINT_BIGDECIMALINTCLASS_H

#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#include <regex>
#include <utility>

using namespace std;

class BigDecimalInt{
private:
    string number;
    char signNumber;
    bool checkValidInput(string input);
    void split(string num);
public:
    bool operator < (const BigDecimalInt& anotherDec);
    bool operator > (const BigDecimalInt& anotherDec);
    bool operator == (const BigDecimalInt anotherDec);
    BigDecimalInt& operator = (BigDecimalInt anotherDec);
    BigDecimalInt operator + (BigDecimalInt number2);
    BigDecimalInt operator - (BigDecimalInt anotherDec);
    friend ostream &operator << (ostream &out, BigDecimalInt num);
    int size();
    int sign();
    void setNumber(string num);
    string getNumber(){
        return number;
    }
    BigDecimalInt(){
        number = "0";
    }
	BigDecimalInt(string input):number(input){}
};
class BigReal{
	string digits = "", who = "", frac = "", answer = "";
	BigDecimalInt whole, fraction;
	void into_two(string num);
public:
	BigDecimalInt* whole_ptr;
	BigDecimalInt* fraction_ptr;
	BigReal();
	BigReal(string realNumber);
	BigReal(long double num);
	BigReal (BigDecimalInt bigInteger);
	BigReal(const BigReal& obj);
	BigReal (BigReal&& other);
	BigReal& operator= (BigReal& other);
	BigReal& operator= (BigReal&& other);
	BigReal operator+ (BigReal &other);
	BigReal operator- (BigReal &other);
	bool operator== (BigReal anotherReal);
	bool operator< (BigReal anotherReal);
	bool operator> (BigReal anotherReal);
	int size();
	int sign();
    friend ostream &operator << (ostream &out, BigReal num);
	void set_answer(string s){
		answer = s;
	}
	string get_answer(){
		return answer;
	}
};

#endif //BIGDECIMALINT_BIGDECIMALINTCLASS_H