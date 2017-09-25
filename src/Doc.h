#pragma once

#include "CGNSLib.h"
#include <iostream>
#include <string>
#include <vector>
#include <node/node.h>
#include <node/node_object_wrap.h>

using v8::Isolate;

class Doc : public node::ObjectWrap
{
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit Doc(v8::MaybeLocal<v8::String> filePath);
    ~Doc();

    static void New(const v8::FunctionCallbackInfo<v8::Value> &args);
    static void Open(const v8::FunctionCallbackInfo<v8::Value> &args);
    static void Close(const v8::FunctionCallbackInfo<v8::Value> &args);

    void open(v8::Local<v8::String> path);
    void close();

  private:
    int m_handler;
    Isolate *m_isolate;

    static v8::Persistent<v8::Function> constructor;
};
