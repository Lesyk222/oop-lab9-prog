#include "CMultiSet.h"

using namespace std;

int main() {

	CMultiSet<short int> intMultiset;

	cin >> intMultiset;
	cout << "Output int multiset: " << intMultiset;

	CMultiSet<double> doubleMultiset;
	cin >> doubleMultiset;
	cout << "Output double multiset: " << doubleMultiset;
}