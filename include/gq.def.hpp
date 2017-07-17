// $flavio.lisboa @ 2017-07-17.
//
/*
 * @file gq.def.hpp
 */


#ifndef gq_def_hpp__
#define gq_def_hpp__

#include "gq.cfg.hpp"

//
// [[ CONSTANTS ]]
//


// LANGUAGE_STANDARDS

#define gq_CONFIG_LANG_CPP11 1
#define gq_CONFIG_LANG_CPP14 2
#define gq_CONFIG_LANG_CPP17 3

#define gq_CONFIG_LANG_IS_CPP11 (gq_CONFIG_LANG_DETECTED == gq_CONFIG_LANG_CPP11)
#define gq_CONFIG_LANG_IS_CPP14 (gq_CONFIG_LANG_DETECTED == gq_CONFIG_LANG_CPP14)
#define gq_CONFIG_LANG_IS_CPP17 (gq_CONFIG_LANG_DETECTED == gq_CONFIG_LANG_CPP17)


// COMPILERS

#define gq_CONFIG_COMPILER_GCC   1
#define gq_CONFIG_COMPILER_CLANG 2
#define gq_CONFIG_COMPILER_MSVC  3

#define gq_CONFIG_COMPILER_GCC_NAME   "gcc"
#define gq_CONFIG_COMPILER_CLANG_NAME "clang"
#define gq_CONFIG_COMPILER_MSVC_NAME  "msvc"

#define gq_CONFIG_COMPILER_IS_MSVC (gq_CONFIG_COMPILER_DETECTED == gq_CONFIG_COMPILER_MSVC)
#define gq_CONFIG_COMPILER_IS_GCC (gq_CONFIG_COMPILER_DETECTED == gq_CONFIG_COMPILER_GCC)
#define gq_CONFIG_COMPILER_IS_CLANG (gq_CONFIG_COMPILER_DETECTED == gq_CONFIG_COMPILER_CLANG)


// OPERATING SYSTEMS

#define gq_CONFIG_OS_LINUX   1
#define gq_CONFIG_OS_APPLE   2
#define gq_CONFIG_OS_WINDOWS 3

#define gq_CONFIG_OS_LINUX_NAME   "linux"
#define gq_CONFIG_OS_APPLE_NAME   "apple"
#define gq_CONFIG_OS_WINDOWS_NAME "win"

#define gq_CONFIG_OS_IS_LINUX (gq_CONFIG_OS_DETECTED == gq_CONFIG_OS_IS_LINUX)
#define gq_CONFIG_OS_IS_APPLE (gq_CONFIG_OS_DETECTED == gq_CONFIG_OS_IS_APPLE)
#define gq_CONFIG_OS_IS_WINDOWS (gq_CONFIG_OS_DETECTED == gq_CONFIG_OS_IS_WINDOWS)


// ARCHITECTURES

#define gq_CONFIG_ARCH_X86 1
#define gq_CONFIG_ARCH_X64 2
#define gq_CONFIG_ARCH_ARMV6 3
#define gq_CONFIG_ARCH_ARMV7 4
#define gq_CONFIG_ARCH_ARMV8 5
#define gq_CONFIG_ARCH_ARMV8_64 6

#define gq_CONFIG_ARCH_X86_NAME "x86"
#define gq_CONFIG_ARCH_X64_NAME "x86_64"
#define gq_CONFIG_ARCH_ARMV6_NAME "armv6"
#define gq_CONFIG_ARCH_ARMV7_NAME "armv7"
#define gq_CONFIG_ARCH_ARMV8_NAME "armv8"
#define gq_CONFIG_ARCH_ARMV8_64_NAME "aarch64"


// ARTIFACT (BINARY) TYPES

#define gq_CONFIG_BINTYPE_HEADERLIB 1
#define gq_CONFIG_BINTYPE_STATICLIB 2
#define gq_CONFIG_BINTYPE_SHAREDLIB 3
#define gq_CONFIG_BINTYPE_EXECUTABLE 4

