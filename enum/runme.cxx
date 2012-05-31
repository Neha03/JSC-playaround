#include "JavaScriptCore/JavaScript.h"
#include "examplejsc.h"
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


bool DefineJSCoreFunction(JSGlobalContextRef context, JSObjectRef parentObject, const char* p_szFunctionName,
                               JSObjectCallAsFunctionCallback p_cbFunction)
{
    JSStringRef	functionString = JSStringCreateWithUTF8CString(p_szFunctionName);
    JSObjectSetProperty(
			context,
			parentObject,
			functionString,
			JSObjectMakeFunctionWithCallback(
				context,
				functionString,
				p_cbFunction),
			kJSPropertyAttributeNone,
			NULL);
	JSStringRelease(functionString);
	return true;
}


int main(int argc, char* argv[]) {
  cout<<"main() called"<<endl;
  JSGlobalContextRef context = JSGlobalContextCreate(NULL);
  JSObjectRef globalObject = JSContextGetGlobalObject(context);
  DefineJSCoreFunction(context, globalObject, "print", print); // Utility print function

  // Declare the constants class
  cconst_initClass(context, globalObject, "cconst");

  // Declare the classes
  Foo_initClass(context, globalObject, "Foo");

 // Evaluate the javascript
  char*	szString = createStringWithContentsOfFile("runme.js");
  JSStringRef Script = JSStringCreateWithUTF8CString(szString);

  JSValueRef Exception;
  JSValueRef Result = JSEvaluateScript(context,Script,NULL,NULL,0,&Exception);

  if (Result) 
	printf("runme.js executed successfully\n");
		
  else {
	printf("Script Exception\n");
	JSStringRef ExceptionIString;
	ExceptionIString = JSValueToStringCopy(context, Exception, NULL);
	char stringUTF8[256];
	JSStringGetUTF8CString(ExceptionIString, stringUTF8, 256);
	printf(":%s\n",stringUTF8);
	JSStringRelease(ExceptionIString);
  }
  
  if (szString != NULL)
	free(szString);

  JSStringRelease(Script);
  globalObject = 0;
  JSGlobalContextRelease(context);

   return 0;
}
