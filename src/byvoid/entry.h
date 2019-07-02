/*
 * =====================================================================================
 *
 *       Filename:  entry.h
 *
 *    Description:  Byvoid algorithms entry.
 *
 *        Version:  1.0
 *        Created:  2015/11/22 15时49分49秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  XadillaX <zhukaidi@souche.com>
 *   Organization:  Souche.com
 *
 * =====================================================================================
 */
#ifndef __BYVOID_ENTRY_H__
#define __BYVOID_ENTRY_H__

#include "algorithms.h"
#include "../common.h"

using v8::String;

void ToUpperCase(std::string& str)
{
    for(unsigned int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

NAN_METHOD(CalcHash)
{
    CURRENT_CONTEXT(ctx);

    // argument length...
    if(info.Length() < 2)
    {
        return Nan::ThrowError("invalid argument count");
    }

    Nan::Utf8String v8_algorithm_type(info[0]->ToString(ctx).ToLocalChecked());
    Nan::Utf8String v8_string(info[1]->ToString(ctx).ToLocalChecked());

    // type to uppercase
    std::string algorithm_type = *v8_algorithm_type;
    ToUpperCase(algorithm_type);

    ByvoidHashFunc func = BKDRHash;
    if(algorithm_type == "SDBM") func = SDBMHash;
    else
    if(algorithm_type == "RS") func = RSHash;
    else
    if(algorithm_type == "JS") func = JSHash;
    else
    if(algorithm_type == "PJW") func = PJWHash;
    else
    if(algorithm_type == "ELF") func = ELFHash;
    else
    if(algorithm_type == "BKDR") func = BKDRHash;
    else
    if(algorithm_type == "DJB") func = DJBHash;
    else
    if(algorithm_type == "AP") func = APHash;

    unsigned int hash = func(*v8_string);

    info.GetReturnValue().Set(hash);
}

#endif
