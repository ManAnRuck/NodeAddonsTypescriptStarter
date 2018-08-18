#include "functionexample.h"

std::string functionexample::Hello()
{
    return "Hello World";
}

Napi::String functionexample::HelloWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, functionexample::Hello());
    return returnValue;
}

Napi::Object functionexample::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("Hello", Napi::Function::New(env, functionexample::HelloWrapped));
    return exports;
}