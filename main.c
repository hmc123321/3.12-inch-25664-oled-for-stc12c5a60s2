#include <reg52.h>
#include <intrins.h>
#include <string.h>
#include <25664.h>
#include <ASCII_CODE_8X16_5X8_VERTICAL.h>
typedef struct {
	uchar rawData;
	uchar byte1;
	uchar byte2;
	uchar byte3;
	uchar byte4;
} pixel_8;


pixel_8 dataprocess (uchar dat);
void displayOneChar(uchar ch,uchar x,uchar y);//x y是字数间隔
void display8x16(uchar *str,uchar x,uchar y);

void main(){
		  RES=0;
		  Delay(5);
		  RES=1;
		  Initial();
		  Screen_clear();

			display8x16("Hello world",5,0);
			display8x16("Hello world",5,1);
			while(1);			
}

void displayOneChar(uchar ch,uchar x,uchar y){
			char i=0;
			pixel_8 dat;
	
			Ins_trans(0x75);//行坐标
			Data_trans(32*y);
			Data_trans(32*y+31);//16*2,行坐标不变
			Ins_trans(0x15);//列坐标
			Data_trans(0x1c+2*x);
			Data_trans(0x1c+2*x+1);//1为4pix,2byte一显示
			Ins_trans(0x5c);
			for (i=15;i>=0;i--){
				dat=dataprocess(ascii_table_8x16[ch-0x20][i]);
				Data_trans(dat.byte1);
				Data_trans(dat.byte2);
				Data_trans(dat.byte3);
				Data_trans(dat.byte4);
				Data_trans(dat.byte1);
				Data_trans(dat.byte2);
				Data_trans(dat.byte3);
				Data_trans(dat.byte4);
			}
}

void display8x16(uchar *str,uchar x,uchar y){
	uchar j,i=strlen(str);
	for (j=0;j<i;j++){
		displayOneChar(str[j],x+j,y);
	}
}
pixel_8 dataprocess (uchar dat){
	pixel_8 temp;
	uchar i;
	temp.rawData=dat;
	for (i=1;i<9;i++){
		switch (i){
			case (1):
				if(temp.rawData&0x80)
					temp.byte2|=0x0F;
				else temp.byte2&=0xF0;
				break;
				
			case (2):
				if(temp.rawData&0x80)
					temp.byte2|=0xF0;
				else temp.byte2&=0x0F;
				break;
				
				
			case (3):
				if(temp.rawData&0x80)
					temp.byte1|=0x0F;
				else temp.byte1&=0xF0;
				break;
				
			case (4):
				if(temp.rawData&0x80)
					temp.byte1|=0xF0;
				else temp.byte1&=0x0F;
				break;
				
				
			case (5):
				if(temp.rawData&0x80)
					temp.byte4|=0x0F;
				else temp.byte4&=0xF0;
				break;
				
			case (6):
				if(temp.rawData&0x80)
					temp.byte4|=0xF0;
				else temp.byte4&=0x0F;
				break;
				
				
			case (7):
				if(temp.rawData&0x80)
					temp.byte3|=0x0F;
				else temp.byte3&=0xF0;
				break;
				
			case (8):
				if(temp.rawData&0x80)
					temp.byte3|=0xF0;
				else temp.byte3&=0x0F;
				break;
		}
		temp.rawData<<=1;
	}
	
	return temp;
	}