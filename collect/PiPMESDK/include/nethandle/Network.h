#pragma once

#include "SocketHandle.h"

class DeviceRecordInfo
{
public:
	CString IPAddress;
	CString ModelName;
	CString ProjectName;
	CString LocalIPAddress;
};

class PairIPAddress{
public:
	CString startAddress;
	CString endAddress;

	PairIPAddress(){};
	PairIPAddress(CString start, CString end)
	{
		startAddress = start;
		endAddress = end;
	};

};

class IPArrayInNIC{
public:
	CString NICAddress;
	vector<CString> destIPAddressArray; 

public:
	IPArrayInNIC(){};
	IPArrayInNIC(vector<CString> IPArray,CString LocalAddress)
	{
		destIPAddressArray =IPArray;
		NICAddress = LocalAddress;
	};

	~IPArrayInNIC()
	{

	};

};

class PNetwork
{
public:
	PNetwork(void);
	~PNetwork(void);

	/**
     * Verify IPv4 address
     * @param strIPAddress IP address
     * @return true if IPv4 address
     */
	static bool CheckIPAddressV4Legal(CString strIPAddress);

    /**
     * Verify IPv6 address
     * @param strIPAddress IP address
     * @return true if IPv6 address
     */
	static bool CheckIPAddressV6Legal(CString strIPAddress);

	inline static bool IsNumber(TCHAR ch);

	inline static bool IsHexNumber(TCHAR ch);

	inline static bool ValidDigit(TCHAR *ip_str);

	static bool SearchScannerFromIPv4(CArray<NetworkDevice>& arrDeviceInfo, char* pszNetworkID, int nNetworkID);
	static bool SearchScannerFromIPv6(CArray<NetworkDevice>& arrDeviceInfo, char* pszNetworkID, int nNetworkID);

//	static bool SearchPrinterWithSNMP(CArray<NetworkDevice>& arrDeviceInfo,const CStringArray &arrProductID);
//	static bool SearchPrinterWithIPv4(CArray<NetworkDevice>& arrDeviceInfo, char* pszNetworkID, int nNetworkID);
	static bool SearchPrinterWithSNMP(HWND hWnd,const CStringArray &arrProductID);
	static bool SearchPrinterWithIPv4(HWND hWnd, char* pszNetworkID, int nNetworkID);

public:
	CSocketHandle mSocketHandle;
	BOOL mIsWriteThreadAlreadyExit;
	BOOL mStopSNMPThread;

	CStringArray mIPAddressArray;
	CStringArray mProductArray;
	CString mNICAddress;
	CArray<IPArrayInNIC> mDestIPNIC;
	long mScannedIPCounter;
	HWND mHwnd;

private:
	static UINT WriteSNMPThreadProc(LPVOID handle);
	static UINT ReadSNMPThreadProc(LPVOID handle);

public:
	bool  ScanPrinterInUnicast(HWND hWnd, CString IPAddress, CString NICAddress, CStringArray & productIDArray);
	bool  ScanPrinterInIPArray(HWND hWnd, CStringArray & IPAddressArray,CString NICAddress, CStringArray & productIDArray);
	bool  ScanPrinterInSegment(HWND hWnd, CStringArray & segmentAddressArray, CString NICAddress, CStringArray & productIDArray);

	bool  ScanPrinterInRange(HWND hWnd, CArray<PairIPAddress> & segmentPairArray,CString NICAddress, CStringArray & productIDArray);

	//separate ScanPrinterInRange for multi NIC progress calculation
	bool AddIPInRangeWithNIC(CArray<PairIPAddress> & segmentPairArray,CString NICAddress);
	bool StartScanPrinterInRange(HWND hWnd, CStringArray & productIDArray);
};
