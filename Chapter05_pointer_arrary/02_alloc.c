/*
 * @FilePath: /tcpl-demo/Chapter05_pointer_arrary/02_alloc.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-11 09:55:52
 * @Version: 0.0.1
 */
#include <stdlib.h>

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* return a pointer to a newly allocated block of n bytes */
char *local_alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else {
		return 0;
	}
}

void local_afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

size_t local_strlen(char *str)
{
	char *p = str;
	while (*p++)
		;

	return p - str;
}

void local_strcpy(char *dest, char *src)
{
	while (*dest++ = *src++)
		;
}

int local_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++) {
		if (*s1 == '\0' || *s2 == '\0')
			return 0;
	}

	return *s1 - *s2;
}