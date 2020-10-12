#include "transpose_handle.h"

namespace prototype {

_321Handle::_321Handle(int* dim): TransposeHandle(dim) {
	d3d2 = d3 * d2;
}

int _321Handle::l321(int k, int i, int j) {
	return k + i * d3 + j * d3d2;
}

int _321Handle::s1(int k, int i, int j) {
	return l321(k, i, j) % d1;
}
int _321Handle::s2(int k, int i, int j) {
	return (l321(k, i, j) / d1) % d2;
}
int _321Handle::s3(int k, int i, int j) {
	return (l321(k, i, j) / d1d2) % d3;
}

int _321Handle::g1(int k, int i, int j) {
	return (l123(k, i, j) / d3d2) % d1;
}
int _321Handle::g2(int k, int i, int j) {
	return (l123(k, i, j) / d3) % d2;
}
int _321Handle::g3(int k, int i, int j) {
	return l123(k, i, j)  % d3;
}

}