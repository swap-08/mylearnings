#include<stdio.h>
#include "a.h"
void extern fun2();
void extern fun3();
int main()
{
   printf("In main");
   fun2();
   fun3();
   printf("End of main");
   return 0;
} 
