/*
 * This file is part of the CN24 semantic segmentation software,
 * copyright (C) 2015 Clemens-Alexander Brust (ikosa dot de at gmail dot com).
 *
 * For licensing information, see the LICENSE file included with this project.
 */  
/**
 * @file Config.h
 * @brief Contains configuration macros.
 * 
 * @author Clemens-Alexander Brust (ikosa dot de at gmail dot com)
 */

#ifndef CONV_CONFIG_H
#define CONV_CONFIG_H

#include <sys/types.h>
#include <cstdint>

#include "FloatDatum.h"

namespace Conv {
  
/**
 * This makes the networks data type configurable without using
 * templates. Templates do not allow for move constructors and
 * are evil.
 */
typedef FloatDatum datum;
//define DATUM_IS_FLOAT

typedef int32_t dint;
#ifdef __MINGW32__
typedef uint32_t duint;
#else
#ifdef _MSC_VER
typedef uint32_t duint;
#else
typedef u_int32_t duint;
#endif
#endif
#define DATUM_FROM_UCHAR(x) ((Conv::datum)((Conv::datum)0.003921569f * (Conv::datum) ((unsigned char)x)))
#define DATUM_FROM_USHORT(x) ((Conv::datum)((Conv::datum)0.0000152590219f * (Conv::datum) ((unsigned short)x)))
#define UCHAR_FROM_DATUM(x) ((unsigned char) ((Conv::datum)255.0f * ((Conv::datum)x) ) )
#define MCHAR_FROM_DATUM(x) ((unsigned char) ((Conv::datum)127.0f + (Conv::datum)127.0f * ((Conv::datum)x) ) )

}



#endif
