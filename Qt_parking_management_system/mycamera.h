#ifndef MYCAMERA_H
#define MYCAMERA_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>        //跟perror有关的头文件
#include <sys/mman.h>     //跟内存映射有关的头文件
#include <linux/input.h>  //跟输入子系统模型有关的头文件
#include <linux/videodev2.h> //跟V4L2架构有关的头文件
#include <QLabel>
#include <QLCDNumber>
#include <QThread>
#define W 160  //本来我想把宽设置成800，但是摄像头默认最大的宽是640
#define H 120

//结构体，把每个缓冲块的信息组合在一个
struct bufmsg
{
    void *start;  //存放每个缓冲区的首地址
    int somelen;  //存放每个缓冲区的大小
};
class mycamera:public QThread
{
public:
    mycamera();
    //初始化摄像头
    int camera_init();
    //摄像头捕捉画面
    int camera_capture();
    //摄像头关闭
    int camera_uninit();
    //重写父类的run方法
    void run();

    //自定义一个成员函数，用来接收主界面传递过来的标签地址
    void getLabel(QLabel *p,QLCDNumber *lc);

private:
    int camerafd;
    int lcdfd;
    int *lcdmem;
    //定义结构体数组，存放4个缓冲区的信息
    struct bufmsg array[4];
    QLCDNumber *mylcd;
    QLabel *myla;
};

#endif // MYCAMERA_H
