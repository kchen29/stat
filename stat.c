#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  struct stat sb;
  stat("stat.c", &sb);

  printf("file size: %ld\n", sb.st_size);
  printf("mode: %o\n", sb.st_mode);
  printf("last access time: %s\n", ctime(&sb.st_atime) );
  
  return 0;
}
