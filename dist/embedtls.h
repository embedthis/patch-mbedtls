/*
    embedthis.h - MbedTLS customization Header

    Pak will blend this header with others to create a single master header "mbedtls.h".
 */

#include "me.h"
#include "osdep.h"

#define EMBEDTHIS 1
#undef MBEDTLS_SELF_TEST
#define MBEDTLS_REMOVE_ARC4_CIPHERSUITES

#if ME_COM_MPR || ME_MPR_PRODUCT || ME_MULTITHREAD
    #define MBEDTLS_THREADING_C
    #define MBEDTLS_THREADING_ALT
    typedef struct MprMutex* mbedtls_threading_mutex_t;
#endif

#if ME_DEBUG
    #define MBEDTLS_SSL_DEBUG_ALL
    #define MBEDTLS_DEBUG_C
#endif
#if ME_CPU_ARCH == ME_CPU_X86 || ME_CPU_ARCH == ME_CPU_X64
    #define MBEDTLS_HAVE_SSE2
#endif
#if VXWORKS
    #undef MBEDTLS_HAVE_TIME
#endif

/*
    Map MakeMe configuration into MbedTLS defines
 */
#if ME_MBEDTLS_COMPACT
    #undef MBEDTLS_BLOWFISH_C
    #undef MBEDTLS_CAMELLIA_C
    #undef MBEDTLS_DES_C
    #undef MBEDTLS_PADLOCK_C
    #undef MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
    #undef MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED
    #undef MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED
    #undef MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED
    #undef MBEDTLS_ARC4_C
    #undef MBEDTLS_AES_ROM_TABLES
    #undef MBEDTLS_XTEA_C
#endif

/*
    If mbedtls.NAME is defined, then override the MbedTLS definition from config.h
 */
#if ME_MBEDTLS_BLOWFISH
    #define MBEDTLS_BLOWFISH_C
#elif ME_MBEDTLS_BLOWFISH == 0
    #undef MBEDTLS_BLOWFISH_C
#endif

#if ME_MBEDTLS_CAMELLIA
    #define MBEDTLS_CAMELLIA_C
#elif ME_MBEDTLS_CAMELLIA == 0
    #undef MBEDTLS_CAMELLIA_C
#endif

#if ME_MBEDTLS_DES
    #define MBEDTLS_DES_C
#elif ME_MBEDTLS_DES == 0
    #undef MBEDTLS_DES_C
#endif

#if ME_MBEDTLS_PADLOCK
    #define MBEDTLS_PADLOCK_C
#elif ME_MBEDTLS_PADLOCK == 0
    #undef MBEDTLS_PADLOCK_C
#endif

#if ME_MBEDTLS_PSK
    #define MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
    #define MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED
    #define MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED
    #define MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED
#elif ME_MBEDTLS_PSK == 0
    #undef MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
    #undef MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED
    #undef MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED
    #undef MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED
#endif

#if ME_MBEDTLS_ARC4
    #define MBEDTLS_ARC4_C
#elif ME_MBEDTLS_ARC4 == 0
    #undef MBEDTLS_ARC4_C
#endif

#if ME_MBEDTLS_AES_ROM_TABLES
    #define MBEDTLS_AES_ROM_TABLES
#elif ME_MBEDTLS_AES_ROM_TABLES == 0
    #undef MBEDTLS_AES_ROM_TABLES
#endif

#if ME_MBEDTLS_XTEA
    #define MBEDTLS_XTEA_C
#elif ME_MBEDTLS_XTEA == 0
    #undef MBEDTLS_XTEA_C
#endif
