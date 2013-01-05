#include <node.h>
#include "wrapped_elephant.h"
#include "../inc/MH3/MurmurHash3.h"

using namespace v8;


Handle<Value> murmur32(const Arguments& args) {
    HandleScope scope;
    uint32_t out;

    String::Utf8Value key(args[0]->ToString());

    MurmurHash3_x86_32(reinterpret_cast<const char *> (*key), (int) key.length(), &out);

    return scope.Close(Integer::New(out));
}

void InitAll(Handle<Object> target) {
	MyObject::Init(target);
	NODE_SET_METHOD(target, "mh3", murmur32);
}

NODE_MODULE(elephant, InitAll)