#define gq_CONFIG_BINTYPE_IS_HEADERLIB (gq_CONFIG_BINTYPE == gq_CONFIG_BINTYPE_HEADERLIB)
#define gq_CONFIG_BINTYPE_IS_STATICLIB (gq_CONFIG_BINTYPE == gq_CONFIG_BINTYPE_STATICLIB)
#define gq_CONFIG_BINTYPE_IS_SHAREDLIB (gq_CONFIG_BINTYPE == gq_CONFIG_BINTYPE_SHAREDLIB)
#define gq_CONFIG_BINTYPE_IS_EXECUTABLE (gq_CONFIG_BINTYPE == gq_CONFIG_BINTYPE_EXECUTABLE)


//
// [[ HELPER MACROS ]]
//

#define gq_STRFY_(s__) #s__
#define gq_STRFY(s__) gq_STRFY_(s__)
#define gq_TPASTE3_(a__, b__, c__) a__ ## b__ ## c__
#define gq_TPASTE3(a__, b__, c__) gq_TPASTE3_(a__, b__, c__)


// The fun starts here.
#ifndef gq__BUILDING_DOCS


//
// [[ ABI CUSTOMIZATION OPTIONS ]]
//

#ifndef gq_CONFIG_ROOT_NAMESPACE_NAME
    #define gq_CONFIG_ROOT_NAMESPACE_NAME adl
#endif

#ifndef gq_CONFIG_ABI_NAMESPACE_PREFIX
    #define gq_CONFIG_ABI_NAMESPACE_PREFIX abi_v
#endif

#define gq_CONFIG_NAME_STR gq_STRFY(gq_CONFIG_NAME)
#define gq_CONFIG_VERSION_STR gq_STRFY(gq_CONFIG_VERSION_MAJOR) "." gq_STRFY(gq_CONFIG_VERSION_MINOR) "." gq_STRFY(gq_CONFIG_VERSION_PATCH)
#define gq_CONFIG_ABI_NAMESPACE_NAME gq_TPASTE3(gq_CONFIG_ABI_NAMESPACE_PREFIX, gq_CONFIG_VERSION_ABI, _)


//
// [[ COMPILING OPTIONS ]]
//

#ifndef gq_CONFIG_NAME
    #error Please give a name to your project.
#endif

#ifndef gq_CONFIG_VERSION_MAJOR
    #error Please give a major version to your project.
#endif

#ifndef gq_CONFIG_VERSION_MINOR
    #if gq_CONFIG_VERSION_MAJOR == 0
        #define gq_CONFIG_VERSION_MINOR 1
    #else
        #define gq_CONFIG_VERSION_MINOR 0
    #endif
#endif

#ifndef gq_CONFIG_VERSION_PATCH
    #define gq_CONFIG_VERSION_PATCH 0
#endif

#ifndef gq_CONFIG_VERSION_ABI
    #define gq_CONFIG_VERSION_ABI gq_CONFIG_VERSION_MAJOR
#endif

#ifndef gq_CONFIG_DEBUG_DEFAULT
    #define gq_CONFIG_DEBUG_DEFAULT 0
#endif

#if !defined(gq_CONFIG_DEBUG)
    #if defined(gq__DEBUG)
        #define gq_CONFIG_DEBUG 1
    #elif defined(gq__PROFILE)
        #define gq_CONFIG_DEBUG 1
    #else
        #define gq_CONFIG_DEBUG gq_CONFIG_DEBUG_DEFAULT
    #endif
#endif

#ifndef gq_CONFIG_PROFILE_DEFAULT
    #define gq_CONFIG_PROFILE_DEFAULT 0
#endif

