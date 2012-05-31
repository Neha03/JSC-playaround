
#include <JavaScriptCore/JavaScript.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "examplejsc.h"
#include<iostream>
using namespace std;

JSStaticValue cconst_staticValues[] = {
    {"ICONST",ICONST_get, NULL, kJSPropertyAttributeNone },
    {"FCONST",FCONST_get, NULL, kJSPropertyAttributeNone },
    {"CCONST",CCONST_get, NULL, kJSPropertyAttributeNone },
    {"CCONST2",CCONST2_get, NULL, kJSPropertyAttributeNone },
    {"SCONST",SCONST_get, NULL, kJSPropertyAttributeNone },
    {"SCONST2",SCONST2_get, NULL, kJSPropertyAttributeNone },
    {"EXPR",EXPR_get, NULL, kJSPropertyAttributeNone },
    {"iconst",iconst_get, NULL, kJSPropertyAttributeNone },
    {"fconst",fconst_get, NULL, kJSPropertyAttributeNone },

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
    cout<<"cconst_initClass called"<<endl;
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

JSValueRef ICONST_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"ICONST_get called"<<endl;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, 42); 
    return jsresult;
}
JSValueRef FCONST_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"FCONST_get called"<<endl;
   JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, 2.1828); 
    return jsresult;
}
JSValueRef CCONST_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"CCONST_get called"<<endl;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, 'x'); 
    return jsresult;
}
JSValueRef CCONST2_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"CCONST2_get called"<<endl;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, '\n'); 
    return jsresult;
}
JSValueRef SCONST_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
  cout<<"SCONST_get called"<<endl;
  JSValueRef jsresult;
  JSStringRef jsstring = JSStringCreateWithUTF8CString("Hello World");
  jsresult = JSValueMakeString(context, jsstring);
  JSStringRelease(jsstring);

    return jsresult;
}
JSValueRef SCONST2_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"SCONST2_get called"<<endl;
    JSValueRef jsresult;
    JSStringRef jsstring = JSStringCreateWithUTF8CString("\"Hello World\"");
  jsresult = JSValueMakeString(context, jsstring);
  JSStringRelease(jsstring);

    return jsresult;
}
JSValueRef EXPR_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"EXPR_get called"<<endl;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, 42+3*(2.1828)); 
    return jsresult;
}
JSValueRef iconst_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"iconst_get called"<<endl;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, 37); 
    return jsresult;
}
JSValueRef fconst_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
    cout<<"fconst_get called"<<endl;
    JSValueRef jsresult;
     jsresult = JSValueMakeNumber(context, 3.14); 
    return jsresult;
}


