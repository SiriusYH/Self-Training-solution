#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
int total = 0;

int main(){
	
	for (int x=0; x<=1000;x++){
		for(int y=0; y<= 1000;y++){
			for(int z=0; z<= 1000;z++){
				if (x*y*z ==2*(x+y+z)){
					cout << x<< ","<<y<<","<<z <<endl;
					if (x==0 & y==0 &z==0){continue;
					}
					else{total++;
					}
					}
				}
			}
		}
	cout << total <<endl;
	return 0;
}

