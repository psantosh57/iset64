#include "iset64.h"

void iset64::free() {

	delete[] _set;

}

void iset64::allocate(int n) {

	_set = new int[n];
}

bool iset64::isPresent(int n) const {

	for (int i = 0; i < _numElements; ++i) {

		if (_set[i] == n) {

			return true;
		}
	}

	return false;

}

int iset64::getNumCommonElements(const iset64& lhs) const {

	int count = 0;

	for (int i = 0; i < lhs._numElements; ++i) {

		if (isPresent(lhs._set[i])) {

			count++;
		}

	}

	cout << "Number of common elements are " << count << endl;

	return count;

}

void iset64::copy(const iset64& lhs) {

	for (int i = 0; i < lhs._numElements; ++i) {

		_set[i] = lhs._set[i];
	}


}

void iset64::remove(int n, const iset64& temp) {

	for (int i = 0, j = 0; i < _numElements, j < temp._numElements;) {

		if (temp._set[j] != n) {

			_set[i] = temp._set[j];
			i++;
			j++;
		}
		else {

			j++;

		}
	}

}

void iset64::remove( const iset64& temp) {


}