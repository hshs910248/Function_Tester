#include <transpose_handle.h>

namespace prototype {

TransposeHandle::TransposeHandle(int* dim): d1(dim[0]), d2(dim[1]), d3(dim[2]) {
	d1d2 = d1 * d2;
}

TransposeHandle::~TransposeHandle() {}

int TransposeHandle::l123(int k, int i, int j) {
	return j + i * d1 + k * d1d2;
}

}