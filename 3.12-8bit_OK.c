//Modle :3.12
//Driver IC:SSD1322
//Interfaces:6800-8bit
#include<reg51.h>
#include<intrins.h>
#include<25664.h>
//stc12c5a60s2的机器周期是89c52的8~12倍，所以加了不少_nop_()，若是52可以只留下“DATAPORT=tData”后的一个。
void Delay(unsigned int time)//这个延时只用于上电重启屏幕，时间任意。
        {
		  unsigned int i,j;
		  for(i=0;i<time;i++)
		     for(j=0;j<1000;j++)
			       {;}
		}
void Ins_trans(unsigned char  tData)
{
  _RS=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  R_W=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  E=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
   _CS=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  DATAPORT=tData;   
  _nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
   E=1; 
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  _CS=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}

void Data_trans(unsigned char  tCom)
{ 
  _RS=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  R_W=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
   E=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  _CS=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  DATAPORT=tCom; 
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  E=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  _CS=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}

void Screen_fill()
       {
	     unsigned char row,column;	
         Ins_trans(0x15);
         Data_trans(0x1c);
         Data_trans(0x5b);
         Ins_trans(0x75);
         Data_trans(0x00);
         Data_trans(0x7f);
				 Ins_trans(0x5c);
 		  for(row=0;row<64;row++)             //page loop
		     { 	  
			   for(column=0;column<128;column++)	//column loop
			      {
				     Data_trans(0xFF);
				     Data_trans(0xFF);
				    }
			   }
	     }

void Screen_clear()
       {
	     unsigned char row,column;	
         Ins_trans(0x15);
         Data_trans(0x1c);
         Data_trans(0x5b);
         Ins_trans(0x75);
         Data_trans(0x00);
         Data_trans(0x7F);
		 Ins_trans(0x5c);
 		  for(row=0;row<64;row++)             //page loop120
		     { 	  
			   for(column=0;column<128;column++)	//column loop
			      {
				     Data_trans(0x00);
				     Data_trans(0x00);
				    }
			   }
	     }
	     
void Initial()
{
Ins_trans(0xfd);
Data_trans(0x12);

Ins_trans(0xae);

Ins_trans(0xb3);
Data_trans(0x91);

Ins_trans(0xca);
Data_trans(0x3f);

Ins_trans(0xA2);//set offset
Data_trans(0x00);

Ins_trans(0xa1);//Set display RAM display start line register from 0-127 Display start line register is reset to 00h after RESET
Data_trans(0x00);

Ins_trans(0xca);
Data_trans(0x3f);
       
Ins_trans(0xa0);
Data_trans(0x14);//0001 0100 Scan from COM[N-1] to COM0, where N is the  Multiplex ratio. Enable Nibble Re-map
Data_trans(0x11);//0001 0001  Enable Dual COM mode (MUX ≤ 63)

Ins_trans(0xca);
Data_trans(0x3f);

Ins_trans(0xb5);
Data_trans(0x00);

Ins_trans(0xab);
Data_trans(0x01);

Ins_trans(0xb4);
Data_trans(0xa0);
Data_trans(0xfd);

Ins_trans(0xc1);
Data_trans(0x9f);

Ins_trans(0xc7);
Data_trans(0x0f);

Ins_trans(0xb1);
Data_trans(0xe2);

Ins_trans(0xd1);
Data_trans(0x82);
Data_trans(0x20);

Ins_trans(0xbb);
Data_trans(0x1f);

Ins_trans(0xb6);
Data_trans(0x08);


Ins_trans(0xbe);
Data_trans(0x07);

Ins_trans(0xa6);

Ins_trans(0xaF);
       	
}




