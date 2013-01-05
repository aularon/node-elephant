#include <node.h>
#include "wrapped_elephant.h"

using namespace v8;

MyObject::MyObject() {};
MyObject::~MyObject() {};

void MyObject::Init(Handle<Object> target) {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Elephant"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("memorize"),
      FunctionTemplate::New(memorize)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("remember"),
      FunctionTemplate::New(remember)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("stats"),
      FunctionTemplate::New(stats)->GetFunction());

  Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
  target->Set(String::NewSymbol("Elephant"), constructor);
}

Handle<Value> MyObject::New(const Arguments& args) {
  HandleScope scope;

  MyObject* obj = new MyObject();
  obj->Wrap(args.This());

  return args.This();
}


Handle<Value> MyObject::memorize(const Arguments& args) {
  HandleScope scope;

  MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.This());

  String::Utf8Value key(args[0]->ToString());
  bool res = obj->e.memorize(reinterpret_cast<char *> (*key));

  return scope.Close(Boolean::New(res));
}
Handle<Value> MyObject::remember(const Arguments& args) {
  HandleScope scope;

  MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.This());

  String::Utf8Value key(args[0]->ToString());
  bool res = obj->e.remember(reinterpret_cast<char *> (*key));

  return scope.Close(Boolean::New(res));
}
Handle<Value> MyObject::stats(const Arguments& args) {
  HandleScope scope;

  MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.This());

  v8::Local<v8::Object> res = Object::New();
  res->Set(String::New("added"), Integer::New(obj->e.get_stats_added()));
  res->Set(String::New("duplicates"), Integer::New(obj->e.get_stats_duplicates()));

  return scope.Close(res);
}