#include <nan.h>
#include "dxt.h"  // NOLINT(build/include)
#include <node_buffer.h>
#include "squish/squish.h"
using namespace v8;
using namespace node;
using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using Nan::GetFunction;
using Nan::New;

NAN_METHOD(dxt_decompress) {
  Nan::EscapableHandleScope scope;
  Local<Object> input_buffer = info[0]->ToObject();
  int width = info[1]->Int32Value();
  int height = info[2]->Int32Value();
  int flags = info[3]->Int32Value();

  int output_len = width * height * 4;
  Nan::MaybeLocal<Object> output_buffer = Nan::NewBuffer(output_len);

  squish::u8 *input = (squish::u8*) Buffer::Data(input_buffer);
  squish::u8 *output = (squish::u8*) Buffer::Data(output_buffer.ToLocalChecked());

  squish::DecompressImage(output, width, height, input, flags);

  info.GetReturnValue().Set(scope.Escape(output_buffer.ToLocalChecked()));
}

NAN_METHOD(dxt_compress) {
  Nan::EscapableHandleScope scope;

  Local<Object> input_buffer = info[0]->ToObject();
  int width = info[1]->Int32Value();
  int height = info[2]->Int32Value();
  int flags = info[3]->Int32Value();

  int output_len = squish::GetStorageRequirements(width, height, flags);
  Nan::MaybeLocal<Object> output_buffer = Nan::NewBuffer(output_len);

  squish::u8 *input = (squish::u8*) Buffer::Data(input_buffer);
  squish::u8 *output = (squish::u8*) Buffer::Data(output_buffer.ToLocalChecked());

  squish::CompressImage(input, width, height, output, flags);

  info.GetReturnValue().Set(scope.Escape(output_buffer.ToLocalChecked()));
}

NAN_MODULE_INIT(InitAll) {

  Nan::Set(target, Nan::New<String>("decompress").ToLocalChecked(),
    Nan::GetFunction(New<FunctionTemplate>(dxt_decompress)).ToLocalChecked());

  Nan::Set(target, Nan::New<String>("compress").ToLocalChecked(),
    Nan::GetFunction(New<FunctionTemplate>(dxt_compress)).ToLocalChecked());
}

NODE_MODULE(dxt, InitAll)
