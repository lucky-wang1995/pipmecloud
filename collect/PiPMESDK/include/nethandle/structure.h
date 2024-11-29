#ifndef _STRUCT_H
#define _STRUCT_H



typedef struct tagSCANNER_STATUS
{
	unsigned char LockSwitch;           // Bit0: 0: Lock on; 1: Lock off; Bit1: 0: LDAP off; 1: LDAP on;
	unsigned char ButtonNum;            // Actural HW button numbers
	unsigned char DetectButton;			// 0 Button up; 1 Button down
	unsigned char Behavior;             // 0: Sleep; 1: Ready; 2:Lamp warming up; 3: Busy
	unsigned char WarmUpRemainTime;     // Warming up remain time (sec.)
	unsigned char SupportMechanicalType;// Bit0: Flatbed; Bit1: ADF; Bit2: ARDF; Bit3: DADF; (0: Not support; 1: Support)
	unsigned char ADFPaperExistence;    // 0: ADF Paper Empty; 1: ADF Paper Exist;
	unsigned char ADFStatus;            // 0: Normal; 1: ADF Paper Jam; 2: ADF Cover Open; 4: FB Cover Open;
	DWORD   dwTick;				// Timestamp
} SCANNER_STATUS, *PSCANNER_STATUS;

typedef struct tagSCANNER_SETPARAMETER
{
	unsigned char PaperSource;          // 1: FB; 2: ADF; 3:ARDF(Duplex); 4: DADF;
	unsigned char ScanMode;             // 0: Preview; 1: Scan;
	unsigned char DataType;             // 0: BW; 1: Gray; 2: Color
	unsigned char Reserved1;
	unsigned int XResolution;           // dpi
	unsigned int YResolution;           // dpi
	unsigned int WidthPixels;           // pixel
	unsigned int Lines;                 // pixel
	unsigned int XPosition;             // pixel
	unsigned int YPosition;             // pixel
	unsigned char BitsPerPixel;         // bits per each pixel
	unsigned char RGBSequence;          // 0: RGB; 1: BGR;
	unsigned char DataFormat;           // 0: RAW; 1: JPEG;
	unsigned char Reserved2;
} SCANNER_SETPARAMETER, *PSCANNER_SETPARAMETER;

typedef struct tagSCANNER_JOBID_PARAMETER
{
	unsigned char PaperSource;
	unsigned char REserved1;
	unsigned char REserved2;
	unsigned char REserved3;
} SCANNER_JOBID_PARAMETER, *PSCANNER_JOBID_PARAMETER;

typedef struct tagSCANNER_GETPARAMETER
{
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int XResolution;           // dpi
	unsigned int YResolution;           // dpi
	unsigned char SupportDataType;		// 0 bits: BW; 1 bits: Gray; 2 bits: Color; 7 bits: JPEG compression (0:No, 1:Support)
	unsigned char Reserved1;
	unsigned char RGBSequence;			// 0: RGB; 1: BGR;
	unsigned char MaxBufferSize;		// byte
	unsigned char CurrentDataType;		// 0: BW; 1: Gray; 2: Color;
	unsigned char CurrentPixelbits;		// bits per each pixel
	unsigned char CurrentIntensity;     // 
	unsigned char CurrentContrast;
	unsigned int CurrentXResolution;   // dpi
	unsigned int CurrentYResolution;   // dpi
	unsigned int JobIdentify;          // Job Identify
} SCANNER_GETPARAMETER, *PSCANNER_GETPARAMETER;

typedef struct tagJOB_ID_COMMAND
{
	unsigned int nCmd;
	unsigned int nDataSize;
	SCANNER_JOBID_PARAMETER SetJobParam;
} JOB_ID_COMMAND, PJOB_ID_COMMAND;

typedef struct tagSEND_PARAMETER_HEADER
{
	unsigned int nCmd;
	unsigned int nJobID;
} SEND_PARAMETER_HEADER, PSEND_PARAMETER_HEADER;

typedef struct tagSEND_START_SCAN_HEADER
{
	unsigned int nCmd;
	unsigned int nJobID;
} SEND_START_SCAN_HEADER, *PSEND_START_SCAN_HEADER;

typedef struct tagSEND_CANCEL_SCAN_HEADER
{
	unsigned int nCmd;
	unsigned int nJobID;
} SEND_CANCEL_SCAN_HEADER, *PSEND_CANCEL_SCAN_HEADER;

typedef struct tagSEND_PAGE_DONE_HEADER
{
	unsigned int nCmd;
	unsigned int nJobID;
} SEND_PAGE_DONE_HEADER, *PSEND_PAGE_DONE_HEADER;

typedef struct tagSEND_JOB_DONE_HEADER
{
	unsigned int nCmd;
	unsigned int nJobID;
} SEND_JOB_DONE_HEADER, *PSEND_JOB_DONE_HEADER;

typedef struct tagUISetting
{
	int nScanPage;
	int nPaperSource;
	int nScanMode;
	int nXRes;
	int nYRes;
	int nPaperSizeID;
	int nUnit;
	int nImageType;
	int nImageHeader;	// 1: add bitmap image header
	int nxOffsetPixel;
	int nyOffsetPixel;
	int nWidthPixel;
	int nHeightPixel;
	TCHAR szProject[MAX_PATH];
	TCHAR szFolder[MAX_PATH];
	TCHAR szFileName[MAX_PATH];
	TCHAR szPortName[MAX_PATH];
} UISetting, *PUISetting;




