#include <stdio.h>
main()
{
 int a[]={1,2,3,4,5};
 int *p;
 p = a;
 printf("%d\n",*p);
 printf("%d\n",p);
 printf("%d\n",a);
 printf("%d\n",&p);
 system("pause");
}
 