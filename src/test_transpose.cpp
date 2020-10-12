#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "transpose.h"
#include "tensor_util.h"

void test_transpose(int* dim, int* permutation) {
	TensorUtil<int> tu(NULL, 3, dim, permutation);
	size_t dataSize = sizeof(int) * tu.vol;
	int* idata = (int*)malloc(dataSize);
	int* odata = (int*)malloc(dataSize);
	
	prototype::TransposeHandle* handle = prototype::init_handle(dim, permutation);
	if (handle == nullptr) return;
	tu.init_data(idata);
	tu.print_mat(idata);
	
	printf("Transpose\n");
	prototype::transpose_scatter(odata, idata, handle);
	
	tu.print_mat(odata);
	int* ans = (int*)malloc(dataSize);
	tu.seq_tt(ans, idata);
	if (!memcmp(ans, odata, dataSize)) printf("Pass\n");
	else printf("Error\n");
	
	free(handle);
	free(idata);
	free(odata);
	free(ans);
}

int main(int argc, char** argv) {
	int dim[3] = {4, 3, 2};
	//int permutation[3] = {0, 2, 1};
	int permutation[3] = {1, 2, 0};
	test_transpose(dim, permutation);
	return 0;
}