typedef struct tagRESPONSE_TO_CLIENT
{
	UINT32	ID; // constant, NETA
	BYTE    ScannerStatusFlag;	// 0x20
	BYTE	ScannerStatus;	// 0: Ready; 1: Busy
	BYTE    SupportType;	// Bit0: The field is available; Bit1: Support ADF; Bit2: Support ARDF; Bit3: Support DADF; 
	BYTE    nErrorFlags;	// Unknown = 0, Sleep = 1, Cabliration = 2, Scanning = 3, ADFOpen = 4, ADFJam = 5, ScannerLocked = 6, Ready = 7, FlatbedOpen = 8
	BYTE	nDeviceModelLen;
	BYTE	DeviceModel[64]; // Device Model,Maximum characters is 64Bytes.
} RESPONSE_TO_CLIENT, *PRESPONSE_TO_CLIENT; 


enum MouseSelectFlags
{
	cropResizeWidth =   (int) 0x00000,
	cropResizeHeight =  (int) 0x00001,
	cropResizeBoth =    (int) 0x00002,
	cropMovingBody =    (int) 0x00003,
	cropNone =          (int) -1,
};

typedef struct tagCropArea
{
	RECT rect;
	int nCropState;
	int nActiveIndex;
	double dPVDpi;
} CropArea;

typedef struct tagSupportSource
{
	int bSupportFB;
	int bSupportADF;
	int bSupportARDF;
	int bSupportDADF;
} DeviceParameters;


typedef struct tagProjectInfo
{
	int nProjectID;
	WORD wPid;
	WORD wVid;
	WORD wInterface;
	char szNetworkID[10];
	int nNetworkIDLen;
} ProjectInfo;

typedef struct tagRequestDeviceInfo
{
	DWORD dwNetworkID;	// Network ID
	BYTE RequestFlag;	// 0x10
	BYTE Reserved1;
	BYTE Reserved2;
	BYTE Reserved3;
	DWORD dwTimestamp;
} RequestDeviceInfo;

typedef struct tagResponseDeviceInfo
{
	DWORD NetworkID;	// Network ID
	BYTE ResponseFlag;	// 0x20
	BYTE ScannerStatus;	// 0: Ready; 1: Busy
	BYTE Reserved1;
	BYTE Reserved2;
	DWORD dwTimestamp;
	BYTE DeviceType;	// Bit0: FB; Bit1: ADF; Bit2: ARDF; Bit3: DADF; Bit7: Flag;
	BYTE HighErrorCode;	//  Bit0: Flatbed Open; Bit1: ADF Open; Bit2: ADF Jam;
	BYTE LowErrorCode;	//
	BYTE ModelNameLen;	// Model name length
	char szModelName[MODLENAMELEN];	// Model name
} ResponseDeviceInfo;

typedef struct tagJPEG_HEADER_INFO
{
	char	 szHeaderFlag[8];       // Length of user code in byte
	UINT32   nDataSize;		   // Size of block data (Not includes header size)
	BYTE     BlockFlag;        // 0: Normal block, 128: Last block of current job
	BYTE     Reserved1;
	BYTE     Reserved2;
	BYTE     Reserved3;
} JPEG_HEADER_INFO, *PJPEG_HEADER_INFO;

typedef struct tagRawDataHeader
{
	char HeaderFlag[8];		// RAWDATA, JPEGDATA constant
	UINT32 DataSize;	// Size of block data (Not includes header size)
	BYTE BlockFlag;			// 0: Normal block, 0x80: Last block of current job
	BYTE PaperFlag;		// 0: front of paper; 1: back of paper;
	UINT16 BlockIndex;	// Index of data block
} RawDataHeader, JpegDataHeader;

typedef struct tagRawDataHeaderV2
{
	char HeaderFlag[8];		// RAWDATA, JPEGDATA constant
	UINT32 DataSize;	// Size of block data (Not includes header size)
	BYTE BlockFlag;			// 0: Normal block, 0x80: Last block of current job
	BYTE PaperFlag;		// 0: front of paper; 1: back of paper;
	UINT16 BlockIndex;	// Index of data block
	UINT16 ImageWidth;
	UINT16 ImageHeight;
} RawDataHeaderV2, JpegDataHeaderV2;

typedef struct tagUSBDevice
{
	CString strSymbol;
	CString strPort;
} USBDevice;

typedef struct tagNetworkDevice
{
	CString strProject;
	CString strDestName;
	CString strHostName;
	CString strModelName;
	int nPasswordUpdateStatus;
} NetworkDevice;

typedef struct tagProjects
{
	int nProjectID;
	TCHAR szProjectName[MAX_PATH];
	DWORD dwVid;
	DWORD dwPid;
	DWORD wMI;
	WORD wSupportScanType;
	int nProtocol;
	char szNetworkID[8];
	int nNetworkIDLen;
	TCHAR szPasswordResultSign[32];
	char szUpdatePasswordKey[256];
} ProjectsStruct;


typedef struct tagEditCharFormat
{
	BOOL bBold;
	BOOL bItalic;
	BOOL bUnderLine;
	LONG lHeight;
	COLORREF color;
	TCHAR szFontName[128];
} EditCharFormat;

typedef struct tagAutoTest
{
	BOOL bAutoTest;
	
	BOOL bTestWidth;
	int nWidthStep;
	BOOL bWidthDesc;
	
	BOOL bTestHeight;
	int nHeightStep;
	BOOL bHeightDesc;

	BOOL bTestCancel;
	int nCancelValue;
	int nCancelStep;
	BOOL bCancelDesc;
	BOOL bCancelCurrentJob;

	int nScanCount;
} AutoTestStruct;
















#endif	// _STRUCT_H
