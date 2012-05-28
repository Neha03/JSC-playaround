#include <JavaScriptCore/JavaScript.h>
#include "Test.h"
#include "Testjsc.h"
#include "stdlib.h"
#include<iostream>
using namespace std;

// JSTest class implementation
JSStaticValue JSCircle_Values[] = {
    { 0, 0, 0, 0 }
};

JSStaticFunction JSCircle_Functions[] = {
	{ "area", JSCircle_area, kJSPropertyAttributeDontDelete },
 { 0, 0, 0 }
};
JSClassRef JSCircle_GetJSClass(JSContextRef context)
{
	static JSClassRef jsClass = NULL;
	if (!jsClass)
	{
		JSClassDefinition definition	= kJSClassDefinitionEmpty;
		definition.staticValues		= JSCircle_Values;
		definition.staticFunctions	= JSCircle_Functions;
		jsClass = JSClassCreate(&definition);
	}
	return jsClass;
}

JSObjectRef JSCircle_ObjectCreate(JSContextRef context, JSObjectRef object, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    cout<<"JSCircle_ObjectCreate called" <<endl;
    return JSObjectMake(context, JSCircle_GetJSClass(context), new Circle());
}

bool JSCircle_DeclareClass(JSGlobalContextRef& context, JSObjectRef& p_rParentObject, const char* p_szClassName)
{
        cout<<"JSCircle_DeclareClass called" <<endl;
	JSStringRef	propertyname = JSStringCreateWithUTF8CString(p_szClassName);
	JSObjectSetProperty(
			context, 
			p_rParentObject, 
			propertyname,
			JSObjectMakeConstructor(
				context, 
				JSCircle_GetJSClass(context), 
				JSCircle_ObjectCreate), 
			kJSPropertyAttributeNone, 
			NULL);
	JSStringRelease(propertyname);

	return true;
}
JSValueRef JSCircle_area(JSContextRef context, JSObjectRef function, JSObjectRef thisObject,
			          size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{

    if (!JSValueIsObjectOfClass(context, thisObject, JSCircle_GetJSClass(context))) {
        JSStringRef message = JSStringCreateWithUTF8CString("TypeError: Call on invalid object");
        *exception = JSValueMakeString(context, message);
        JSStringRelease(message);
    }
    cout<<"JSCircle called\n";
    Circle* c = (Circle*)JSObjectGetPrivate(thisObject);
	int result = c->area(JSValueToNumber(context, arguments[0], NULL));
    return JSValueMakeNumber(context, result);
}


