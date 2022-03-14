#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    double b = 0, total = 0;
    
    cin >> a;

    for(int i = 0; i < a; i++){
        cin >> b;
        total = total + b;
    }
    cout << total / a << endl;
    
	return 0;
}