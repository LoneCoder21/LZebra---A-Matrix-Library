#ifndef MATRIX_H
#define MATRIX_H

#include <utility>
#include <functional>
#include <iostream>
#include <fstream>
#include <vector>
#include <initializer_list>
#include <string>

namespace LZebra {
	template<typename T>
	class ColVector;
	template<typename T>
	class RowVector;
	template<typename T>
	class SubView;
	template<typename T>
	class SubViewCol;
	template<typename T>
	class SubViewRow;
	//ONLY SUPPOSED TO BE USED FOR INTEGRAL AND FLOATING TYPES
	template<typename T>
	class Matrix
	{
	protected:
		size_t rows;
		size_t cols;
		size_t size;
		std::vector<T> matrix;
	public:
		//GETTERS
		inline size_t getRows() const;
		inline size_t getCols() const;
		inline size_t getSize() const;

		//ELEMENT ACCESSORS
		T& operator[] (const size_t ii);
		const T& operator[] (const size_t ii) const;
		T& at(const size_t ii);
		const T& at(const size_t ii) const;
		T& operator() (const size_t ii);
		const T& operator() (const size_t ii) const;

		T& at(const size_t in_row, const size_t in_col);
		const T& at(const size_t in_row, const size_t in_col) const;
		T& operator() (const size_t in_row, const size_t in_col);
		const T& operator() (const size_t in_row, const size_t in_col) const;

		//IN-RANGE
		bool in_range(const size_t ii) const;
		bool in_range(const size_t in_row, const size_t in_col) const;

		//SAME SIZE
		bool is_same_size(const Matrix& m) const;
		bool is_same_size(const size_t in_rows, const size_t in_cols);

		//CHECKS ROWS-COLS OF ELEMENT
		inline bool is_same_row(size_t r1, const T val) const;
		inline bool is_same_col(size_t r1, const T val) const;

		inline bool is_same_rows(size_t r1, size_t r2, const T val) const;
		inline bool is_same_cols(size_t r1, size_t c2, const T val) const;

		//EQUAL ROWS-COLS
		inline bool is_equal_rows(size_t r1, size_t r2) const;
		inline bool is_equal_cols(size_t r1, size_t c2) const;

		//SIZE MANIPULATION
		inline void reset();
		inline void copysize(const Matrix& m);

		inline void set_size(const size_t in_rows, const size_t in_cols);
		inline void resize(const size_t in_rows, const size_t in_cols);
		inline void reshape(const size_t in_rows, const size_t in_cols);

		//SET ELEMENTS
		inline void zeros();
		inline void row_zeros(const size_t in_rows);
		inline void col_zeros(const size_t in_cols);
		inline void zeros(const size_t in_rows, const size_t in_cols);

		inline void ones();
		inline void row_ones(const size_t in_rows);
		inline void col_ones(const size_t in_cols);
		inline void ones(const size_t in_rows, const size_t in_cols);

		inline void replace(const T old_val, const T new_val);
		inline void replace_row(const size_t in_rows, const T old_val, const T new_val);
		inline void replace_col(const size_t in_cols, const T old_val, const T new_val);

		inline void fill(const T val);
		inline void fill_row(const size_t in_rows, const T val);
		inline void fill_col(const size_t in_cols, const T val);
		inline void fill_rows(size_t r1, size_t r2, const T val);
		inline void fill_cols(size_t r1, size_t c2, const T val);

		//FLOATING-POINT ONLY
		template<typename G = T, typename = typename std::enable_if<std::is_floating_point<G>::value>::type>
		inline void randu();
		template<typename G = T, typename = typename std::enable_if<std::is_floating_point<G>::value>::type>
		inline void row_randu(const size_t in_rows);
		template<typename G = T, typename = typename std::enable_if<std::is_floating_point<G>::value>::type>
		inline void col_randu(const size_t in_cols);
		template<typename G = T, typename = typename std::enable_if<std::is_floating_point<G>::value>::type>
		inline void randu(const size_t in_rows, const size_t in_cols);

