#include <stdio.h>
#include <curl/curl.h>
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>


static int hello_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
                         off_t offset, struct fuse_file_info *fi)
{
    (void)offset;
    (void)fi;

    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        printf("Falhou!");
        return 1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    return 0;
}

static struct fuse_operations_compat2 hello_oper = {
    .readdir = hello_readdir
    };

int main(int argc, char *argv[])
{
    return fuse_main(argc, argv, &hello_oper);
}
