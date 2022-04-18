/*
 * This program displays the names of all files in the current directory.
 */

#include <dirent.h>
#include <stdio.h>

int main(void) {
  DIR *folder;
  struct dirent *dirc;
  folder = opendir(".");
  if (folder) {
    while ((dirc = readdir(folder)) != NULL) {
      printf("%s\n", dirc->d_name);
    }
    closedir(folder);
  }
  return(0);
}
