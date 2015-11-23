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
 *         Author:  XadillaX (ZKD), zhukaidi@souche.com
 *   Organization:  Design & Development Center, Souche Car Service Co., Ltd, HANGZHOU
 *
 * =====================================================================================
 */
#ifndef __CITYHASH_ENTRY_H__
#define __CITYHASH_ENTRY_H__

#include <nan.h>
#include <string>
#include "cityhash.h"

void __CityHash64FreeCallback(char* data, void* hint)
{
    unsigned long long* hash = (unsigned long long*)data;
    delete hash;
}

NAN_METHOD(_CityHash32)
{
    // argument length...
    if(info.Length() < 1)
    {
        return Nan::ThrowError("invalid argument count");
    }

    String::Utf8Value v8_source_string(info[0]->ToString());
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
    // argument length...
    if(info.Length() < 1)
    {
        return Nan::ThrowError("invalid argument count");
    }

    String::Utf8Value v8_source_string(info[0]->ToString());
    std::string source_string = *v8_source_string;
    unsigned int len = source_string.size();

    unsigned long long* hash = new unsigned long long(CityHash64(source_string.c_str(), len));
    // printf("    %llu\n", *hash);
    info.GetReturnValue().Set(
            Nan::NewBuffer(
                (char*)hash,
                sizeof(unsigned long long),
                __CityHash64FreeCallback,
                NULL).ToLocalChecked());
}

#endif
