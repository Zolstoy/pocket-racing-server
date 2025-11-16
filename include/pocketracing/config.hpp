#pragma once

#define POCKETRACING_VERSION_MAJOR 0
#define POCKETRACING_VERSION_MINOR 1
#define POCKETRACING_VERSION_PATCH 0

#if defined(_WIN32)
# define POCKETRACING_SYSTEM_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
# define POCKETRACING_SYSTEM_MACOS
#elif defined(__unix__)
# define POCKETRACING_SYSTEM_UNIX
#else
# error This operating system is not supported by POCKETRACING library
#endif

#if !defined(POCKETRACING_STATIC)
# if defined(POCKETRACING_SYSTEM_WINDOWS)
#  define POCKETRACING_API_EXPORT __declspec(dllexport)
#  define POCKETRACING_API_IMPORT __declspec(dllimport)
# else
#  define POCKETRACING_API_EXPORT __attribute__((__visibility__("default")))
#  define POCKETRACING_API_IMPORT __attribute__((__visibility__("default")))
# endif
#else
# define POCKETRACING_API_EXPORT
# define POCKETRACING_API_IMPORT
#endif

#if !defined(POCKETRACING_STATIC)
# if defined(POCKETRACING_BUILDING_THE_LIB)
#  define POCKETRACING_API POCKETRACING_API_EXPORT
# else
#  define POCKETRACING_API POCKETRACING_API_IMPORT
# endif
#else
# define POCKETRACING_API
#endif
