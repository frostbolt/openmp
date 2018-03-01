# TODO
- [ ] генерация случайной матрицы зерез OpenMP
- [ ] перенести однострочные функции (все кроме умножения в заголовочный файл), сделать их `inline`'овыми
- [ ] ~~добавить оптимизацию~~ и ворнинги к флагам
- [x] избавиться от куска интерфейса в умножении матриц с помощью прерывания. как в примере.
	```cpp
	#include <stdexcept> 
	bool example(int x) {
		if (x != 0) {
			throw std::invalid_argument("x != 0");
		}
		return true;
	}
	```
- [x] Вынести умножение в отдельную функцию `mulSerial(Matrix A,Matrix B)`, (потом появится `mulOpenMP()`), запихать их в `Matrix` вместе с `toString` К `m_data` обращаться через опреатор ()
- [x] Убрать дублирование кода в умножении. Умножение вынести. Сделать функцией, а не методом. В операторе умножения просто вызывать функцию `mulSerial(Matrix A, Matrix B)` или `mulOpenMP(Matrix A, Matrix B)`
- [ ] добавить параллельное заполнение матрицы. статичным методом.
	```cpp
	static Matrix::rand(size_t rows, size_t cols)
	```
- [ ] Приватный конструктор (или не приватный но спроверкой размерности)
	```cpp
	Matrix(size_t rows, size_t cols, std::vector<double> m_data)
	 : m_rows(size_t rows), m_rows(size_t cols), m_rows(size_t cols) {} 
		```

