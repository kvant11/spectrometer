#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H
#include <QWidget>

#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <string.h>
#include "sm32_2.h"   //Probably card specific lib
#include <time.h>

/* #define DEBUG */
/* default values and global variables */
#define DEFAULT_VOLT 3.1        //vel for PWM
#define DEFAULT_SPEED 1000      //Speed of stepper
#define DEFAULT_MOVEMODE 0  /* 0: pos, 1: vel */

#define DEVICE  "/dev/ioboards/stepper3"    //Not really nice... Can change
#define FIFO_FILE "/home/kikor/programs/spectro/fifo_spectro"   //IO
#define MAXINLEN 200

/* some timeouts (all in ms) and limits*/
#define timeout_motor_ready 2000
#define waitmode 0   /* o: don't wait after write command */
#define timeout_motor_travel 15000
#define MAXVOLT 12.0
#define MAXSPEED 1000
#define NUMCOMMANDS 14

class stepper_motor : public QWidget
{
    Q_OBJECT
public:
    explicit stepper_motor(QWidget *parent = 0);
    int emsg(int a);
    int is_motor_ready(int num);
    int get_mot_status(int num);
    int is_motor_there(int motnum);
    int get_mot_pos(int num);
    int parse_command(char * cmd);





private:
    int handle;
    float volts[3];        //3 Values... Number of motors...
    int speed[3];
    int movemode[3];
    FILE *fp;
    char * errormessage[];
    int MOT[3];

    // some basic motor commands
    struct timespec twenty_millisec = {0,20000000};
    struct timespec time_left;
    char cmd[MAXINLEN+1];
    char * commands[];



signals:

public slots:
};

#endif // STEPPER_MOTOR_H
///

