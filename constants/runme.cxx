#include "JavaScriptCore/JavaScript.h"
#include "examplejsc.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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


bool initFunction(JSGlobalContextRef rContext, JSObjectRef rObject, const char* szFunctionName,
                               JSObjectCallAsFunctionCallback cbFunction)
{
    JSStringRef	cbFunctionfunctionString = JSStringCreateWithUTF8CString(szFunctionName);
    JSObjectSetProperty(
			rContext,
			rObject,
			cbFunctionfunctionString,
			JSObjectMakeFunctionWithCallback(
				rContext,
				cbFunctionfunctionString,
				cbFunction),
			kJSPropertyAttributeNone,
			NULL);
	JSStringRelease(cbFunctionfunctionString);
	return true;
}


int main(int argc, char* argv[]) {
cout<<"main() called"<<endl;

  JSGlobalContextRef cbFunctionContext = JSGlobalContextCreate(NULL);
  JSObjectRef cbFunctionGlobalObject = JSContextGetGlobalObject(cbFunctionContext);
  initFunction(cbFunctionContext, cbFunctionGlobalObject, "print", print); // Utility print function

  // Declare the class for constants
  cconst_initClass(cbFunctionContext, cbFunctionGlobalObject, "cconst");

 // Evaluate the javascript
  char*	cbFunctionszString = createStringWithContentsOfFile("runme.js");
  JSStringRef cbFunctionScript = JSStringCreateWithUTF8CString(cbFunctionszString);

  JSValueRef cbFunctionException;
  JSValueRef cbFunctionResult = JSEvaluateScript(cbFunctionContext,cbFunctionScript,NULL,NULL,0,&cbFunctionException);

  if (cbFunctionResult) 
	printf("runme.js executed successfully\n");
		
  else {
	printf("Script Exception\n");
	JSStringRef cbFunctionExceptionIString;
	cbFunctionExceptionIString = JSValueToStringCopy(cbFunctionContext, cbFunctionException, NULL);
	char stringUTF8[256];
	JSStringGetUTF8CString(cbFunctionExceptionIString, stringUTF8, 256);
	printf(":%s\n",stringUTF8);
	JSStringRelease(cbFunctionExceptionIString);
  }
  
  if (cbFunctionszString != NULL)
	free(cbFunctionszString);

  JSStringRelease(cbFunctionScript);
  cbFunctionGlobalObject = 0;
  JSGlobalContextRelease(cbFunctionContext);

   return 0;
}
