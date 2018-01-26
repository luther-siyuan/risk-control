
#ifndef _FTDDATASTRUCT_DEFINE_H
#define _FTDDATASTRUCT_DEFINE_H

#include "FTDDataType.h"

#pragma pack(1)     // 调整结构体的边界对齐，让其以一个字节对齐；<使结构体按1字节方式对齐>

/*

一个FTD包是如下结构:
|--------------|--------------|------------------|
|---head-------|------ex_buf--|-------ftdc-------|
|----4---------|   0~127      |   0~4096         |
|--------------|-----head+buf-|-----head+field...|

*/

/*  FTD报头
 *  
 *  |----1----|----1----|---------2---------|
 *  | 报文类型 | 扩充长度 |   信息正文长度     |
 * 
 *  报文类型：
 *      FTDTypeNone	        0x00	此报文不具有任何意义，一般用于心跳
 *      FTDTypeFTDC	        0x01	信息正文中是正常的域数据内容
 *      FTDTypeCompressed	0x02	报文经过编码处理
 */
typedef struct  
{
	CtpFTDTypeType				FtdType;							//类型(FTDType)
	char						FtdExLen;							//补充长度(0~127)
	short						FtdcLen;							//内容长度(0~4096)
}tagCtpFTDHead;


// FTD扩展报头
// 标记类型+标记长度+数据+…，如果没有数据，则补充长度为0
typedef struct  
{
	CtpFTDExTagType				FtdExTag;							//FTDExTag定义
	char						Len;								//长度
}tagCtpFTDExHead;


//FTDC报头
//网上的大多数资料较老，sizeof = 16
/*
typedef struct
{
	unsigned char				Version;							//版本号
	CtpTransactionIDType		Tid;								//信息正文类型(见附录A)
	CtpFTDChainType				Chain;								//报文链(见报文链定义)
	unsigned short				SequenceSeries;						//序列类别号 (对话模式、私有模式、广播模式)
	unsigned int				SequenceNumber;						//序列号
	unsigned short				FieldCount;							//数据域的个数
	unsigned short				Len;								//FTDC正文的长度
}tagCtpFTDCHead;
*/

//新的报头为22个字节，short：2字节，int：4字节
typedef struct  
{
	unsigned char				Version;
	unsigned char				Type;
	unsigned char				EnEncLen;
	CtpFTDChainType				Chain;
	unsigned short				SequenceSeries;						//序列类别号 (对话模式、私有模式、广播模式)
	unsigned int				SequenceNumber;						//序列号
	unsigned int				unknown;
	unsigned short				FieldCount;							//数据域的个数
	unsigned short				Len;								//FTDC正文的长度
	unsigned int				requestid;
}tagCtpFTDCHead;

//Field报头
typedef struct  
{
	unsigned short				Tid;			
	unsigned short				Len;								//Field Length	网络序短整数
}tagCtpFTDCFieldHead;



#pragma pack()      // 取消自定义字节对齐方式

#endif