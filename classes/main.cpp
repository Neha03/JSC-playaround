#include <JavaScriptCore/JavaScript.h>
#include "Test.h"
#include "Testjsc.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

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
			//assert(buffer);
		}
		//assert(buffer_size < buffer_capacity);
	}
	fclose(f);
	buffer[buffer_size] = '\0';
	
	return buffer;
}

bool DefineJSCoreFunction(JSGlobalContextRef rContext, JSObjectRef rObject, const char* szFunctionName,
						  JSObjectCallAsFunctionCallback cbFunction)
{
    JSStringRef	functionString = JSStringCreateWithUTF8CString(szFunctionName);
    JSObjectSetProperty(
						rContext,
						rObject,
						functionString,
						JSObjectMakeFunctionWithCallback(
														 rContext,
														 functionString,
														 cbFunction),
						kJSPropertyAttributeNone,
						NULL);
	JSStringRelease(functionString);
	return true;
}

JSValueRef  _wrap_print(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, 
				size_t argCount, const JSValueRef args[], JSValueRef* exception)
{
   if (argCount > 0) {
	// Get First argument as string
	JSStringRef string = JSValueToStringCopy(context, args[0], NULL);

	// Get string size
	size_t numChars = JSStringGetMaximumUTF8CStringSize(string);

	// Print string
	char stringUTF8[numChars];
	JSStringGetUTF8CString(string, stringUTF8, numChars);
	printf("%s\n", stringUTF8);		
  }
  
  return JSValueMakeUndefined(context);
}

int main() {
  cout<<"main() called"<< endl;
  JSGlobalContextRef Context = JSGlobalContextCreate(NULL);
  JSObjectRef GlobalObject = JSContextGetGlobalObject(Context);
// Create functions
  DefineJSCoreFunction(Context, GlobalObject, "print", _wrap_print);		// helper print function

  // Create classes
  JSCircle_DeclareClass(Context, GlobalObject, "Circle");

  // Evaluate the javascript
  char*	szString = createStringWithContentsOfFile("Test.js");
  JSStringRef Script = JSStringCreateWithUTF8CString(szString);

  JSValueRef Exception;
  JSValueRef Result = JSEvaluateScript(Context,Script,NULL,NULL,0,&Exception);

  if (Result) 
	printf("Test script executed successfully\n");
		
  else {
	printf("Test script Exception\n");
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
  //JSGarbageCollect(Context);

  return 0;
}
