#if !defined(gq_CONFIG_PROFILE)
    #if defined(gq__PROFILE)
        #define gq_CONFIG_PROFILE 1
    #elif defined(gq__DEBUG)
        #define gq_CONFIG_PROFILE 1
    #else
        #define gq_CONFIG_PROFILE gq_CONFIG_PROFILE_DEFAULT
    #endif
#endif

#ifndef gq_CONFIG_STRIPPED_DEFAULT
    #define gq_CONFIG_STRIPPED_DEFAULT !gq_CONFIG_DEBUG
#endif

#if !defined(gq_CONFIG_STRIPPED)
    #if defined(gq__STRIPPED)
        #define gq_CONFIG_STRIPPED 1
    #else
        #define gq_CONFIG_STRIPPED gq_CONFIG_STRIPPED_DEFAULT
    #endif
#endif

#if !defined(gq_CONFIG_BUILDING)
    #if defined(gq__BUILDING)
        #define gq_CONFIG_BUILDING 1
    #elif defined(gq__DEBUG) || defined(gq__PROFILE) || defined(gq__STRIPPED) \
        || defined(gq__STATIC) || defined(gq__SHARED) || defined(gq__EXECUTABLE)
        #define gq_CONFIG_BUILDING 1
    #else
        #define gq_CONFIG_BUILDING 0
    #endif
#endif

#ifndef gq_CONFIG_BINTYPE_DEFAULT
    #define gq_CONFIG_BINTYPE_DEFAULT 0
#endif

#if !defined(gq_CONFIG_BINTYPE)
    #if defined(gq__HEADERONLY)
        #define gq_CONFIG_BINTYPE gq_CONFIG_BINTYPE_HEADERLIB
    #elif defined(gq__STATIC)
        #define gq_CONFIG_BINTYPE gq_CONFIG_BINTYPE_STATICLIB
    #elif defined(gq__SHARED)
        #define gq_CONFIG_BINTYPE gq_CONFIG_BINTYPE_SHAREDLIB
    #elif defined(gq_EXECUTABLE)
        #define gq_CONFIG_BINTYPE gq_CONFIG_BINTYPE_EXECUTABLE
    #else
        #define gq_CONFIG_BINTYPE gq_CONFIG_BINTYPE_DEFAULT
    #endif

    #if !gq_CONFIG_BINTYPE
        #error Could not detect artifact (binary) type.
    #endif
#endif

#ifndef gq_CONFIG_INLINEIMPL_DEFAULT
    #define gq_CONFIG_INLINEIMPL_DEFAULT 0
#endif

#ifndef gq_CONFIG_INLINEIMPL
    #if gq_CONFIG_BINTYPE_IS_HEADERLIB
        #define gq_CONFIG_INLINEIMPL 1
    #elif defined gq__INLINEIMPL
        #define gq_CONFIG_INLINEIMPL 1
    #else
        #define gq_CONFIG_INLINEIMPL gq_CONFIG_INLINEIMPL_DEFAULT
    #endif
#endif


//
// [[ CORE FEATURE DETECTION: COMPILERS ]]
//

#ifndef gq_CONFIG_COMPILER_DETECTED
    #if defined(_MSC_VER)
        #define gq_CONFIG_COMPILER_DETECTED gq_CONFIG_COMPILER_MSVC
        #if !(_MSC_VER >= 1910) // MSVC++ 2017, relaxed constexpr rules
            #error Unsupported MSVC version.
        #endif
    #elif defined(__clang__)
        #define gq_CONFIG_COMPILER_DETECTED gq_CONFIG_COMPILER_CLANG
        #if !(__clang_major__ > 3 || (__clang_major__ == 3 && __clang_minor__ >= 4))
            #error Unsupported Clang C++ version.
        #endif
    #elif defined(__GNUC__)
        #define gq_CONFIG_COMPILER_DETECTED gq_CONFIG_COMPILER_GCC
        #if __GNUC__ < 5
            #error Unsupported G++ version.
        #endif
    // Insert here your custom checking (in a new elif clause).
    #else
        #define gq_CONFIG_COMPILER_DETECTED 0
    #endif

    #if !gq_CONFIG_COMPILER_DETECTED
        #pragma message("What compiler is this? The world is so vast...")
    #endif
