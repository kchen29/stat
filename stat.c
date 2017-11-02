#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

int main() {
  struct stat sb;
  stat("stat.c", &sb);

  long filesize = sb.st_size;
  int permission = sb.st_mode;
  
  printf("file size: %ldB\n", filesize);
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

  printf("better file size: %ld GB %ld MB %ld KB %ld B\n", gb, mb, kb, b);

  permission = permission % (64 * 8);
  //printf("%o\n", permission);
  
  int user = permission / 64;
  int group = (permission % 64) / 8;
  int other = (permission % 8);
  
  // printf("%d\n", user);
  //printf("%d\n", group);
  //printf("%d\n", other);

  char zero[50] = "---";
  char one[50] = "--x";
  char two[50] = "-w-";
  char three[50] = "-wx";
  char four[50] = "r--";
  char five[50] = "r-x";
  char six[50] = "rw-";
  char seven[50] = "rwx";

  char numero[50] = "-";

  if (user == 0){
    strcat(numero, zero);
  }
  if (user == 1){
    strcat(numero, one);
  }
  if (user == 2){
    strcat(numero, two);
  }
  if (user == 3){
    strcat(numero, three);
  }
  if (user == 4){
    strcat(numero, four);
  }
  if (user == 5){
    strcat(numero, five);
  }
  if (user == 6){
    strcat(numero, six);
  }
  if (user == 7){
    strcat(numero, seven);
  }
  
  if (group == 0){
    strcat(numero, zero);
  }
  if (group == 1){
    strcat(numero, one);
  }
  if (group == 2){
    strcat(numero, two);
  }
  if (group == 3){
    strcat(numero, three);
  }
  if (group == 4){
    strcat(numero, four);
  }
  if (group == 5){
    strcat(numero, five);
  }
  if (group == 6){
    strcat(numero, six);
  }
  if (group == 7){
    strcat(numero, seven);
  }

  if (other == 0){
    strcat(numero, zero);
  }
  if (other == 1){
    strcat(numero, one);
  }
  if (other == 2){
    strcat(numero, two);
  }
  if (other == 3){
    strcat(numero, three);
  }
  if (other == 4){
    strcat(numero, four);
  }
  if (other == 5){
    strcat(numero, five);
  }
  if (other == 6){
    strcat(numero, six);
  }
  if (other == 7){
    strcat(numero, seven);
  }

  printf("better permissions: %s\n", numero);
  
  return 0;
}