		template<typename G = T, typename = typename std::enable_if<std::is_floating_point<G>::value>::type>
		inline void randn();
		template<typename G = T, typename = typename std::enable_if<std::is_floating_point<G>::value>::type>
		inline void row_randn(const size_t in_rows);
		template<typename G = T, typename = typename std::enable_if<std::is_floating_point<G>::value>::type>
		inline void col_randn(const size_t in_cols);
		template<typename G = T, typename = typename std::enable_if<std::is_floating_point<G>::value>::type>
		inline void randn(const size_t in_rows, const size_t in_cols);

		//FOR INTEGERS
		template<typename G = T, typename = typename std::enable_if<std::is_integral<G>::value>::type>
		inline void randi(T min=0, T max = std::numeric_limits<T>::max);
		template<typename G = T, typename = typename std::enable_if<std::is_integral<G>::value>::type>
		inline void row_randi(const size_t in_rows, T min = 0, T max = std::numeric_limits<T>::max);
		template<typename G = T, typename = typename std::enable_if<std::is_integral<G>::value>::type>
		inline void col_randi(const size_t in_cols, T min = 0, T max = std::numeric_limits<T>::max);
		template<typename G = T, typename = typename std::enable_if<std::is_integral<G>::value>::type>
		inline void randi(const size_t in_rows, const size_t in_cols, T min = 0, T max = std::numeric_limits<T>::max);

		typedef std::function<T(T)> lambdaT;
		typedef T(*func_p)(T);

		//FOREACH
			//LAMBDA FUNCTION
		inline void fill(const lambdaT val);
		inline void fill_row(const size_t in_rows, const lambdaT val);
		inline void fill_col(const size_t in_cols, const lambdaT val);
		inline void fill_rows(size_t r1, size_t r2, const lambdaT val);
		inline void fill_cols(size_t r1, size_t c2, const lambdaT val);
		//FUNCTOR FUNCTION
		inline void fill(const func_p val);
		inline void fill_row(const size_t in_rows, const func_p val);
		inline void fill_col(const size_t in_cols, const func_p val);
		inline void fill_rows(size_t r1, size_t r2, const func_p val);
		inline void fill_cols(size_t r1, size_t c2, const func_p val);

		//OPERATIONS
			//MATRIX - MATRIX
		inline Matrix<T> operator+ (const Matrix<T>& m);
		inline Matrix<T> operator- (const Matrix<T>& m);
		inline Matrix<T> operator* (const Matrix<T>& m);
		inline Matrix<T> operator% (const Matrix<T>& m);
		inline Matrix<T> operator/ (const Matrix<T>& m);
		inline Matrix<T>& operator= (const Matrix<T>& m);
		inline Matrix<T>& operator= (const SubView<T>& v);
		inline Matrix<T>& operator= (Matrix<T>&& m);
		inline Matrix<T>& operator+=(const Matrix<T>& m);
		inline Matrix<T>& operator-=(const Matrix<T>& m);
		inline Matrix<T>& operator*=(const Matrix<T>& m);
		inline Matrix<T>& operator%=(const Matrix<T>& m);
		inline Matrix<T>& operator/=(const Matrix<T>& m);
		//BOOLEAN EVALUATION
		inline Matrix<char> operator!=(const Matrix<T>& m);
		inline Matrix<char> operator==(const Matrix<T>& m);
		inline Matrix<char> operator>=(const Matrix<T>& m);
		inline Matrix<char> operator<=(const Matrix<T>& m);
		inline Matrix<char> operator< (const Matrix<T>& m);
		inline Matrix<char> operator> (const Matrix<T>& m);

