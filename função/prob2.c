#include <stdio.h> 
#include <stdbool.h>

int PrimeMover(int num)
{
  const int max_limit = 110000;
  bool is_prime[110000];

  for(int i = 0;i < max_limit; i++)
  {
    is_prime[i] = true;
  }

  is_prime[0] = false;
  is_prime[1] = false;

  for(int p = 2; p * p < max_limit; p++)
  {
    if(is_prime[p])
    {
      for(int i = p * p; i < max_limit; i += p)
      {
        is_prime[i] = false;
      }
    }
  }

  int count = 0;
  for(int p = 2; p < max_limit; p++)
  {
    if(is_prime[p])
    {
      count++;
      if(count == num)
      {
        return p;
      }
    }
  }

  return -1;
}

int main()
{
  int pos;
  scanf("%d",&pos);

  printf("%d\n",PrimeMover(pos));
}
