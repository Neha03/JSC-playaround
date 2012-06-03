#include "example.h"
#include "examplejsc.h"
#include "stdlib.h"

// JSFoo class implementation
JSStaticValue JSFoo_Values[] = {
    { 0, 0, 0, 0 }
};

JSStaticFunction JSFoo_Functions[] = {
	{ "display", JSFoo_display, kJSPropertyAttributeDontDelete },
    { "printMe", JSFoo_printMe, kJSPropertyAttributeDontDelete },
    { "setMe", JSFoo_setMe, kJSPropertyAttributeDontDelete },
    { "helloString", JSFoo_helloString, kJSPropertyAttributeDontDelete },
    { 0, 0, 0 }
};

void JSFoo_ObjectConstructor(JSContextRef context, JSObjectRef object)
{
	Foo* t = (Foo*)JSObjectGetPrivate(object);
}

void JSFoo_ObjectDestructor(JSObjectRef object)
{
	Foo* t = (Foo*)JSObjectGetPrivate(object);
}

JSClassRef JSFoo_GetJSClass(JSContextRef context)
{
cout<<"JSFoo_Class called"<<endl;
	static JSClassRef jsClass = NULL;
	if (!jsClass)
	{
		JSClassDefinition definition	= kJSClassDefinitionEmpty;
		definition.staticValues		= JSFoo_Values;
		definition.staticFunctions	= JSFoo_Functions;
		definition.initialize		= JSFoo_ObjectConstructor;
		definition.finalize		= JSFoo_ObjectDestructor;
		jsClass = JSClassCreate(&definition);
	}
	return jsClass;
}

JSObjectRef JSFoo_ObjectCreate(JSContextRef context, JSObjectRef object, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    return JSObjectMake(context, JSFoo_GetJSClass(context), new Foo());
}

bool JSFoo_DeclareClass(JSGlobalContextRef& context, JSObjectRef& p_rParentObject, const char* p_szClassName)
{
cout<<"JSFoo_DeclareClass called"<<endl;
	JSStringRef	propertyname = JSStringCreateWithUTF8CString(p_szClassName);
	JSObjectSetProperty(
			context, 
			p_rParentObject, 
			propertyname,
			JSObjectMakeConstructor(
				context, 
				JSFoo_GetJSClass(context), 
				JSFoo_ObjectCreate), 
			kJSPropertyAttributeNone, 
			NULL);
	JSStringRelease(propertyname);

	return true;
}

JSValueRef JSFoo_printMe(JSContextRef context, JSObjectRef function, JSObjectRef thisObject,
						  size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    cout<<"JSFoo_ static function printMe called\n";
	Foo* obj = (Foo*)JSObjectGetPrivate(thisObject);
	obj->printMe();
    return JSValueMakeUndefined(context);
	
}

JSValueRef JSFoo_setMe(JSContextRef context, JSObjectRef function, JSObjectRef thisObject,
						size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    if (!JSValueIsObjectOfClass(context, thisObject, JSFoo_GetJSClass(context))) {
        JSStringRef message = JSStringCreateWithUTF8CString("TypeError: Call on invalid object");
        *exception = JSValueMakeString(context, message);
        JSStringRelease(message);
    }
    cout<<"JSFoo_ static function setMe called\n";
    Foo* obj = (Foo*)JSObjectGetPrivate(thisObject);
	int arg0 = JSValueToNumber(context, arguments[0], NULL);
    obj->setMe(arg0);
	return JSValueMakeUndefined(context);
}

JSValueRef JSFoo_display(JSContextRef context, JSObjectRef function, JSObjectRef thisObject,
			          size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    cout<<"JSFoo_display called\n";
    if (!JSValueIsObjectOfClass(context, thisObject, JSFoo_GetJSClass(context))) {
        JSStringRef message = JSStringCreateWithUTF8CString("TypeError: Call on invalid object");
        *exception = JSValueMakeString(context, message);
        JSStringRelease(message);
    }
	JSValueRef jsresult;
    Foo* obj = (Foo*)JSObjectGetPrivate(thisObject);
	JSStringRef arg0_str = JSValueToStringCopy(context, arguments[0], NULL);
	size_t arg0_size = JSStringGetMaximumUTF8CStringSize(arg0_str);
	char *arg0 = (char *)malloc(arg0_size * sizeof(arg0));
	JSStringGetUTF8CString(arg0_str, arg0, arg0_size);
	char *result = obj->display(arg0);
	free(arg0);
    JSStringRef	jscorestring = JSStringCreateWithUTF8CString(result);
	jsresult = JSValueMakeString(context, jscorestring);
	JSStringRelease(jscorestring);
    return jsresult;
}

JSValueRef JSFoo_helloString(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception)
{
        
	JSValueRef jsresult;
    string arg1;
	Foo* obj = (Foo*)JSObjectGetPrivate(thisObject);
	cout<<"JSFoo_helloString called\n";

	JSStringRef arg0_str = JSValueToStringCopy(context, argv[0], NULL);
	size_t arg0_size = JSStringGetMaximumUTF8CStringSize(arg0_str);
	char *arg0 = (char *)malloc(arg0_size * sizeof(arg0));
	JSStringGetUTF8CString(arg0_str, arg0, arg0_size);
	arg1 = arg0;
	string result = obj->helloString(arg1);
	free(arg0);
    JSStringRef	jscorestring = JSStringCreateWithUTF8CString(result.c_str());
	jsresult = JSValueMakeString(context, jscorestring);
	JSStringRelease(jscorestring);
    return jsresult;	
}



