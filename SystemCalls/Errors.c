#include <stdio.h>
#include <errno.h>
#ifndef _UNISTD_H
#define _UNISTD_H    1


void verify_fd(int fd) {
  if (fd < 0) {
    printf("File descriptor is negative!\n");

    if (errno == EAGAIN) {
      printf("Error: EAGAIN - Resource temporarily unavailable\n");
    } else if (errno == EACCES) {
      printf("Error: EACCES - Permission denied\n");
    } else if (errno == EBADF) {
      printf("Error: EBADF - Bad file descriptor\n");
    } else {
      printf("Unknown error code: %d\n", errno);
    }
  }
}


int main() {
  int fd = open("example.txt", O_RDONLY);
  if (fd < 0) {
    perror("Failed to open file");
  } else {
    // Do something with the file
  }

  verify_fd(fd);

  return 0;
}