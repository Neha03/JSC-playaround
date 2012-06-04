#include "JavaScriptCore/JavaScript.h"
#include "example_wrap.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

static JSValueRef	print(
			JSContextRef		context, 
			JSObjectRef			object, 
			JSObjectRef			thisObject, 
			size_t				argumentCount, 
			const JSValueRef	arguments[], 
			JSValueRef*			exception)
{
	if (argumentCount > 0)
	{
		JSStringRef string = JSValueToStringCopy(context, arguments[0], NULL);
		size_t numChars = JSStringGetMaximumUTF8CStringSize(string);
		char stringUTF8[numChars];
		JSStringGetUTF8CString(string, stringUTF8, numChars);
		printf("%s\n", stringUTF8);
	}

	return JSValueMakeUndefined(context);
}


static char* createStringWithContentsOfFile(const char* fileName)
{
	char* buffer;
	
	size_t buffer_size = 0;
	size_t buffer_capacity = 1024;
	buffer = (char*)malloc(buffer_capacity);
	
	FILE* f = fopen(fileName, "r");
	if (!f)
	{
		fprintf(stderr, "Could not open file: %s\n", fileName);
		return 0;
	}
	
	while (!feof(f) && !ferror(f))
	{
		buffer_size += fread(buffer + buffer_size, 1, buffer_capacity - buffer_size, f);
		if (buffer_size == buffer_capacity)
		{ 
			// guarantees space for trailing '\0'
			buffer_capacity *= 2;
			buffer = (char*)realloc(buffer, buffer_capacity);
		}
	}
	fclose(f);
	buffer[buffer_size] = '\0';
	
	return buffer;
}


bool initFunction(JSGlobalContextRef p_rContext, JSObjectRef p_rObject, const char* p_szFunctionName,
                               JSObjectCallAsFunctionCallback p_cbFunction)
{
    JSStringRef	functionString = JSStringCreateWithUTF8CString(p_szFunctionName);
    JSObjectSetProperty(
			p_rContext,
			p_rObject,
			functionString,
			JSObjectMakeFunctionWithCallback(
				p_rContext,
				functionString,
				p_cbFunction),
			kJSPropertyAttributeNone,
			NULL);
	JSStringRelease(functionString);
	return true;
}


int main(int argc, char* argv[]) {
cout<<"main() called"<<endl;

  JSGlobalContextRef Context = JSGlobalContextCreate(NULL);
  JSObjectRef GlobalObject = JSContextGetGlobalObject(Context);
  initFunction(Context, GlobalObject, "print", print); // Utility print function
	
  // initClass cvar object for global variables and the class static variables
  cvar_initClass(Context, GlobalObject, "cvar");

  // initClass the classes
  Circle_initClass(Context, GlobalObject, "Circle");
  Square_initClass(Context, GlobalObject, "Square");
	
 // initClass static class functions as global functions
 initFunction(Context, GlobalObject, "Shape_printMe", Shape_printMe);

 // Evaluate the javascript
  char*	szString = createStringWithContentsOfFile("runme.js");
  JSStringRef Script = JSStringCreateWithUTF8CString(szString);

  JSValueRef Exception;
  JSValueRef Result = JSEvaluateScript(Context,Script,NULL,NULL,0,&Exception);

  if (Result) 
	printf("runme.js executed successfully\n");
		
  else {
	printf("Script Exception\n");
	JSStringRef ExceptionIString;
	ExceptionIString = JSValueToStringCopy(Context, Exception, NULL);
	char stringUTF8[256];
	JSStringGetUTF8CString(ExceptionIString, stringUTF8, 256);
	printf(":%s\n",stringUTF8);
	JSStringRelease(ExceptionIString);
  }
  
  if (szString != NULL)
	free(szString);

  JSStringRelease(Script);
  GlobalObject = 0;
  JSGlobalContextRelease(Context);

   return 0;
}
