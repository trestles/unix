
#include <stdio.h>

int main()
{
  printf("here are things\n");
  int x,y,z;
  int *px;
  x=5;
  y=18;
  printf("x: %i and address: %p\n",x, &x);
  printf("y: %i and address: %p\n",y, &y);
  px=&x;
  printf("px value: %i\n\n",*px);  
  z=*px;
  printf("z value: %i\n", z);
  *px=8;
  printf("z now is: %i\n\n",x);
  printf("new value for x:");
  scanf("%d",&x);
  printf("x is :%i\n\n",x);
}
