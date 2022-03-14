#include <iostream>
#include <cmath>
#include <iomanip>


int main(){
	float D,T;
	std::cin >> T ;
	if (T>0 && T<=5){
		D= (T *(30) + T*(22))/2;
		std::cout << std::fixed<<std::setprecision(2)<< D ;
	}
	return 0 ;
}
