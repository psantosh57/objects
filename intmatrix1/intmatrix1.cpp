#include "intmatrix1.h"

void intmatrix1::init() {

	this->row = 0;
	this->column = 0;

}

void intmatrix1::init(int r, int c, int e) {

	if (r == 0 || c == 0) {

		//cout << "Invalid matrix" << endl;
		this->row = 0;
		this->column = 0;
	}
	else {

		this->row = r;
		this->column = c;

		int size = this->row*this->column;

		this->matrix = new int[size];

		for (int i = 0; i < size; i++) {

			this->matrix[i] = e;
		}

	}
}

void intmatrix1::init(const char* str) {

	int num = 0;
	int sum = 0;
	int arr[2] = { 1,1 };
	int i = 0;
	int j = 0;
	int k = 0;
	bool ifColFixed = false;
	int columns = 0;
	bool firstCol = false;
	int firstNum = 0;
	bool ifInvalid = false;

	//cout << "Input string is " << str << endl;

	if (str == "") {

		this->row = 0;
		this->column = 0;

	}
	else {

		while (str[i] != '\0') {

			//cout << "Setting j to " << i << endl;

			j = i;

			while (str[j] != '|' && str[j] != '\0') {

				//cout << "Current element is at index " << j << " = " << str[j] << endl;

				if (isDigit(str[j])) {

					k = j;

					while (isDigit(str[k + 1])) {

						k++;
					}

					j = k;
					firstNum++;
					//cout << "Incrementing firstNum to " << firstNum << " at index " << j << endl;
					if (firstNum > 1) {
						arr[1]++;
						//cout << "Incrementing column cnt to " << arr[1] << endl;

					}

				}

				j++;
				if (str[j] == '\0') {
					break;
				}
			}

			//cout << "Index after integer is " << j << " and char is " << str[j] << endl;
			//cout << "Column cnt is " << arr[1] << endl;

			if (str[j] == '|') {
				//cout << "Came here at index " << j << endl;
				arr[0]++;
				if (!ifColFixed) {
					columns = arr[1];
					//cout << "Fixing column width to " << columns << endl;
					arr[1] = 1;
					firstNum = 0;
					ifColFixed = true;
				}
				else if (columns != arr[1]) {
					//cout << "Invalid matrix input" << endl;
					//cout << "Prev col = " << columns << " current col = " << arr[1] << endl;
					ifInvalid = true;

				}
				else if (columns == arr[1]) {
					arr[1] = 1;
					firstNum = 0;

				}


			}

			else if (str[j] == '\0') {

				//cout << "Came here!!!!!!!! " << columns << " " << arr[1] << endl;
				//cout << "ifColFixed is " << ifColFixed << endl;

				if (!ifColFixed) {
					columns = arr[1];
					//cout << "Fixing column width to " << columns << endl;
					arr[1] = 1;
					firstNum = 0;
					ifColFixed = true;
					continue;
				}

				if (columns != arr[1]) {
					//cout << "Invalid matrix at end" << endl;
					//cout << "Prev col = " << columns << " current col = " << arr[1] << endl;
					ifInvalid = true;
					//break;

				} 

			}

			i = j;

			i++;
			if (str[i] == '\0') {
				break;
			}
		}


		if (ifInvalid) {

			this->row = 0;
			this->column = 0;
		}
		else {

			//cout << "Creating 2d array with row = " << arr[0] << " and col = " << arr[1] << endl;
			this->row = arr[0];
			this->column = arr[1];
			int size = this->row*this->column;

			this->matrix = new int[size];

			for (int i = 0; i < size; i++) {

				this->matrix[i] = 0;
				//cout << this->matrix[i] << endl;
			}

			fillMatrix(this->matrix, this->row, this->column, str);

			//display(this->matrix, this->row, this->column);

		}

	}

}

bool intmatrix1::isDigit(char ch) {

	int ch1 = ch - '0';

	return (ch1 >= 0 && ch1 <= 9) ? true : false;
}


