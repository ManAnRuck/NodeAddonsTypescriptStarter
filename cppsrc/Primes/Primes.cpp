#include "Primes.h"
#include <math.h>

bool Primes::IsPrime(int p)
{
    int upper = sqrt(p);
    for (int i = 2; i <= upper; i++)
    {
        if (p % i == 0)
        {
            return false;
        }
    }
    return true;
}

int Primes::Prime(napi_env env, int n)
{
    if (n < 1)
    {
        napi_throw_error(env, nullptr, "n too small");
    }
    int count = 0;
    int result = 1;
    while (count < n)
    {
        result++;
        if (IsPrime(result))
        {
            count++;
        }
    }
    return result;
}

Napi::Number Primes::PrimeWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int number = info[0].ToNumber().Int32Value();
    int res = Primes::Prime(env, number);
    return Napi::Number::New(env, res);
}

Napi::Object Primes::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("Prime", Napi::Function::New(env, Primes::PrimeWrapped));
    return exports;
}
