//
// Created by Arthur Anderson on 9/17/16.
//

#ifndef BEARS_DEN_LIBEXPORTS_H
#define BEARS_DEN_LIBEXPORTS_H

#ifdef(WIN32)

#ifdef(bdCommon_EXPORTS)
#define BD_COMMON_EXPORT __declspec( dllexport )
#else
#define BD_COMMON_EXPORT __declspec( dllimport )
#endif

#else

#define BD_COMMON_EXPORT

#endif //BEARS_DEN_LIBEXPORTS_H
