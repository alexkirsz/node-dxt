#include <node_buffer.h>
#include "squish/squish.h"

using namespace v8;
using namespace node;

Handle<Value> dxt_decompress(const Arguments &args) {
  HandleScope scope;

  Handle<Object> input_buffer = args[0]->ToObject();
  int width = args[1]->Int32Value();
  int height = args[2]->Int32Value();
  int flags = args[3]->Int32Value();

  int output_len = width * height * 4;
  Buffer *output_buffer = Buffer::New(output_len);

  squish::u8 *input = (squish::u8*) Buffer::Data(input_buffer);
  squish::u8 *output = (squish::u8*) Buffer::Data(output_buffer);

  squish::DecompressImage(output, width, height, input, flags);

  return scope.Close(output_buffer->handle_);
}

Handle<Value> dxt_compress(const Arguments &args) {
  HandleScope scope;

  Handle<Object> input_buffer = args[0]->ToObject();
  int width = args[1]->Int32Value();
  int height = args[2]->Int32Value();
  int flags = args[3]->Int32Value();

  int output_len = squish::GetStorageRequirements(width, height, flags);
  Buffer *output_buffer = Buffer::New(output_len);

  squish::u8 *input = (squish::u8*) Buffer::Data(input_buffer);
  squish::u8 *output = (squish::u8*) Buffer::Data(output_buffer);

  squish::CompressImage(input, width, height, output, flags);

  return scope.Close(output_buffer->handle_);
}

void init (Handle<Object> exports) {
  HandleScope scope;
  exports->Set(String::New("decompress"), FunctionTemplate::New(dxt_decompress)->GetFunction());
  exports->Set(String::New("compress"), FunctionTemplate::New(dxt_compress)->GetFunction());
}
NODE_MODULE(dxt, init)
