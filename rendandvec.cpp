#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> vec_1 {1,2,3,4,5,6,7,8};
	vector<int> vec_2 (vec_1.rbegin(),vec_1.rend());
	for (int i=0;i < vec_2.size();i++){
		cout << vec_2[i]<<endl;
	}
	return 0 ;
}
