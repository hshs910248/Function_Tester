#pragma once

namespace prototype {

class TransposeHandle {

public:
	int d1;
	int d2;
	int d3;
	int d1d2;
	
	TransposeHandle(int* dim);
	~TransposeHandle();
	int l123(int k, int i, int j);
	virtual int s1(int k, int i, int j) = 0;
	virtual int s2(int k, int i, int j) = 0;
	virtual int s3(int k, int i, int j) = 0;
	virtual int g1(int k, int i, int j) = 0;
	virtual int g2(int k, int i, int j) = 0;
	virtual int g3(int k, int i, int j) = 0;
};

class _132Handle: public TransposeHandle {

public:
	int d1d3;
	_132Handle(int* dim);
	~_132Handle();
	int l132(int k, int i, int j);
	int s1(int k, int i, int j);
	int s2(int k, int i, int j);
	int s3(int k, int i, int j);
	int g1(int k, int i, int j);
	int g2(int k, int i, int j);
	int g3(int k, int i, int j);
};

class _213Handle: public TransposeHandle {

public:
	int d2d1;
	_213Handle(int* dim);
	~_213Handle();
	int l213(int k, int i, int j);
	int s1(int k, int i, int j);
	int s2(int k, int i, int j);
	int s3(int k, int i, int j);
	int g1(int k, int i, int j);
	int g2(int k, int i, int j);
	int g3(int k, int i, int j);
};

class _312Handle: public TransposeHandle {

public:
	int d3d1;
	_312Handle(int* dim);
	~_312Handle();
	int l312(int k, int i, int j);
	int s1(int k, int i, int j);
	int s2(int k, int i, int j);
	int s3(int k, int i, int j);
	int g1(int k, int i, int j);
	int g2(int k, int i, int j);
	int g3(int k, int i, int j);
};

class _321Handle: public TransposeHandle {

public:
	int d3d2;
	_321Handle(int* dim);
	~_321Handle();
	int l321(int k, int i, int j);
	int s1(int k, int i, int j);
	int s2(int k, int i, int j);
	int s3(int k, int i, int j);
	int g1(int k, int i, int j);
	int g2(int k, int i, int j);
	int g3(int k, int i, int j);
};

class _231Handle: public TransposeHandle {

public:
	int d2d3;
	_231Handle(int* dim);
	~_231Handle();
	int l231(int k, int i, int j);
	int s1(int k, int i, int j);
	int s2(int k, int i, int j);
	int s3(int k, int i, int j);
	int g1(int k, int i, int j);
	int g2(int k, int i, int j);
	int g3(int k, int i, int j);
};

}