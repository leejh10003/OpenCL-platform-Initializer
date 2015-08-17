# OpenCL platform Initializer
OpenCL platform initializer made by joonji.<br />
CAUTION: Makefile is not completed. So do not use make command to build it.<br />
주의: Makefile은 완성되지 않았습니다. 따라서 이를 빌드하기 위해서 make 명령어를 사용하지 마십시오.<br />

##ENGLISH:
###Introduction:
  OpenCL is a powerful heterogeneous computing environment, but it is so hard to control it's function perfectly.
  And to most of programmer, even getting platform is an annoying job.
  
  In this library, only declaring one JJ_CL_PLATFORMS variable, and calling function jjOpenCLPlatformInitialize,
  you can get the number of all platform and information about each platforms.

###Usage:
  
  Usage is this. in any function where you want to get all platform can use,
  
```c
  JJ_CL_PLATFORMS platformsInformations;//Declare this variable which contains platforms' information
  cl_int errNum;//And error checking variable
  
  errNum = jjOpenCLPlatformInitialize(&platformsInformations, true);
  /*And call jjOpenCLPlatformInitialize to get all platforms.
   *Second boolean argument will determine
   *weather or not to display information about
   *all platforms at terminal(or console).
   */
```
  
  You can access all platform number like this:
```c
  platformsInformations.platformsNum//Type cl_uint
```
  You can access each platform's property like this:
```c
  platformsInformations.platforms[i].property//Type cl_platform_id or char[]
```  
  Read More information section what properties each platform has.
  
###More information:
  
  JJ_CL_PLATFORMS is structure which has variables:
```c
  typedef struct clPlatforms{
  	cl_uint platformsNum;
  	JJ_CL_PLAT_INFO platforms[];
  }JJ_CL_PLATFORMS;
```
  platformsNum has the number how much platform a given OpenCL environment has.<br />
  And platforms is a array whose each element has all informations about platform.<br />
  It can happen because JJ_CL_PLAT_INFO structure's form is:
```c
  typedef struct platformInformation{
  	cl_platform_id platformID;
  	char fullSupportOrNot[];
  	char clVersion[];
  	char clPlatformName[];
  	char clVendor[];
  	char clPlatformExtensions[];
  }JJ_CL_PLAT_INFO;
```
  platformID stores each platform's cl_platform_id.<br />
  All rest string contain information can get from OpenCL API function clGetPlatformInfo with macro:
```c
  CL_PLATFORM_PROFILE,
  CL_PLATFORM_VERSION,
  CL_PLATFORM_NAME,
  CL_PLATFORM_VENDOR,
  CL_PLATFORM_EXTENSION
```
  in this order.
  
  You can learn what information you can get from each macro from hear: https://www.khronos.org/registry/cl/sdk/1.0/docs/man/xhtml/clGetPlatformInfo.html
  


##한국어:

###소개:
  OpenCL 은 강력한 이종 컴퓨팅 환경입니다. 하지만 그 기능 전부를 활용하는 것은 매우 어렵죠.<br />
  그리고 대부분의 프로그래머에게는 플랫폼 정보를 받아오는 것도 귀찮은 작업입니다.<br />
  이 라이브러리를 사용하시면 단 하나의 JJ_CL_PLATFORMS 변수를 선언하고, jjOpenCLPlatformInitialize 함수를 호출하시는 만으로 모든 플랫폼의 수와 각각의 정보를 받아올 수 있습니다.
  
###사용법:
  당신이 사용할 수 있는 모든 플랫폼을 얻어오고 싶은 곳에서
```c
  JJ_CL_PLATFORMS platformsInformations;//플랫폼들의 정보를 포함하는 변수와
  cl_int errNum;//에러 처리용 변수를 선언하시고
  errNum = jjOpenCLPlatformInitialize(&platformsInformations, true);
  /*jjOpenCLPlatformInitialize를 호출하세요.
   *두번째 boolean 형 인자는 함수호출시
   *모든 플랫폼에 대한 정보들을 터미널(혹은 콘솔)에 표시할 지 결정합니다.
   */
```
  모든 플랫폼의 수에는 다음과 같이 접근하실 수 있습니다:
```c
  platformsInformations.platformsNum//cl_uint 형
```
  각 플랫폼의 속성에는 다음과 같이 접근하실 수 있습니다:
```c
  platformsInformations.platforms[i].property//cl_platform_id 혹은 char[] 형
```
각 플랫폼이 어떤 속성을 가지는 지 알고 싶으시면 더 알아보기 섹션을 읽어주세요.

###더 알아보기:
  JJ_CL_PLATFORMS 은 다음과 같은 변수들을 지닌 구조체입니다:
```c  
  typedef struct clPlatforms{
  	cl_uint platformsNum;
  	JJ_CL_PLAT_INFO platforms[];
  }JJ_CL_PLATFORMS;
```
  platformsNum 은 한 OpenCL 환경이 얼마나 많은 플랫폼을 가지고 있는지 저장되는 변수입니다.<br />
  그리고 platforms 변수는 각 원소가 플랫폼에 대한 모든 정보를 가지는 배열입니다.<br />
  JJ_CL_PLAT_INFO 구조체의 형태가 다음과 같기에 가능한 일이죠:<br />
```c
  typedef struct platformInformation{
  	cl_platform_id platformID;
  	char fullSupportOrNot[];
  	char clVersion[];
  	char clPlatformName[];
  	char clVendor[];
  	char clPlatformExtensions[];
  }JJ_CL_PLAT_INFO;
```
  platformID 는 각 플랫폼의 cl_platform_id를 저장합니다.<br />
  나머지 문자열은 OpenCL API 함수 clGetPlatformInfo 에 다음 매크로로 질의했을 때의 정보들을 포함하고 있습니다:
```c
  CL_PLATFORM_PROFILE,
  CL_PLATFORM_VERSION,
  CL_PLATFORM_NAME,
  CL_PLATFORM_VENDOR,
  CL_PLATFORM_EXTENSION
```
  순서는 구조체에서의 순서와 동일합니다.
  
  각 매크로로 받아올 수 있는 정보들에 대해서는 다음 주소를 참고하세요: https://www.khronos.org/registry/cl/sdk/1.0/docs/man/xhtml/clGetPlatformInfo.html
