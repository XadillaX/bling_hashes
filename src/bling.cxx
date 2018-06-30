/*
 * =====================================================================================
 *
 *       Filename:  bling.cxx
 *
 *    Description:  Bling Hashes Native Impl
 *
 *        Version:  1.0
 *        Created:  2015/09/11 11时11分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  XadillaX <i@2333.moe>
 *   Organization:  Souche.com
 *
 * =====================================================================================
 */
#include <nan.h>
#include "byvoid/entry.h"
#include "cityhash/entry.h"
#include <string.h>

using Nan::Set;
using Nan::New;
using Nan::GetFunction;
using v8::FunctionTemplate;
using v8::String;

NAN_MODULE_INIT(InitAll)
{
    // BYVoid hashes
    Set(target, New<String>("calcHash").ToLocalChecked(),
            GetFunction(New<FunctionTemplate>(CalcHash)).ToLocalChecked());

    // City hashes
    Set(target, New<String>("cityHash32").ToLocalChecked(),
            GetFunction(New<FunctionTemplate>(_CityHash32)).ToLocalChecked());
    Set(target, New<String>("cityHash64").ToLocalChecked(),
            GetFunction(New<FunctionTemplate>(_CityHash64)).ToLocalChecked());
    Set(target, New<String>("cityHash128").ToLocalChecked(),
            GetFunction(New<FunctionTemplate>(_CityHash128)).ToLocalChecked());
}

NODE_MODULE(bling, InitAll)
