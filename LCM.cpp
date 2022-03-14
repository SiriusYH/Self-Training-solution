#include <iostream>
using namespace std;

int main(){
	int num1, num2 ,num3, maximum;
	cin >> num1 >> num2 >> num3;
	
	maximum= (num1 >num2) ? num1 : num2;
	maximum= (maximum > num3)? maximum : num3;
	for (;;){
		if(maximum %num1 ==0 && maximum % num2 ==0 && maximum % num3 ==0){
			cout << maximum <<endl;
			break;
		}
		else
			maximum++;
	}
	return 0;
}
