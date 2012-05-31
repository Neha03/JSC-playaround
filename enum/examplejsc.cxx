#include <JavaScriptCore/JavaScript.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "examplejsc.h"
#include "example.h"
#include<iostream>
using namespace std;

JSStaticValue cconst_staticValues[] = {
    {"RED",RED_get, NULL, kJSPropertyAttributeNone },
    {"BLUE",BLUE_get, NULL, kJSPropertyAttributeNone },
    {"GREEN",GREEN_get, NULL, kJSPropertyAttributeNone },
    {"Foo_IMPULSE",Foo_IMPULSE_get, NULL, kJSPropertyAttributeNone },
    {"Foo_WARP",Foo_WARP_get, NULL, kJSPropertyAttributeNone },
    {"Foo_LUDICROUS",Foo_LUDICROUS_get, NULL, kJSPropertyAttributeNone },

    { 0, 0, 0, 0 }
};

JSClassRef cconst_createJSClass(JSContextRef context)
{
        cout<<"cconst_createJSClass called"<<endl;
	static JSClassRef jsClass = NULL;
	if (!jsClass)
	{
		JSClassDefinition definition	= kJSClassDefinitionEmpty;
		definition.staticValues			= cconst_staticValues;
		jsClass 						= JSClassCreate(&definition);
	}
	return jsClass;
}

bool cconst_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* constclassname)
{
    cout<<"cconst_initClass called" << endl;
    JSStringRef jsstring = JSStringCreateWithUTF8CString(constclassname);
    static JSObjectRef cconstclassObject = JSObjectMake(context, cconst_createJSClass(context), NULL);
    JSObjectSetProperty(
		context,
	    parentObject,
	    jsstring,
	    cconstclassObject,
	    kJSPropertyAttributeNone,
	    NULL);
    JSStringRelease(jsstring);
    return true;
} 

JSValueRef RED_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"RED_get called"<< endl;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, RED); 
    return jsresult;
}
JSValueRef BLUE_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"BLUE_get called"<< endl;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, BLUE); 
    return jsresult;
}
JSValueRef GREEN_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"GREEN_get called"<< endl;;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, GREEN); 
    return jsresult;
}

JSStaticValue Foo_staticValues[] = {

    { 0, 0, 0, 0 }
};

JSStaticFunction Foo_staticFunctions[] = {

    { 0, 0, 0 }
};



JSClassRef Foo_createJSClass(JSContextRef context)
{
  cout<<"FOO_createJSClass called"<<endl;
  static JSClassRef jsClass = NULL;
  if (!jsClass)
  {
    JSClassDefinition definition	= kJSClassDefinitionEmpty;
    definition.staticValues			= Foo_staticValues;
    definition.staticFunctions		= Foo_staticFunctions;
    jsClass 						= JSClassCreate(&definition);
  }
  return jsClass;
}

JSObjectRef Foo_createcppObject(JSContextRef context, JSObjectRef thisObject, size_t argc, const JSValueRef argv[],
  JSValueRef* exception)
{
  cout<<"FOO_createcppObject called" << endl;
  JSObjectRef jsresult;	
  Foo * result = 0;
  if (argc == 0) {
    result = (Foo *)new Foo();

}

 jsresult = JSObjectMake(context, Foo_createJSClass(context), new Foo());
  return jsresult;
}

bool Foo_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* className)
{
  cout<<"FOO_initClass called"<< endl;
  JSStringRef jsstring = JSStringCreateWithUTF8CString(className);
  JSObjectSetProperty(context, parentObject, jsstring, 
    JSObjectMakeConstructor(context,
      Foo_createJSClass(context),
      Foo_createcppObject), 
    kJSPropertyAttributeNone, 
    NULL);
  JSStringRelease(jsstring);
  return true;
} 

JSValueRef Foo_IMPULSE_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"Foo_IMPULSE_get called"<<endl;
    JSValueRef jsresult;
    jsresult = JSValueMakeNumber(context, Foo::IMPULSE); 
    return jsresult;
}
JSValueRef Foo_WARP_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"Foo_WARP_get called"<<endl;
    JSValueRef jsresult;
    jsresult = JSValueMakeNumber(context, Foo::WARP); 
    return jsresult;
}
JSValueRef Foo_LUDICROUS_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"Foo_LUDICROUS_get called"<<endl;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, Foo::LUDICROUS); 
    return jsresult;
}






