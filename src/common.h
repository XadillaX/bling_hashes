#ifndef __COMMON_H__
#define __COMMON_H__

#include <nan.h>

using v8::Isolate;
using v8::Local;
using v8::Context;

#define CURRENT_CONTEXT(ctx) Local<Context> ctx = Nan::GetCurrentContext();

#endif
