

bool jsc_Foo_x_set(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef value, 
JSValueRef* exception);

JSValueRef jsc_Foo_x_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);

bool Foo_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* globalvarsclassname);

