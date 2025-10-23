#include <stdio.h>
#include <float.h>

int main(){
  char op;
  double a,b,res;

  printf("enter your operator of + , - , / , *: ");
  scanf("%c",&op);

  printf("enter your numbers: ");
  scanf("%lf %lf",&a ,&b);
  switch(op){
  case('*'):res=a*b;break;
  case('+'):res=a+b;break;
  case('-'):res=a-b;break;
  case('/'):res=a/b;break;
    default:printf("error");
      res=-DBL_MAX;
}
  if(res!=-DBL_MAX){
    printf("%.2lf",res);
  }
  return 0;
}
