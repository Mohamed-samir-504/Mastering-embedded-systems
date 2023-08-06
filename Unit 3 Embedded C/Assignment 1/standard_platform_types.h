#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include <stdint.h>

#ifndef FALSE
#define FALSE  (boolean)false
#endif

#ifndef TRUE
#define TRUE  (boolean)true
#endif


typedef unsigned char boolean;
typedef char char_t;

typedef int8_t sint8;
typedef uint8_t uint8;
typedef volatile int8_t vint8;
typedef volatile uint8_t vuint8;


typedef int16_t sint16;
typedef uint16_t uint16;
typedef volatile int16_t vint16;
typedef volatile uint16_t vuint16;


typedef int32_t sint32;
typedef uint32_t uint32;
typedef volatile int32_t vint32;
typedef volatile uint32_t vuint32;


typedef int64_t sint64;
typedef uint64_t uint64;
typedef volatile int64_t vint64;
typedef volatile uint64_t vuint64;


#endif