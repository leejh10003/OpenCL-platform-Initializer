CC = G++
CFLAGS =
OUT = test

ifeq ($(UNAME),Darwin) #Mac OS
    echo "Darwin"
    SRC = main.cpp jjOpenCLPlatformInitialize.cpp jjOpenCLPlatformInitialize.hpp
    LIBS = -framework OpenCL
endif

ifeq ($(UNAME),Linux) #Linux based systems
	SRC = main.cpp jjOpenCLPlatformInitialize.cpp jjOpenCLPlatformInitialize.hpp
    LIBS = -l OpenCL
endif

$(OUT) : $(SRC)
    $(CC) $(CFLAGS) -o $(OUT)

clean :
    rm -f $(OBJ) $(OUT)