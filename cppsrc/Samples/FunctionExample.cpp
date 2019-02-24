#include "FunctionExample.h"

std::string FunctionExample::Hello()
{
    return "Hello World";
}

Napi::String FunctionExample::HelloWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, FunctionExample::Hello());
    return returnValue;
}

Napi::Object FunctionExample::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("Hello", Napi::Function::New(env, FunctionExample::HelloWrapped));
    return exports;
}
