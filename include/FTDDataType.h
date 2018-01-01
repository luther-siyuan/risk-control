
#ifndef _FTDDATATYPE_DEFINE_H
#define _FTDDATATYPE_DEFINE_H

//..........................................................................................................................................................................................................................................................................................................
///FTDType是FTD包类型

#define			FTDTypeNone					0x00			//此报文不具有任何意义，一般用于心跳
#define			FTDTypeFTDC					0x01			//信息正文中是正常的域数据内容
#define			FTDTypeCompressed			0x02			//信息正文中包括的是压缩数据

typedef		char		CtpFTDTypeType;

//..........................................................................................................................................................................................................................................................................................................
///FTDTag是FTD扩展标记

#define			FTDTagNone					0x00			//丢弃不处理此标记	
#define			FTDTagDatetime				0x01			//时间戳 Unix格式时间 网络序
#define			FTDTagCompressMethod		0x02			//信息正文压缩方法 0表示没有压缩   1表示LZ压缩
#define			FTDTagSessionState			0x03			//发送端状态 0：未知状态；1：未登录；2：已登录，但在同步数据；3：同步状态
#define			FTDTagKeepAlive				0x04			//发送端发送心跳信息，表示还在正常工作
#define			FTDTagTradedate				0x05			//交易所当前交易日日期。Unix格式时间，网络序
#define			FTDTagTarget				0x06			//说明报文的目标，使用两个字母，表示目标的交易所。如果要发送的目标就是接收方所处于的交易所，那么就不需要使用此项

typedef		char		CtpFTDExTagType;

//..........................................................................................................................................................................................................................................................................................................
///FTDChain是报文链定义
#define			CHAIN_S					'S'
#define			CHAIN_F					'F'
#define			CHAIN_M					'C'
#define			CHAIN_L					'L'

typedef		char		CtpFTDChainType;

//..........................................................................................................................................................................................................................................................................................................
///Transaction ID(TID)是交易事务的ID
#define			TID_Error								0x0001
#define			TID_ForceExit							0x1005
#define			TID_InstrumentChangeNotify				0x2007
#define			TID_InstrumentStatusChangeNotify		0x2006
#define			TID_MarketBulletin						0x2003
#define			TID_MarketMatchData						0x2004
#define			TID_MarketMatchIncData					0x2002
#define			TID_MarketOrderIncData					0x2001
#define			TID_MarketStatusChangeNotify			0x2005
#define			TID_OrderAction							0x0004
#define			TID_OrderConfirmation					0x1003
#define			TID_OrderInsert							0x0003
#define			TID_ParticipantBulletin					0x1002
#define			TID_QryClient							0x000C
#define			TID_QryDeposit							0x0008
#define			TID_QryInstrument						0x0005
#define			TID_QryInstrumentStatus					0x000E
#define			TID_QryMarket							0x000B
#define			TID_QryMarketMatchData					0x0002
#define			TID_QryMarketOrderData					0x0012
#define			TID_QryMarketStatus						0x000D
#define			TID_QryOrder							0x0006
#define			TID_QryParticipant						0x0013
#define			TID_QryPosition							0x000A
#define			TID_QryPPosition						0x0009
#define			TID_QryTrade							0x0007
#define			TID_QryUser								0x0014
#define			TID_QryUserLogin						0x0015
#define			TID_TradeInsertSingle					0x1001
#define			TID_UserLogin							0x0016
#define			TID_UserLogout							0x0017
#define			TID_UserPasswordUpdate					0x0018

typedef unsigned int	CtpTransactionIDType;

//..........................................................................................................................................................................................................................................................................................................



//..........................................................................................................................................................................................................................................................................................................




//..........................................................................................................................................................................................................................................................................................................





#endif