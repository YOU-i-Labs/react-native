#include <cstdio>

// We discovered that some functions in ReactNative are not implemented when
// cross compiling to other platform other than OSX/iOS/tvOS. For now, we define
// stubs for these functions.

#ifndef __APPLE__

#include <functional>

// forward declarations and type definitions
namespace facebook { namespace react { class IInspector; } }
typedef struct OpaqueJSContext* JSGlobalContextRef;
typedef const struct OpaqueJSContext* JSContextRef;
typedef const struct OpaqueJSValue* JSValueRef;

// stub definitions
extern "C"
{

facebook::react::IInspector* JSInspectorGetInstance() { return NULL; }
void JSStartSamplingProfilingOnMainJSCThread(JSGlobalContextRef) {}
JSValueRef JSPokeSamplingProfiler(JSContextRef) {return NULL; }

void JSGlobalContextEnableDebugger(JSGlobalContextRef, facebook::react::IInspector &, const char *, const std::function<bool()> &) {}
void JSGlobalContextDisableDebugger(JSGlobalContextRef, facebook::react::IInspector &) {}

} // extern "C"

#endif
