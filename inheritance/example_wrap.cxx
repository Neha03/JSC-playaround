

#include <JavaScriptCore/JavaScript.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;


typedef struct {
	bool swigCMemOwn;
	void *swigCObject;
}SWIG_PRV_DATA; 

#include "example_wrap.h"
#include "example.h"


JSStaticValue Shape_staticValues[] = {
    {"x",Shape_x_get,Shape_x_set,kJSPropertyAttributeNone },
    {"y",Shape_y_get,Shape_y_set,kJSPropertyAttributeNone },

    { 0, 0, 0, 0 }
};

JSStaticFunction Shape_staticFunctions[] = {
    {"move",Shape_move,kJSPropertyAttributeDontDelete },
    {"printMe",Shape_printMe,kJSPropertyAttributeDontDelete },

    { 0, 0, 0 }
};



void Shape_finalize(JSObjectRef thisObject)
{
cout<<" Shape_finalize called"<<endl; 
  SWIG_PRV_DATA* t = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
  if(t && t->swigCMemOwn) delete (Shape*)(t->swigCObject);
  if(t) delete t;
}


bool Shape_x_set(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef value, 
  JSValueRef* exception)
{
cout<<"wrap_shape_X_set called"<<endl;
  JSValueRef jsresult;
  Shape *arg1 = (Shape *) 0 ;
  double arg2 ;
  
  
  // Sanity check if the call is not on the global object
  if (!JSValueIsEqual(context, 
      JSValueToObject(context,thisObject,NULL), 
      JSValueToObject(context,JSContextGetGlobalObject(context), NULL), 
      NULL)) {
    SWIG_PRV_DATA* arg1_swigprivatedata = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
    arg1 = (Shape *)arg1_swigprivatedata->swigCObject; 
  }
  
  arg2 = (double)JSValueToNumber(context, value, NULL); 
  if (arg1) (arg1)->x = arg2;
  jsresult = JSValueMakeUndefined(context); 
  return jsresult;
}



JSValueRef Shape_x_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
cout<<"wrap_shape_X_get called"<<endl;
  JSValueRef jsresult;
  Shape *arg1 = (Shape *) 0 ;
  double result;
  
  
  // Sanity check if the call is not on the global object
  if (!JSValueIsEqual(context, 
      JSValueToObject(context,thisObject,NULL), 
      JSValueToObject(context,JSContextGetGlobalObject(context), NULL), 
      NULL)) {
    SWIG_PRV_DATA* arg1_swigprivatedata = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
    arg1 = (Shape *)arg1_swigprivatedata->swigCObject; 
  }
  
  result = (double) ((arg1)->x);
  jsresult = JSValueMakeNumber(context, result); 
  return jsresult;
}



bool Shape_y_set(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef value, 
  JSValueRef* exception)
{
cout<<"wrap_shape_y_set called"<<endl;
  JSValueRef jsresult;
  Shape *arg1 = (Shape *) 0 ;
  double arg2 ;
  
  
  // Sanity check if the call is not on the global object
  if (!JSValueIsEqual(context, 
      JSValueToObject(context,thisObject,NULL), 
      JSValueToObject(context,JSContextGetGlobalObject(context), NULL), 
      NULL)) {
    SWIG_PRV_DATA* arg1_swigprivatedata = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
    arg1 = (Shape *)arg1_swigprivatedata->swigCObject; 
  }
  
  arg2 = (double)JSValueToNumber(context, value, NULL); 
  if (arg1) (arg1)->y = arg2;
  jsresult = JSValueMakeUndefined(context); 
  return jsresult;
}



JSValueRef Shape_y_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
cout<<"wrap_shape_y_get called"<<endl;
  JSValueRef jsresult;
  Shape *arg1 = (Shape *) 0 ;
  double result;
  
  
  // Sanity check if the call is not on the global object
  if (!JSValueIsEqual(context, 
      JSValueToObject(context,thisObject,NULL), 
      JSValueToObject(context,JSContextGetGlobalObject(context), NULL), 
      NULL)) {
    SWIG_PRV_DATA* arg1_swigprivatedata = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
    arg1 = (Shape *)arg1_swigprivatedata->swigCObject; 
  }
  
  result = (double) ((arg1)->y);
  jsresult = JSValueMakeNumber(context, result); 
  return jsresult;
}



