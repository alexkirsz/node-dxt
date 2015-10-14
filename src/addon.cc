#include <nan.h>
#include "dxt.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

// Expose synchronous and asynchronous access to our
// Estimate() function
NAN_MODULE_INIT(InitAll) {

  Set(target, New<String>("decompress").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(dxt_decompress)).ToLocalChecked());

  Set(target, New<String>("compress").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(dxt_compress)).ToLocalChecked());
}


NODE_MODULE(addon, InitAll)
