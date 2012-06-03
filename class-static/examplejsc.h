#include <JavaScriptCore/JavaScript.h>

bool JSFoo_DeclareClass(JSGlobalContextRef& p_rContext, JSObjectRef& p_rParentObject, 
								const char* p_szClassName);

JSValueRef JSFoo_display(JSContextRef context, JSObjectRef function, JSObjectRef thisObject,
	          size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

JSValueRef JSFoo_printMe(JSContextRef context, JSObjectRef function, JSObjectRef thisObject,
						  size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

JSValueRef JSFoo_setMe(JSContextRef context, JSObjectRef function, JSObjectRef thisObject,
						size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

JSValueRef JSFoo_helloString(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception);





