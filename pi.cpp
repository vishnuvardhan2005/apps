#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int n;
	do
	{
		cout << "Enter precision :";
		cin >> n;
		cout.precision(n+1);
		cout << 22.0/7 << endl;
	}
	while(1);
	
	return 0;
}
