#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { W = 800 };

int
main()
{
  unsigned char *buf;
  int R;
  int i;
  int j;
  int u;
  int v;

  if ((buf = malloc(3 * W * W * sizeof *buf)) == NULL) {
    fprintf(stderr, "malloc failed\n");
    exit(2);
  }
  for (R = W/10; R < W/2; R++) {
    memset(buf, 0, 3 * W * W * sizeof *buf);
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
    if (fwrite(buf, 3 * W, W, stdout) != W)
      exit(2);
    if (fflush(stdout) == EOF)
      exit(2);
  }
  free(buf);
  return 0;
}
