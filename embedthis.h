/*
    embedthis.h - MbedTLS customization Header
 */

#define POLARSSL_REMOVE_ARC4_CIPHERSUITES

#if ME_DEBUG
    #define POLARSSL_SSL_DEBUG_ALL
    #define POLARSSL_DEBUG_C
#endif
#if ME_CPU_ARCH == ME_CPU_X86 || ME_CPU_ARCH == ME_CPU_X64
    #define POLARSSL_HAVE_SSE2
#endif

#undef POLARSSL_SELF_TEST
