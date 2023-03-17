﻿///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifndef __SCISERIALIZE_H__
#define __SCISERIALIZE_H__

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include "sciReport.h"

#ifdef __cplusplus
extern "C"
{
#endif   // __cplusplus

    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    gsi_u8* sciSerializeInt8(gsi_u8* theCursor, gsi_i8 theValue);

    gsi_u8* sciSerializeInt16(gsi_u8* theCursor, gsi_i16 theValue);

    gsi_u8* sciSerializeInt32(gsi_u8* theCursor, gsi_i32 theValue);

    gsi_u8* sciSerializeInt64(gsi_u8* theCursor, gsi_i64 theValue);

    gsi_u8* sciSerializeFloat(gsi_u8* theCursor, float theValue);

    gsi_u8* sciSerializeKey(gsi_u8* theCursor, gsi_u16 theKey);

    gsi_u8* sciSerializeDataLength(gsi_u8* theCursor, gsi_u32 theDataLength);

    gsi_u8* sciSerializeGUID(gsi_u8* theCursor, const gsi_u8 theGUID[SC_CONNECTION_GUID_SIZE]);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}   // extern "C"
#endif   // __cplusplus

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif   // __SCSERIALIZE_H__
