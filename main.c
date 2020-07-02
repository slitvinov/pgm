#include <stdio.h>
#include <string.h>

enum { W = 800 };

int
main()
{
  unsigned char buf[3 * W * W];
  memset(buf, 0, sizeof(buf));
  int R = 40;
  int i;
  int j;
  int u;
  int v;

  for (R = 40; R < W/2; R++) {
    for (i = 0; i < W; i++)
      for (j = 0; j < W; j++) {
	u = i - W/2;
	v = j - W/2;
	if (u * u + v * v < R * R)
	  buf[3 * (i * W + j) ] = 0xFF;
	if (u * u + v * v < R * R / 4)
	  buf[3 * (i * W + j) + 1] = 0xFF;	  
      }
    printf("P6\n%d %d\n255\n", W, W);
    fwrite(buf, 3 * W, W, stdout);
    fflush(stdout);
  }
  return 0;
}