#endif

#ifndef gq_CONFIG_COMPILER_IS_GCC_LIKE
    #if gq_CONFIG_COMPILER_IS_CLANG || gq_CONFIG_COMPILER_IS_GCC
        #define gq_CONFIG_COMPILER_IS_GCC_LIKE 1
    #else
        #define gq_CONFIG_COMPILER_IS_GCC_LIKE 0
    #endif
#endif


//
// [[ CORE FEATURE DETECTION: OPERATING SYSTEMS ]]
// Should come after compiler toolkit detection, because the OS can be inferred from some of those toolkits
// (e.g. msvc/mingw/cygwin for the Windows OS family).
//

#ifndef gq_CONFIG_OS_DETECTED
    #if defined _WIN32 || defined __WIN32__ || defined __WINDOWS__ || defined __TOS_WIN__ || defined _WIN64
        #define gq_CONFIG_OS_DETECTED gq_CONFIG_OS_WINDOWS
    #elif defined(__MAC__)
        #define gq_CONFIG_OS_DETECTED gq_CONFIG_OS_APPLE
    #elif defined(__linux__)
        #define gq_CONFIG_OS_DETECTED gq_CONFIG_OS_LINUX
    // Insert here your custom checking (in a new elif clause).
    #else
        #define gq_CONFIG_OS_DETECTED 0
    #endif

    #if !gq_CONFIG_OS_DETECTED
        #pragma message("What OS is this? The world is so vast...")
    #endif
#endif


//
// [[ CORE FEATURE DETECTION: LANGUAGE STANDARD ]]
//

#ifndef gq_CONFIG_LANG_DEFAULT
    #define gq_CONFIG_LANG_DEFAULT 0
#endif

#ifndef gq_CONFIG_LANG_DETECTED
    #ifdef __cplusplus
        #if __cplusplus < 201103L
            #error Your compiler or toolkit does not properly support modern C++ (e.g. is pre-C++11).
        #endif

        #if __cplusplus > 201402L // Most probably C++17. We still need to wait for C++17 to be officially published to correct this check.
            #define gq_CONFIG_LANG_DETECTED gq_CONFIG_LANG_CPP17
        #elif __cplusplus == 201402L
            #define gq_CONFIG_LANG_DETECTED gq_CONFIG_LANG_CPP14
        #elif __cplusplus == 201103L
            #define gq_CONFIG_LANG_DETECTED gq_CONFIG_LANG_CPP11
        #else
            #define gq_CONFIG_LANG_DETECTED gq_CONFIG_LANG_DEFAULT
        #endif
    #else
        // TODO Detect C standard
        #error Unknown language standard.
    #endif

    #if !gq_CONFIG_LANG_DETECTED
        #error Unrecognizable C++ version.
    #endif
#endif


//
// [[ CONFIGURATION-DEFINED MACROS ]]
//

#if gq_CONFIG_LANG_IS_CPP17
    #define gq_INLINEVAR_ inline
#else
    #define gq_INLINEVAR_
#endif

#ifdef __cplusplus
    #define gq_EXTERN_C extern "C"
    #define gq_BEGIN_EXTERN_C extern "C" {
    #define gq_END_EXTERN_C }
#else
    #define gq_EXTERN_C
    #define gq_BEGIN_EXTERN_C
    #define gq_END_EXTERN_C
#endif

#if gq_CONFIG_BINTYPE_IS_HEADERLIB
    #define gq_CONFIG_INCLUDINGIMPL 1
#elif gq_CONFIG_INLINEIMPL && gq_CONFIG_BUILDING
    #define gq_CONFIG_INCLUDINGIMPL 1
#else
    #define gq_CONFIG_INCLUDINGIMPL 0
