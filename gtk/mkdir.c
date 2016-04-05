#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
struct stat st = {0};

if (stat("/home/shuvo/newfi", &st) == -1) {
    mkdir("/home/shuvo/newfi", 0700);
}
else{
	printf("file exists\n");
}
}