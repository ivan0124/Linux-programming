/*app_a.c*/
#include <stdio.h>
#include "lib_common.h"

int main( int argc, char* argv[])
{
    log("\nHello World\n"); 
    testFuncA();
    testFuncA1();
    //calling function in library
    test_lib_a();
    test_lib_a1();
    
    char res[256]={0};
    get_shell_cmd_result("./test.sh", res, sizeof(res));
    log("%s\n",res);
    return 0;
}
