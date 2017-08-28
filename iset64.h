#include "../util/util.h"

#ifndef ISET64_H
#define ISET64_H

class iset64 {

public:

	iset64() :_set(nullptr), _numElements(0) {

		cout << "In iset64 constructor" << endl;
	}

	iset64(int arr[], int len) {

		cout << "In iset64 [] constructor" << endl;

		_numElements = len;

		allocate(_numElements);

		for (int i = 0; i < _numElements; ++i) {

			_set[i] = arr[i];
		}

	}

	~iset64() {

		cout << "In iset64 destructor" << endl;

		free();

		_numElements = 0;
	}

	iset64(const iset64& rhs) {

		cout << "In copy constructor" << endl;		

		_numElements = rhs._numElements;

		allocate(_numElements);

		for (int i = 0; i < _numElements; ++i) {

			_set[i] = rhs._set[i];

		}


	}

	void free();

	void allocate(int n);

	friend ostream& operator<<(ostream& o, const iset64& a) {

		cout << "{ ";
		for (int i = 0; i < a._numElements; ++i) {

			cout << a._set[i] << " ";
		}

		cout << "}" << endl;

		return o;

	}

	friend iset64 operator+(const iset64& lhs, const iset64& rhs) {

		iset64 sum;

		int numCommonElements = rhs.getNumCommonElements(lhs);

		sum._numElements = lhs._numElements + rhs._numElements - numCommonElements;

		sum.allocate(sum._numElements);

		int rhsInd = 0;
		int lhsInd = 0;
		int sumInd = 0;

		while (lhsInd < lhs._numElements) {

			if (!rhs.isPresent(lhs._set[lhsInd])) {

				sum._set[sumInd] = lhs._set[lhsInd];
				sumInd++;

			}

			lhsInd++;

		}

		while (rhsInd < rhs._numElements) {

			sum._set[sumInd] = rhs._set[rhsInd];
			sumInd++;
			rhsInd++;

		}

		return sum;

	}

	friend iset64 operator+(const iset64& lhs, const int n) {

		if (!lhs.isPresent(n)) {

			cout << "In operator+" << endl;

			iset64 temp;

			temp._numElements = lhs._numElements + 1;

			temp.allocate(temp._numElements);

			temp.copy(lhs);

			temp._set[temp._numElements - 1] = n;

			return temp;

		}
		else {

			cout << n << " is already present in the set" << endl;
			return lhs;

		}

	}

	friend iset64 operator+(const int n, const iset64& rhs) {

		if (!rhs.isPresent(n)) {

			cout << "In operator+" << endl;

			iset64 temp;

			temp._numElements = rhs._numElements + 1;

			temp.allocate(temp._numElements);

			temp.copy(rhs);

			temp._set[temp._numElements - 1] = n;

			return temp;

		}
		else {

			cout << n << " is already present in the set" << endl;

			return rhs;

		}		

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
				for (i = 0; i < (_numElements - 1); ++i) {

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

		return *this;

	}

	iset64& operator+=(const iset64& n) {
		
		//iset64 sum;

		int numCommonElements = getNumCommonElements(n);

		iset64 temp = *this;

		free();

		_numElements = temp._numElements + n._numElements - numCommonElements;

		allocate(_numElements);

		int rhsInd = 0;
		int lhsInd = 0;
		int sumInd = 0;

		while (lhsInd < temp._numElements) {

			if (!n.isPresent(temp._set[lhsInd])) {

				_set[sumInd] = temp._set[lhsInd];
				sumInd++;

			}

			lhsInd++;

		}

		while (rhsInd < n._numElements) {

			_set[sumInd] = n._set[rhsInd];
			sumInd++;
			rhsInd++;

		}

		return *this;

	}

	friend iset64 operator-(const iset64& lhs, int n) {

		cout << "In operator-" << endl;

		iset64 temp;

		if (lhs._numElements) {

			if (lhs.isPresent(n)) {

				temp._numElements = lhs._numElements - 1;

				temp.allocate(temp._numElements);

				temp.remove(n, lhs);

				return temp;

			}
			else {

				cout << "Element not present in set" << endl;
				return lhs;
			}

		}
		else {

			cout << "Cannot remove from empty set" << endl;
			return lhs;
		}

	}

	friend iset64 operator-(int n, const iset64& rhs) {

		cout << "In operator-" << endl;

		iset64 temp;

		if (rhs._numElements) {

			if (rhs.isPresent(n)) {

				temp._numElements = rhs._numElements - 1;

				temp.allocate(temp._numElements);

				temp.remove(n, rhs);

				return temp;

			}
			else {

				cout << "Element not present in set" << endl;
				return rhs;
			}

		}
		else {

			cout << "Cannot remove from empty set" << endl;
			return rhs;
		}

	}

	friend iset64 operator-(const iset64& lhs, const iset64 rhs) {

		iset64 diff;

		int commElem = lhs.getNumCommonElements(rhs);

		diff._numElements = lhs._numElements - commElem;

		diff.allocate(diff._numElements);

		diff.remove(rhs);





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

	bool isPresent(int n) const;
	int getNumCommonElements(const iset64& lhs) const;
	void copy(const iset64& lhs);
	void remove(int n, const iset64& a);
	void remove(const iset64& a);
	//void sort();




private:

	int* _set;
	int _numElements;
};


#endif