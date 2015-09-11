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
#include "algorithms.h"
#include <string.h>

using Nan::Set;
using Nan::New;
using Nan::GetFunction;
using v8::FunctionTemplate;
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
    // argument length...
    if(info.Length() < 2)
    {
        return Nan::ThrowError("invalid argument count");
    }

    String::Utf8Value v8_algorithm_type(info[0]->ToString());
    String::Utf8Value v8_string(info[1]->ToString());

    // type to uppercase
    std::string algorithm_type = *v8_algorithm_type;
    ToUpperCase(algorithm_type);

    HashFunc func = BKDRHash;
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

NAN_MODULE_INIT(InitAll)
{
    Set(target, New<String>("calcHash").ToLocalChecked(),
            GetFunction(New<FunctionTemplate>(CalcHash)).ToLocalChecked());
}

NODE_MODULE(bling, InitAll)
