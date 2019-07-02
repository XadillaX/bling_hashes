/*
 * =====================================================================================
 *
 *       Filename:  entry.h
 *
 *    Description:  Entry header for cityhash (https://github.com/google/cityhash)
 *
 *        Version:  1.0
 *        Created:  2015/11/22 16时09分57秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  XadillaX (i@2333.moe)
 *
 * =====================================================================================
 */
#ifndef __CITYHASH_ENTRY_H__
#define __CITYHASH_ENTRY_H__

#include <string>
#include "cityhash.h"
#include "../common.h"

void __CityHash64FreeCallback(char* data, void* hint)
{
    uint64* hash = (uint64*)data;
    delete hash;
}

NAN_METHOD(_CityHash32)
{
    CURRENT_CONTEXT(ctx);

    // argument length...
    if(info.Length() < 1)
    {
        return Nan::ThrowError("invalid argument count");
    }

    Nan::Utf8String v8_source_string(info[0]->ToString(ctx).ToLocalChecked());
    std::string source_string = *v8_source_string;
    unsigned int len = source_string.size();

    unsigned int hash = CityHash32(source_string.c_str(), len);

#if NODE_MAJOR_VERSION == 0 && \
    NODE_MINOR_VERSION <= 10
    info.GetReturnValue().Set((double)hash);
#else
    info.GetReturnValue().Set(hash);
#endif
}

NAN_METHOD(_CityHash64)
{
    CURRENT_CONTEXT(ctx);

    // argument length...
    if(info.Length() < 1)
    {
        return Nan::ThrowError("invalid argument count");
    }

    Nan::Utf8String v8_source_string(info[0]->ToString(ctx).ToLocalChecked());
    std::string source_string = *v8_source_string;
    unsigned int len = source_string.size();

    uint64* hash = new uint64(CityHash64(source_string.c_str(), len));
    // printf("    %llu\n", *hash);
    info.GetReturnValue().Set(
            Nan::NewBuffer(
                (char*)hash,
                sizeof(uint64),
                __CityHash64FreeCallback,
                NULL).ToLocalChecked());
}

typedef uint64 (*Extract128Func)(const uint128&);
const Extract128Func Extract128[] = { Uint128Low64, Uint128High64 };

NAN_METHOD(_CityHash128)
{
    CURRENT_CONTEXT(ctx);

    // argument length...
    if(info.Length() < 1)
    {
        return Nan::ThrowError("invalid argument count");
    }

    Nan::Utf8String v8_source_string(info[0]->ToString(ctx).ToLocalChecked());
    std::string source_string = *v8_source_string;
    unsigned int len = source_string.size();

    uint128 hash = CityHash128(source_string.c_str(), len);
    v8::Local<v8::Array> array = Nan::New<v8::Array>();
    for(int i = 0; i < 2; i++)
    {
        uint64* _64 = new uint64(Extract128[i](hash));

        v8::Local<v8::Value> buf = Nan::NewBuffer(
            (char*)_64,
            sizeof(uint64),
            __CityHash64FreeCallback,
            NULL).ToLocalChecked();
        Nan::Set(array, i, buf);
    }

    info.GetReturnValue().Set(array);
}

#endif
