

void Shape_finalize(JSObjectRef thisObject);

bool Shape_x_set(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef value, 
JSValueRef* exception);

JSValueRef Shape_x_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);

bool Shape_y_set(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef value, 
JSValueRef* exception);

JSValueRef Shape_y_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);

JSValueRef Shape_move(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception);

JSValueRef Shape_printMe(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception);

bool Shape_nshapes_set(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef value, 
JSValueRef* exception);

JSValueRef Shape_nshapes_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);

bool cvar_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* cvarclassname);


void Circle_initialize(JSContextRef context, JSObjectRef thisObject);

bool Circle_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* className);
JSClassRef Circle_createJSClass(JSContextRef context);
JSObjectRef Circle_createcppObject(JSContextRef context, JSObjectRef thisObject, size_t argc, const JSValueRef argv[],
JSValueRef* exception);


JSValueRef Circle_area(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception);

JSValueRef Circle_perimeter(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception);

void Circle_finalize(JSObjectRef thisObject);

void Square_initialize(JSContextRef context, JSObjectRef thisObject);

bool Square_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* className);
JSClassRef Square_createJSClass(JSContextRef context);
JSObjectRef Square_createcppObject(JSContextRef context, JSObjectRef thisObject, size_t argc, const JSValueRef argv[],
JSValueRef* exception);


JSValueRef Square_area(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception);

JSValueRef Square_perimeter(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception);

void Square_finalize(JSObjectRef thisObject);

