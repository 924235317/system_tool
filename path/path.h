#include <stdio.h>
#include <stdbool.h>

/**
*@brief - Make directory if path not exist
*@retval - 0 if success, -1 if error happened
**/
int make_directory (char *path);

/**
*@brief - Get file name from path string
*@param[out] file_name
*@param[in] src_path
*@param[in] flag - Wether need extension
**/
void get_filename (char *file_name, char *src_path, bool flag);
