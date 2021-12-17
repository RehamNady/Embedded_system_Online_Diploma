/*
 * platform_types.h
 *
 *  Created on: Dec 17, 2021
 *      Author: reham
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_



#define CPU_TYPE        CPU_TYPE_32
#define CPU_BIT_ORDER   MSB_FIRST
#define CPU_BYTE_ORDER  HIGH_BYTE_FIRST

#ifndef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FALSE (boolean)0
#endif
#ifndef TRUE
#define TRUE (boolean)1
#endif

typedef _Bool                   boolean;
typedef signed char             sint8;
typedef unsigned char           uint8;
typedef char                    char_t;
typedef short                   sint16;
typedef unsigned short          uint16;
typedef int                     sint32;
typedef unsigned                uint32;
typedef long long               sint64;
typedef unsigned long long      uint64;

typedef volatile signed char    vint8_t;
typedef volatile unsigned char  vuint8_t;

typedef volatile short           vint16_t;
typedef volatile unsigned short  vuint16_t;

typedef volatile int       vint32_t;
typedef volatile unsigned  vuint32_t;

typedef volatile long long           vint64_t;
typedef volatile unsigned long long  vuint64_t;



#endif /* PLATFORM_TYPES_H_ */
