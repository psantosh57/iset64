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

void iset64::copyCommon(const iset64& lhs, const iset64& rhs) {

	int resInd = 0;

	for (int i = 0; i < lhs._numElements; ++i) {

		if (rhs.isPresent(lhs._set[i])) {

			this->_set[resInd] = lhs._set[i];
			resInd++;
		}

	}

}

void iset64::copyCommon(const iset64& lhs, const int n) {

	int resInd = 0;

	

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

void iset64::remove(const iset64& lhs, const iset64& rhs) {

	int lhsInd = 0;
	int resInd = 0;

	while (lhsInd < lhs._numElements) {

		if (!rhs.isPresent(lhs._set[lhsInd])) {

			this->_set[resInd] = lhs._set[lhsInd];
			resInd++;			

		}

		lhsInd++;
	}

}

bool iset64::compare(const iset64& rhs) const {

	for (int i = 0; i < _numElements; ++i) {

		if (!rhs.isPresent(_set[i])) {

			return false;
		} 

	}

	return true;
}