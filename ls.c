#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void ls(char* path) {   //simple ls  mplementation
    DIR* dir = opendir(path);
    struct dirent* ent;
    if (dir == NULL) {
        perror("error");
        exit(1);
    }

    while ((ent = readdir(dir)) != NULL) {
        if(strncmp(ent->d_name, ".", 1) == 0 || strncmp(ent->d_name, "..", 2) == 0) {
            continue;
        }        
        printf("%s\n", ent->d_name);    
    }
    closedir(dir);
}

void ls_a(char* path) {   //ls -a implementation
    DIR* dir = opendir(path);
    struct dirent* ent;
    if (dir == NULL) {
        perror("error");
        exit(1);
    }
    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);    
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 1) {
        perror("error");
        exit(1);
    }
    ls(argv[1]);
    //ls_a(argv[1]);
}
