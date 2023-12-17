// Online C++ compiler to run C++ program online
#include <stdio.h>
int main() {
    // Write C++ code here
  unsigned int x[4][3] = {{1,2,3}, {4, 5, 6}, {7,8,9}, {10,11,12}};
  
  printf("%d\t%d\t%d", x+3, *(x+3), *(x+2)+3);

  return 0;
}