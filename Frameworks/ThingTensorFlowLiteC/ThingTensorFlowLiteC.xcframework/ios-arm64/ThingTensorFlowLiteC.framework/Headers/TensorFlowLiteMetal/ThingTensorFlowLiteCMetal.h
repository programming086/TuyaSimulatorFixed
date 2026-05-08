#ifndef __THING_TENSORFLOW_LITE_C_METAL_H__
#define __THING_TENSORFLOW_LITE_C_METAL_H__

#include <stddef.h>  // For NULL

// This header provides Metal GPU delegate support for ThingTensorFlowLiteC
// Only include this header when using the Metal subspec

// Include the main ThingTensorFlowLiteC header first
#include <ThingTensorFlowLiteC/TensorFlowLite/ThingTensorFlowLiteC.h>

// Metal GPU delegate support (only available when Metal subspec is included)
#ifdef TFLITE_GPU_BINARY_RELEASE

// Forward declarations to avoid including Metal headers in C++ contexts
#ifdef __OBJC__
// When compiling as Objective-C++, include the full Metal delegate header
#include <ThingTensorFlowLiteC/TensorFlowLiteMetal/metal_delegate.h>
#define THING_TFLITE_METAL_AVAILABLE 1
#else
// When compiling as pure C++, only provide forward declarations
struct TfLiteDelegate;
typedef struct {
  bool allow_precision_loss;
  int wait_type;  // TFLGpuDelegateWaitType
  bool enable_quantization;
} TFLGpuDelegateOptions;

#define THING_TFLITE_METAL_AVAILABLE 1
#endif // __OBJC__

#ifdef __cplusplus
extern "C" {
#endif

// Convenience functions for Metal delegate
bool ThingTFLiteIsMetalAvailable(void);
TfLiteDelegate* ThingTFLiteCreateMetalDelegate(const TFLGpuDelegateOptions* options);
void ThingTFLiteDeleteMetalDelegate(TfLiteDelegate* delegate);

#ifdef __cplusplus
}
#endif

#else
// When Metal subspec is not included, provide stub implementations
#ifdef __cplusplus
extern "C" {
#endif

// Stub functions when Metal is not available
static inline bool ThingTFLiteIsMetalAvailable(void) { return false; }
static inline void* ThingTFLiteCreateMetalDelegate(const void* options) { 
    (void)options; // Suppress unused parameter warning
    return NULL; 
}
static inline void ThingTFLiteDeleteMetalDelegate(void* delegate) { 
    (void)delegate; // Suppress unused parameter warning
    /* no-op */ 
}

#ifdef __cplusplus
}
#endif

#endif // TFLITE_GPU_BINARY_RELEASE

#endif // __THING_TENSORFLOW_LITE_C_METAL_H__
