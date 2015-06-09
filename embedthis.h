/*
    embedthis.h - MbedTLS customization Header

    Pak will blend this header with others to create a single master header "mbedtls.h".

    The order of headers is:

        me.h            Generated by MakeMe
        config.h        Standard configuration for MbedTLS
        embedthis.h     This file
        check_config.h  MbedTLS config validation
        ***             Rest of MbedTLS headers
 */

#undef POLARSSL_SELF_TEST
#define POLARSSL_REMOVE_ARC4_CIPHERSUITES

#if ME_DEBUG
    #define POLARSSL_SSL_DEBUG_ALL
    #define POLARSSL_DEBUG_C
#endif
#if ME_CPU_ARCH == ME_CPU_X86 || ME_CPU_ARCH == ME_CPU_X64
    #define POLARSSL_HAVE_SSE2
#endif

/*
    Map MakeMe configuration into MbedTLS defines
 */
#if ME_MBEDTLS_COMPACT
    #undef POLARSSL_BLOWFISH_C
    #undef POLARSSL_CAMELLIA_C
    #undef POLARSSL_DES_C
    #undef POLARSSL_PADLOCK_C
    #undef POLARSSL_KEY_EXCHANGE_PSK_ENABLED
    #undef POLARSSL_KEY_EXCHANGE_RSA_PSK_ENABLED
    #undef POLARSSL_KEY_EXCHANGE_DHE_PSK_ENABLED
    #undef POLARSSL_KEY_EXCHANGE_ECDHE_PSK_ENABLED
    #undef POLARSSL_RC4
    #undef POLARSSL_ROM_TABLES
    #undef POLARSSL_XTEA_C
#endif

#if ME_MBEDTLS_BLOWFISH
    #define POLARSSL_BLOWFISH_C
#elif ME_MBEDTLS_BLOWFISH == 0
    #undef POLARSSL_BLOWFISH_C
#endif

#if ME_MBEDTLS_CAMELLIA
    #define POLARSSL_CAMELLIA_C
#elif ME_MBEDTLS_CAMELLIA == 0
    #undef POLARSSL_CAMELLIA_C
#endif

#if ME_MBEDTLS_DES
    #define POLARSSL_DES_C
#elif ME_MBEDTLS_DES == 0
    #undef POLARSSL_DES_C
#endif

#if ME_MBEDTLS_PADLOCK
    #define POLARSSL_PADLOCK_C
#elif ME_MBEDTLS_PADLOCK == 0
    #undef POLARSSL_PADLOCK_C
#endif

#if ME_MBEDTLS_PSK
    #define POLARSSL_KEY_EXCHANGE_PSK_ENABLED
    #define POLARSSL_KEY_EXCHANGE_RSA_PSK_ENABLED
    #define POLARSSL_KEY_EXCHANGE_DHE_PSK_ENABLED
    #define POLARSSL_KEY_EXCHANGE_ECDHE_PSK_ENABLED
#elif ME_MBEDTLS_PSK == 0
    #undef POLARSSL_KEY_EXCHANGE_PSK_ENABLED
    #undef POLARSSL_KEY_EXCHANGE_RSA_PSK_ENABLED
    #undef POLARSSL_KEY_EXCHANGE_DHE_PSK_ENABLED
    #undef POLARSSL_KEY_EXCHANGE_ECDHE_PSK_ENABLED
#endif

#if ME_MBEDTLS_RC4
    #define POLARSSL_RC4
#elif ME_MBEDTLS_RC4 == 0
    #undef POLARSSL_RC4
#endif

#if ME_MBEDTLS_ROM_TABLES
    #define POLARSSL_ROM_TABLES
#elif ME_MBEDTLS_ROM_TABLES == 0
    #undef POLARSSL_ROM_TABLES
#endif

#if ME_MBEDTLS_XTEA
    #define POLARSSL_XTEA_C
#elif ME_MBEDTLS_XTEA == 0
    #undef POLARSSL_XTEA_C
#endif
