---
id: notes-classes
layout: default
title: Classes in C++
---

<h3>Class Definitions</h3>

<h4>Object-Oriented C++ Basics</h4>

Classes vs. Structs

<ul>
  <li>Classes are an extension to structs and the two are nearly identical
</li>  <li>Only difference between C++'s structs and classes: 
      <ul>
	<li> class members are private by default
</li>  <li> struct members are public by default
</li></ul>
</li><li>Standard coding convention: 
    <ul>
      <li>use stucts for "dumb data" with no methods
</li>      <li>use classes for anything else
</li>    </ul>
</li></ul>

Organization of program

<ul>
  <li> Header files contain class declarations (interface)
</li>    <li> Program files contain class (function) definitions (implementation)
</li>    <li> <code>main()</code> function still needed for execution starting point
</li></ul>

Object oriented (OO) programming language features

<ul>
  <li> Generally objects = fields + methods but C++ terminology is "objects = data members + member functions"
</li>  <li> public interface, private implementation
</li>  <li> Multiple polymorphism forms in OO
      <ul>
        <li>object polmorphism via subclassing
</li>	<li>templates/generics
</li>	<li> function &amp; operator overloading
</li></ul>  
</li>    <li> inheritance
</li>    <li> abstract base classes
</li></ul>

OO Abstraction & modelling

<ul>  <li> data members (properties) - can be of different types or classes
</li>    <li> function members (behaviors) 
        <br />-- can be defined there or elsewhere
        <br />-- assume full access to data members
</li>
</ul>

<h4>Class Components</h4>

Information hiding of class members
<ul>
  <li>public parts - anybody can access
</li>  <li>private parts - access by same class members only
</li>  <li>declared via <code>public:</code> and <code>private:</code>  in .h file
</li></ul>

Member functions
<ul>
  <li>Defined with <code>MyClass::myfunc(args) { ... code ... }</code>
</li>  <li>Can be implemented independently of class declaration, interspersed with other non-class functions
</li></ul>

Syntax for class interface (in *.h file)

```c
class classname {
     // complete member list
};   // semicolon is very important
```

<h4>Constructors and destructors</h4>

Constructors are used to initialize objects and each class can have many:
<ul>
  <li> Default constructor - no parameters; primitive fields are not initialized, object fields are initialized with their default constructors
</li>  <li> Conversion constructor - takes only one parameter, compiler then uses for type conversions from values of that parameter type to the class type
</li>  <li> Copy constructor - has parameter of the class type; default version is shallow copy of data fields (similar to default assignment operator)
</li><li>Alternate constructors - have any combination of parameters different from those above
</li></ul>

C++ automatically provides a default constructor and a (shallow) copy constructor for every class if you don't explicitly create any constructors. However, if you define any constructor, default ones are not created automatically for the class.

Copy constructors are invoked
<ul>
  <li> explicitly when initializing an object in declaration
</li>  <li> implicitly when passing an object call by value
</li>  <li> implicitly when returning an object by value
</li></ul>

Initializer lists for data members 
<ul>
  <li>Special syntax for initializing fields
</li>  <li> <code>Point :: Point () : x(0), y(0) { }</code> initializes x and y to 0
</li><li> initialization happens in the order of declaration, not list order above (doesn't usually matter though)
</li>    <li> All data members initialized even if not listed explicitly
</li>    <li> Body of constructor can be used to change or do more
    initializations
</li><li>May need to do this for members of other class types, particularly
  if they don't have default constructors
</li></ul>

Constructors using default values
<ul>
  <li> Can leave off certain arguments if they have a default value listed
</li>  <li> Defaults only declared in the header, not in the definition!
</li>  <li> Function implementation is as before
</li><li> Must be defaulted from right to left when used, as in <code>Point (int xy=0, int yv=0)</code> - calling options are only to leave out right-most params
</li></ul>

```cpp
Point p1(3, 4); // use both
Point p2(3);    // use x; y defaults to 0
Point p3;       // both default to 0
```

Destructors
<ul>
  <li>Named by prepending <code>~</code> to the class name - <code>MyClass::~MyClass() { ... }</code>
  </li><li>Destructor code invoked when object lifetime ends
</li>  <li>Destruction is <em>shallow</em> (no destruction of objects referenced) unless code <code>...</code> does more
</li>  <li>Locally declared objects are destroyed at function return - their destructors are called right before their memory is freed
</li><li>C++ provides a destructor for your class if you don't explicitly
  write one.
</li></ul>


<h4>Other C++ class definition features</h4>

Inline function definitions
<ul>
  <li>Code is not a function call, its inlined by compiler for speed
</li>  <li>Since its like a macro its OK to put this code in <code>.h</code> file
</li>  <li>Need semicolon: <code>int Myclass::getX() { return x ; } ;</code> 
</li></ul>
	    
Instance variables (data members)
<ul>
<li> They are like struct fields
</li><li> They are not automatically references, as in Java - use <code>&var</code> to make a reference
</li><li> The class constructor should set their initial value
</li></ul>    

The <code>this</code> pointer to current object
<ul>
  <li> Can use <code>this->datamember</code> instead of just <code>datamember</code> for clarification
</li>    <li>Can  use <code>*this</code> as name for current object
</li>    <li>Like <code>this</code> in Java, you don't often need to use it
</li></ul>

Constant member functions
<ul>
  <li> Use <code>const</code> at end of function header to say that it can't modify
		any data members of itself (the current object)
</li>    <li> Must use <code>const</code> in both prototype and implementation header
</li>    <li> Can be applied to <code>const</code> and non-<code>const</code> qualified objects
</li>    <li> A non-<code>const</code> function cannot be applied to <code>const</code> qualified object - violates spirit of <code>const</code>
</li></ul>

<code>static</code> class members 
  <ul>
    <li> Class-wide info, shared by all objects
</li>    <li> Similar to <code>static</code> in Java classes
</li>    <li> Declare data: <code>static int sharedint;</code>
</li>    <li> Can be accessed through class object or globally via <code>classname::</code> (if public)
</li>    <li> Declare functions: static int changeshared (int);
</li>    <li> Function can only be static if it only accesses static data
</li>    <li> No <code>this</code> for static members
</li></ul>


Class composition - objects in classes
<ul>
  <li> Class data members are constructed in order of declaration
		and before the class constructor is executed
</li><li>May need to initialize member objects with constructor initializer list
  if they don't have default constructors
</li></ul>


<h4>Misc points about classes</h4>

Operators <code>=</code> and <code>==</code> on objects:
<ul>
  <li>  <code>=</code> assignment operator  - memberwise assignment is
  provided by default (not deep copy)
</li><li>  <code>==</code> equality operator is not provided automatically for
  your class objects, you have to define it explicitly (see <a href='notes-overloading.html'>Overloading</a>)
</li></ul>
