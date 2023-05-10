#ifndef __SOFT_I2C_H
#define __SOFT_I2C_H 			   

//IO
#define SDA_IN()  GPIO	//IN
#define SDA_OUT() GPIO //OUT
 

#define I2C_SCL    PBout(8) //SCL
#define I2C_SDA    PBout(9) //SDA	 
#define READ_SDA   PBin(9)  //SDA IN

//IIC
void I2C_Init(void);                			 
void I2C_Start(void);				
void I2C_Stop(void);	  			
void I2C_Send_Byte(u8 txd);		
uint8_t I2C_Read_Byte(unsigned char ack);
uint8_t I2C_Wait_Ack(void); 				
void I2C_Ack(void);					
void I2C_NAck(void);

#endif

