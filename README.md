# TODO
* генерация случайной матрицы в отдельном заголовочном файле
* перенести однострочные функции (все кроме умножения в заголовочный файл)
* добавить оптимизацию и ворнинги к флагам
* Убрать дублирование кода в умножении. Умножение вынести. Сделать функцией, а не методом. К `m_data` обращаться через опреатор ()
* Вынести умножение в отдельную функцию `mulSerial(Matrix A,Matrix B)`, (потом появится `mulOpenMP()`), запихать их в `Matrix` вместе с `toString`
* добавить параллельное заполнение матрицы. статичным методом.
	```cpp
	static Matrix::rand(size_t rows, size_t cols)
	```
* Приватный конструктор (или не приватный но спроверкой размерности)
	```cpp
	Matrix(size_t rows, size_t cols, std::vector<double> m_data)
	```