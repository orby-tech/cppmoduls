#include <node.h>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;
void Method(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    double count = args[0].As<Number>()->Value() * 10000;
    int pi = 0;  
    int r = 5000;
    for ( int i = 0; i < count; i++ ) {
        int v1 = rand() % ( r ) ;
        int v2 = rand() % ( r ) ;
        if (v2*v2 + v1*v1 <= r*r) {
            pi += 1;
        }
    };
    double step = pi / count * 4;
    Local<Number> num = Number::New(isolate, step);
    args.GetReturnValue().Set(num);
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "pi", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace demo