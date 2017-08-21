#include "../util/util.h"

#ifndef ISET64_H
#define ISET64_H

class iset64 {

public:

	iset64() :_set(nullptr), _numElements(0) {

		cout << "In iset64 constructor" << endl;
	}

	~iset64() {

		cout << "In iset64 destructor" << endl;

		free();

		_numElements = 0;
	}

	iset64(const iset64& rhs) {

		cout << "In copy constructor" << endl;

		free();

		_numElements = rhs._numElements;

		allocate(_numElements);

		for (int i = 0; i < _numElements; ++i) {

			_set[i] = rhs._set[i];

		}


	}

	void free();

	void allocate(int n);

	friend ostream& operator<<(ostream& o, const iset64& a) {

		cout << "In operator<< " << endl;

		cout << "{ ";
		for (int i = 0; i < a._numElements; ++i) {

			cout << a._set[i] << " ";
		}

		cout << "}" << endl;

		return o;

	}

	friend iset64& operator+(iset64& rhs) {



	}

	iset64& operator+(int n) {

		cout << "In operator+" << endl;

		if (!isPresent(n)) {

			if (_set) {

				iset64 temp = *this;

				free();

				_numElements++;

				allocate(_numElements);

				int i = 0;
				for (i = 0; i < _numElements; ++i) {

					_set[i] = temp._set[i];
				}

				_set[i] = n;

			}
			else {

				_numElements++;

				allocate(_numElements);

				_set[0] = n;

			}

		}

		cout << "Current value of numElem " << _numElements << endl;

		return *this;

	}

	iset64& operator+=(int n) {

		cout << "In operator+" << endl;

		if (!isPresent(n)) {

			if (_set) {

				iset64 temp = *this;

				free();

				_numElements++;

				allocate(_numElements);

				int i = 0;
				for (i = 0; i < _numElements; ++i) {

					_set[i] = temp._set[i];
				}

				_set[i] = n;

			}
			else {

				_numElements++;

				allocate(_numElements);

				_set[0] = n;

			}

		}

		cout << "Current value of numElem " << _numElements << endl;

		return *this;

	}

	iset64& operator=(const iset64& rhs) {

		cout << "In operator =" << endl;

		if (this != &rhs) {

			free();

			_numElements = rhs._numElements;

			allocate(_numElements);

			for (int i = 0; i < _numElements; ++i) {

				_set[i] = rhs._set[i];
			}

			return *this;

		}
		

	}

	bool isPresent(int n);
	//void sort();




private:

	int* _set;
	int _numElements;
};


#endif