		//MATRIX - SCALAR
		inline Matrix<T> operator+ (const T val);
		inline Matrix<T> operator- (const T val);
		inline Matrix<T> operator* (const T val);
		inline Matrix<T> operator/ (const T val);
		inline Matrix<T>& operator= (const T val);
		inline Matrix<T>& operator+=(const T val);
		inline Matrix<T>& operator-=(const T val);
		inline Matrix<T>& operator*=(const T val);
		inline Matrix<T>& operator/=(const T val);
		inline Matrix<T>& operator++();
		inline Matrix<T>& operator--();
		inline Matrix<T> operator++(int);
		inline Matrix<T> operator--(int);

		//MATRIX CHECKS
		bool is_empty()  const;
		bool is_row_vec() const;
		bool is_col_vec() const;
		bool is_vec() const;
		bool is_square() const;
		bool is_sorted() const;
		bool is_symmetric() const;
		bool is_positive_definite() const;
		//FLOATING-POINT ONLY
		bool is_finite() const;
		bool is_inf() const;
		bool is_nan() const;

		//MAX-MIN ELEMENTS
		inline T min() const;
		inline T max() const;
		inline size_t indexmin() const;
		inline size_t indexmax() const;

		inline T min_row(size_t r1) const;
		inline T max_row(size_t r1) const;
		inline size_t indexmin_row(size_t r1) const;
		inline size_t indexmax_row(size_t r1) const;

		inline T min_col(size_t r1) const;
		inline T max_col(size_t r1) const;
		inline size_t indexmin_col(size_t r1) const;
		inline size_t indexmax_col(size_t r1) const;

		//ITERATOR CLASSES
		typedef typename T*              iterator;
		typedef typename const T*  const_iterator;

		typedef typename T*              col_iterator;
		typedef typename const T*  const_col_iterator;

		class const_row_iterator;
	
		class row_iterator { //iterators through rows and single col
		public:
			inline row_iterator();
			inline row_iterator(const row_iterator& X);
			inline row_iterator(Matrix<T>& in_M, const size_t in_col);

			inline T& operator* ();

			inline row_iterator& operator++();
			inline row_iterator  operator++(int);

			inline row_iterator& operator--();
			inline row_iterator  operator--(int);

			inline row_iterator operator+(const size_t n);
			inline row_iterator operator-(const size_t n);

			inline bool operator!=(const       row_iterator& X) const;
			inline bool operator==(const       row_iterator& X) const;
			inline bool operator!=(const const_row_iterator& X) const;
			inline bool operator==(const const_row_iterator& X) const;

			#ifdef _DEBUG
					inline void print() const;
			#endif // _DEBUG

			typedef std::bidirectional_iterator_tag iterator_category;
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;

			Matrix<T>* mat;
			T* current_ptr;
			size_t current_col;
			size_t current_row;
		};

		class const_row_iterator {
		public:
			inline const_row_iterator();
			inline const_row_iterator(const       row_iterator& X);
			inline const_row_iterator(const const_row_iterator& X);
			inline const_row_iterator(const Matrix<T>& in_M, const size_t in_row);

			inline const T& operator*() const;

			inline const_row_iterator& operator++();
			inline const_row_iterator  operator++(int);

			inline const_row_iterator& operator--();
			inline const_row_iterator  operator--(int);

			inline const_row_iterator operator+(const size_t n);
			inline const_row_iterator operator-(const size_t n);

			inline bool operator!=(const       row_iterator& X) const;
			inline bool operator==(const       row_iterator& X) const;
			inline bool operator!=(const const_row_iterator& X) const;
			inline bool operator==(const const_row_iterator& X) const;

			typedef std::bidirectional_iterator_tag iterator_category;
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;

			#ifdef _DEBUG
					inline void print() const;
			#endif // _DEBUG

			const Matrix<T>* mat;
			const T* current_ptr;
			size_t current_row;
			size_t current_col;
		};

		//ITERATOR FUNCTIONS
		inline       iterator  begin();
		inline const_iterator  begin() const;
		inline const_iterator cbegin() const;
	
