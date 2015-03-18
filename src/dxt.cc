#include <node_buffer.h>
#include "squish/squish.h"

using namespace v8;
using namespace node;

void dxt_decompress(const FunctionCallbackInfo<Value> &args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  Handle<Object> input_buffer = args[0]->ToObject();
  int width = args[1]->Int32Value();
  int height = args[2]->Int32Value();
  int flags = args[3]->Int32Value();

  int output_len = width * height * 4;
  v8::Local<v8::Object> output_buffer = Buffer::New(isolate, output_len);

  squish::u8 *input = (squish::u8*) Buffer::Data(input_buffer);
  squish::u8 *output = (squish::u8*) Buffer::Data(output_buffer);

  squish::DecompressImage(output, width, height, input, flags);

  args.GetReturnValue().Set(output_buffer);
}
void dxt_compress(const FunctionCallbackInfo<Value> &args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  Handle<Object> input_buffer = args[0]->ToObject();
  int width = args[1]->Int32Value();
  int height = args[2]->Int32Value();
  int flags = args[3]->Int32Value();

  int output_len = squish::GetStorageRequirements(width, height, flags);
  v8::Local<v8::Object> output_buffer = Buffer::New(isolate, output_len);

  squish::u8 *input = (squish::u8*) Buffer::Data(input_buffer);
  squish::u8 *output = (squish::u8*) Buffer::Data(output_buffer);

  squish::CompressImage(input, width, height, output, flags);

  args.GetReturnValue().Set(output_buffer);
}

void InitAll (Handle<Object> exports) {
  NODE_SET_METHOD(exports, "decompress", dxt_decompress);
  NODE_SET_METHOD(exports, "compress", dxt_compress);
}
NODE_MODULE(dxt, InitAll)
