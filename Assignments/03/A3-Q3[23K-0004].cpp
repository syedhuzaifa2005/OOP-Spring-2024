#include <iostream>
using namespace std;


template <typename T>
class Matrix{
protected:
	T** matrix;
	int Rows;
	int Columns;
	
public:
	Matrix(int rows, int cols){
		Rows = rows;
		Columns = cols;
		
		matrix = new T*[rows];
		for(int i = 0; i < rows; i++){
			matrix[i] = new T[cols];
		}
	}
	
	~Matrix(){
		for(int i = 0; i < Rows; i++){
			delete[] matrix[i];
		}
		
		delete[] matrix;
	}
	
	
	int get_Rows() const{
		return Rows;
	}
	int get_Columns() const{
		return Columns;
	}
	
	T getElements(int row, int col) const{
		return matrix[row][col];
	}
	void setElements(int row, int col, T value){
		matrix[row][col] = value;
	}
	
	
	Matrix<T> operator+(const Matrix<T>& other) const{
		if(Rows != other.Rows  ||  Columns != other.Columns){
			cout << "Error!! The dimensions of the matrices should be same in order to ADD them" << endl;
		}
		Matrix<T> result(Rows, Columns);
		for(int i = 0; i < Rows; i++){
			for(int j = 0; j < Columns; j++){
				result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
				}
			}
		return result;
	}
	
	Matrix<T> operator-(const Matrix<T>& other) const{
		if(Rows != other.Rows  ||  Columns != other.Columns){
			cout << "Error!! The dimensions of the matrices should be same in order to ADD them" << endl;
		}
		Matrix<T> result(Rows, Columns);
		for(int i = 0; i < Rows; i++){
			for(int j = 0; j < Columns; j++){
				result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
			}
		}
		return result;
	}
	
	Matrix<T> operator*(const Matrix<T>& other) const{
		if(Columns != other.Rows){
			cout << "Error!! Conditions for multiplication are not Valid" << endl;
		}
		Matrix<T> result(Rows, other.Columns);
		for (int i = 0; i < Rows; i ++) {
            for (int j = 0; j < other.Columns; j++) {
               	result.matrix[i][j] = 0;
               	for (int k = 0; k < Columns; k++) {
                   	result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
               	}
           	}
       	}
		return result;
	}
	
	
	virtual void Display(){
		for(int i = 0; i < Rows; i++){
			for(int j = 0; j < Columns; j++){
				cout << matrix[i][j] << "\t"; 
			}
			cout << endl;
		}
	}
};


class IntMatrix: public Matrix<int> {
public:
	IntMatrix(int rows, int cols): Matrix(rows, cols){
		
	}
	void Display(){
		Matrix<int>::Display();
	}
};


class DoubleMatrix: public Matrix<double> {
public:
	DoubleMatrix(int rows, int cols): Matrix(rows, cols){
		
	}
	void Display(){
		Matrix<double>::Display();
	}
};

int main(){
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl;
	
	IntMatrix intMatrix01(2, 2);
	intMatrix01.setElements(0, 0, 4);
	intMatrix01.setElements(0, 1, 3);
	intMatrix01.setElements(1, 0, 6);
	intMatrix01.setElements(1, 1, 9);
	
	IntMatrix intMatrix02(2,2);
	intMatrix02.setElements(0, 0, 7);
	intMatrix02.setElements(0, 1, 2);
	intMatrix02.setElements(1, 0, 3);
	intMatrix02.setElements(1, 1, 5);


	Matrix<int> intAddResult = intMatrix01 + intMatrix02;
	cout << "INTEGER Matrix ADDITION Result: " << endl;
	intAddResult.Display();
	cout << endl;
	
	
	Matrix<int> intSubtractResult = intMatrix01 - intMatrix02;
	cout << "INTEGER Matrix SUBTRACTION Result: " << endl;
	intSubtractResult.Display();
	cout << endl;
	
	
	Matrix<int> intMultiplyResult = intMatrix01 * intMatrix02;
	cout << "INTEGER Matrix MULTIPLICATION Result: " << endl;
	intMultiplyResult.Display();
	cout << endl;
	
	
	
	DoubleMatrix doubleMatrix01(2, 2);
	doubleMatrix01.setElements(0, 0, 3.7);
	doubleMatrix01.setElements(0, 1, 2.9);
	doubleMatrix01.setElements(1, 0, 6.2);
	doubleMatrix01.setElements(1, 1, 4.3);
	
	DoubleMatrix doubleMatrix02(2, 2);
	doubleMatrix02.setElements(0, 0, 1.8);
	doubleMatrix02.setElements(0, 1, 2.3);
	doubleMatrix02.setElements(1, 0, 5.4);
	doubleMatrix02.setElements(1, 1, 2.6);


	Matrix<double> doubleAddResult = doubleMatrix01 + doubleMatrix02;
	cout << "DOUBLE Matrix ADDITION Result: " << endl;
	doubleAddResult.Display();
	cout << endl;
	
	
	Matrix<double> doubleSubtractResult = doubleMatrix01 - doubleMatrix02;
	cout << "DOUBLE Matrix SUBTRACTION Result: " << endl;
	doubleSubtractResult.Display();
	cout << endl;
	
	
	Matrix<double> doubleMultiplyResult = doubleMatrix01 * doubleMatrix02;
	cout << "DOUBLE Matrix MULTIPLICATION Result: " << endl;
	doubleMultiplyResult.Display();
	cout << endl;
	
}
