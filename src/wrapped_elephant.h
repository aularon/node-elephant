#ifndef WRAPPED_ELEPHANT
#define WRAPPED_ELEPHANT

#include <node.h>
#include "../inc/elephant.h"
class MyObject : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> target);

 private:
  MyObject();
  ~MyObject();



  static v8::Handle<v8::Value> New(const v8::Arguments& args);

  static v8::Handle<v8::Value> memorize(const v8::Arguments& args);
  static v8::Handle<v8::Value> remember(const v8::Arguments& args);
  static v8::Handle<v8::Value> stats(const v8::Arguments& args);
  Elephant e;
};


#endif