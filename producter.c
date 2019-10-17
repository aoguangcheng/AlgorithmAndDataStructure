#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h> 

int main()
{
	const int SIZE = 4096;
	const char *name = "OS";
	const char *message0 = "This is the first message,  ";
	const char *message1 = "This is the second message!!";
	int shm_fd;
	
	void *ptr;
	shm_fd = shm_open(name, O_CREAT|O_RDWR, 0666);
	ftruncate(shm_fd, SIZE);
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	
	sprintf(ptr, "%s", message0);
	ptr += strlen(message0);
	sprintf(ptr, "%s", message1);
	ptr += strlen(message1);
	

	return 0;
}
