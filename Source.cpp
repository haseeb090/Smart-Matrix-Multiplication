#include "Smatrix.h" 
using namespace std;

//Haseeb Khizar BSCS-3B 4624
//Lab 2



int main() {
	auto_ptr <matrix> a(new matrix(4, 4)); // constructor arguments are the number of rows and columns for the matrix
	auto_ptr <matrix> b(new matrix(4, 4));
	auto_ptr <matrix> c(new matrix(4, 4));
	//auto_ptr <matrix> d(new matrix(2, 2));
	
	a->inputmat();
	cout << "Matrix A" << endl;
	a->printmat();
	fflush(stdin);
	b->inputmat();
	cout << endl;
	cout << "Matrix B" << endl;
	b->printmat();
	c = a->iterativemul(b);
	cout << endl;
	cout << "A x B (Iterative Multiplication)" << endl;
	c->printmat();
	cout << endl;
	/*d = a->strassenmul(b);
	cout << endl;
	cout << "A x B (Stressan Multiplication)" << endl;
	cout << endl;
	d->printmat();*/
	system("PAUSE");
	return 0;

}