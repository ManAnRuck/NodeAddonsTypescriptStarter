#include <napi.h>

namespace Primes
{
    bool IsPrime(int p);
    int Prime(napi_env env, int n);
    Napi::Number PrimeWrapped(const Napi::CallbackInfo& info);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
}