#include <stdio.h>
#include <jpeglib.h>


/**
*@brief - Save uint8_t pointer to a jpeg file
*@param[in] data - Source data
**/
void save_jpeg (char *save_path, uint8_t *data, int width, int height);
