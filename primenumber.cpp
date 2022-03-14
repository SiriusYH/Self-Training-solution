#include <iostream>
using namespace std;

int main(){
	int i, k ;
	int request;
	cout << "To which number to find its prime? :" <<endl;
	cin >> request;
	for (i=2 ; i <= request ;i++){
		
		for (k=2; k <=(i/k);k++){
		
		if (!(i%k))break;}
		if(k>(i/k)){
			cout << i <<endl;
		}
	}
	return 0;
}
