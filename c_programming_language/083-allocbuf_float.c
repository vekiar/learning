#define ALLOCSIZE 10000           // Available space

static float allocbuf[ALLOCSIZE];  // Storage for alloc
static float *allocp = allocbuf;   // Next free position

float *alloc(int n);               // Returns pointer to n floatacters
void afree(float *p);

int main()
{
  return 0;
}

float *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else { // not enough space
    return 0;
  }
}

void afree(float *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
