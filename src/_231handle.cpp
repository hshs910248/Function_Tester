#include "transpose_handle.h"

namespace prototype {

_231Handle::_231Handle(int* dim): TransposeHandle(dim) {
	d2d3 = d2 * d3;
}

int _231Handle::l231(int k, int i, int j) {
	return i + k * d2 + j * d2d3;
}

int _231Handle::s1(int k, int i, int j) {
	return l231(k, i, j) % d1;
}
int _231Handle::s2(int k, int i, int j) {
	return (l231(k, i, j) / d1) % d2;
}
int _231Handle::s3(int k, int i, int j) {
	return (l231(k, i, j) / d1d2) % d3;
}

int _231Handle::g1(int k, int i, int j) {
	return (l123(k, i, j) / d2d3) % d1;
}
int _231Handle::g2(int k, int i, int j) {
	return l123(k, i, j) % d2;
}
int _231Handle::g3(int k, int i, int j) {
	return (l123(k, i, j) / d2)  % d3;
}

}