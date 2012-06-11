#include <JavaScriptCore/JavaScript.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
#include "examplejsc.h"
extern double x;

bool jsc_Foo_x_set(JSContextRef context, JSObjectRef globalobj, JSStringRef propertyName, JSValueRef value, 
  JSValueRef* exception)
{
  cout<<"jsc_Foo_x_set function called"<<endl;
  JSValueRef jscresult;
  double arg1 = (double)JSValueToNumber(context, value, NULL); 
  x = arg1;
  jscresult = JSValueMakeUndefined(context); 
  return jscresult;
}

JSValueRef jsc_Foo_x_get(JSContextRef context, JSObjectRef globalobj, JSStringRef propertyName, JSValueRef* exception)
{
  cout<<"jsc_Foo_x_get function called"<<endl;
  JSValueRef jscresult;
  double result = (double)x;
  jscresult = JSValueMakeNumber(context, result); 
  return jscresult;
}


JSStaticValue Foo_staticValues[] = {
    {"x",jsc_Foo_x_get,jsc_Foo_x_set, kJSPropertyAttributeNone },
    { 0, 0, 0, 0 }
};

JSClassRef Foo_createJSClass(JSContextRef context)
{
  	cout<<"Foo_createJSClass called"<<endl;
	static JSClassRef jsClass = NULL;
	if (!jsClass)
	{
		JSClassDefinition definition	= kJSClassDefinitionEmpty;
		definition.staticValues			= Foo_staticValues;
		jsClass							= JSClassCreate(&definition);
	}
	return jsClass;
}

bool Foo_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* globalvarsclassname)
{
    cout<<"Foo_initClass called"<<endl;
    JSStringRef jsstring = JSStringCreateWithUTF8CString(globalvarsclassname);
    static JSObjectRef globalvarsclassObject = JSObjectMake(context, Foo_createJSClass(context), NULL);
    JSObjectSetProperty(
		context,
	    parentObject,
	    jsstring,
	    globalvarsclassObject,
	    kJSPropertyAttributeNone,
	    NULL);
   JSStringRelease(jsstring);
   return true;
} 



