#include <iostream>
using namespace std;

main(){
	int x=6,y=6,z=7;
	z=++y + x--;
	cout << z << endl;
	cout << y << endl;
	cout << x << endl;
	y = ++x;
	cout << y << endl;
	
	cout << (z-- + --y) << endl;
	return 0;
}

/* look at the prepostfix_logic*/
