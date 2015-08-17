#include "jjOpenCLPlatformInitialize.hpp"

int main(int argc, char** argv)
{
	JJ_CL_PLATFORMS platformsInformations;
	cl_int errNum;

	errNum = jjOpenCLPlatformInitialize(&platformsInformations, true);
	return 0;
}