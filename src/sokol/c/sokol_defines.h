#define SOKOL_ZIG_BINDINGS
#define SOKOL_NO_ENTRY
#if !(defined(SOKOL_GLCORE33) || defined(SOKOL_GLES2) || defined(SOKOL_GLES3) || defined(SOKOL_D3D11) || defined(SOKOL_METAL) || defined(SOKOL_WGPU) || defined(SOKOL_DUMMY_BACKEND))
    #if defined(_WIN32)
        #define SOKOL_WIN32_FORCE_MAIN
        #define SOKOL_D3D11
        #define SOKOL_LOG(msg) OutputDebugStringA(msg)
    #elif defined(__APPLE__)
        #define SOKOL_METAL
    #else
        #define SOKOL_GLCORE33
    #endif
#endif
// FIXME: macOS Zig HACK without this, some C stdlib headers throw errors
#if defined(__APPLE__)
#include <TargetConditionals.h>
#endif
