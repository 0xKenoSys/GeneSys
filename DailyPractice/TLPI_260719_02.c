 #include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

 setenv("Galaxy", "42", 1);

 char *val = getenv("Galaxy");
 if (val != NULL)
  printf("Galaxy = %s\n", val);
 else
  printf("Galaxy is not set\n");

 unsetenv("Galaxy");

 char *val2 = getenv("Galaxy");
 if (val2 != NULL)
  printf("Galaxy = %s\n", val2);
 else
  printf("Galaxy is not set\n");

 printf("val = %s\n", val);
 val = 1;
 printf("val = %s\n", val);

 exit(EXIT_SUCCESS);
}


//
// Created by Yingmei Zhang on 19/7/2026.
//
