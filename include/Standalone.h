#ifndef STANDALONE_H
#define STANDALONE_H

#define _USE_MATH_DEFINES

#include <vector>
#include <cmath>
#include <complex>
#include <random>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <limits>
#include <type_traits>

#define templ template<typename T>
#define cmat const Matrix<T>&
#define noncmat Matrix<T>&
#define ccvec const ColVector<T>& 
#define crvec const RowVector<T>& 
#define cpmat const Matrix<std::complex<T>>&
#define noncpmat Matrix<std::complex<T>>&
#define _fPtr template<double(*_func)(double), typename T>

#define ftempldec template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
#define ftempldef template<typename T, typename>

typedef unsigned char uchar;

template<typename T>
class Matrix;
template<typename T>
class ColVector;
template<typename T>
class RowVector;

namespace random {
	double gaussianRandom();
	double uniformFloatRandom();
	int uniformIntRandom(int max = INT_MAX);
}

namespace tenseopr {
	templ Matrix<T> abs(cmat m);
	templ T accu(cmat m);
	templ Matrix<T> affmul(cmat m1, noncmat m2);

	templ Matrix<char> all(cmat m, uchar c=0);
	templ Matrix<char> any(cmat m, uchar c=0);
	templ bool approx_equal(cmat m1, cmat m2, uchar c, T t1, T t2 = 0);
	ftempldec Matrix<T> round(cmat m1, T tolerance);

	template<typename C, typename T> Matrix<C> arg(cpmat complexmat);
	templ T as_scalar(cmat m);
	templ Matrix<T> clamp(cmat m, T min, T max);

	templ double cond(cmat m);//eigen values
	templ Matrix<std::complex<T>> conj(cpmat complexmat);
	template<typename C, typename T> Matrix<C> conv_to(cmat m);

	templ Matrix<T> cross(cmat m1, cmat m2);
	templ Matrix<T> cumsum(cmat m, size_t dim = 0); 
	templ Matrix<T> cumprod(cmat m, size_t dim = 0);

	templ Matrix<T> ref(cmat m);//almost done. maybe done. no clue
	templ T det(cmat m);//finish this
	templ Matrix<T> diagmat(cmat m, int val = 0);
	templ Matrix<T> diagvec(cmat m, int val = 0);
 
	templ Matrix<T> diff(cmat m1, size_t k=1, uchar dim = 0);
	templ double dot(cmat v1, cmat v2);
	templ double norm_dot(cmat v1, cmat v2);
	templ double magnitude(cmat v1);
	
	templ Matrix<T> expmat(cmat m); //later
	templ Matrix<T> expmat_sym(cmat m);//later

	templ Matrix<size_t> find(cmat m,size_t k=0, uchar s=0);
	templ Matrix<size_t> find_finite(cmat m);
	templ Matrix<size_t> find_nonfinite(cmat m);
	templ Matrix<size_t> find_unique(cmat m, bool ascending = 1);

	templ Matrix<T> fliplr(cmat m);
	templ Matrix<T> flipud(cmat m);
	templ Matrix<T> real(cpmat m);
	templ Matrix<T> imag(cpmat m);
	templ ColVector<size_t> ind2sub(cmat size, size_t index);
	templ Matrix<size_t> ind2sub(size_t rows, size_t cols, cmat indices);
	templ Matrix<size_t> ind2sub(cmat size, cmat indices);
	
	templ Matrix<size_t> index_max(cmat m, uchar dim = 0);
	templ Matrix<size_t> index_min(cmat m, uchar dim = 0);
	templ void inplace_trans(noncmat m);
	templ void inplace_trans(noncpmat m);
	templ void inplace_strans(noncpmat m);

	templ bool is_finite(cmat m);
	templ Matrix<T> join_rows(cmat m1, cmat m2);
	templ Matrix<T> join_cols(cmat m1, cmat m2);
	templ Matrix<T> join_horiz(cmat m1, cmat m2);
	templ Matrix<T> join_vert(cmat m1, cmat m2);

	templ Matrix<T> kron(cmat m1, cmat m2);
	templ void log_det(double &val, double& sign, cmat m); //need trace
	templ Matrix<std::complex<T>> log_det(cmat m);//need trace
	templ Matrix<T> logmat(cmat m);//need to diagonalize first
	templ Matrix<T> logmat_sympd(cmat m);//need to diagonalize first

	templ Matrix<T> max(cmat m, uchar dim = 0);
	templ Matrix<T> min(cmat m, uchar dim = 0);
	templ ColVector<T> nonzeros(cmat m);

	templ double pnorm(cmat m, uchar type=2); //need eigenvals
	templ double pnorm(cmat m, std::string type); //need eigenvals

	templ Matrix<T> normalise(cmat m, uchar type = 2, uchar dim = 0);//eigenvals
	templ Matrix<T> prod(cmat m, uchar dim = 0);

	templ size_t rank(cmat m);
	templ double rcond(cmat m);//eigen stuff
	templ Matrix<T> repelem(cmat m, size_t rowcopy, size_t colcopy);//doesn't work
	templ Matrix<T> repmat(cmat m, size_t rowcopy, size_t colcopy);//doesn't work

	templ Matrix<T> reshape(cmat m, size_t n_rows, size_t n_cols); //not sure
	templ Matrix<T> resize(cmat m, size_t n_rows, size_t n_cols);//not sure

	templ Matrix<T> reverse(cmat m,size_t dim=0);
	templ ColVector<std::complex<T>> roots(cmat m); //eigen decomp
	templ Matrix<T> shift(cmat m, int c, uchar dim = 0);//failed iterator
	templ Matrix<T> shuffle(cmat m, uchar dim=0);//failed iterator
	templ Matrix<T> sort(cmat m, std::string type, uchar dim = 0);//need random-access iterator

	templ Matrix<std::complex<T>> sqrtmat(cmat m);
	templ Matrix<T> sqrtmat_sympd(cmat m);

	templ Matrix<T> sum(cmat m, uchar dim = 0);
	templ size_t sub2ind(cmat size, size_t i, size_t j);
	templ ColVector<size_t> sub2ind(size_t rows, size_t cols, cmat indices);
	templ ColVector<size_t> sub2ind(cmat size, cmat indices);

	templ T trace(cmat m);
	templ Matrix<T> trans(cmat m);
	templ Matrix<std::complex<T>> trans(cpmat m);
	templ Matrix<std::complex<T>> strans(cpmat m);
	templ Matrix<T> trapz(cmat m, uchar dim = 0);

	templ Matrix<T> trimatu(cmat m, int k = 0);//nope
	templ Matrix<T> trimatl(cmat m, int k = 0);//nope
	templ Matrix<T> unique(cmat m);
	templ Matrix<T> vectorise(cmat m, uchar dim=0);

	_fPtr Matrix<double> misc(cmat m);
}

#endif