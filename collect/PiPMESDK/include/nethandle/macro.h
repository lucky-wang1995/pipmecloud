#ifndef _MACRO_H_
#define _MACRO_H_

#pragma once

#define IPV6_BROADCAST_ADDR		_T("FF12::fb88:1")
#define LINK_LOCAL_ADDR			_T("FE80")
#define IPV4_BROADCAST_ADDR		_T("255.255.255.255")
#define BROADCAST_PORT			_T("53550")
#define PRO3LC				_T("PRO3-LC")
#define LILO2				_T("LILO2")
#define ZOLO6				_T("ZOLO6")
#define PC4SC4				_T("PC4SC4")
#define PRO1				_T("PRO1")
#define PRO2				_T("PRO2")
#define ZOLO4				_T("ZOLO4")
#define ZOLO5				_T("ZOLO5")
#define PROX				_T("PROX")
#define Grappa2				_T("Grappa2")
#define PANTUM_PRT			_T("PANTUM")

#define GETSTATUSTIMEOUT			120  // 120s
#define SCANNING_TIMEOUT_NETWORK	60	// 60s
#define SCANNING_TIMEOUT_USB		35	// 35s
#define SCANNING_TIMEOUT			30	// 30s

#define CANCEL_TIMEOUT_USB			3	// Cancel job timeous is set 5s, USB
#define CANCEL_TIMEOUT_NETWORK		3	// Cancel job timeous is set 5s, Network

#define UDP_RETRY_TIMES				2
#define UDP_TIMEOUT					3000	// 100ms
#define UDP_RETRY_TIMEOUT			20	// 20s	// for scanning retry timeout

#define MFPCFG_INI				_T("MFPCFG.INI")

#define MAX_PORT_NAME_LEN		1024
#define MAX_FILES_SUM			65535

#define UDP_BROADCAST_PORT		_T("53550")
#define TCP_PORT				_T("53550")

#define JPEG_HEADER_LEN			8
#define JPEG_HEADER_FLAG		"TWAINJPG"
#define RAW_HEADER_LEN			7
#define RAW_HEADER_FLAG			"RAWDATA"


#define PREVIEW_RESOLUTION		38		// Preview resolution

#define MODLENAMELEN			64

#define IPV6_BROADCAST_ADDR		_T("FF12::fb88:1")
#define IPV4_BROADCAST_ADDR		_T("255.255.255.255")
#define BROADCAST_PORT			_T("53550")

#define BITMAPPAGE1				_T("_BitmapPage1.bmp")
#define BITMAPPAGE2				_T("_BitmapPage2.bmp")
#define JPEGPAGE1				_T("_JpegPage1.jpg")
#define JPEGPAGE2				_T("_JpegPage2.jpg")
#define FWPAGE1					_T("_FWPage1.raw")
#define FWPAGE2					_T("_FWPage2.raw")

#define FWDEBUGPAGE1			_T("_FWDebugPage1.raw")
#define FWDEBUGPAGE2			_T("_FWDebugPage2.raw")

#define MAXLOOP_UI				100


//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Bit0: Flatbed; Bit1: Support ADF; Bit2: Support ARDF; Bit3: Support DADF; Bit7: The filed is available;
#define SupportFB				0x01
#define SupportADF				0x02
#define SupportARDF				0x04
#define SupportDADF				0x08
#define SupportFlag				0x80

#define DE_FBCoverOpen			0x0001	// Device error; 0x0001: FB cover open;
#define DE_ADFCoverOpen			0x0002	// Device error; 0x0002: ADF cover open;
#define DE_ADFJam				0x0004	// Device error; 0x0004: ADF jam;

#define MAX_SCAN_PATH			512

//////////////////////////////////////////////////////////////////////////

enum UpdatePasswordStatus
{
	UPDATE_PASSWORD_STATUS_NONE = -1,
	UPDATE_PASSWORD_STATUS_OK	= 0,
	UPDATE_PASSWORD_STATUS_NG = 1,
};

// Support project

enum Projects
{
	PROJECT_INVALID = -1,
	PROJECT_ALL	= 0,
	PROJECT_PC4SC4,
	PROJECT_PRO1,
	PROJECT_PRO2,
	PROJECT_ZOLO4,
	PROJECT_ZOLO5,
	PROJECT_PRO3LC,
	PROJECT_LILO2,
	PROJECT_ZOLO6,
	PROJECT_PROX,
	PROJECT_GRAPPA2,
	PROJECT_PANTUM,
};

enum Protocol_Transfer
{
	PROTOCOL_V1		= 1,	// v1 protocol; PRO3LC, LILO2
	PROTOCOL_V2		= 2,	// v2 protocol; ZOLO6
};

enum PaperSource
{
	PAPER_SOURCE_FB  = 0,
	PAPER_SOURCE_ADF = 1,
	PAPER_SOURCE_ARDF = 3,
	PAPER_SOURCE_DADF = 4,
};

enum ScanMode
{
	SCAN_MODE_COLOR = 0,
	SCAN_MODE_GRAY  = 1,
	SCAN_MODE_BW    = 2,
};

enum UnitMode
{
	Unit_Inch =  (int) 0x0000,
	Unit_CM =    (int) 0x0001,
	Unit_Pixel = (int) 0x0002,
};

