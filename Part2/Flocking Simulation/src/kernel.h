#ifndef KERNEL_H
#define KERNEL_H

#include <stdio.h>
#include <thrust/random.h>
#include <cuda.h>
#include <cmath>

#if CUDA_VERSION >= 5000
    #include <helper_math.h>
#else
    #include <cutil_math.h>
#endif

#define blockSize 128
#define checkCUDAErrorWithLine(msg) checkCUDAError(msg, __LINE__)
#define SHARED 0
#define N_FOR_VIS 15000
#define g_fMaxSpeed 1.0f

void checkCUDAError(const char *msg, int line);
void cudaFlockingUpdateWrapper(float dt);
void initCuda(int N);
void cudaUpdatePBO(float4 * pbodptr, int width, int height);
void cudaUpdateVBO(float * vbodptr);
#endif