JSValueRef Shape_move(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception)
{
cout<<"wrap_shape_move called"<<endl;
  JSValueRef jsresult;
  Shape *arg1 = (Shape *) 0 ;
  double arg2 ;
  double arg3 ;
  
  
  // Sanity check if the call is not on the global object
  if (!JSValueIsEqual(context, 
      JSValueToObject(context,thisObject,NULL), 
      JSValueToObject(context,JSContextGetGlobalObject(context), NULL), 
      NULL)) {
    SWIG_PRV_DATA* arg1_swigprivatedata = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
    arg1 = (Shape *)arg1_swigprivatedata->swigCObject; 
  }
  
  arg2 = (double)JSValueToNumber(context, argv[0], NULL); 
  arg3 = (double)JSValueToNumber(context, argv[1], NULL); 
  (arg1)->move(arg2,arg3);
  jsresult = JSValueMakeUndefined(context); 
  return jsresult;
}


JSValueRef Shape_printMe(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception)
{
cout<<"wrap_shape_printme called"<<endl;
  JSValueRef jsresult;
  
  Shape::printMe();
  jsresult = JSValueMakeUndefined(context); 
  return jsresult;
}


bool Shape_nshapes_set(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef value, 
  JSValueRef* exception)
{
cout<<"wrap_nshapes_set called"<<endl;
  JSValueRef jsresult;
  int arg1 ;
  
  arg1 = (int)JSValueToNumber(context, value, NULL); 
  Shape::nshapes = arg1;
  jsresult = JSValueMakeUndefined(context); 
  return jsresult;
}



JSValueRef Shape_nshapes_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception)
{
cout<<"wrap_nshape_get called"<<endl;
  JSValueRef jsresult;
  int result;
  
  result = (int)Shape::nshapes;
  jsresult = JSValueMakeNumber(context, result); 
  return jsresult;
}




JSStaticValue cvar_staticValues[] = {
    {"Shape_nshapes",Shape_nshapes_get,Shape_nshapes_set, kJSPropertyAttributeNone },

    { 0, 0, 0, 0 }
};

JSClassRef cvar_createJSClass(JSContextRef context)
{
cout<<"cvar_createJSClass called"<<endl;
	static JSClassRef jsClass = NULL;
	if (!jsClass)
	{
		JSClassDefinition definition	= kJSClassDefinitionEmpty;
		definition.staticValues			= cvar_staticValues;
		jsClass							= JSClassCreate(&definition);
	}
	return jsClass;
}

bool cvar_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* cvarclassname)
{ 
cout<<"cvar_initClass called"<<endl;
    JSStringRef jsstring = JSStringCreateWithUTF8CString(cvarclassname);
    static JSObjectRef cvarclassObject = JSObjectMake(context, cvar_createJSClass(context), NULL);
    JSObjectSetProperty(
		context,
	    parentObject,
	    jsstring,
	    cvarclassObject,
	    kJSPropertyAttributeNone,
	    NULL);
   JSStringRelease(jsstring);
   return true;
} 


JSStaticValue Circle_staticValues[] = {
    {"x",Shape_x_get,Shape_x_set,kJSPropertyAttributeNone },
    {"y",Shape_y_get,Shape_y_set,kJSPropertyAttributeNone },


    { 0, 0, 0, 0 }
};

JSStaticFunction Circle_staticFunctions[] = {
    {"move",Shape_move,kJSPropertyAttributeDontDelete },
    {"printMe",Shape_printMe,kJSPropertyAttributeDontDelete },

    {"area",Circle_area,kJSPropertyAttributeDontDelete },
    {"perimeter",Circle_perimeter,kJSPropertyAttributeDontDelete },

    { 0, 0, 0 }
};