#endif

#if gq_CONFIG_OS_IS_WINDOWS && gq_CONFIG_COMPILER_IS_GCC_LIKE
    #ifdef gq_CONFIG_BINTYPE_IS_STATICLIB
        #define gq_CONFIG_FT_EXTERNAL_GCC_ATTRIBUTE_
    #elif gq_CONFIG_BINTYPE_IS_SHAREDLIB || gq_CONFIG_BINTYPE_IS_EXECUTABLE
        #define gq_CONFIG_FT_EXTERNAL_GCC_DECLSPEC_
    #else
        #define gq_CONFIG_FT_EXTERNAL_GCC_DECLSPEC_
    #endif
    #define gq_CONFIG_FT_INTERNAL_GCC_ATTRIBUTE_
#elif gq_CONFIG_OS_IS_WINDOWS
    #if gq_CONFIG_BINTYPE_IS_SHAREDLIB || gq_CONFIG_BINTYPE_IS_EXECUTABLE
        #define gq_CONFIG_FT_EXTERNAL_DECLSPEC_
    #endif
#elif gq_CONFIG_COMPILER_IS_GCC_LIKE
    #define gq_CONFIG_FT_EXTERNAL_GCC_ATTRIBUTE_
    #define gq_CONFIG_FT_INTERNAL_GCC_ATTRIBUTE_
#endif


#ifdef gq_CONFIG_FT_EXTERNAL_DECLSPEC_
#	define gq_CONFIG_MARKER_API_EXPORT __declspec(dllexport)
#	define gq_CONFIG_MARKER_API_IMPORT __declspec(dllimport) extern
#	define gq_CONFIG_MARKER_API_IMPL
#	define gq_CONFIG_MARKER_VAR_EXPORT __declspec(dllexport)
#	define gq_CONFIG_MARKER_VAR_IMPORT __declspec(dllimport) extern
#	define gq_CONFIG_MARKER_VAR_IMPL
#	define gq_CONFIG_MARKER_CLS_EXPORT __declspec(dllexport)
#	define gq_CONFIG_MARKER_CLS_IMPORT __declspec(dllimport)
#	define gq_CONFIG_MARKER_CLS_IMPL
#elif defined(gq_CONFIG_FT_EXTERNAL_GCC_DECLSPEC_)
#	define gq_CONFIG_MARKER_API_EXPORT __attribute__((dllexport))
#	define gq_CONFIG_MARKER_API_IMPORT __attribute__((dllimport)) extern
#	define gq_CONFIG_MARKER_API_IMPL
#	define gq_CONFIG_MARKER_VAR_EXPORT __attribute__((dllexport))
#	define gq_CONFIG_MARKER_VAR_IMPORT __attribute__((dllimport)) extern
#	define gq_CONFIG_MARKER_VAR_IMPL
#	define gq_CONFIG_MARKER_CLS_EXPORT __attribute__((dllexport))
#	define gq_CONFIG_MARKER_CLS_IMPORT __attribute__((dllimport))
#	define gq_CONFIG_MARKER_CLS_IMPL
#elif defined(gq_CONFIG_FT_EXTERNAL_GCC_ATTRIBUTE_)
#	define gq_CONFIG_MARKER_API_EXPORT __attribute__((visibility("default")))
#	define gq_CONFIG_MARKER_API_IMPORT extern
#	define gq_CONFIG_MARKER_API_IMPL
#	define gq_CONFIG_MARKER_VAR_EXPORT __attribute__((visibility("default")))
#	define gq_CONFIG_MARKER_VAR_IMPORT extern
#	define gq_CONFIG_MARKER_VAR_IMPL
#	define gq_CONFIG_MARKER_CLS_EXPORT __attribute__((visibility("default")))
#	define gq_CONFIG_MARKER_CLS_IMPORT
#	define gq_CONFIG_MARKER_CLS_IMPL
#else
#	define gq_CONFIG_MARKER_API_EXPORT extern
#	define gq_CONFIG_MARKER_API_IMPORT
#	define gq_CONFIG_MARKER_API_IMPL
#	define gq_CONFIG_MARKER_VAR_EXPORT
#	define gq_CONFIG_MARKER_VAR_IMPORT
#	define gq_CONFIG_MARKER_VAR_IMPL
#	define gq_CONFIG_MARKER_CLS_EXPORT
#	define gq_CONFIG_MARKER_CLS_IMPORT
#	define gq_CONFIG_MARKER_CLS_IMPL
#endif

