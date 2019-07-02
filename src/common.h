/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  Common header
 *
 *        Version:  1.0
 *        Created:  2019/07/02 14时41分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  XadillaX <i@2333.moe>
 *
 * =====================================================================================
 */
#ifndef __COMMON_H__
#define __COMMON_H__

#include <nan.h>

using v8::Isolate;
using v8::Local;
using v8::Context;

#define CURRENT_CONTEXT(ctx) Local<Context> ctx = Nan::GetCurrentContext();

#endif
