#include "mycamera.h"

#include <QTime>

//封装函数把YUV转成RGB
int yuvtorgb(int y,int u,int v)
{
    int r,g,b;
    int pix;
    r=y+1.4075*(v-128);
    g=y-0.3455*(u-128)-0.7169*(v-128);
    b=y+1.779*(u-128);
    //修正计算结果
    if(r>255)
        r=255;
    if(g>255)
        g=255;
    if(b>255)
        b=255;
    if(r<0)
        r=0;
    if(g<0)
        g=0;
    if(b<0)
        b=0;
    //因为lcd要求是ARGB，所以我们顺便在这里把RGB转成ARGB，方便后续使用
    pix=0x00<<24|r<<16|g<<8|b;
    return pix;
}

//封装函数把一张完整画面的YUYV数据全部转换成ARGB数据
int allyuvtoargb(char *yuvdata,int *argb)
{
    /*
        yuvdata[0] -->Y
        yuvdata[1] -->U
        yuvdata[2] -->Y
        yuvdata[3] -->V
    */
    int i,j;
    //循环究竟循环多少次，取决于你的画面有多少个像素点
    //有W*H个像素点
    for(i=0,j=0; i<W*H; i+=2,j+=4) // W*H/2  次数
    {
        argb[i]=yuvtorgb(yuvdata[j],yuvdata[j+1],yuvdata[j+3]);
        argb[i+1]=yuvtorgb(yuvdata[j+2],yuvdata[j+1],yuvdata[j+3]);
    }
    return 0;
}
mycamera::mycamera()
{

}

int mycamera::camera_init()
{
    int ret;
    int i;

    //打开液晶屏的驱动
    lcdfd=open("/dev/fb0",O_RDWR);
    if(lcdfd==-1)
    {
        perror("打开液晶屏的驱动失败!\n");
        return -1;
    }

    //映射得到液晶屏的首地址
    lcdmem=(int *)mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,lcdfd,0);
    if(lcdmem==NULL)
    {
        perror("映射lcd失败了!\n");
        return -1;
    }

    //摄像头的驱动是谁？--》打开摄像头的驱动
    camerafd=open("/dev/video7",O_RDWR);
    if(camerafd==-1)
    {
        perror("打开摄像头的驱动失败!\n");
        return -1;
    }

    //提前设置好摄像头的采集格式--》画面宽，画面高，画面是什么格式。。。。
    struct v4l2_format myfmt;
    bzero(&myfmt,sizeof(myfmt));
    myfmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    myfmt.fmt.pix.width=W;
    myfmt.fmt.pix.height=H;
    myfmt.fmt.pix.pixelformat=V4L2_PIX_FMT_YUYV; //yuv格式
    ret=ioctl(camerafd,VIDIOC_S_FMT,&myfmt);
    if(ret==-1)
    {
        perror("设置采集格式失败了!\n");
        return -1;
    }

    //跟摄像头的驱动申请缓冲区
    struct v4l2_requestbuffers mybuf;
    bzero(&mybuf,sizeof(mybuf));
    mybuf.count=4;
    mybuf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    mybuf.memory=V4L2_MEMORY_MMAP;
    ret=ioctl(camerafd,VIDIOC_REQBUFS,&mybuf);
    if(ret==-1)
    {
        perror("申请缓冲区失败!\n");
        return -1;
    }

    //分配刚才你申请的4个缓冲区
    struct v4l2_buffer otherbuf;
    for(i=0; i<4; i++)
    {
        bzero(&otherbuf,sizeof(otherbuf));
        otherbuf.index=i;
        otherbuf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
        otherbuf.memory=V4L2_MEMORY_MMAP;
        ret=ioctl(camerafd,VIDIOC_QUERYBUF,&otherbuf);
        if(ret==-1)
        {
            perror("分配缓冲区失败!\n");
            return -1;
        }

        //顺便映射得到4个缓冲块的首地址(方便后面取出画面数据)
        array[i].somelen=otherbuf.length;
        array[i].start=mmap(NULL,otherbuf.length,PROT_READ|PROT_WRITE,MAP_SHARED,camerafd,otherbuf.m.offset);
        if(array[i].start==NULL)
        {
            perror("映射缓冲区首地址失败!\n");
            return -1;
        }

        //立马申请入队--》下一步摄像头立马就要启动采集了
        ret=ioctl(camerafd,VIDIOC_QBUF,&otherbuf);
        if(ret==-1)
        {
            perror("入队失败!\n");
            return -1;
        }
    }

    //启动摄像头采集
    enum v4l2_buf_type mytype;
    mytype=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret=ioctl(camerafd,VIDIOC_STREAMON,&mytype);
    if(ret==-1)
    {
        perror("启动摄像头失败!\n");
        return -1;
    }
    return 0;
}

int mycamera::camera_capture()
{
    int i,j;
    int ret;
    int argbbuf[W*H];
    struct v4l2_buffer otherbuf;
    fd_set myset;
    //循环出队，入队显示视频流
    FD_ZERO(&myset);
    FD_SET(camerafd,&myset); //监测摄像头
    //用多路复用监测摄像头是否有数据可读，有数据可读我才来出队
    ret=select(camerafd+1,&myset,NULL,NULL,NULL);
    if(ret>0)
    {
        for(i=0; i<4; i++)
        {
            bzero(&otherbuf,sizeof(otherbuf));
            otherbuf.index=i;
            otherbuf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
            otherbuf.memory=V4L2_MEMORY_MMAP;
            //出队
            ret=ioctl(camerafd,VIDIOC_DQBUF,&otherbuf);
            if(ret==-1)
            {
                perror("出队失败!\n");
                return -1;
            }
            //把出队的画面数据在开发板的液晶屏上显示出来
            //array[i].start里面保存的就是一张张画面数据
            //画面数据是YUV格式,液晶屏要求ARGB格式
            //把YUV格式转换成ARGB格式
            allyuvtoargb((char *)(array[i].start),argbbuf);
            //把ARGB数据填充到开发板的液晶屏中
            /*
                argbbuf[0]---argbbuf[W-1]   画面的第一行数据
                lcdmem+80
                argbbuf[W]---argbbuf[2*W-1] 画面的第二行数据
                lcdmem+800+80
            */
            for(j=0; j<H; j++)
                memcpy(lcdmem+620+800*(j+30),&argbbuf[j*W],W*4);

            //入队
            ret=ioctl(camerafd,VIDIOC_QBUF,&otherbuf);
            if(ret==-1)
            {
                perror("入队失败!\n");
                return -1;
            }
        }
    }
    return 0;
}

int mycamera::camera_uninit()
{
    int i;
    int ret;
    enum v4l2_buf_type mytype;
    mytype=V4L2_BUF_TYPE_VIDEO_CAPTURE;

    ret=ioctl(camerafd,VIDIOC_STREAMOFF,&mytype);
    if(ret==-1)
    {
        perror("关闭摄像头失败!\n");
        return -1;
    }
    close(camerafd);
    close(lcdfd);
    munmap(lcdmem,800*480*4);
    for(i=0; i<4; i++)
        munmap(array[i].start,array[i].somelen);
    return 0;
}

void mycamera::run()
{
    while(1)
    {
        camera_capture();

    }
}

void mycamera::getLabel(QLabel *p, QLCDNumber *lc)
{
    myla = p;
    mylcd = lc;
}