JSClassRef Circle_createJSClass(JSContextRef context)
{
cout<<"wrap_Circle_createJSClass called"<<endl;
  static JSClassRef jsClass = NULL;
  if (!jsClass)
  {
    JSClassDefinition definition	= kJSClassDefinitionEmpty;
    definition.staticValues			= Circle_staticValues;
    definition.staticFunctions		= Circle_staticFunctions;
    definition.initialize			= Circle_initialize;
    definition.finalize				= Circle_finalize;
    jsClass 						= JSClassCreate(&definition);
  }
  return jsClass;
}

JSObjectRef Circle_createcppObject(JSContextRef context, JSObjectRef thisObject, size_t argc, const JSValueRef argv[],
  JSValueRef* exception)
{
cout<<"wrap_Circle_createcppObject called"<<endl;
  JSObjectRef jsresult;	
  Circle * result = 0;
  if (argc == 1) {
double arg1 ;
 arg1 = (double)JSValueToNumber(context, argv[0], NULL); 
    result = (Circle *)new Circle(arg1);

}

  SWIG_PRV_DATA *swigprivatedata = new SWIG_PRV_DATA();
  swigprivatedata->swigCMemOwn = true;
  swigprivatedata->swigCObject = result;
  
  jsresult = JSObjectMake(context, Circle_createJSClass(context), swigprivatedata);
  return jsresult;
}

bool Circle_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* className)
{
  JSStringRef jsstring = JSStringCreateWithUTF8CString(className);
  JSObjectSetProperty(context, parentObject, jsstring, 
    JSObjectMakeConstructor(context,
      Circle_createJSClass(context),
      Circle_createcppObject), 
    kJSPropertyAttributeNone, 
    NULL);
  JSStringRelease(jsstring);
  return true;
} 

void Circle_initialize(JSContextRef context, JSObjectRef thisObject)
{
  
}



JSValueRef Circle_area(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception)
{
cout<<"wrap_Circle_area called"<<endl;
  JSValueRef jsresult;
  Circle *arg1 = (Circle *) 0 ;
  double result;
  
  
  // Sanity check if the call is not on the global object
  if (!JSValueIsEqual(context, 
      JSValueToObject(context,thisObject,NULL), 
      JSValueToObject(context,JSContextGetGlobalObject(context), NULL), 
      NULL)) {
    SWIG_PRV_DATA* arg1_swigprivatedata = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
    arg1 = (Circle *)arg1_swigprivatedata->swigCObject; 
  }
  
  result = (double)(arg1)->area();
  jsresult = JSValueMakeNumber(context, result); 
  return jsresult;
}


JSValueRef Circle_perimeter(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception)
{
cout<<"wrap_Circle_perimeter called"<<endl;
  JSValueRef jsresult;
  Circle *arg1 = (Circle *) 0 ;
  double result;
  
  
  // Sanity check if the call is not on the global object
  if (!JSValueIsEqual(context, 
      JSValueToObject(context,thisObject,NULL), 
      JSValueToObject(context,JSContextGetGlobalObject(context), NULL), 
      NULL)) {
    SWIG_PRV_DATA* arg1_swigprivatedata = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
    arg1 = (Circle *)arg1_swigprivatedata->swigCObject; 
  }
  
  result = (double)(arg1)->perimeter();
  jsresult = JSValueMakeNumber(context, result); 
  return jsresult;
}




void Circle_finalize(JSObjectRef thisObject)
{
cout<<"wrap_Circle_finalize called"<<endl;
  SWIG_PRV_DATA* t = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
  if(t && t->swigCMemOwn) delete (Circle*)(t->swigCObject);
  if(t) delete t;
}


JSStaticValue Square_staticValues[] = {
    {"x",Shape_x_get,Shape_x_set,kJSPropertyAttributeNone },
    {"y",Shape_y_get,Shape_y_set,kJSPropertyAttributeNone },


    { 0, 0, 0, 0 }
};