#ifdef gq_CONFIG_FT_INTERNAL_GCC_ATTRIBUTE_
#	define gq_CONFIG_MARKER_IAPI_EXPORT __attribute__((visibility("hidden")))
#	define gq_CONFIG_MARKER_IAPI_IMPORT extern
#	define gq_CONFIG_MARKER_IAPI_IMPL
#	define gq_CONFIG_MARKER_IVAR_EXPORT __attribute__((visibility("hidden")))
#	define gq_CONFIG_MARKER_IVAR_IMPORT extern
#	define gq_CONFIG_MARKER_IVAR_IMPL
#	define gq_CONFIG_MARKER_ICLS_EXPORT __attribute__((visibility("hidden")))
#	define gq_CONFIG_MARKER_ICLS_IMPORT
#	define gq_CONFIG_MARKER_ICLS_IMPL
#else
#	define gq_CONFIG_MARKER_IAPI_EXPORT extern
#	define gq_CONFIG_MARKER_IAPI_IMPORT
#	define gq_CONFIG_MARKER_IAPI_IMPL
#	define gq_CONFIG_MARKER_IVAR_EXPORT
#	define gq_CONFIG_MARKER_IVAR_IMPORT
#	define gq_CONFIG_MARKER_IVAR_IMPL
#	define gq_CONFIG_MARKER_ICLS_EXPORT
#	define gq_CONFIG_MARKER_ICLS_IMPORT
#	define gq_CONFIG_MARKER_ICLS_IMPL
#endif

//
// [[ LIBRARY INTERFACE MARKERS ]]
//

#define gq_BEGIN_CODE namespace gq_CONFIG_ROOT_NAMESPACE_NAME { inline namespace gq_CONFIG_ABI_NAMESPACE_NAME {
#define gq_END_CODE }}

#if gq_CONFIG_BUILDING || gq_CONFIG_INLINEIMPL || gq_CONFIG_BINTYPE_IS_HEADERLIB
    #define gq_API gq_CONFIG_MARKER_API_EXPORT
    #define gq_IAPI gq_CONFIG_MARKER_IAPI_EXPORT
    #define gq_VAR gq_CONFIG_MARKER_VAR_EXPORT
    #define gq_IVAR gq_CONFIG_MARKER_IVAR_EXPORT
    #define gq_CLASS gq_CONFIG_MARKER_CLS_EXPORT
    #define gq_ICLASS gq_CONFIG_MARKER_ICLS_EXPORT
#else
    #define gq_API gq_CONFIG_MARKER_API_IMPORT
    #define gq_IAPI gq_CONFIG_MARKER_IAPI_IMPORT
    #define gq_VAR gq_CONFIG_MARKER_VAR_IMPORT
    #define gq_IVAR gq_CONFIG_MARKER_IVAR_IMPORT
    #define gq_CLASS gq_CONFIG_MARKER_CLS_IMPORT
    #define gq_ICLASS gq_CONFIG_MARKER_ICLS_IMPORT
#endif

#if gq_CONFIG_INLINEIMPL
    #define gq_FIMPL inline
    #define gq_VIMPL gq_INLINEVAR_
#else
    #define gq_FIMPL
    #define gq_VIMPL
#endif


//
// [[ PREPROCESSOR DEBUGGING ]]
//

