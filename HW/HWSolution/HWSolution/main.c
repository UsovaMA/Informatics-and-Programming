#include <stdio.h>
#include <math.h>

int main() {
  printf("Task with circles");
  //init
  float x1, x2, y1, y2, r1, r2;
  float d;

  printf("Input 1st circle (in form x y r): ");
  scanf_s("%f %f %f", &x1, &y1, &r1);

  printf("Input 2nd circle (in form x y r): ");
  scanf_s("%f %f %f", &x2, &y2, &r2);

  // action

  d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

  // output

  if (d == r1 + r2) {
    printf("Kasautsa");
  } else 
  if (d < r1 + r2) {
    if (d == 0 && r1 == r2) {          // && = AND
      printf("Sovpadaut");
    } else
    if (d + r1 < r2 || d + r2 < r1) {  // || = OR
      printf("Odna vnutri drugoi");
    } 
    else {
      printf("Peresecautsa");
    }
  } else
  if (d > r1 + r2) {
    printf("Ne svazani");
  }

  /// <summary>
  /// 
  /// 
  /// </summary>
  /// <returns></returns>

  return 0;
}
