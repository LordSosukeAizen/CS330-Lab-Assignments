#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>
#include<sys/mman.h>

#define _PB 4096


long how_large(void *address)
{
  /*
   *  TODO: Your code
   */ 

unsigned long addr = (unsigned long) address;
addr = (addr >> 12) << 12;
void *ptr1 = mmap((void *)addr, _PB, PROT_READ | PROT_WRITE,  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

assert(ptr1 != MAP_FAILED);
munmap(ptr1, _PB);

if(ptr1 == (void *)addr)
	return 0;

void *left = (void *) addr - 4096;
void *right = (void *) addr + 4096;


while(1){
	void *allocated = mmap(left, _PB, PROT_READ | PROT_WRITE,  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
        assert(allocated != MAP_FAILED);
        munmap(allocated, _PB);
	if(allocated == left){
		left += _PB;
		break;
	}
	left -= _PB;
}

while(1) {
     void* allocated = mmap(right, _PB, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
     assert(allocated != MAP_FAILED);
     munmap(allocated, _PB);
     if(allocated == right) break;

     right += _PB;

}

long ans = right - left;

return ans;


 
}
