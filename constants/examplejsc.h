
bool cconst_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* constclassname);

JSValueRef ICONST_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef FCONST_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef CCONST_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef CCONST2_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef SCONST_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef SCONST2_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef EXPR_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef iconst_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);
JSValueRef fconst_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);

