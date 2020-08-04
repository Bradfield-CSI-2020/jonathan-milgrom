/*
    Implementation of stripped down version of shell script "ls". This program by default
        - lists all the files (and directories) in the directory specified (or current directory)
        - prints file if file is specified instead of directory
    
    optional flags
        -l: print groupid, userid, file size, name
        -a: print files that begin with "."
*/
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
/* for user/group name retrieval (-l option) */
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

#define PROGRAM_NAME "ls"
#define PATH_MAX 100
#define PRINT_USAGE(void) printf("usage: %s [-la] [file ...]\n", PROGRAM_NAME)

struct options {
    int verbose;    /* corresponds to -l flag */
    int dotfiles;   /* corresponds to -a flag */
};

void dirprinter(DIR *dfp, char *path, struct options *op);
int parseoption(char *option, struct options *op);

int main(int argc, char *argv[])
{
    struct stat stbuff;                 /* description of a file */
    DIR *dfp;                           /* directory-file pointer to a typedef for directory description */

    struct options options = {0, 0};    /* support option flags -l, -a; defaults to off */
    char *name = ".";                   /* use current directory when none is provided */

    argc--, argv++; /* ./a.out registers as an argument, which we want to ignore. */

    if (!argc-- || strcmp(PROGRAM_NAME, *argv++)) {
        PRINT_USAGE();
        return 0;
    }

    for (; argc > 0 && **argv == '-'; argc--, argv++) {
        if (parseoption(++*argv, &options) == 0) {
            printf("%s: illegal option -- %s\n", PROGRAM_NAME, *argv);
            PRINT_USAGE();
            return 0;
        }
    }
    
    /* use directory name if provied */
    if (argc--)
        name = *argv++;

    /* if file/directory meta data cannot be retrieved, presume does not exist. */
    if  (stat(name, &stbuff) == -1) {
        printf("%s: %s: No such file or directory\n", PROGRAM_NAME, name);
        return 0;
    }

    /* if file was passed instead of directory, echo file name */
    if (S_ISREG(stbuff.st_mode)) {
        printf("%s\n", name);
        return 0;
    }

    if ((dfp = opendir(name)) == NULL) {
        printf("%s: %s: Unable to open directory\n", PROGRAM_NAME, name);
        return 0;
    }

    dirprinter(dfp, name, &options);

    return 0;
}

int parseoption(char *option, struct options *op)
{
    char c;

    while((c = *option++) != '\0') {
        switch (c) {
        case 'l':
            op->verbose = 1;
            break;
        case 'a':
            op->dotfiles = 1;
            break;
        default:
            return 0;
        }
    }

    return 1;
}

/*

    ###### PRINTERS #######

*/

char *filepath(char *path, char *name, char *fpath, int lim);
void fileprinter(char *name, struct stat *s, struct options *op);
void printfile(char *name, struct stat *s);

void dirprinter(DIR *dfp, char *path, struct options *op)
{
    char fpath[PATH_MAX];   /* buffer for building relative file path */
    struct dirent *sdp;     /* file entry from reading a DIR */
    struct stat stbuff;     /* description of a file */

    while ((sdp = readdir(dfp)) != NULL) {
        /* write relative file path into fpath */
        if (filepath(path, sdp->d_name, fpath, PATH_MAX) == NULL) {
            printf("%s: %s: Path name longer than max path %d\n", PROGRAM_NAME, fpath, PATH_MAX);
            continue;
        };

        /* write file info into stbuff */
        if (stat(fpath, &stbuff) == -1)
            continue;

        fileprinter(sdp->d_name, &stbuff, op);
    }

    if (!op->verbose)
        putchar('\n');
}

void fileprinter(char *name, struct stat *s, struct options *op)
{
    if (name[0] == '.' && !op->dotfiles)
        return;   

    printfile(name, op->verbose ? s : NULL);
}

void printfile(char *name, struct stat *s)
{
    struct passwd *pwd;
    struct group *grp;

    if (s) {
        pwd = getpwuid(s->st_uid);
        grp = getgrgid(s->st_gid);
        printf("%10s %10s %10lld %s\n",  pwd->pw_name, grp->gr_name, s->st_size, name);
    } else {
        printf("%s\t", name);
    }
}

/*

    ###### GENERIC HELPERS #######

*/

char *safestrcpy(char *s1, char *s2, int lim)
{
    int i;

    for (i = 0; i <= lim && (s1[i] = s2[i]) != '\0'; i++)
        ;

    if (s1[i] != '\0')
        return NULL;

    return s1;
}

char *safestrcat(char *s1, char *s2, int lim)
{
    int i;

    for (i = 0; i <= lim && s1[i] != '\0'; i++)
        ;
    
    for (; i <= lim && (s1[i] = *s2++) != '\0'; i++)
        ;

    if (s1[i] != '\0')
        return NULL;

    return s1;
}

char *filepath(char *path, char *name, char *fpath, int lim)
{
    if (safestrcpy(fpath, path, lim) == NULL)
        return NULL;

    if (safestrcat(fpath, "/", lim) == NULL)
        return NULL;

    if (safestrcat(fpath, name, lim) == NULL)  
        return NULL;

    return fpath;
}   