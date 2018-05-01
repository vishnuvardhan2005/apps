#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter n : ";
	cin >> n;
	unsigned long a = 0;
	unsigned long b = 1;
	unsigned long c;
	while(n>0)
	{
		c = a + b;
		cout << c << endl;
		a = b;
		b = c;
		n--;
	}
	return 0;
}
