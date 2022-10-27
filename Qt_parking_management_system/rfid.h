#ifndef RFID_H
#define RFID_H

#include <QThread>
#include <QString>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/select.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#define DEV_PATH   "/dev/ttySAC2"



class rfid
{
public:
    rfid();

    unsigned int read_card();
    int open_serial();
    void init_tty(int fd);
    unsigned char CalBCC(unsigned char *buf, int n);
    int PiccRequest(int fd);
    int PiccAnticoll(int fd);
private:
    volatile unsigned int cardid ;
    // unsigned int buf[6] ;
    struct timeval timeout;
};

#endif // RFID_H
