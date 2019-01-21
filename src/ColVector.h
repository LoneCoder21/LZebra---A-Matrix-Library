#ifndef COL_VECTOR
#define COL_VECTOR

#include "Matrix.h"
template<typename T>
class ColVector : public Matrix<T>
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
	inline ColVector<T>& operator= (ColVector<T>&& m);

	//DEFAULT CONSTRUCTOR AND DESTRUCTOR
	inline ColVector(size_t size);
	inline ColVector(size_t size, T elem);
	inline ColVector(const std::initializer_list<T>& list);
	inline ColVector(const std::vector<T>& list);
	inline ColVector(size_t size, const T* list);
	inline ColVector(ColVector<T>&& c);
	inline ColVector();
	inline ~ColVector();
};

#endif // !COL_VECTOR