#ifdef gl__MACRODEBUG
#	pragma message gq_STRFY_(gq_API) ": " gq_STRFY(gq_API)
#	pragma message gq_STRFY_(gq_IAPI) ": " gq_STRFY(gq_IAPI)
#	pragma message gq_STRFY_(gq_FIMPL) ": " gq_STRFY(gq_FIMPL)
#	pragma message gq_STRFY_(gq_VAR) ": " gq_STRFY(gq_VAR)
#	pragma message gq_STRFY_(gq_IVAR) ": " gq_STRFY(gq_IVAR)
#	pragma message gq_STRFY_(gq_VIMPL) ": " gq_STRFY(gq_VIMPL)
#	pragma message gq_STRFY_(gq_CLASS) ": " gq_STRFY(gq_CLASS)
#	pragma message gq_STRFY_(gq_ICLASS) ": " gq_STRFY(gq_ICLASS)
#endif

#else

/*
platform = <compiler>[_<os>]
build = <platform>-<arch>-<variant> # e.g. gcc_linux-x86-debug
*/

//
// [[ COMPILER-FLAG-ONLY DEFINITIONS ]]
//

#define gq__BUILDING_DOCS
#define gq__BUILDING

// Independent build mode flags
#define gq__DEBUG /**< Activates debug mode (e.g. additional logging, more descriptive messages, keeping extra debug data). */
#define gq__PROFILE /**< Activates profiling functionality (e.g. extra time measurement, introduction of code probes). */
#define gq__STRIPPED /**< Strips any extra data that is not required for proper library operation. Should not be activated if debugging. */
#define gq__INLINEIMPL

// Mutually-exclusive artifact types
#define gq__STATIC
#define gq__SHARED
#define gq__EXECUTABLE
#define gq__HEADERONLY


//
// [[ ABI CUSTOMIZATION OPTIONS ]]
//

#define gq_CONFIG_ROOT_NAMESPACE_NAME
#define gq_CONFIG_ABI_NAMESPACE_PREFIX
#define gq_CONFIG_ABI_NAMESPACE_NAME

#define gq_CONFIG_NAME_STR
#define gq_CONFIG_VERSION_STR


//
// [[ COMPILING OPTIONS ]]
//

#define gq_CONFIG_BUILD_NAME

#define gq_CONFIG_DEBUG
#define gq_CONFIG_PROFILE
#define gq_CONFIG_STRIPPED
#define gq_CONFIG_BUILDING
#define gq_CONFIG_BINTYPE


//
// [[ CORE FEATURE DETECTION ]]
//

#define gq_CONFIG_LANG_DETECTED
#define gq_CONFIG_COMPILER_DETECTED
#define gq_CONFIG_OS_DETECTED
#define gq_CONFIG_ARCH_DETECTED

#define gq_CONFIG_COMPILER_IS_GCC_LIKE


//
// [[ CONFIGURATION-DEFINED MACROS ]]
//

#define gq_INLINEVAR_
#define gq_EXTERN_C
#define gq_BEGIN_EXTERN_C
#define gq_END_EXTERN_C



//
// [[ LIBRARY INTERFACE MARKERS ]]
//

#define gq_BEGIN_CODE
#define gq_END_CODE

#define gq_API    /**< Public function declaration marker. */
#define gq_IAPI   /**< Library-Internal function declaration marker. */
#define gq_FIMPL  /**< Public function definition marker, not to be used with default-inlined members (e.g. constexpr, header-only inline) */

#define gq_VAR    /**< Public global variable declaration marker. */
#define gq_IVAR   /**< Library-Internal Variable declaration marker. */
#define gq_VIMPL  /**< Public global variable definition marker (for C++17's inline variables, same usage as `gq_FIMPL`). */

#define gq_CLASS  /**< Public class definition marker. */
#define gq_ICLASS /**< Library-Internal class definition marker. */

#endif

#endif // gq_def_hpp__
