#include <node.h>
#include <cmath>

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
    int len = args[0].As<Number>()->Value() + 2 ;
    long double pi = 1;  
    long double step = 0;
    int count = 1;
    int r = 5000;
    long double last = 20;
    while ( abs(last - step) * pow(10, len) > 1 ) {
        int v1 = rand() %  r ;
        int v2 = rand() %  r ;
        if (v2*v2 + v1*v1 <= r*r) {
            pi += 1;
            last = step;
            step = pi / count * 4;
        }
        count++;
    }

    Local<Number> num = Number::New(isolate, step);
    args.GetReturnValue().Set(num);
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "pi", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace demo