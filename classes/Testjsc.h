bool JSCircle_DeclareClass(JSGlobalContextRef& p_rContext, JSObjectRef& p_rParentObject, 
								const char* p_szClassName);

JSValueRef JSCircle_area(JSContextRef context, JSObjectRef function, JSObjectRef thisObject,
	          size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

