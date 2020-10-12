#pragma once
#include "transpose_handle.h"

namespace prototype {

TransposeHandle* init_handle(int* dim, int* permutation);
void transpose_scatter(int* AT, int* A, TransposeHandle* handle);
void transpose_gather(int* AT, int* A, TransposeHandle* handle);

}