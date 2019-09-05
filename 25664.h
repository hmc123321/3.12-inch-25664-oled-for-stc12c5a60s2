#ifndef __25664_H__
#define __25664_H__

#define DATAPORT P0
#define uchar unsigned char
#define uint unsigned int


sbit _CS=P1^4; //片选      16
sbit RES=P1^3; //复位       15
sbit _RS=P1^2; //数据/命令 14  D/C#
sbit R_W=P1^1; //读/写     13  R/W#
sbit   E=P1^0;   //使能    12  RD#

void send_2bit(unsigned char two_bit_data);
void Delay(unsigned int time);
void Ins_trans(unsigned char  tData);
void Data_trans(unsigned char  tCom);
void Screen_clear();
void Screen_fill();
void Initial();
void Test_display();
void Picture_display();
void Picture_display1();
void send_2bit(unsigned char two_bit_data);

#endif