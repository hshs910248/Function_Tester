#include "transpose_handle.h"

namespace prototype {

_132Handle::_132Handle(int* dim): TransposeHandle(dim) {
	d1d3 = d1 * d3;
}

int _132Handle::l132(int k, int i, int j) {
	return j + k * d1 + i * d1d3;
}

int _132Handle::s1(int k, int i, int j) {
	return l132(k, i, j) % d1;
}
int _132Handle::s2(int k, int i, int j) {
	return (l132(k, i, j) / d1) % d2;
}
int _132Handle::s3(int k, int i, int j) {
	return (l132(k, i, j) / d1d2) % d3;
}

int _132Handle::g1(int k, int i, int j) {
	return l123(k, i, j) % d1;
}
int _132Handle::g2(int k, int i, int j) {
	return (l123(k, i, j) / d1d3) % d2;
}
int _132Handle::g3(int k, int i, int j) {
	return (l123(k, i, j) / d1)  % d3;
}

}