/******************************************************************************
	Copyright 1998-2006 Critical Path Software
******************************************************************************/
/* This code expects the following types to be available.  If they aren't
	predefined, uncomment them here and make sure the types are correct
	for your compiler.
*/
#pragma once
#include <sys/types.h>
#include "stdint.h"
typedef unsigned char		u_int8_t;		// unsigned 8-bit integer
//typedef signed char		int8_t;			// signed 8-bit integer
typedef unsigned short	u_int16_t;		// unsigned 16-bit integer
//typedef signed short		int16_t;		// signed 16-bit integer
typedef unsigned long		u_int32_t;		// unsigned 32-bit integer
//typedef signed long		int32_t;		// signed 32-bit integer

enum
{	/* These numbers match the SNMP type tags. */
	SNMPTypeError = -1,
	SNMPTypeInteger = 0x02,
	SNMPTypeString = 0x04,
	SNMPTypeNull = 0x05,
	SNMPTypeObjectID = 0x06,
	
	SNMPTypeSequence = 0x30,
	
	/* The next 3 types are stored like SNMPTypeInteger */
	SNMPTypeCounter = 0x41,
	SNMPTypeGauge = 0x42,
	SNMPTypeTimeTicks = 0x43,
	
	SNMPTypeGetRequest = 0xa0,
	SNMPTypeGetNextRequest = 0xa1,
	SNMPTypeGetResponse = 0xa2,
	SNMPTypeSetRequest = 0xa3,
	SNMPTypeTrap = 0xa4
};

/* Generate an SNMP query packet for the specified property.
	requestID is for the caller's use, to match replies to requests. 
	Returns the length of the generated packet.
*/
int32_t SNMPBuildGetRequest(u_int8_t *output, char *property, int32_t requestID);

/* Generate an SNMP query packet with multiple properties.  The second argument
	is a null-terminated array of char pointers, like this:
	
	char *properties[] = 
	{
		"1.3.6.1.2.3.4.5.6.0",
		"1.3.6.1.7.8.9.0.0",
		0
	};
*/
int32_t SNMPBuildGetRequestMulti(u_int8_t *output, char **properties, int32_t requestID);

/* Generate 'GetNextRequest' packets.  These two functions work almost
	exactly like the previous two.
*/
int32_t SNMPBuildGetNextRequest(u_int8_t *output, char *property, int32_t requestID);
int32_t SNMPBuildGetNextRequestMulti(u_int8_t *output, char **properties, int32_t requestID);

/* Parse an SNMP response packet and determine the type of the response.
	The caller may pass NULL for requestID if it isn't needed.
	Returns the type of the response data, or SNMPTypeError if the packet
	indicates an error or there is a problem parsing the packet.
	If 'mibString' is not NULL, a human-readable representation of the
	mib will be stored there.
*/
int32_t SNMPResponseType(u_int8_t *data, int32_t len, int32_t index, int32_t *requestID, char *mibString);

/* Extract the data from an SNMP response.  The data type stored at *output
	depends on the type of the data (call SNMPResponseType first to find out).
	If the type is SNMPTypeString, a C string will be stored at *(char*)output.
	If the type is SNMPTypeInteger or equivalents (see above), a u_int32_t will be
	stored at *(u_int32_t*)output.
*/
int32_t SNMPResponseData(u_int8_t *data, int32_t len, int32_t index, void *output);

/* Print the contents of a packet in human-readable form. 
	Returns the length of the generated string.
*/
int32_t SNMPPrintPacket(char *output, u_int8_t *data, int32_t len);

/* Print a buffer of binary data in hexadecimal (human-readable) form. 
	Returns the length of the generated string.
*/
int32_t SNMPPrintBuffer(char *output, u_int8_t *data, int32_t len);

#if 0   /***** Ideas for future expansion *****/

/* XXX -- ability to build other types of packets (SetRequest, GetNextRequest) */
/* XXX -- ability to build/parse packets with multiple properties (add 
	index number to existing functions?)  */


#endif
