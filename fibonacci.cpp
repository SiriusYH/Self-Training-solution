#include <iostream>
using namespace std;


int main(){
	int required;
	long long int first= 0, second =1, number;
	cin >> required ;
	if ((required >=2) & (required <=50)){
		for(int x=2; x<= required ; x++){
		number= first + second;
		first=second;
		second=number;
		}
	cout << number <<endl;
	}
	return 0;
}
