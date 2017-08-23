#include "iset64.h"

void iset64::free() {

	delete[] _set;

}

void iset64::allocate(int n) {

	_set = new int[n];
}

bool iset64::isPresent(int n) {

	for (int i = 0; i < _numElements; ++i) {

		if (_set[i] == n) {

			return true;
		}
	}

	return false;

}
