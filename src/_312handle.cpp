#include "transpose_handle.h"

namespace prototype {

_312Handle::_312Handle(int* dim): TransposeHandle(dim) {
	d3d1 = d3 * d1;
}

int _312Handle::l312(int k, int i, int j) {
	return k + j * d3 + i * d3d1;
}

int _312Handle::s1(int k, int i, int j) {
	return l312(k, i, j) % d1;
}
int _312Handle::s2(int k, int i, int j) {
	return (l312(k, i, j) / d1) % d2;
}
int _312Handle::s3(int k, int i, int j) {
	return (l312(k, i, j) / d1d2) % d3;
}

int _312Handle::g1(int k, int i, int j) {
	return (l123(k, i, j) / d3) % d1;
}
int _312Handle::g2(int k, int i, int j) {
	return (l123(k, i, j) / d3d1) % d2;
}
int _312Handle::g3(int k, int i, int j) {
	return l123(k, i, j) % d3;
}

}