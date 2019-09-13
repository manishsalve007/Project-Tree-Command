#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

struct commandinformation {
    char command[20];
    int noofcommand;
}commandinformation;

void printthetree(char *name, int root);
void tree(char *name, char *basepath, const int root);
void printthepath(char *name, int root);

int main(int argc, char *argv[]) {
    commandinformation.noofcommand = 0;
    strcpy(commandinformation.command, "");
    commandinformation.noofcommand = argc - 1;
    int c;
    for(c = 1; c < argc - 1; c++) {
        commandinformation.command[c - 1] = argv[c][1];
    }

    tree(argv[argc - 1] ,argv[argc - 1], 0);
    return 0;
}

int findcommand(char p) {
    int i;
    int c = 0;
    for(i = 0; i < commandinformation.noofcommand; i++) {
        if(commandinformation.command[i] == p)
            c = 1;
    }
    return c;
}

void tree(char *name, char *basepath, int root) {
    char path[1000];
    struct dirent *dp;
    if(findcommand('f'))
        printthepath(basepath, root);
    else
        printthetree(name, root);
    DIR *dir = opendir(basepath);

    if (!dir)
        return;


    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && (dp->d_name[0] != '.' || findcommand('a'))) {

            strcpy(path, basepath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            if(findcommand('d') == 0 || dp->d_type != DT_REG)
                tree(dp->d_name ,path, root + 1);
        }
    }

    closedir(dir);
}

void printthetree(char *name, int root) {
    int i;
    if(!findcommand('i')) {
        for(i = 0; i < root - 1; i++) {
            printf("   ");
        }
        if(root)
            printf("|__");

    }
    printf("%s\n", name);

}
void printthepath(char *name, int root) {
    int i;
    if(!findcommand('i')) {
        for(i = 0; i < root - 1; i++) {
            printf("   ");
        }
        if(root)
            printf("|__");
    }
    printf("%s\n", name);
}
