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

#include <bits/stdc++.h>
#include "BigDecimalIntClass.h"

using namespace std;

// regex function that checks the validation of the input.
bool BigDecimalInt :: checkValidInput(string input)
{
    /*regex validInput("[-+]?[0-9]+");
    return regex_match(input, validInput);*/
	return true;
}

// constructor that takes a string as an input.
void BigDecimalInt :: setNumber(string num)
{
    bool validNumber = checkValidInput(num);
    if(validNumber)
    {
        number = num;
        if(number[0] == '+')
        {
            number.erase(0,1);
            signNumber = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0,1);
            signNumber = '-';
        }
        else
        {
            signNumber = '+';
        }
    }
    else
    {
        cout << "Invalid" << "\n";
        exit(1);
    }
}

// operator < overloading function.
bool BigDecimalInt :: operator < (const BigDecimalInt& anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(signNumber == '-' && anotherDec.signNumber == '+')
    {
        return true;
    }
    else if(signNumber == '+' && anotherDec.signNumber == '-')
    {
        return false;
    }
    else if(signNumber == '+' && anotherDec.signNumber == '+')
    {
        return comp1 < comp2;
    }
    else
    {
        return comp1 > comp2;
    }
}

// operator > overloading function.
bool BigDecimalInt :: operator > (const BigDecimalInt &anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(signNumber == '-' && anotherDec.signNumber == '+')
    {
        return false;
    }
    else if(signNumber == '+' && anotherDec.signNumber == '-')
    {
        return true;
    }
    else if(signNumber == '+' && anotherDec.signNumber == '+')
    {
        return comp1 > comp2;
    }
    else
    {
        return comp1 < comp2;
    }
}

// operator == overloading function.
bool BigDecimalInt :: operator == (const BigDecimalInt anotherDec)
{
    if (signNumber == anotherDec.signNumber && number == anotherDec.number)
    {
        return true;

    }
    else
    {
        return false;
    }
}

// operator = overloading function.
BigDecimalInt& BigDecimalInt :: operator = (BigDecimalInt anotherDec)
{
    signNumber = anotherDec.signNumber;
    number = anotherDec.number;
    return *this;
}

//addition implementation.
string addition(string num1,string num2)
{
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    string res = "";
    int carry = 0;
    while (it1 != num1.rend())
    {
        int twoDigitsSum;
        carry = 0;
        twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
        if (twoDigitsSum >= 10)
        {
            carry = 1;
        }
        res = char((twoDigitsSum % 10) + '0') + res;
        *(it1 + 1) = char(((*(it1 + 1) - '0') + carry) + '0');
        it1++;
        it2++;
    }
    if (carry)
    {
        res = char((carry) + '0') + res;
    }
    return res;
}

//subtraction implementation
string subtraction(string num1,string num2){
    deque<long long>d;
    string res;

    for (long long i = num1.length() - 1; i >= 0; i--)
    {
        if (num1[i] < num2[i])
        {
            num1[i] = char (((num1[i] - '0') + 10) + '0');
            num1[i - 1] = char (((num1[i - 1] - '0') - 1) + '0');
            d.push_front((num1[i] - '0') - (num2[i] - '0'));
        }
        else
        {
            d.push_front((num1[i] - '0') - (num2[i] - '0'));
        }
    }

    for (auto i : d)
    {
        res += to_string(i);
    }
    return res;
}

// // operator + overloading function.
BigDecimalInt BigDecimalInt :: operator + (BigDecimalInt number2)
{
    BigDecimalInt result;
    char signNumber1 = signNumber, signNumber2 = number2.signNumber;
    string num1 = number, num2 = number2.number;
    BigDecimalInt number1 = *this;

    while (num1.length() < num2.length()){
        num1 = '0' + num1;
    }
    while (num2.length() < num1.length()){
        num2 = '0' + num2;
    }

    if (signNumber1 == signNumber2){
        result.signNumber = signNumber1;
        result.number = addition(num1,num2);

    }else{

        if(number1.signNumber == '-')
        {
            number1.signNumber = '+';
            result = (number2 - number1);
        }
        else{
            number2.signNumber = '+';
            result = (number1 - number2);
        }
    }
    return result;
}

