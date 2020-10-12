#include "transpose_handle.h"

namespace prototype {

_213Handle::_213Handle(int* dim): TransposeHandle(dim) {
	d2d1 = d2 * d1;
}

int _213Handle::l213(int k, int i, int j) {
	return i + j * d2 + k * d2d1;
}

int _213Handle::s1(int k, int i, int j) {
	return l213(k, i, j) % d1;
}
int _213Handle::s2(int k, int i, int j) {
	return (l213(k, i, j) / d1) % d2;
}
int _213Handle::s3(int k, int i, int j) {
	return (l213(k, i, j) / d1d2) % d3;
}

int _213Handle::g1(int k, int i, int j) {
	return (l123(k, i, j) / d2) % d1;
}
int _213Handle::g2(int k, int i, int j) {
	return l123(k, i, j) % d2;
}
int _213Handle::g3(int k, int i, int j) {
	return (l123(k, i, j) / d2d1)  % d3;
}

}