JSStaticFunction Square_staticFunctions[] = {
    {"move",Shape_move,kJSPropertyAttributeDontDelete },
    {"printMe",Shape_printMe,kJSPropertyAttributeDontDelete },

    {"area",Square_area,kJSPropertyAttributeDontDelete },
    {"perimeter",Square_perimeter,kJSPropertyAttributeDontDelete },

    { 0, 0, 0 }
};



JSClassRef Square_createJSClass(JSContextRef context)
{
cout<<"wrap_Circle_createJSClass called"<<endl;
  static JSClassRef jsClass = NULL;
  if (!jsClass)
  {
    JSClassDefinition definition	= kJSClassDefinitionEmpty;
    definition.staticValues			= Square_staticValues;
    definition.staticFunctions		= Square_staticFunctions;
    definition.initialize			= Square_initialize;
    definition.finalize				= Square_finalize;
    jsClass 						= JSClassCreate(&definition);
  }
  return jsClass;
}

JSObjectRef Square_createcppObject(JSContextRef context, JSObjectRef thisObject, size_t argc, const JSValueRef argv[],
  JSValueRef* exception)
{
cout<<"wrap_Square_createcppObject called"<<endl;
  JSObjectRef jsresult;	
  Square * result = 0;
  if (argc == 1) {
double arg1 ;
 arg1 = (double)JSValueToNumber(context, argv[0], NULL); 
    result = (Square *)new Square(arg1);

}

  SWIG_PRV_DATA *swigprivatedata = new SWIG_PRV_DATA();
  swigprivatedata->swigCMemOwn = true;
  swigprivatedata->swigCObject = result;
  
  jsresult = JSObjectMake(context, Square_createJSClass(context), swigprivatedata);
  return jsresult;
}

bool Square_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* className)
{
cout<<"wrap_squre_initclass called"<<endl;
  JSStringRef jsstring = JSStringCreateWithUTF8CString(className);
  JSObjectSetProperty(context, parentObject, jsstring, 
    JSObjectMakeConstructor(context,
      Square_createJSClass(context),
      Square_createcppObject), 
    kJSPropertyAttributeNone, 
    NULL);
  JSStringRelease(jsstring);
  return true;
} 

void Square_initialize(JSContextRef context, JSObjectRef thisObject)
{
  
}



JSValueRef Square_area(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception)
{
cout<<"wrap_square_area called"<<endl;
  JSValueRef jsresult;
  Square *arg1 = (Square *) 0 ;
  double result;
  
  
  // Sanity check if the call is not on the global object
  if (!JSValueIsEqual(context, 
      JSValueToObject(context,thisObject,NULL), 
      JSValueToObject(context,JSContextGetGlobalObject(context), NULL), 
      NULL)) {
    SWIG_PRV_DATA* arg1_swigprivatedata = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
    arg1 = (Square *)arg1_swigprivatedata->swigCObject; 
  }
  
  result = (double)(arg1)->area();
  jsresult = JSValueMakeNumber(context, result); 
  return jsresult;
}


JSValueRef Square_perimeter(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception)
{
cout<<"wrap_square_perimeter called"<<endl;
  JSValueRef jsresult;
  Square *arg1 = (Square *) 0 ;
  double result;
  
  
  // Sanity check if the call is not on the global object
  if (!JSValueIsEqual(context, 
      JSValueToObject(context,thisObject,NULL), 
      JSValueToObject(context,JSContextGetGlobalObject(context), NULL), 
      NULL)) {
    SWIG_PRV_DATA* arg1_swigprivatedata = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
    arg1 = (Square *)arg1_swigprivatedata->swigCObject; 
  }
  
  result = (double)(arg1)->perimeter();
  jsresult = JSValueMakeNumber(context, result); 
  return jsresult;
}




void Square_finalize(JSObjectRef thisObject)
{
cout<<"wrap_square_finalize called"<<endl;
  SWIG_PRV_DATA* t = (SWIG_PRV_DATA*)JSObjectGetPrivate(thisObject);
  if(t && t->swigCMemOwn) delete (Square*)(t->swigCObject);
  if(t) delete t;
}



