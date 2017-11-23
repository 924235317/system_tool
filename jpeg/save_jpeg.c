#include "save_jpeg.h"


void save_jpeg (char *save_path, uint8_t *data, int width, int height) {

    /* 分配和一个jpeg压缩对象 */
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    JSAMPROW row_pointer[1];
    int row_stride;
    FILE *fp;

    /* 指定压缩数据保存的位置 */
    fp = fopen(save_path, "wb");
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);/* 初始化 */
    jpeg_stdio_dest(&cinfo, fp);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    /* 设置压缩参数 */
    jpeg_set_defaults(&cinfo);

    /* 设置质量参数 */
    jpeg_set_quality(&cinfo, 100, TRUE);

    /* 开始压缩循环，逐行进行压缩：使用jpeg_start_compress开始一个压缩循环 */
    jpeg_start_compress(&cinfo, TRUE);

    row_stride = width * 3;/* 一行数据所占字节数:如果图片为RGB，这个值要*3.灰度图像不用 */
    while (cinfo.next_scanline < height) {
        row_pointer[0] = &data[cinfo.next_scanline * row_stride];//需要压缩成jpeg图片的位  图数据缓冲区
        (void)jpeg_write_scanlines(&cinfo, row_pointer, 1);//参数：1表示写入一行
    }

    jpeg_finish_compress(&cinfo);//结束压缩循环
    fclose(fp);
    jpeg_destroy_compress(&cinfo);//释放jpeg压缩对象

    return;
}
