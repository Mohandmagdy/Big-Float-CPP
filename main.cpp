#include <bits/stdc++.h>
#include "BigDecimalIntClass.h"

using namespace std;

BigReal vvv(){
	BigReal honda;
	honda.set_answer("124124");
	cout << "vvv " << honda.whole_ptr << ' ' << honda.fraction_ptr << endl;
	return honda;
}

int main() {
	BigReal a;
	a = BigReal(2.123512);
	cout << a << endl;
	BigReal n1 ("11.9000000000000000000000000000000001");
	BigReal n2 ("2333333333339.1134322222222292");
	BigReal n3 = n1+n2;
	cout << n3 << endl;
	BigReal eg1 ("1.2");
	BigReal eg2("1.20");

	bool x = eg1 ==eg2;
	cout << x << endl;
	BigReal b1 ("6.8");
	BigReal b2 ("4.7");
	BigReal b3 = b1 - b2;
	cout << b3 << endl;
	b3 = b2-b1;
	cout << b3 << endl;
	BigReal n4(n2);
	cout << n4 << endl;
	BigReal n6;
	n6 = vvv();
	cout << n6 << endl;
	cout << n6.whole_ptr << ' ' << n6.fraction_ptr << endl;
}



