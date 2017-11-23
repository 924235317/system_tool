#include <stdio.h>
#include <unistd.h>//access
#include <sys/stat.h>//mkdir

#include "path.h"

int make_directory (char *path) {
	int ret;
    ret = access(path, F_OK);
	if (ret != 0) {
		fprintf(stdout, "[INFO]: \"%s\" does not exist\n", path);
		fprintf(stdout, "[INFO]: Create folder %s\n", path);

		ret = mkdir(path, S_IRUSR | S_IWUSR | S_IXUSR);
		if (ret != 0) {
			fprintf(stderr, "[ERRO]: Create folder %s FAILED!\n", path);
			return -1;
		}
	}
    return 0;
}

void get_filename (char *file_name, char *src_path, bool flag) {
    char *src_name = strrchr(src_path, '/') + 1;
	if (flag) { //need extension
		strcpy(file_name, src_name);
	}
	else {
		size_t len = strrchr(src_path, '.') - src_name; 
        strncpy(file_name, src_name, len);
	}
}