// operator - overloading function.
BigDecimalInt BigDecimalInt :: operator - (BigDecimalInt anotherDec)
{
    BigDecimalInt obj;
    deque<long long> d;
    string strmin = "", res = "";
    string num1 = number, num2 = anotherDec.number;
    char sign1 = signNumber, sign2 = anotherDec.signNumber;

    if (number.length() > anotherDec.number.length())
    {
        for (long long i = 0; i < number.length() - anotherDec.number.length(); i++)
        {
            strmin += '0';
        }
        strmin += anotherDec.number;
        num2 = strmin;
    }
    else if (number.length() < anotherDec.number.length())
    {
        for (long long i = 0; i < anotherDec.number.length() - number.length(); i++)
        {
            strmin += '0';
        }
        strmin += number;
        num1 = strmin;
    }

    bool ok = false, is_determined = false;
    if (num1 < num2)
    {
        swap(num1, num2);
        swap(sign1, sign2);
        ok = true;
    }

    if (sign1 == sign2 )
    {
        res = subtraction(num1,num2);

        if(sign1=='-')ok = !ok;
    }
    else
    {
        res = addition(num1,num2);
        if(signNumber == '-')
        {
            obj.signNumber = '-';
            is_determined = true;
        }
        else
        {
            obj.signNumber = '+';
            is_determined = true;
        }

    }

    bool right = false;
    for (long long i = 0; i < res.length(); i++)
    {
        if (res[i] != '-' && res[i] != '0')
        {
            right = true;
        }
        if (!right && res[i] == '0')
        {
            res.erase(i, 1);
            i--;
        }
    }

    if(res.empty()) res = "0";
    if (!is_determined && (ok))
    {
        obj.signNumber = '-';
    }
    else if(!is_determined)
    {
        obj.signNumber = '+';
    }

    obj.number = res;
    return obj;
}

// function to return the size of number.
int BigDecimalInt :: size()
{
    return number.size();
}