		inline       iterator  begin(const size_t index);
		inline const_iterator  begin(const size_t index) const;

		inline       iterator  end();
		inline const_iterator  end() const;
		inline const_iterator cend() const;

		inline       col_iterator begin_row(const size_t row_num);
		inline const_col_iterator begin_row(const size_t row_num) const;

		inline       col_iterator end_row(const size_t row_num);
		inline const_col_iterator end_row(const size_t row_num) const;

		inline       row_iterator begin_col(const size_t col_num);
		inline const_row_iterator begin_col(const size_t col_num) const;

		inline       row_iterator end_col(const size_t col_num);
		inline const_row_iterator end_col(const size_t col_num) const;

		//SWAP
		inline void swap(Matrix<T>& m);
		inline void swap_rows(size_t r1, size_t r2);
		inline void swap_cols(size_t r1, size_t c2);

		//INSERT 
		inline void insert_rows(size_t r1, const Matrix<T>& m);
		inline void insert_cols(size_t r1, const Matrix<T>& m);

		inline void insert_row(size_t r1, const T val);
		inline void insert_col(size_t r1, const T val);

		inline void insert_rows(size_t r1, size_t r2, const T val);
		inline void insert_cols(size_t r1, size_t c2, const T val);

		//SUBVIEW
		inline SubViewCol<T> get_col(size_t r1) const;
		inline SubViewRow<T> get_row(size_t r1) const;

		inline SubView<T> get_cols(size_t r1, size_t c2);
		inline SubView<T> get_rows(size_t r1, size_t r2);

		inline SubView<T> submat(size_t r1, size_t c1, size_t r2, size_t c2);

		inline SubView<T> head_cols(size_t cols);
		inline SubView<T> head_rows(size_t rows);
		   
		inline SubView<T> tail_cols(size_t cols);
		inline SubView<T> tail_rows(size_t rows);
		//SHED 
		inline void shed_row(size_t r1);
		inline void shed_rows(size_t rbegin, size_t rend);
		inline void shed_col(size_t r1);
		inline void shed_cols(size_t cbegin, size_t cend);

		//PRINT-SAVE MATRIX
		#ifdef _DEBUG
			inline void printInfo() const;
		#endif // _DEBUG

		inline void print() const; 
		inline void save(const std::string& name);
		inline void load(const std::string& name);

		//DEFAULT CONSTRUCTOR AND DESTRUCTOR
		inline Matrix(T elem);
		inline Matrix(size_t rows, size_t cols);
		inline Matrix(size_t rows, size_t cols, T elem); 
		inline Matrix(size_t rows, size_t cols, const std::initializer_list<T>& list);
		inline Matrix(const std::initializer_list< std::initializer_list<T> >& list); 
		inline Matrix(size_t rows, size_t cols, const std::vector<T>& list); 
		inline Matrix(const std::vector< std::vector<T> >& list); 
		inline Matrix(size_t rows, size_t cols, const T* list); 
		inline Matrix(size_t rows, size_t cols, const T * const * list);
		inline Matrix(const Matrix<T>& m);
		inline Matrix(Matrix<T>&& m); 
		inline Matrix(const std::string& name);
		inline Matrix(const SubView<T>& v);
		inline Matrix(); 
		inline ~Matrix();
	};

	template<typename T>
	inline std::ostream& operator<<(std::ostream& o, const Matrix<T>& m); 
	template<typename T>
	inline std::ostream& operator<<(std::ostream& o, const typename Matrix<T>::row_iterator& m); 

	template<typename T>
	inline Matrix<T> operator+ (const T val, const Matrix<T>& m);
	template<typename T>
	inline Matrix<T> operator- (const T val, const Matrix<T>& m);
	template<typename T>
	inline Matrix<T> operator* (const T val, const Matrix<T>& m);
	template<typename T>
	inline Matrix<T> operator/ (const T val, const Matrix<T>& m);

};
#endif // !MATRIX