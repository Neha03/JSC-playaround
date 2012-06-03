 // Member function call
 obj = new Foo();
 string = obj.display("Hello World!!!!!!");	// Passing and Returning char*
 print(string);

 string = obj.helloString("Neha");	// Passing and Returning string
 print(string)

 /// Static C++ function - called via object in Javascript and as global function with classname qualifier
 obj.printMe(); 
 Foo_printMe();

 // passing primary and object type by reference.. but the value will not changed i.e they behave as const reference
 x = 5;
 obj.setMe(x);
 print("x has been set to " + x);
