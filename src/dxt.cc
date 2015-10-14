#include <nan.h>
#include "dxt.h"  // NOLINT(build/include)
#include <node_buffer.h>
#include "squish/squish.h"
using namespace v8;
using namespace node;

NAN_METHOD(dxt_decompress) {
  Nan::HandleScope scope;

  Local<Object> input_buffer = info[0]->ToObject();
  int width = info[1]->Int32Value();
  int height = info[2]->Int32Value();
  int flags = info[3]->Int32Value();

  int output_len = width * height * 4;
  char data[output_len];

  squish::u8 *input = (squish::u8*) Buffer::Data(input_buffer);
  squish::u8 *output = (squish::u8*) data;

  squish::DecompressImage(output, width, height, input, flags);

  MaybeLocal<Object> buffer = Nan::CopyBuffer(data, output_len);
  info.GetReturnValue().Set(buffer.ToLocalChecked());
}

NAN_METHOD(dxt_compress) {
  Nan::HandleScope scope;

  Local<Object> input_buffer = info[0]->ToObject();
  int width = info[1]->Int32Value();
  int height = info[2]->Int32Value();
  int flags = info[3]->Int32Value();

  int output_len = squish::GetStorageRequirements(width, height, flags);
  char data[output_len];

  squish::u8 *input = (squish::u8*) Buffer::Data(input_buffer);
  squish::u8 *output = (squish::u8*) data;

  squish::CompressImage(input, width, height, output, flags);

  MaybeLocal<Object> buffer = Nan::CopyBuffer(data, output_len);
  info.GetReturnValue().Set(buffer.ToLocalChecked());
}