enum DuplexMode
{
	PORTRAIT_T2T = (int) 0x0000,
	PORTRAIT_T2B = (int) 0x0001,
	LANDSCAPE_T2T = (int) 0x0002,
	LANDSCAPE_T2B = (int) 0x0003,
};

enum ImageType
{
	IMAGE_TYPE_BMP		= 0,
	IMAGE_TYPE_JPEG		= 1,
	IMAGE_TYPE_PNG		= 2,
	IMAGE_TYPE_TIFF		= 3,
	IMAGE_TYPE_PDF		= 4,
};

enum TransferFormat
{
	TRANSFER_FORMAT_RAW  = 0,
	TRANSFER_FORMAT_JEPG = 1,
};

enum ConnectionMode
{
	CONNECTION_MODE_INVALID = -1,
	CONNECTION_MODE_USB		= 0,
	CONNECTION_MODE_NETWORK = 1,
};

// Paper size
#define FB_MAXWIDTH_INCH		8.5	// inch
#define FB_MAXHEIGHT_INCH		11.693
#define FB_PRE_MAXHEIGHT_INCH	11.693	// inch precise value
#define FB_MINWIDTH_INCH		0.30
#define FB_MINHEIGHT_INCH		0.30

#define ADF_MAXWIDTH_INCH		8.5
#define ADF_MAXHEIGHT_INCH		14.0
#define ADF_MINWIDTH_INCH		5.5
#define ADF_MINHEIGHT_INCH		5.5

#define FB_MAXWIDTH_CM			21.59	// cm
#define FB_MAXHEIGHT_CM			29.7
#define FB_MINWIDTH_CM			0.76
#define FB_MINHEIGHT_CM			0.76

#define ADF_MAXWIDTH_CM			21.59
#define ADF_MAXHEIGHT_CM		35.56
#define ADF_MINWIDTH_CM			13.97
#define ADF_MINHEIGHT_CM		13.97

// A4
#define A4_WIDTH				8.2677
#define A4_HEIGHT				11.693
// Letter
#define LETTER_WIDTH			8.5
#define LETTER_HEIGHT			11.0


//////////////////////////////////////////////////////////////////////////
// Windows custom define message
// 
#define MSG_UPDATEUNIT			WM_USER + 2000
#define MSG_PREVIEWUPDATE		WM_USER + 2001
#define MSG_UPDATEPAPERSOURCE	WM_USER + 2002
#define MSG_SCANSTATUS			WM_USER + 2003
#define MSG_DESTORY_LOG_DIALOG	WM_USER + 2004
#define MSG_LOG_OUTPUT			WM_USER + 2005
#define MSG_PROGRESS_DIALOG		WM_USER + 2006

#define MSG_DEVICESEARCH_FINISH  WM_USER + 2010
#define MSG_DEVICESEARCH_PROGRESS WM_USER +2011
#define MSG_UPDATEPASSWORD_FINISH  WM_USER + 2012
#define MSG_UPDATEPASSWORD_PROGRESS WM_USER +2013
#define MSG_DEVICE_UPDATE  WM_USER + 2014

//////////////////////////////////////////////////////////////////////////
#define SCANNER_NO_ERROR			0
#define SCANNER_FAILED				-1    // Do some thing failed.

#define SCANNER_PAPER_JAM			-2

#define SCANNER_FB_COVER_OPEN		-3
#define SCANNER_ADF_COVER_OPEN		-4
#define SCANNER_ADF_PAPER_EMPTY		-5
#define SCANNER_JOB_CANCELED		-6
#define SCANNER_HAVE_NOT_JOB		-7

#define SCANNER_NOT_FOUND			-20
#define SCANNER_NOT_READY			-21
#define SCANNER_BUSY				-22
#define SCANNER_LOCK_ON				-25
#define SCANNER_LDAP_ON				-26

#define SCANNER_TCP_CLOSED			-30
#define SCANNER_IO_ERROR			-31
#define SCANNER_IO_TIMEOUT			-32
#define SCANNER_INVALID_HANDLE		-33
#define SCANNER_PORT_ERROR			-34

#define PARAMETER_ERROR				-40
#define MEMORY_NOT_ENOUGH			-41
#define LOAD_RESOURCE_ERROR			-42
#define DISK_NOT_ENOUGH				-43

#define FILE_PATH_ERROR				-50
#define READ_IMAGE_ERROR			-51
#define FILE_CREATE_ERROR			-52
#define CONFIG_FILE_ERROR			-53

#define FILE_MAX_LIMIT_ERROR		-54
#define FILE_SAVE_ERROR				-55
#define FILE_NAME_TOO_LONG_ERROR	-56

#define SCANNER_WAKE_UP			    -110
#define SCANNER_WAKE_UP_TIMEOUT  	-111
#define USER_CANNEL_OPERATION		-150
#define UNKNOWN_ERROR				-999

//---------------------------------------------------------
// Scanner Vendor Command Definition.
//
#define Get_Scanner_Status			0x01
#define Get_Scanner_Parameter		0x02
#define Set_Scanner_Parameter		0x03
#define Scanner_Start_Scan			0x04
#define Set_Cancel_scan             0x0C
#define Set_Scanning_Finish         0x1E
#define Set_Driver_Clsoe            0x0D
#define Check_User_Authentication	0x25













#endif	// _MACRO_H_