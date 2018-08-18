/* cppsrc/main.cpp */
#include <napi.h>
#include "Samples/FunctionExample.h"
#include "Primes/Primes.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  Primes::Init(env, exports);
  return FunctionExample::Init(env, exports);
}

NODE_API_MODULE(testaddon, InitAll)