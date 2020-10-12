#include <cstdio>
#include "transpose_handle.h"

namespace prototype {

const int rank = 3;

TransposeHandle* init_handle(int* dim, int* permutation) {
	int type = 0;
	for (int i = 0; i < rank; i++) {
		type = type * 10 + permutation[i] + 1;
	}
	printf("Permutation: %d\n", type);
	TransposeHandle* handle = nullptr;
	switch (type) {
		case 132:
			handle = new _132Handle(dim);
			break;
		case 213:
			handle = new _213Handle(dim);
			break;
		case 312:
			handle = new _312Handle(dim);
			break;
		case 321:
			handle = new _321Handle(dim);
			break;
		case 231:
			handle = new _231Handle(dim);
			break;
		default:
			printf("Invalid permutation\n");
			break;
	}
	
	return handle;
}

void transpose_scatter(int* AT, int* A, TransposeHandle* handle) {
	int d1 = handle->d1;
	int d2 = handle->d2;
	int d3 = handle->d3;
	for (int k = 0; k < d3; k++) {
		for (int i = 0; i < d2; i++) {
			for (int j = 0; j < d1; j++) {
				int j_prime = handle->s1(k, i, j);
				int i_prime = handle->s2(k, i, j);
				int k_prime = handle->s3(k, i, j);
				int src = handle->l123(k, i, j);
				int dest = handle->l123(k_prime, i_prime, j_prime);
				AT[dest] = A[src];
			}
		}
	}
}

void transpose_gather(int* AT, int* A, TransposeHandle* handle) {
	int d1 = handle->d1;
	int d2 = handle->d2;
	int d3 = handle->d3;
	for (int k = 0; k < d3; k++) {
		for (int i = 0; i < d2; i++) {
			for (int j = 0; j < d1; j++) {
				int j_prime = handle->g1(k, i, j);
				int i_prime = handle->g2(k, i, j);
				int k_prime = handle->g3(k, i, j);
				int src = handle->l123(k_prime, i_prime, j_prime);
				int dest = handle->l123(k, i, j);
				AT[dest] = A[src];
			}
		}
	}
}

}