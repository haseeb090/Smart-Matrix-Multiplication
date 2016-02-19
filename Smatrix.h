#pragma once
#include <iostream>
#include <time.h>
#include <memory>

//Haseeb Khizar BSCS-3B Reg #4624

using namespace std;

class matrix { //matrix class

public:
	int rows;
	int col;
	int** mat; //2D Dynamic array

	matrix(int r, int c) { //Array initialization
		this->rows = r;
		this->col = c;
		this->mat = new int*[r];
		for (int i = 0;i < r; i++) {
			this->mat[i] = new int[c];
		}
	}
	void inputmat() { // Matrix values generation
		srand(time(NULL)); //random number seed time to get different value everytime rand is called
		for (int i = 0; i < this->rows;i++) {
			for (int j = 0;j < this->col; j++) {
				this->mat[i][j] = rand() % 1000; //random number generation limit 1000
			}
		}
	}
	auto_ptr<matrix> iterativemul(auto_ptr<matrix> b) { //iterative multiplication
		auto_ptr<matrix> c (new matrix(b->col, this->rows)); //new matrix to store product in and later return

		for (int i = 0; i < this->rows;i++) {
			for (int j = 0; j < b->col; j++) {
				int sum = 0;
				for (int k = 0; k < this->col;k++) {
					sum = sum + (this->mat[i][k] * b->mat[k][j]);
				}
				c->mat[i][j] = sum;
			}
		}
		return c;
	}
	/*auto_ptr<matrix> strassenmul(auto_ptr<matrix> b) {
		auto_ptr<matrix> c (new matrix(b->col, this->rows));
		int q1 = (this->mat[0][0] + this->mat[1][1]) * (b->mat[0][0] + b->mat[1][1]);
		int q2 = (this->mat[1][0] + this->mat[1][1]) * b->mat[0][0];
		int q3 = (this->mat[0][0]) * (b->mat[0][1] - b->mat[1][1]);
		int q4 = (this->mat[1][1]) * (b->mat[1][0] - b->mat[0][0]);
		int q5 = (this->mat[0][0] + this->mat[0][1]) * b->mat[1][1];
		int q6 = (this->mat[1][0] - this->mat[0][0]) * (b->mat[0][0] + b->mat[0][1]);
		int q7 = (this->mat[0][1] - this->mat[1][1]) * (b->mat[1][0] + b->mat[1][1]);

		c->mat[0][0] = q1 + q4 - q5 + q7;
		c->mat[1][0] = q2 + q4;
		c->mat[0][1] = q3 + q5;
		c->mat[1][1] = q1 + q3 - q2 + q6;

		return c;

	}*/
	void printmat() {
		for (int i = 0; i < this->rows;i++) {
			for (int j = 0; j < this->col;j++) {
				cout << this->mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};