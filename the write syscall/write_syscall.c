#include <unistd.h>
#include <string.h>

int main(){
	char* str = "Writing to stdout\n";
	write(1,str,strlen(str));
	return 0;
} 
