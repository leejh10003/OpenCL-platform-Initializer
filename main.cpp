#ifndef _GLIBCXX_CSTDIO
	#include <cstdio>
	#define _GLIBCXX_CSTDIO
#endif
#ifndef _GLIBCXX_CSTDLIB
	#include <cstdlib>
	#define _GLIBCXX_CSTDLIB
#endif
#ifndef _GLIBCXX_CSTRING
	#include <cstring>
	#define _GLIBCXX_CSTRING
#endif
#ifndef _GLIBCXX_IOSTREAM
	#include <iostream>
	#define _GLIBCXX_IOSTREAM
#endif
#ifndef _GLIBCXX_FSTREAM
	#include <fstream>
	#define _GLIBCXX_FSTREAM
#endif
#ifndef _GLIBCXX_SSTREAM
	#include <sstream>
	#define _GLIBCXX_SSTREAM
#endif
#ifndef __OPENCL_CL_H
	#ifdef __APPLE__
		#include <OpenCL/opencl.h>
	#else
		#include <CL/cl.h>
	#endif
	#define __OPENCL_CL_H
#endif
#ifndef JJ_OPENCL_PLATFORM_INITIALIZE
	#include "jjOpenCLPlatformInitialize.hpp"
	#define JJ_OPENCL_PLATFORM_INITIALIZE
#endif
int main(int argc, char** argv)
{
	JJ_CL_PLATFORMS platformsInformations;
	cl_int errNum;

	errNum = jjOpenCLPlatformInitialize(&platformsInformations, true);
	return 0;
}