void intmatrix1::display(int* mat, int r, int c) {

	cout << "Displaying matrix" << endl;

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < c; j++) {

			cout << mat[(i*c) + j]<<" ";
		}

		cout << endl;
	}

}

void intmatrix1::fillMatrix(int*& mat, int r, int c, const char* str) {

	//cout << "Filling matrix" << endl;

	int ii = 0;
	int jj = 0;
	int kk = 0;
	int grandSum = 0;

		while (str[ii] != '\0') {
		
			if (isDigit(str[ii])) {
				
				jj = ii;

				 do {

					grandSum = grandSum * 10 + toDigit(str[jj]);
					jj++;

				 } while (isDigit(str[jj]));

				ii = jj;
				//cout << "Sum at index " << kk << " is " << grandSum << endl;
				mat[kk] = grandSum;
				kk++;
				grandSum = 0;
				
				
			}

			ii++;

		}

}

int intmatrix1::toDigit(char ch) {

	return (ch - '0');
}

void intmatrix1::print(const char* str) {

	cout << "----------" << str << "----------" << endl;
	//cout << "Rows = " << this->row << " Columns = " << this->column << endl;

	if (this->row == 0 && this->column == 0) {

		cout << "Empty Matrix" << endl;
	}

	for (int i = 0; i < this->row; i++) {

		for (int j = 0; j < this->column; j++) {

			cout << this->matrix[((i*this->column) + j)]<<" ";
		}

		cout << endl;
	}
}

void intmatrix1::fini() {

	if (this->row != 0 && this->column != 0) {
		delete[] this->matrix;
	}
	
}

bool intmatrix1::isEmpty() {

	return (this->row == 0 && this->column == 0) ? true : false;
}

bool intmatrix1::isEqual(intmatrix1 rhs) {

	//cout << "lhs row = " << this->row << " lhs column = " << this->column << endl;
	//cout << "rhs row = " << rhs.row << " rhs column = " << rhs.column << endl;

	if (this->row != rhs.row || this->column != rhs.column) {
		return false;
	}
	else {
		int size = this->row*this->column;
		for (int i = 0; i < size; i++) {

			if (this->matrix[i] != rhs.matrix[i]) {

				return false;
				break;
			}
		}

		return true;
	}

}

intmatrix1 intmatrix1::add(intmatrix1 rhs) {

	intmatrix1 ans;

	if (this->row != rhs.row || this->column != rhs.column) {

		ans.row = 0; 
		ans.column = 0;

	}
	else {

		int size = this->row*this->column;
		ans.row = this->row;
		ans.column = this->column;
		ans.matrix = new int[size];

		for (int i = 0; i < size; i++) {

			ans.matrix[i] = this->matrix[i] + rhs.matrix[i];
		}

	}

	return ans;

}

intmatrix1 intmatrix1::mult(intmatrix1 rhs) {

	intmatrix1 ans;

	if (this->column != rhs.row) {

		ans.row = 0;
		ans.column = 0;
	}
	else {

		ans.row = this->row;
		ans.column = rhs.column;

		//cout << "DIMENSIONS FOR ANS ARE ROWS = " << ans.row << " COLUMNS = " << ans.column << endl;

		int size = ans.column*ans.row;
		ans.matrix = new int[size];

		for (int k = 0; k < size; k++) {

			ans.matrix[k] = 0;
		}


		for (int i = 0; i < this->row; i++) {

			for (int j = 0; j < rhs.column; j++) {

				for (int k = 0; k < this->column; k++) {
					//cout << "Multiplying " << this->matrix[(i*this->column) + k] << " and " << rhs.matrix[k*(rhs.row) + j] << endl;
					ans.matrix[((i*ans.column) + j)] += this->matrix[(i*this->column) + k] * rhs.matrix[k*(rhs.column) + j];
				}
			}
		}			

	}

	return ans;


}