/*
 * @FilePath: /tcpl-demo/Chapter04_function_program_structure/06_macro_test.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-10 16:05:24
 * @Version: 0.0.1
 */
// #include <stdio.h>

// #define DPRINT(expr) printf(#expr " = %g\n", expr)

// int main(void)
// {
// 	double x = 10.0, y = 5.0;

// 	DPRINT(x / y);

// 	return 0;
// }

#include <stdio.h>

#define STRINGIFY(x) #x
#define CONCATENATE(x, y) x##y
#define MACRO_NAME "MyMacro"

int main()
{
	// 直接使用不转义的字符串
	printf("Macro name is: " MACRO_NAME "\n");

	// 使用转义后的字符串
	printf("Macro name is: \"" STRINGIFY(MACRO_NAME) "\"\n");

	return 0;
}