#ifndef ROW_VECTOR
#define ROW_VECTOR

#include "Matrix.h"
template<typename T>
class RowVector : public Matrix<T>
{
public:
	//SIZE MANIPULATION
	inline void set_size(const size_t size);
	inline void reshape(const size_t size);
	inline void resize(const size_t size);

	//INSERT
	inline void insert(size_t s, const T val);
	inline void insert_zeros(size_t s);
	inline void insert_ones(size_t s);

	//MOVE OPERATOR
	inline RowVector<T>& operator= (RowVector<T>&& m);

	//DEFAULT CONSTRUCTOR AND DESTRUCTOR
	inline RowVector(size_t size);
	inline RowVector(size_t size, T elem);
	inline RowVector(const std::initializer_list<T>& list);
	inline RowVector(const std::vector<T>& list);
	inline RowVector(size_t size, const T* list);
	inline RowVector(RowVector<T>&& c);
	inline RowVector();
	inline ~RowVector();
};

#endif // !ROW_VECTOR