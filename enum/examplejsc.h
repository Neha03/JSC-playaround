

bool cconst_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* constclassname);

JSValueRef RED_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef BLUE_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef GREEN_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);



bool Foo_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* className);
JSClassRef Foo_createJSClass(JSContextRef context);
JSObjectRef Foo_createcppObject(JSContextRef context, JSObjectRef thisObject, size_t argc, const JSValueRef argv[],
JSValueRef* exception);

JSValueRef Foo_IMPULSE_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef Foo_WARP_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef Foo_LUDICROUS_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);



