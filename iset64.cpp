#include "iset64.h"

void iset64::free() {

	cout << "Freeing _set" << endl;

	delete[] _set;

}

void iset64::allocate(int n) {

	cout << "Allocating new array of size " << n << endl;

	_set = new int[n];
}

bool iset64::isPresent(int n) {

	for (int i = 0; i < _numElements; ++i) {

		if (_set[i] == n) {
			cout << n << " is present at index " << i << endl;
			return true;
		}
	}

	return false;

}
