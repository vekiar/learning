#define ALLOCSIZE 10000           // Available space

static char allocbuf[ALLOCSIZE];  // Storage for alloc
static char *allocp = allocbuf;   // Next free position

char *alloc(int n);               // Returns pointer to n characters
void afree(char *p);

int main()
{
  return 0;
}

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else { // not enough space
    return 0;
  }
}

void afree(char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
