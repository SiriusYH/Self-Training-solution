#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

long double x;
bool isPerfectSquare(long double x)
{
    if (x >= 0) {
        long long sr = sqrt(x);
        long long sru = sqrt (x+2021);
        return ((sr * sr == x)&&(sru * sru == (x+2021)));
    }
    // else return false if n<0
    return false;
}
 
int main()
{
	long double x = 1;
    while (x>0){
    	if (isPerfectSquare(x)==true){
    		cout << x <<endl ;
    		x++; 
		}
		else if (isPerfectSquare(x)==false){
			x++;
			continue;}
	}
	
}
