#include <iostream>

// Write a non-recursive and recursive program to calculate
// Fibonacci numbers and analyze their time and space complexity.

using namespace std;
using ll = long long;

ll recursive(int count) {
	if (count <= 1) return count;
	return recursive(count-1) + recursive(count-2);
}

ll iterative(int count) {
	ll n1 = 1;
	ll n2 = 0;
	
	for (int i = 0; i < count; i++) {
		ll temp = n1;
		n1 = n1 + n2;
		n2 = temp;
	}

	return n2;
}


int main() {

	cout << "HW!" << endl;

	ll res = recursive(10);

	cout << "RECURSIVE: " << res << endl;

	res = iterative(10);
	cout << "ITERATIVE: " << res << endl;
	
	return 1;
}
