/**
 *
 * @copyright John Wong 2006-2014
 *  john.innovation@yahoo.com.au
 *
 * timeanalyze is free software. You can redistribute it and/or modify it
 * under the terms of the GNU General Public License, version 2 (GPL-2.0)
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * A copy of the license can be viewed in the docs/LICENSE.txt file.
 * The same can be viewed at <http://opensource.org/licenses/gpl-2.0.php>
 *
 */

#ifndef _TIMEANALYZE_H_
#define _TIMEANALYZE_H_

#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    static inline unsigned long long GetTimeInMicroSecond()
    {
        unsigned long long nRet = 0;
        
        struct timeval time;
        gettimeofday( &time, NULL );
        
        //nRet = (time.tv_sec ) * 1000 + time.tv_usec / 1000;
        //nRet = (time.tv_sec ) * 1024 + time.tv_usec / 1024;
        nRet = ( (time.tv_sec ) << 10 ) + (time.tv_usec >> 10);
        return nRet;
    }
    
    int TimeAnalyzeItemInit();
    int TimeAnalyzeItemDealloc();
    
    int TimeAnalyzeBeginMain( unsigned int nID, unsigned int nValue, const char* pszDescription );
    int TimeAnalyzeEndMain( unsigned int nID, unsigned int nValue );
    
    int TimeAnalyzeBeginSub( unsigned int nID, unsigned int nValue, const char* pszDescription );
    int TimeAnalyzeEndSub( unsigned int nID, unsigned int nValue );
    
    int TimeAnalyzeBeginExt( unsigned int nID, unsigned int nValue, const char* pszDescription );
    int TimeAnalyzeEndExt( unsigned int nID, unsigned int nValue );
    
    
    int TimeAnalyzeIsMainTimeOut( unsigned int nID, unsigned int nTimeOutCount );
    int TimeAnalyzeIsMainLost( unsigned int nID );
    int TimeAnalyzeIsSubTimeOut( unsigned int nID, unsigned int nTimeOutCount );
    int TimeAnalyzeIsSubLost( unsigned int nID );
    int TimeAnalyzeIsExtTimeOut( unsigned int nID, unsigned int nTimeOutCount );
    int TimeAnalyzeIsExtLost( unsigned int nID );
    
    int SetupSaveFileNames( const char* pszMainFileName, const char* pszSubFileName, const char* pszExtFileName );
    
    int TimeAnalyzeSaveAllData();
    int TimeAnalyzeSaveData( const char* pszMainFileName, const char* pszSubFileName, const char* pszExtFileName );
    
    int WarnLog( const char* pszFormat, ... );

#define NEED_TIME_ANALYZE 1
    
#ifdef NEED_TIME_ANALYZE
    
#define TIME_ANALYZE_INIT()     do { TimeAnalyzeItemInit();        } while(0)
#define TIME_ANALYZE_DEALLOC()  do { TimeAnalyzeItemDealloc();    } while(0)
    
#   define TIME_ANALYZE_BEGINMAIN(id,value,desc)    do { TimeAnalyzeBeginMain(id,value,desc);   } while(0)
#   define TIME_ANALYZE_ENDMAIN(id,value)           do { TimeAnalyzeEndMain(id,value);          } while(0)
#   define TIME_ANALYZE_BEGINSUB(id,value,desc)     do { TimeAnalyzeBeginSub(id,value,desc);    } while(0)
#   define TIME_ANALYZE_ENDSUB(id,value)            do { TimeAnalyzeEndSub(id,value);           } while(0)
#   define TIME_ANALYZE_BEGINEXT(id,value,desc)     do { TimeAnalyzeBeginExt(id,value,desc);    } while(0)
#   define TIME_ANALYZE_ENDEXT(id,value)            do { TimeAnalyzeEndExt(id,value);           } while(0)
    
#   define TIME_ANALYZE_WARN(pszFormat, ...)        do{ WarnLog( pszFormat, ##__VA_ARGS__);     } while(0)
    
#else
    
#define TIME_ANALYZE_INIT()         do { ; } while(0)
#define TIME_ANALYZE_DEALLOC()      do { ; } while(0)
    
#    define TIME_ANALYZE_BEGINMAIN(id,value,desc)   do { ; } while(0)
#    define TIME_ANALYZE_ENDMAIN(id,value)          do { ; } while(0)
#    define TIME_ANALYZE_BEGINSUB(id,value,desc)    do { ; } while(0)
#    define TIME_ANALYZE_ENDSUB(id,value)           do { ; } while(0)
#    define TIME_ANALYZE_BEGINEXT(id,value,desc)    do { ; } while(0)
#    define TIME_ANALYZE_ENDEXT(id,value)           do { ; } while(0)
    
#    define TIME_ANALYZE_WARN(pszFormat, ...)       do { ; } while(0)
    
#endif
    
#ifdef __cplusplus
}
#endif

#endif
