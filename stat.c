#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  struct stat sb;
  stat("stat.c", &sb);

  long filesize = sb.st_size;
  int permission = sb.st_mode;
  
  printf("file size: %ld\n", filesize);
  printf("mode: %o\n", permission);
  printf("last access time: %s\n", ctime(&sb.st_atime) );

  //check
  //long b = 1024 * 1024 + 1024 + 1;
  long b = filesize;
  long kb = b / 1024;
  long mb = kb / 1024;
  long gb = mb / 1024;
  mb = mb % 1024;
  kb = kb % 1024;
  b = b % 1024;

  printf("%ld GB %ld MB %ld KB %ld B\n", gb, mb, kb, b);

  permission = permission % (64 * 8);
  //printf("%o\n", permission);
  
  int user = permission / 64;
  int group = (permission % 64) / 8;
  int other = (permission % 8);
  
  //printf("%d\n", user);
  //printf("%d\n", group);
  //printf("%d\n", other);
  
  return 0;
}
