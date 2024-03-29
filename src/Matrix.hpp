#include "Matrix.h"

#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace LZebra {

	template<typename T>
	inline T & Matrix<T>::operator[](size_t index)
	{
		return matrix[index];
	}

	template<typename T>
	const T & Matrix<T>::operator[](const size_t ii) const
	{
		return matrix[ii];
	}

	template<typename T>
	T & Matrix<T>::at(const size_t ii)
	{
		if (!this->in_range(ii))
		{
			std::cout << "Index out of bounds!" << '\n';
		}
		return matrix[ii];
	}

	template<typename T>
	const T & Matrix<T>::at(const size_t ii) const
	{
		if (!this->in_range(ii))
		{
			std::cout << "Index out of bounds!" << '\n';
		}
		return matrix[ii];
	}

	template<typename T>
	T & Matrix<T>::operator()(const size_t ii)
	{
		return matrix[ii];
	}

	template<typename T>
	const T & Matrix<T>::operator()(const size_t ii) const
	{
		return matrix[ii];
	}

	template<typename T>
	T & Matrix<T>::at(const size_t in_row, const size_t in_col)
	{
		if (!this->in_range(in_row,in_col))
		{
			std::cout << "Index out of bounds!" << '\n';
		}
		return matrix[in_row * cols + in_col];
	}

	template<typename T>
	const T & Matrix<T>::at(const size_t in_row, const size_t in_col) const
	{
		if (!this->in_range(in_row, in_col))
		{
			std::cout << "Index out of bounds!" << '\n';
		}
		return matrix[in_row * cols + in_col];
	}

	template<typename T>
	T & Matrix<T>::operator()(const size_t in_row, const size_t in_col)
	{
		return matrix[in_row * cols + in_col];
	}

	template<typename T>
	const T & Matrix<T>::operator()(const size_t in_row, const size_t in_col) const
	{
		return matrix[in_row * cols + in_col];
	}

	template<typename T>
	bool Matrix<T>::in_range(const size_t ii) const
	{
		return ii < size;
	}

	template<typename T>
	bool Matrix<T>::in_range(const size_t in_row, const size_t in_col) const
	{
		return this->in_range(in_row * cols + in_col);
	}

	template<typename T>
	inline bool Matrix<T>::is_same_size(const Matrix & m) const
	{
		return rows == m.rows && cols == m.cols;
	}

	template<typename T>
	inline bool Matrix<T>::is_same_size(const size_t in_rows, const size_t in_cols)
	{
		return rows == in_rows && cols == in_cols;
	}

	template<typename T>
	inline bool Matrix<T>::is_same_row(size_t r1, const T val) const
	{
		if (r1 >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		Matrix<T>::const_col_iterator itr = this->begin_row(r1);
		Matrix<T>::const_col_iterator itrend = this->end_row(r1);

		for (;itr != itrend;++itr) {
			if ((*itr) != val)
				return false;
		}

		return true;
	}

	template<typename T>
	inline bool Matrix<T>::is_same_col(size_t in_cols, const T val) const
	{
		if (in_cols >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		Matrix<T>::const_row_iterator itr = this->begin_col(in_cols);
		Matrix<T>::const_row_iterator itrend = this->end_col(in_cols);

		for (; itr != itrend;itr++) {
			if ((*itr) != val)
				return false;
		}

		return true;
	}

	template<typename T>
	inline bool Matrix<T>::is_same_rows(size_t r1, size_t r2, const T val) const
	{
		for (size_t i = r1;i <= r2;++i) {
			if (!this->is_same_row(i, val))
				return false;
		}

		return true;
	}

	template<typename T>
	inline bool Matrix<T>::is_same_cols(size_t c1, size_t c2, const T val) const
	{
		for (size_t i = c1;i <= c2;++i) {
			if (!this->is_same_col(i, val))
				return false;
		}

		return true;
	}

	template<typename T>
	inline bool Matrix<T>::is_equal_rows(size_t r1, size_t r2) const
	{
		if (r1 == r2)
			return true;

		if (r1 >= rows || r2 >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		Matrix<T>::const_col_iterator itr1 = this->begin_row(r1);
		Matrix<T>::const_col_iterator itr1end = this->end_row(r1);
		Matrix<T>::const_col_iterator itr2 = this->begin_row(r2);

		for (; itr1 != itr1end;++itr1, ++itr2) {
			if ((*itr1) != (*itr2))
				return false;
		}

		return true;
	}

	template<typename T>
	inline bool Matrix<T>::is_equal_cols(size_t c1, size_t c2) const
	{
		if (c1 == c2)
			return true;

		if (c1 >= cols || c2 >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		Matrix<T>::const_row_iterator itr1 = this->begin_col(c1);
		Matrix<T>::const_row_iterator itr1end = this->end_col(c1);
		Matrix<T>::const_row_iterator itr2 = this->begin_col(c2);

		for (; itr1 != itr1end;++itr1,++itr2) {
			if ((*itr1) != (*itr2))
				return false;
		}

		return true;
	}

	template<typename T>
	inline void Matrix<T>::reset()
	{
		matrix.clear();
		rows = 0;
		cols = 0;
		size = 0;
	}

	template<typename T>
	inline void Matrix<T>::copysize(const Matrix& m)
	{
		this->set_size(m.rows, m.cols);
	}

	template<typename T>
	inline void Matrix<T>::set_size(const size_t in_rows, const size_t in_cols)
	{
		this->reset();
		matrix = std::vector<T>();
		rows = in_rows;
		cols = in_cols;
		size = in_rows * in_cols;
		matrix.resize(size);
	}

	template<typename T>
	inline void Matrix<T>::resize(const size_t in_rows, const size_t in_cols)
	{
		rows = in_rows;
		cols = in_cols;
		size = in_rows * in_cols;
		matrix.resize(size);
	}

	template<typename T>
	inline void Matrix<T>::reshape(const size_t in_rows, const size_t in_cols)
	{
		rows = in_rows;
		cols = in_cols;
		size = rows * cols;
	}

	template<typename T>
	inline void Matrix<T>::zeros()
	{
		this->fill(0);
	}

	template<typename T>
	inline void Matrix<T>::row_zeros(const size_t in_rows)
	{
		this->fill_row(in_rows, 0);
	}

	template<typename T>
	inline void Matrix<T>::col_zeros(const size_t in_cols)
	{
		this->fill_col(in_cols, 0);
	}

	template<typename T>
	inline void Matrix<T>::zeros(const size_t in_rows, const size_t in_cols)
	{
		this->set_size(in_rows, in_cols);
		for (T& i : matrix) {
			i = 0;
		}
	}

	template<typename T>
	inline void Matrix<T>::ones()
	{
		this->fill(1);
	}

	template<typename T>
	inline void Matrix<T>::row_ones(const size_t in_rows)
	{
		this->fill_row(in_rows, 1);
	}

	template<typename T>
	inline void Matrix<T>::col_ones(const size_t in_cols)
	{
		this->fill_col(in_cols, 1);
	}

	template<typename T>
	inline void Matrix<T>::ones(const size_t in_rows, const size_t in_cols)
	{
		this->set_size(in_rows, in_cols);
		for (T& i : matrix) {
			i = 1;
		}
	}

	template<typename T>
	inline void Matrix<T>::replace(const T old_val, const T new_val)
	{
		for (T& i : matrix) {
			if (i == old_val)
				i = new_val;
		}
	}

	template<typename T>
	inline void Matrix<T>::replace_row(const size_t in_rows, const T old_val, const T new_val)
	{
		if (in_rows >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		Matrix<T>::col_iterator itrend = this->end_row(in_rows);

		for (Matrix<T>::col_iterator itr = this->begin_row(in_rows); itr != itrend;itr++) {
			if (*itr == old_val)
				*itr = new_val;
		}
	}

	template<typename T>
	inline void Matrix<T>::replace_col(const size_t in_cols, const T old_val, const T new_val)
	{
		if (in_cols >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		Matrix<T>::row_iterator itrend = this->end_col(in_cols);

		for (Matrix<T>::row_iterator itr = this->begin_col(in_cols); itr != itrend;itr++) {
			if (*itr == old_val)
				*itr = new_val;
		}
	}

	template<typename T>
	inline void Matrix<T>::fill(const T val)
	{
		for (T& i : matrix) {
			i = val;
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_row(const size_t in_rows, const T val)
	{
		if (in_rows >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		Matrix<T>::col_iterator itr = this->begin_row(in_rows);
		Matrix<T>::col_iterator itrend = this->end_row(in_rows);

		std::fill(itr, itrend, val);
	}

	template<typename T>
	inline void Matrix<T>::fill_col(const size_t in_cols, const T val)
	{
		if (in_cols >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		Matrix<T>::row_iterator itrend = this->end_col(in_cols);

		for (Matrix<T>::row_iterator itr = this->begin_col(in_cols); itr != itrend;itr++) {
			*itr = val;
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_rows(size_t r1, size_t r2, const T val)
	{
		for (size_t i = r1;i <= r2;++i) {
			this->fill_row(i, val);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_cols(size_t c1, size_t c2, const T val)
	{
		for (size_t i = c1;i <= c2;++i) {
			this->fill_col(i, val);
		}
	}

	template<typename T>
	template<typename G , typename>
	inline void Matrix<T>::randu()
	{
		for (T& i : matrix) {
			i = random::uniformFloatRandom();
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::row_randu(const size_t in_rows)
	{
		if (in_rows >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		Matrix<T>::col_iterator itrend = this->end_row(in_rows);

		for (Matrix<T>::col_iterator itr = this->begin_row(in_rows); itr != itrend;itr++) {
			*itr = random::uniformFloatRandom();
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::col_randu(const size_t in_cols)
	{
		if (in_cols >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		Matrix<T>::row_iterator itrend = this->end_col(in_cols);

		for (Matrix<T>::row_iterator itr = this->begin_col(in_cols); itr != itrend;itr++) {
			*itr = random::uniformFloatRandom();
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::randu(const size_t in_rows, const size_t in_cols)
	{
		this->set_size(in_rows, in_cols);
		for (T& i : matrix) {
			 i = random::uniformFloatRandom();
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::randn()
	{
		for (T& i : matrix) {
			i = random::gaussianRandom();
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::row_randn(const size_t in_rows)
	{
		if (in_rows >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		Matrix<T>::col_iterator itrend = this->end_row(in_rows);

		for (Matrix<T>::col_iterator itr = this->begin_row(in_rows); itr != itrend;itr++) {
			*itr = random::gaussianRandom();
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::col_randn(const size_t in_cols)
	{
		if (in_cols >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		Matrix<T>::row_iterator itrend = this->end_col(in_cols);

		for (Matrix<T>::row_iterator itr = this->begin_col(in_cols); itr != itrend;itr++) {
			*itr = random::gaussianRandom();
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::randn(const size_t in_rows, const size_t in_cols)
	{
		this->set_size(in_rows, in_cols);
		for (auto i : matrix) {
			matrix[i] = random::gaussianRandom();
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::randi(T min, T max)
	{
		for (T& i : matrix) {
			i = random::uniformIntRandom(min, max);
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::row_randi(const size_t in_rows, T min, T max)
	{
		if (in_rows >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		Matrix<T>::col_iterator itrend = this->end_row(in_rows);

		for (Matrix<T>::col_iterator itr = this->begin_row(in_rows); itr != itrend;itr++) {
			*itr = random::uniformIntRandom(min, max);
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::col_randi(const size_t in_cols, T min, T max)
	{
		if (in_cols >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		Matrix<T>::row_iterator itrend = this->end_col(in_cols);

		for (Matrix<T>::row_iterator itr = this->begin_col(in_cols); itr != itrend;itr++) {
			*itr = random::uniformIntRandom(min, max);
		}
	}

	template<typename T>
	template<typename G, typename>
	inline void Matrix<T>::randi(const size_t in_rows, const size_t in_cols, T min, T max)
	{
		this->set_size(in_rows, in_cols);
		for (T& i : matrix) {
			i = random::uniformIntRandom(min,max);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill(const lambdaT val)
	{
		for (T& i : matrix) {
			i = val(i);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_row(const size_t in_rows, const lambdaT val)
	{
		if (in_rows >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		Matrix<T>::col_iterator itrend = this->end_row(in_rows);

		for (Matrix<T>::col_iterator itr = this->begin_row(in_rows); itr != itrend;itr++) {
			*itr = val(*itr);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_col(const size_t in_cols, const lambdaT val)
	{
		if (in_cols >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		Matrix<T>::row_iterator itrend = this->end_col(in_cols);

		for (Matrix<T>::row_iterator itr = this->begin_col(in_cols); itr != itrend;itr++) {
			*itr = val(*itr);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_rows(size_t r1, size_t r2, const lambdaT val)
	{
		for (size_t i = r1;i <= r2;++i) {
			this->fill_row(i, val);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_cols(size_t c1, size_t c2, const lambdaT val)
	{
		for (size_t i = c1;i <= c2;++i) {
			this->fill_col(i, val);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill(const func_p val)
	{
		for (T& i : matrix) {
			i = val(i);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_row(const size_t in_rows, const func_p val)
	{
		if (in_rows >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		Matrix<T>::col_iterator itrend = this->end_row(in_rows);

		for (Matrix<T>::col_iterator itr = this->begin_row(in_rows); itr != itrend;itr++) {
			*itr = val(*itr);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_col(const size_t in_cols, const func_p val)
	{
		if (in_cols >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		Matrix<T>::row_iterator itrend = this->end_col(in_cols);

		for (Matrix<T>::row_iterator itr = this->begin_col(in_cols); itr != itrend;itr++) {
			*itr = val(*itr);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_rows(size_t r1, size_t r2, const func_p val)
	{
		for (size_t i = r1;i <= r2;++i) {
			this->fill_row(i, val);
		}
	}

	template<typename T>
	inline void Matrix<T>::fill_cols(size_t c1, size_t c2, const func_p val)
	{
		for (size_t i = c1;i <= c2;++i) {
			this->fill_col(i, val);
		}
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator+(const Matrix<T>& m)
	{
		Matrix<T> result(*this);
		result += m;

		return result;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator-(const Matrix<T>& m)
	{
		Matrix<T> result(*this);
		result -= m;

		return result;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator*(const Matrix<T>& m)
	{
		Matrix<T> newmat(rows, m.cols);

		for (size_t i = 0;i < rows;++i) {
			for (size_t f = 0;f < m.cols;++f) {
				for (size_t k = 0;k < cols;++k) {
					newmat(i, f) += (*this)[i * cols + k] * m(k, f);
				}
			}
		}

		return newmat;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator%(const Matrix<T>& m)
	{
		Matrix<T> result(*this);
		result %= m;

		return result;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator/(const Matrix<T>& m)
	{
		Matrix<T> result(*this);
		result /= m;

		return result;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m)
	{
		set_size(m.rows, m.cols);

		for (size_t i = 0;i < m.size;i++) {
			matrix[i] = m[i];
		}

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator=(const SubView<T>& v)
	{
		set_size(v.n_rows, v.n_cols);

		for (size_t i = 0;i < v.n_rows;++i) {
			for (size_t j = 0;j < v.n_cols;++j) {
				matrix(i, j) = v(i, j);
			}
		}

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator=(Matrix<T>&& m)
	{
		matrix = std::move(m.matrix);
		rows = std::exchange(m.rows, 0);
		cols = std::exchange(m.cols, 0);
		size = std::exchange(m.size, 0);

		return (*this);
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& m)
	{
		for (size_t i = 0;i < size;++i) {
			matrix[i] += m[i];
		}

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& m)
	{
		for (size_t i = 0;i < size;++i) {
			matrix[i] -= m[i];
		}

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& m)
	{
		Matrix<T> result = (*this) * m;
		(*this) = result;
		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator%=(const Matrix<T>& m)
	{
		for (size_t i = 0;i < size;++i) {
			matrix[i] *= m[i];
		}

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator/=(const Matrix<T>& m)
	{
		for (size_t i = 0;i < size;++i) {
			matrix[i] /= m[i];
		}

		return *this;
	}

	template<typename T>
	inline Matrix<char> Matrix<T>::operator!=(const Matrix<T>& m) 
	{
		if (!this->is_same_size(m))
			return Matrix<char>();

		Matrix<char> boolmat(m.getRows(),m.getCols());

		for (size_t i = 0;i < size;++i) {
			boolmat(i) = (*this)(i) != m(i);
		}

		return boolmat;
	}

	template<typename T>
	inline Matrix<char> Matrix<T>::operator==(const Matrix<T>& m) 
	{
		if (!this->is_same_size(m))
			return Matrix<char>();

		Matrix<char> boolmat(m.getRows(), m.getCols());

		for (size_t i = 0;i < size;++i) {
			boolmat(i) = ((*this)(i) == m(i));
		}

		return boolmat;
	}

	template<typename T>
	inline Matrix<char> Matrix<T>::operator>=(const Matrix<T>& m) 
	{
		if (!this->is_same_size(m))
			return Matrix<char>();

		Matrix<char> boolmat(m.getRows(), m.getCols());

		for (size_t i = 0;i < size;++i) {
			boolmat(i) = (*this)(i) >= m(i);
		}

		return boolmat;
	}

	template<typename T>
	inline Matrix<char> Matrix<T>::operator<=(const Matrix<T>& m) 
	{
		if (!this->is_same_size(m))
			return Matrix<char>();

		Matrix<char> boolmat(m.getRows(), m.getCols());

		for (size_t i = 0;i < size;++i) {
			boolmat(i) = (*this)(i) <= m(i);
		}

		return boolmat;
	}

	template<typename T>
	inline Matrix<char> Matrix<T>::operator<(const Matrix<T>& m) 
	{
		if (!this->is_same_size(m))
			return Matrix<char>();

		Matrix<char> boolmat(m.getRows(), m.getCols());

		for (size_t i = 0;i < size;++i) {
			boolmat(i) = (*this)(i) < m(i);
		}

		return boolmat;
	}

	template<typename T>
	inline Matrix<char> Matrix<T>::operator>(const Matrix<T>& m) 
	{
		if (!this->is_same_size(m))
			return Matrix<char>();

		Matrix<char> boolmat(m.getRows(), m.getCols());

		for (size_t i = 0;i < size;++i) {
			boolmat(i) = (*this)(i) > m(i);
		}

		return boolmat;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator+(const T val)
	{
		Matrix<T> result(*this);
		result += val;

		return result;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator-(const T val)
	{
		Matrix<T> result(*this);
		result -= val;

		return result;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator*(const T val)
	{
		Matrix<T> result(*this);
		result *= val;

		return result;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator/(const T val)
	{
		Matrix<T> result(*this);
		result /= val;

		return result;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator=(const T val)
	{
		set_size(1, 1);
		fill(val);

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator+=(const T val)
	{
		for (T& i : matrix) {
			i += val;
		}

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator-=(const T val)
	{
		for (T& i : matrix) {
			i -= val;
		}

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator*=(const T val)
	{
		for (T& i : matrix) {
			i *= val;
		}

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator/=(const T val)
	{
		for (T& i : matrix) {
			i /= val;
		}

		return *this;
	}

	template<typename T>
	inline Matrix<T> operator+(const T val, const Matrix<T>& m)
	{
		Matrix<T> result(m);
		result += val;

		return result;
	}

	template<typename T>
	inline Matrix<T> operator-(const T val, const Matrix<T>& m)
	{
		Matrix<T> result(m);
		result -= val;

		return -1 * result;
	}

	template<typename T>
	inline Matrix<T> operator*(const T val, const Matrix<T>& m)
	{
		Matrix<T> result(m);
		result *= val;

		return result;
	}

	template<typename T>
	inline Matrix<T> operator/(const T val, const Matrix<T>& m)
	{
		Matrix<T> mat(m);

		for (typename Matrix<T>::iterator itr = mat.begin();itr != mat.end();++itr) {
			*itr = val / *itr;
		}

		return mat;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator++()
	{
		(*this) += 1;

		return *this;
	}

	template<typename T>
	inline Matrix<T>& Matrix<T>::operator--()
	{
		(*this) -= 1;

		return *this;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator++(int)
	{
		Matrix<T> temp(*this);
		++(*this);

		return temp;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator--(int)
	{
		Matrix<T> temp(*this);
		--(*this);

		return temp;
	}

	template<typename T>
	bool Matrix<T>::is_empty() const
	{
		return size;
	}

	template<typename T>
	bool Matrix<T>::is_row_vec() const
	{
		return rows == 1;
	}

	template<typename T>
	bool Matrix<T>::is_col_vec() const
	{
		return cols == 1;
	}

	template<typename T>
	inline bool Matrix<T>::is_vec() const
	{
		return this->is_col_vec() || this->is_row_vec();
	}

	template<typename T>
	bool Matrix<T>::is_square() const
	{
		return rows == cols;
	}

	template<typename T>
	bool Matrix<T>::is_sorted() const
	{
		for (Matrix<T>::iterator itr = matrix.begin() + 1; itr != matrix.end(); ++itr) {
			if (*(itr-1) > *itr)
				return false;
		}

		return true;
	}

	template<typename T>
	bool Matrix<T>::is_symmetric() const
	{
		if (rows != cols)
			return false;

		for (size_t i = 0;i < rows;++i) {
			for (size_t j = 0;j < cols;++j) {
				if ((*this)(i, j) != (*this)(j, i))
					return false;
			}
		}

		return true;
	}

	template<typename T>
	inline bool Matrix<T>::is_positive_definite() const
	{
		if (!this->is_symmetric())
			return false;

		Matrix<double> mat = tenseopr::ref((*this));

		for (size_t i = 0;i < rows;++i) {
			if (mat(i, i) <= 0)
				return false;
		}

		return true;
	}

	template<typename T>
	bool Matrix<T>::is_finite() const
	{
		for (const T& i : matrix) {
			if (!std::isfinite(static_cast<float>(i)))
				return false;
		}
		return true;
	}

	template<typename T>
	bool Matrix<T>::is_inf() const
	{
		for (const T& i : matrix) {
			if (!std::isinf(i))
				return false;
		}
		return true;
	}

	template<typename T>
	bool Matrix<T>::is_nan() const
	{
		for (const T& i : matrix) {
			if (!std::isnan(i))
				return false;
		}
		return true;
	}

	template<typename T>
	inline T Matrix<T>::min() const
	{
		return matrix[this->indexmin()];
	}

	template<typename T>
	inline T Matrix<T>::max() const
	{
		return matrix[this->indexmax()];
	}

	template<typename T>
	inline size_t Matrix<T>::indexmin() const
	{
		T minval = std::numeric_limits<T>::max();
		size_t index = 0;

		for (size_t i = 0;i < size;++i) {
			if (matrix[i] < minval)
			{
				index = i;
				minval = matrix[i];
			}
		}

		return index;
	}

	template<typename T>
	inline size_t Matrix<T>::indexmax() const
	{
		T maxval = std::numeric_limits<T>::min();

		size_t index = 0;

		for (size_t i = 0;i < size;++i) {
			if (matrix[i] > maxval)
			{
				index = i;
				maxval = matrix[i];
			}
		}

		return index;
	}

	template<typename T>
	inline T Matrix<T>::min_row(size_t r1) const
	{
		return matrix[this->indexmin_row(r1)];
	}

	template<typename T>
	inline T Matrix<T>::max_row(size_t r1) const
	{
		return matrix[this->indexmax_row(r1)];
	}

	template<typename T>
	inline size_t Matrix<T>::indexmin_row(size_t r1) const
	{
		T minval = std::numeric_limits<T>::max();
		size_t index = 0;

		for (size_t i = r1 * cols; i < r1 * cols + cols;++i) {
			if (matrix[i] < minval)
			{
				index = i;
				minval = matrix[i];
			}
		}

		return index;
	}

	template<typename T>
	inline size_t Matrix<T>::indexmax_row(size_t r1) const
	{
		T maxval = std::numeric_limits<T>::min();

		size_t index = 0;

		for (size_t i = r1 * cols; i < r1 * cols + cols;++i) {
			if (matrix[i] > maxval)
			{
				index = i;
				maxval = matrix[i];
			}
		}

		return index;
	}

	template<typename T>
	inline T Matrix<T>::min_col(size_t c1) const
	{
		return matrix[this->indexmin_col(c1)];
	}

	template<typename T>
	inline T Matrix<T>::max_col(size_t c1) const
	{
		return matrix[this->indexmin_col(c1)];
	}

	template<typename T>
	inline size_t Matrix<T>::indexmin_col(size_t c1) const
	{
		T minval = std::numeric_limits<T>::max();
		size_t index = 0;

		for (size_t i = c1;i < size;i+=cols) {
			if (matrix[i] < minval) {
				index = i;
				minval = matrix[i];
			}
		}

		return index;
	}

	template<typename T>
	inline size_t Matrix<T>::indexmax_col(size_t c1) const
	{
		T maxval = std::numeric_limits<T>::min();
		size_t index = 0;

		for (size_t i = c1;i < size;i+=cols) {
			if (matrix[i] > maxval)
			{
				index = i;
				maxval = matrix[i];
			}
		}

		return index;
	}

	template<typename T>
	inline Matrix<T>::row_iterator::row_iterator() : mat(NULL), current_ptr(NULL), current_col(0), current_row(0)
	{
		//invalid iterator. Not good for use
	}

	template<typename T>
	inline Matrix<T>::row_iterator::row_iterator(const row_iterator& X) : mat(X.mat), current_ptr(X.current_ptr), current_col(X.current_col), current_row(X.current_row)
	{

	}

	template<typename T>
	inline Matrix<T>::row_iterator::row_iterator(Matrix<T>& in_M, const size_t in_col) : mat(&in_M), current_ptr(&in_M.at(in_col)), current_col(in_col), current_row(0)
	{
	
	}

	template<typename T>
	inline T & Matrix<T>::row_iterator::operator*()
	{
		return (*current_ptr);
	}

	template<typename T>
	inline typename Matrix<T>::row_iterator& Matrix<T>::row_iterator::operator++()
	{
		current_row++;

		if (current_row == mat->getRows())
		{
			current_row = 0;
			current_col++;

			//if (current_col == mat->getCols())
				//current_col = 0;

			current_ptr = &mat->at(0) + current_col;
		}
		else
		{
			current_ptr += mat->getCols();
		}

		return (*this);
	}

	template<typename T>
	inline typename Matrix<T>::row_iterator Matrix<T>::row_iterator::operator++(int)
	{
		typename Matrix<T>::row_iterator temp(*this);

		++(*this);

		return temp;
	}

	template<typename T>
	inline typename Matrix<T>::row_iterator& Matrix<T>::row_iterator::operator--()
	{
		current_row--;

		if (current_row == -1) {
			current_row = mat->getRows() - 1;

			current_col--;

			if (current_col == -1)
				current_col = mat->getCols() - 1;

			current_ptr = &mat->at(0) + (current_row * mat->getCols() + current_col);
		}
		else {
			current_ptr -= mat->getCols();
		}

		return (*this);
	}

	template<typename T>
	inline typename Matrix<T>::row_iterator Matrix<T>::row_iterator::operator--(int)
	{
		typename Matrix<T>::row_iterator temp(*this);

		--(*this);

		return temp;
	}

	template<typename T>
	inline typename Matrix<T>::row_iterator  Matrix<T>::row_iterator::operator+(const size_t n)
	{
		Matrix<T>::row_iterator itr(*this);

		for (size_t i = 0;i < n;++i) {
			itr++;
		}
		return itr;
	}

	template<typename T>
	inline typename Matrix<T>::row_iterator  Matrix<T>::row_iterator::operator-(const size_t n)
	{
		Matrix<T>::row_iterator itr(*this);

		for (size_t i = 0;i < n;++i) {
			itr--;
		}
		return itr;
	}

	template<typename T>
	inline bool Matrix<T>::row_iterator::operator!=(const typename Matrix<T>::row_iterator & X) const
	{
		return (current_ptr != X.current_ptr);
	}

	template<typename T>
	inline bool Matrix<T>::row_iterator::operator==(const typename Matrix<T>::row_iterator & X) const
	{
		return (current_ptr == X.current_ptr);
	}

	template<typename T>
	inline bool Matrix<T>::row_iterator::operator!=(const typename Matrix<T>::const_row_iterator & X) const
	{
		return (current_ptr != X.current_ptr);
	}

	template<typename T>
	inline bool Matrix<T>::row_iterator::operator==(const typename Matrix<T>::const_row_iterator & X) const
	{
		return (current_ptr == X.current_ptr);
	}

	#ifdef _DEBUG
	template<typename T>
	inline void Matrix<T>::row_iterator::print() const
	{
		std::cout << "itr: " << (*current_ptr) << ' ';
		std::cout << "row: " << current_row << ' ';
		std::cout << "col: " << current_col << '\n';
	}
	#endif // _DEBUG

	template<typename T>
	inline Matrix<T>::const_row_iterator::const_row_iterator() {

	}

	template<typename T>
	inline Matrix<T>::const_row_iterator::const_row_iterator(const row_iterator& X) : mat(X.mat), current_ptr(X.current_ptr), current_col(X.current_col), current_row(X.current_row)
	{

	}

	template<typename T>
	inline Matrix<T>::const_row_iterator::const_row_iterator(const const_row_iterator& X) : mat(X.mat), current_ptr(X.current_ptr), current_col(X.current_col), current_row(X.current_row)
	{

	}

	template<typename T>
	inline Matrix<T>::const_row_iterator::const_row_iterator(const Matrix<T>& in_M, const size_t in_col) : mat(&in_M), current_ptr(&in_M.at(0) + in_col), current_col(in_col), current_row(0)
	{

	}

	template<typename T>
	inline const T & Matrix<T>::const_row_iterator::operator*() const
	{
		return (*current_ptr);
	}

	template<typename T>
	inline typename Matrix<T>::const_row_iterator& Matrix<T>::const_row_iterator::operator++()
	{
		current_row++;

		if (current_row == mat->getRows())
		{
			current_row = 0;
			current_col++;

			if (current_col == mat->getCols())
				current_col = 0;

			current_ptr = &mat->at(0) + current_col;
		}
		else
		{
			current_ptr += mat->getCols();
		}

		return *this;
	}

	template<typename T>
	inline typename Matrix<T>::const_row_iterator Matrix<T>::const_row_iterator::operator++(int)
	{
		typename Matrix<T>::const_row_iterator temp(*this);

		++(*this);

		return temp;
	}

	template<typename T>
	inline typename Matrix<T>::const_row_iterator& Matrix<T>::const_row_iterator::operator--()
	{
		current_row--;

		if (current_row == -1) {
			current_row = mat->getRows() - 1;

			current_col--;

			if (current_col == -1)
				current_col = mat->getCols() - 1;

			current_ptr = &mat->at(0) + (current_row * mat->getCols() + current_col);
		}
		else {
			current_ptr -= mat->getCols();
		}

		return *this;
	}

	template<typename T>
	inline typename Matrix<T>::const_row_iterator Matrix<T>::const_row_iterator::operator--(int)
	{
		typename Matrix<T>::const_row_iterator temp(*this);

		--(*this);

		return temp;
	}

	template<typename T>
	inline typename Matrix<T>::const_row_iterator Matrix<T>::const_row_iterator::operator+(const size_t n)
	{
		Matrix<T>::const_row_iterator itr(*this);

		for (size_t i = 0;i < n;++i) {
			itr++;
		}
		return itr;
	}

	template<typename T>
	inline typename Matrix<T>::const_row_iterator Matrix<T>::const_row_iterator::operator-(const size_t n)
	{
		Matrix<T>::const_row_iterator itr(*this);

		for (size_t i = 0;i < n;++i) {
			itr--;
		}
		return itr;
	}

	template<typename T>
	inline bool Matrix<T>::const_row_iterator::operator!=(const row_iterator & X) const
	{
		return current_ptr != X.current_ptr;
	}

	template<typename T>
	inline bool Matrix<T>::const_row_iterator::operator==(const row_iterator & X) const
	{
		return current_ptr == X.current_ptr;
	}

	template<typename T>
	inline bool Matrix<T>::const_row_iterator::operator!=(const const_row_iterator & X) const
	{
		return current_ptr != X.current_ptr;
	}

	template<typename T>
	inline bool Matrix<T>::const_row_iterator::operator==(const const_row_iterator & X) const
	{
		return current_ptr == X.current_ptr;
	}

	#ifdef _DEBUG
	template<typename T>
	inline void Matrix<T>::const_row_iterator::print() const
	{
		std::cout << "itr: " << (*current_ptr) << ' ';
		std::cout << "row: " << current_row << ' ';
		std::cout << "col: " << current_col << '\n';
	}
	#endif // _DEBUG

	template<typename T>
	inline typename Matrix<T>::iterator Matrix<T>::begin() 
	{
		return &matrix.at(0);
	}

	template<typename T>
	inline typename Matrix<T>::const_iterator Matrix<T>::begin() const
	{
		return &matrix.at(0);
	}

	template<typename T>
	inline typename Matrix<T>::const_iterator Matrix<T>::cbegin() const
	{
		return &matrix.at(0);
	}

	template<typename T>
	inline typename Matrix<T>::iterator Matrix<T>::begin(const size_t index)
	{
		return &matrix.at(0) + index;
	}

	template<typename T>
	inline typename Matrix<T>::const_iterator Matrix<T>::begin(const size_t index) const
	{
		return &matrix.at(0) + index;
	}

	template<typename T>
	inline typename Matrix<T>::iterator Matrix<T>::end() {
		return &matrix.at(size - 1) + 1;
	}

	template<typename T>
	inline typename Matrix<T>::const_iterator Matrix<T>::end() const
	{
		return &matrix.at(size - 1) + 1;
	}

	template<typename T>
	inline typename Matrix<T>::const_iterator Matrix<T>::cend() const
	{
		return &matrix.at(size - 1) + 1;
	}

	template<typename T>
	inline typename Matrix<T>::col_iterator Matrix<T>::begin_row(const size_t row_num)
	{
		return &matrix.at(0) + (row_num * cols);
	}

	template<typename T>
	inline typename Matrix<T>::const_col_iterator Matrix<T>::begin_row(const size_t row_num) const
	{
		return &matrix.at(0) + (row_num * cols);
	}

	template<typename T>
	inline typename Matrix<T>::col_iterator Matrix<T>::end_row(const size_t row_num)
	{
		return &matrix.at(0) + ((row_num+1) * cols);
	}

	template<typename T>
	inline typename Matrix<T>::const_col_iterator Matrix<T>::end_row(const size_t row_num) const
	{
		return &matrix.at(0) + ((row_num + 1) * cols);
	}

	template<typename T>
	inline typename Matrix<T>::row_iterator Matrix<T>::begin_col(const size_t col_num)
	{
		return row_iterator(*this,col_num);
	}

	template<typename T>
	inline typename Matrix<T>::const_row_iterator Matrix<T>::begin_col(const size_t col_num) const
	{
		return const_row_iterator(*this, col_num);
	}

	template<typename T>
	inline typename Matrix<T>::row_iterator Matrix<T>::end_col(const size_t col_num)
	{
		return row_iterator(*this, col_num + 1);
	}

	template<typename T>
	inline typename Matrix<T>::const_row_iterator Matrix<T>::end_col(const size_t col_num) const
	{
		return const_row_iterator(*this, col_num + 1);
	}

	template<typename T>
	inline void Matrix<T>::swap(Matrix<T>& m)
	{
		matrix.swap(m.matrix);
	}

	template<typename T>
	inline void Matrix<T>::swap_rows(size_t r1, size_t r2)
	{
		if (r1 == r2)
			return;
	
		if (r1 >= rows || r2 >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}else if (r1 > r2)
			std::swap(r1, r2);
	
		Matrix<T>::col_iterator itrend = this->end_row(r1);

		Matrix<T>::col_iterator itr1;
		Matrix<T>::col_iterator itr2;

		for (itr1 = this->begin_row(r1), itr2 = this->begin_row(r2); itr1 != itrend;itr1++, itr2++) {
			std::swap(*itr1, *itr2);
		}
	}

	template<typename T>
	inline void Matrix<T>::swap_cols(size_t c1, size_t c2)
	{
		if (c1 == c2)
			return;

		if (c1 >= cols || c2 >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		else if (c1 > c2)
			std::swap(c1, c2);
	
		Matrix<T>::row_iterator itrend = this->end_col(c1);

		for (Matrix<T>::row_iterator itr1 = this->begin_col(c1), itr2 = this->begin_col(c2); itr1 != itrend;itr1++,itr2++) {
			std::swap(*itr1, *itr2);
		}
	}

	template<typename T>
	inline void Matrix<T>::insert_rows(size_t r1, const Matrix<T>& m)
	{
		if (r1 > rows)
		{
			std::cout << "Row out of range" << '\n';
		}
		matrix.insert(this->begin_row(r1), &m.at(0), &m.at(m.getSize()-1));

		rows+=m.rows;
		this->resize(rows, cols);
	}

	template<typename T>
	inline void Matrix<T>::insert_cols(size_t c1, const Matrix<T>& m)
	{
		if (c1 > cols)
		{
			std::cout << "Col out of range" << '\n';
		}

		const size_t mat_cols = m.getCols();

		for (size_t a = 0;a < mat_cols;++a) {
			Matrix<T>::col_iterator itr = matrix.insert(&m.at(0) + c1 + a, m(0, a));

			for (size_t i = 1;i < rows;++i) {
				itr = matrix.insert(itr + cols + 1, m(i, a));
			}
			++cols;
			size = cols * rows;
		}

	}

	template<typename T>
	inline void Matrix<T>::insert_row(size_t r1, const T val)
	{
		if (r1 > rows)
		{
			std::cout << "Row out of range" << '\n';
		}

		std::vector<int>::iterator it = matrix.begin() + (this->begin_row(r1) - this->begin());
		matrix.insert(it, cols, val);

		rows++;
		this->resize(rows, cols);
	}

	template<typename T>
	inline void Matrix<T>::insert_col(size_t c1, const T val)
	{
		if (c1 > cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		std::vector<int>::iterator itr = matrix.insert(matrix.begin() + c1, val);

		for (size_t i = 1;i < rows;++i) {
			itr = matrix.insert(itr + cols + 1, val);
		}

		cols++;
		size = cols * rows;
	}

	template<typename T>
	inline void Matrix<T>::insert_rows(size_t r1, size_t r2, const T val)
	{
		for (size_t i = r1;i <= r2;++i) {
			this->insert_row(i, val);
		}
	}

	template<typename T>
	inline void Matrix<T>::insert_cols(size_t c1, size_t c2, const T val)
	{
		for (size_t i = c1;i <= c2;++i) {
			this->insert_col(i, val);
		}
	}

	template<typename T>
	inline SubViewCol<T> Matrix<T>::get_col(size_t c1) const
	{
		if (c1 >= cols)
		{
			std::cout << "Col out of range!" << '\n';
		}
		return SubViewCol<T>((*this), c1);
	}

	template<typename T>
	inline SubViewRow<T> Matrix<T>::get_row(size_t r1) const
	{
		if (r1 >= rows)
		{
			std::cout << "Row out of range!" << '\n';
		}
		return SubViewRow<T>((*this), r1);
	}

	template<typename T>
	inline SubView<T> Matrix<T>::get_cols(size_t c1, size_t c2)
	{
		if (c1 > c2)
			std::swap(c1, c2);

		if (c2 >= cols)
		{
			std::cout << "Col out of range!" << '\n';
		}

		return this->submat(0, c1, rows - 1, c2);
	}

	template<typename T>
	inline SubView<T> Matrix<T>::get_rows(size_t r1, size_t r2)
	{
		if (r1 > r2)
			std::swap(r1, r2);

		if (r2 >= rows)
		{
			std::cout << "Row out of range!" << '\n';
		}

		return this->submat(r1, 0, r2, cols - 1);
	}

	template<typename T>
	inline SubView<T> Matrix<T>::submat(size_t r1, size_t c1, size_t r2, size_t c2)
	{
		if (r1 > r2)
			std::swap(r1, r2);
		if (c1 > c2)
			std::swap(c1, c2);

		if (r2 >= rows) {
			std::cout << "Row out of range!" << '\n';
		}
		if (c2 >= cols){
			std::cout << "Col out of range!" << '\n';
		}

		return SubView<T>((*this), r1, c1, r2 - r1 + 1, c2 - c1 + 1);
	}

	template<typename T>
	inline SubView<T> Matrix<T>::head_cols(size_t c1)
	{
		return this->get_cols(0, c1-1);
	}

	template<typename T>
	inline SubView<T> Matrix<T>::head_rows(size_t r1)
	{
		return this->get_rows(0, r1-1);
	}

	template<typename T>
	inline SubView<T> Matrix<T>::tail_cols(size_t c1)
	{
		return this->get_cols(cols-c1, cols-1);
	}

	template<typename T>
	inline SubView<T> Matrix<T>::tail_rows(size_t r1)
	{
		return this->get_rows(rows - r1, rows - 1);
	}

	template<typename T>
	inline void Matrix<T>::shed_row(size_t r1)
	{
		if (r1 >= rows)
		{
			std::cout << "Row out of range" << '\n';
		}

		std::vector<int>::iterator it = matrix.begin() + (this->begin_row(r1) - this->begin());
		std::vector<int>::iterator itend = matrix.begin() + (this->end_row(r1) - this->begin());
		matrix.erase(it, itend);

		rows--;
		size = rows * cols;
	}

	template<typename T>
	inline void Matrix<T>::shed_rows(size_t rbegin, size_t rend)
	{
		for (size_t i = rbegin;i <= rend;++i) {
			this->shed_row(i);
		}
	}

	template<typename T>
	inline void Matrix<T>::shed_col(size_t c1)
	{
		if (c1 >= cols)
		{
			std::cout << "Col out of range" << '\n';
		}
		std::vector<int>::iterator itr = matrix.erase(matrix.begin() + c1);
	
		for (size_t i = 0;i < rows - 1;++i) 
			itr = matrix.erase(itr + cols - 1);

		cols--;
		size = rows * cols;
	}

	template<typename T>
	inline void Matrix<T>::shed_cols(size_t cbegin, size_t cend)
	{
		for (size_t i = cbegin;i <= cend;++i) {
			this->shed_col(i);
		}
	}

	template<typename T>
	inline std::ostream & operator<<(std::ostream & stream, const Matrix<T>& mat)
	{
		for (size_t i = 0;i < mat.getRows();++i)
		{
			for (size_t f = 0;f < mat.getCols();++f)
			{
				stream << mat(i, f) << ' ';
			}
			stream << '\n';
		}
		return stream;
	}

	template<typename T>
	inline std::ostream & operator<<(std::ostream & stream, const typename Matrix<T>::row_iterator & m)
	{
		stream << "itr: " << (*m.itr) << ' ';
		stream << "row: " << m.current_row << ' ';
		stream << "col: " << m.current_col << '\n';

		return stream;
	}

	template<typename T>
	inline void Matrix<T>::print() const
	{
		for (size_t i = 0;i < rows;++i)
		{
			for (size_t f = 0;f < cols;++f)
			{
				std::cout << (*this)(i,f) << ' ';
			}
			std::cout << '\n';
		}
	}

	#ifdef _DEBUG
	template<typename T>
	inline void Matrix<T>::printInfo() const
	{
		std::cout << "Rows: " << rows << '\n';
		std::cout << "Cols: " << cols << '\n';

		for (size_t i = 0;i < rows;++i)
		{
			for (size_t f = 0;f < cols;++f)
			{
				std::cout << (*this)(i, f) << ' ';
			}
			std::cout << '\n';
		}
	}
	#endif // _DEBUG

	template<typename T>
	inline void Matrix<T>::save(const std::string & name)
	{
		std::ofstream stream;
	
		stream.open(name);

		stream << rows << '\n';
		stream << cols << '\n';

		for (T& i : matrix) {
			stream << i << '\n';
		}

		stream << '\n';
		stream.close();
	}

	template<typename T>
	inline void Matrix<T>::load(const std::string & name)
	{
		this->reset();
		std::ifstream stream;

		stream.open(name);

		if (!stream.is_open()) {
			std::cout << "File not found!" << '\n';
		}

		stream >> rows;
		stream >> cols;

		this->resize(rows, cols);

		for (T& i:matrix) {
			stream >> i;
		}

		stream.close();
	}

	template<typename T>
	inline size_t Matrix<T>::getRows() const
	{
		return rows;
	}

	template<typename T>
	inline size_t Matrix<T>::getCols() const
	{
		return cols;
	}

	template<typename T>
	inline size_t Matrix<T>::getSize() const
	{
		return size;
	}

	template<typename T>
	inline Matrix<T>::Matrix(T elem) : Matrix(1,1,elem)
	{

	}

	template<typename T>
	inline Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), size(rows * cols)
	{
		matrix.resize(size);
	}

	template<typename T>
	inline Matrix<T>::Matrix(size_t rows, size_t cols, T elem) : Matrix(rows, cols)
	{
		this->fill(elem);
	}

	template<typename T>
	inline Matrix<T>::Matrix(size_t rows, size_t cols, const std::initializer_list<T>& list) : Matrix(rows, cols)
	{
		matrix = list;
	}

	template<typename T>
	inline Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>>& list)
	{
		for (auto& i : list) {
			matrix.insert(matrix.end(), i.begin(), i.end());
		}

		this->reshape(list.size(), list.begin()[0].size());
	}

	template<typename T>
	inline Matrix<T>::Matrix(size_t rows, size_t cols, const std::vector<T>& list) : Matrix(rows, cols)
	{
		matrix = list;
	}

	template<typename T>
	inline Matrix<T>::Matrix(const std::vector<std::vector<T>>& list) 
	{
		for (auto& i : list) {
			matrix.insert(matrix.end(), i.begin(), i.end());
		}

		this->reshape(list.size(), list[0].size());
	}

	template<typename T>
	inline Matrix<T>::Matrix(size_t rows, size_t cols, const T * list) : Matrix(rows, cols)
	{
		for (size_t i = 0;i < size;++i) {
			matrix[i] = list[i];
		}
	}

	template<typename T>
	inline Matrix<T>::Matrix(size_t rows, size_t cols, const T * const * list)
	{
		for (size_t i = 0;i < rows;i++) {
			matrix.insert(matrix.end(), list[i], list[i] + cols);
		}

		this->reshape(rows, cols);
	}

	template<typename T>
	inline Matrix<T>::Matrix(const Matrix<T>& m) : matrix(m.matrix), rows(m.rows), cols(m.cols), size(m.size) {
	
	}

	template<typename T>
	inline Matrix<T>::Matrix(Matrix<T>&& m) :
	rows(std::exchange(m.rows, 0)), 
	cols(std::exchange(m.cols, 0)), 
	size(std::exchange(m.size, 0)),
	matrix(std::move(m.matrix))
	{

	}

	template<typename T>
	inline Matrix<T>::Matrix(const std::string & name)
	{
		this->load(name);
	}

	template<typename T>
	inline Matrix<T>::Matrix(const SubView<T>& v)
	{
		(*this) = v;
	}

	template<typename T>
	inline Matrix<T>::Matrix() : rows(0), cols(0), size(0), matrix(NULL){

	}

	template<typename T>
	inline Matrix<T>::~Matrix() {

	}

};

#endif // !MATRIX_HPP