// function returns the sign.
int BigDecimalInt :: sign()
{
    if (signNumber == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// operator << overloading function.
ostream &operator << (ostream &out, BigDecimalInt num)
{
    if(num.signNumber == '+')
    {
        out << num.number ;
    }
    else
    {
        if(num.number == "0")
        {
            out << num.number ;
        }
        else
        {
            out << num.signNumber << num.number ;
        }
    }
    return out;
}



void BigReal::into_two(string input) {
		bool check = false;
		if (input[0] == '+' || input[0] == '-'){
			who += input[0];
			frac += input[0];
			for (int i = 1; i < input.size(); i++){
				if (!check && input[i]!='.'){
					who+=input[i];
				}
				else if (!check){
					check = true;
				}
				else{
					frac += input[i];
				}
			}
		}
		else{
			for (int i = 0; i < input.size(); i++){
				if (!check && input[i]!='.'){
					who+=input[i];
				}
				else if (!check){
					check = true;
				}
				else{
					frac += input[i];
				}
			}
		}
		whole.setNumber(who);
		fraction.setNumber(frac);
}

BigReal::BigReal() {
	digits = "0";
	whole.setNumber("0");
	fraction.setNumber("0");
	whole_ptr = &whole;
	fraction_ptr = &fraction;
	answer = "0.0";
}

BigReal::BigReal(string realNumber) {
	digits = realNumber;
	answer = realNumber;
	into_two(realNumber);
	whole_ptr = &whole;
	fraction_ptr = &fraction;
}

BigReal::BigReal(long double num) {
	string input = to_string(num);
	digits = input;
	answer = input;
	into_two(input);
	whole_ptr = &whole;
	fraction_ptr = &fraction;
}

BigReal::BigReal(const BigReal &obj) {
	whole = obj.whole;
	fraction = obj.fraction;
	who=obj.who;
	frac=obj.frac;
	answer=obj.answer;
	whole_ptr = &whole;
	fraction_ptr = &fraction;
}

BigReal::BigReal(BigReal &&other) {
	whole_ptr = other.whole_ptr;
	fraction_ptr = other.fraction_ptr;
	other.whole_ptr = nullptr;
	other.fraction_ptr = nullptr;
	whole = *whole_ptr;
	fraction = *fraction_ptr;
	answer = other.answer;
}

BigReal &BigReal::operator=(BigReal &other) {
	whole = other.whole;
	fraction=other.fraction;
	answer = other.answer;
	return *this;
}

BigReal &BigReal::operator=(BigReal &&other)  {
	if (whole_ptr == other.whole_ptr && fraction_ptr == other.fraction_ptr)
		return *this;
	whole_ptr = other.whole_ptr;
	fraction_ptr = other.fraction_ptr;
	other.whole_ptr = nullptr;
	other.fraction_ptr = nullptr;
	whole = *whole_ptr;
	fraction= *fraction_ptr;
	answer = other.answer;
	return *this;
}


BigReal BigReal::operator+(BigReal &other) {
	BigReal ans, num1 = *this;
	bool two_minus = false;
	if ((whole.sign() && other.whole.sign()) || ((!whole.sign()) && (!other.whole.sign()))) {
		if ((!whole.sign()) && (!other.whole.sign())) {two_minus = true;}
		ans.whole = whole + other.whole;
		ans.fraction = fraction + other.fraction;
		if (ans.fraction.size() > max(fraction.size(), other.fraction.size())) {
			string f = ans.fraction.getNumber();
			ans.fraction.setNumber(f.substr(1, f.size() - 1));
			BigDecimalInt one("1");
			ans.whole = ans.whole - one;
		}
		if (two_minus) {
			ans.answer = "-" + ans.whole.getNumber() + "." + ans.fraction.getNumber();
		} else { ans.answer = ans.whole.getNumber() + "." + ans.fraction.getNumber(); }
		return ans;
	} else if (whole > other.whole) {
		return num1 - other;
	} else {
		return other - num1;
	}
}

BigReal BigReal::operator-(BigReal &other) {
	BigReal ans;
	*ans.whole_ptr = *whole_ptr - *other.whole_ptr;
	*ans.fraction_ptr = *fraction_ptr - *other.fraction_ptr;
	if (*fraction_ptr < *other.fraction_ptr && *whole_ptr > *other.whole_ptr) {
		string new_str = ans.fraction_ptr->getNumber();
		for (int i = 0; i < ans.fraction_ptr->size(); i++) {
			new_str[i] = 9 - (new_str[i] - '0') + '0';
		}
		ans.fraction_ptr->setNumber(new_str);
		BigDecimalInt one("1");
		*ans.whole_ptr = *ans.whole_ptr + one;
	}
	ans.answer = ans.whole_ptr->getNumber() + "." + ans.fraction_ptr->getNumber();
	string non_lead_zero = ans.answer;
	while (non_lead_zero[0] == '0')non_lead_zero = non_lead_zero.substr(1, non_lead_zero.size());
	ans.answer = non_lead_zero;
	return ans;
}

int BigReal::size() {
	return whole.size() + fraction.size() + 1;
}

int BigReal::sign() {
	return whole.sign();
}

bool BigReal::operator==(BigReal anotherReal) {
	if (whole == anotherReal.whole && fraction == anotherReal.fraction)return true;
	else return false;
}

bool BigReal::operator<(BigReal anotherReal) {
	if (whole < anotherReal.whole) {
		return true;
	} else if (whole == anotherReal.whole && fraction < anotherReal.fraction) {
		return true;
	}
	return false;
}

bool BigReal::operator>(BigReal anotherReal) {
	if (whole>anotherReal.whole){
		return true;
	}
	else if (whole == anotherReal.whole && fraction > anotherReal.fraction){
		return true;
	}
	return false;
}

BigReal::BigReal(BigDecimalInt bigInteger) {
	whole = bigInteger;
	fraction.setNumber("0");
}

// operator << overloading function.
ostream &operator << (ostream &out, BigReal num)
{
    if(num.sign() == 1)
    {
        out << num.get_answer() ;
    }
    else
    {
        if(num.get_answer() == "0")
        {
            out << num.get_answer();
        }
        else
        {
            out << "-" << num.get_answer() ;
        }
    }
    return out;
}





