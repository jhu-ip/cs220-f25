---
id: notes-Carrays
layout: default
title: C Arrays
---

<h3>Basic Usage</h3>
<ul>
      <li> Hold multiple values all of the same base type
</li><li> Use indices to access individual elements; like most languages these days, indices start at <code>0</code>
</li><li> Declare as <code>type var[CONST_SIZE]</code>, e.g. <code>int temps[3]</code>
</li>	<li> Can also declare w/initialization list: <code>type var[] = {val1, val2, val3}</code>, e.g. <code>int temps[] = {75, 67, 83}</code> and array will be as long as the list
</li> </ul>

<h3>Multiple dimension arrays</h3>
<ul>
  <li>Two or more dimensions; the size of each must be specified
</li><li> Declare as <code>myarray[size1][size2]</code>, access individual element with <code>myarray[i][j]</code>
</li><li> Initialize by nesting lists: <code>int testr[2][3] = { {4, 3, 2}, {6, 8, 33} };</code>
</li><li> Does initialization one row at a time
</li><li><code>myarray[i]</code> refers to a one dimensional array of the base type (row i); <code>myarray[size1][size2]</code> can be used as an array of arrays
</li>  </ul>

Example

```c
  #include <stdio.h>
  int main (void) {
    char a[2][4] = { {'w','o','w','\0'}, {'h','i','\0','X'} };
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++)
            printf("a[%d][%d] is %c\n", i, j, a[i][j]);
    for (i = 0; i < 2; i++)
            printf("row a[%d] is %s\n", i, a[i]);  // a[i] is a char array (i.e. a string)
    return 0;
  }
```



<h3>Arrays and Functions</h3> 

Use <code>[]</code> to indicate an array variable in function definition and in function prototype, e.g.

```c
      void doArray (int [], int); /* prototype version */
      void doArray (int myarray[], int size) /* on function itself */
```

<ul>
<li> Pass whole array to function with just name, no subscript: aray contents are passed by REFERENCE 
</li><li>Element values may be changed permanently within the function
</li><li> Doesn't create new storage location (ie, doesn't copy array)
</li><li> Array name is really address of first element (more later on this)
</li><li> Array names are passed by VALUE (copied, changes won't reach caller)
</li>	<li> Individual array elements passed to functions are handled like any variable of that base type
</li></ul>

If declaring a multi-dimensional array as function argument, need sizes of subcripts for all dimensions but 1st
    <ul>
      <li>eg: <code>void passarray(int a[][3][4])</code>  receives a 3 dimensional array
     </li> <li>Sizes needed because arrays are stored sequentially - need dimensions to locate items
     </li> <li>Another example of low-level nature of C data structures.
</li></ul>

Can use <code>const</code> in parameter list to make array unmodifiable: <code>void doArray (const int ma[])</code> results in compile error if any attempt to assign or read new value into an array element


<h3>Command line options</h3>

To read what arguments if any were on a command line invocation, use the following <code>main</code> function declaration: <br />
<code>main(int argc, char *argv[])</code>

<ul>
<li><code>argc</code> is count of how many arguments, including program name
</li><li> <code>char *argv[]</code> is a "pointer to an array of characters". We will explain pointers in detail later. For now, you can use it like <code>char argv[][]</code> - a 2d array of chars
</li>  <li> <code>argv[0]</code> is program name (string)
</li><li><code>argv[i]</code> is <code>i</code>th argument as a string
</li>
</ul>

Example: given <code>./a.out one two</code><br />
<code>argc</code> is 3,
<code>argv[0]</code> is "./a.out", <code>argv[1]</code> is "one",
and <code>argv[2]</code> is "two"


<h3>CAUTION: review the below sections after learning pointers</h3>

<h4>Pointers and arrays</h4>

Welcome to C's Wacky World
<ul>
  <li>A declared array, say <code>int a[10]</code>, is "really" just an address that starts a block of memory.
</li>  <li>So, writing <code>a</code> is generally the same as writing <code>&a[0]</code>
</li>  <li><code>a[3]</code> is a synonym for <code>*(a + 3)</code> (offset three from pointer to start of array)
</li>  <li><code>&a[3]</code> is a synonym for <code>a + 3</code>
</li></ul>

<p>
<code>int *ptr</code> and <code>int a[10]</code> variables are
often interchangeable but not 100%:
<ul>
  <li><code>a = ptr</code> will be a compile error since size
  of <code>a</code> could get changed if this were
  allowed; <code>sizeof(a)</code> is <em>always fixed</em>
</li><li><code>ptr = a</code> is perfectly acceptable,
  but <code>printf("%d", sizeof(ptr));</code> is only 4 or 8, the size
  of a pointer
</li>  <li>locally declared array types <em>(but not function parameters)</em> have allocated space the size of the whole array:<br>
      <code>char s[100]; printf("%d",sizeof(s));</code> prints 100 (bytes)<br>
      <code>char s[10]; printf("%d",sizeof(&s[0]));</code> prints the size of a pointer, 4 or 8 bytes
</li></ul>


<h4>Arrays of pointers</h4>
<ul> 
     <li>Note writing <code>main(int argc, char *argv[])</code> is same as <code>main(int argc, char **argv)</code> since more generally any function parameter <code>mytype myvar[]</code> is nearly identical to writing <code>mytype * myvar</code>.
</li><li> Common use is array of strings
</li><li> Each string is pointer to a string array, 
  eg: <code>char *suitptr[4] = {"Hearts", "Diamonds", "Clubs", "Spades"}</code>
</li><li>Note that this is not the same as a 2d array which is laid out sequentially
</li>
</ul>

<p>

```c
int main(void) {
  char *suitptr[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  char suit[4][20] = {"hearts", "diamonds", "clubs", "spades"};
  printf("%s %s\n", suit[1], suitptr[1]); // they more or less behave the same
  printf("size of suit = %lu size of suitptr = %lu\n",sizeof(suit),sizeof(suitptr)); // sizes differ!
}
```


<!--

<h3>Dynamic memory allocation</h3>

Real Programs need dynamic memory
	<ul>
	  <li>Arrays we have used up to now must have fixed size from when program launched
</li>	  <li>Want to let program grow unboundedly (up to available memory on the computer)
</li>	  <li>Solution: dynamic memory allocation
      </ul>
	      
<ul>
  <li>C takes a low-level view of dynamic memory: allocate blocks and free blocks of memory<br>
-- compare to Java/Python/etc where you just say <code>new</code> or invoke class constructor to allocate space for new objects, and a garbage collector frees for you
  <li>Dynamic memory is allocated on a <em>heap</em> (which is a huge dynamically growable array)
  <li>Data persists until it is explicitly <code>free</code>d
  <li>Can return <code>char*</code> from functions, unlike <code>char[]</code>

</ul>
<p>
<p>

<code>void *<a href="http://www.cplusplus.com/reference/cstdlib/calloc/">calloc</a> (size_t <em>numels</em>, size_t <em>sizeofel</em>)</code><br>
&nbsp;&nbsp;&nbsp;&nbsp;e.g. <code>int * arr = calloc (10,sizeof(int)); // arr[0] .. arr[9] are fresh 0'd array elements after this statement
</code>
<ul>    <li> Makes array of <code>numels</code> with each element having size <code>sizeofel</code>; initialize all to 0's
    <li> <code>calloc</code> returns a pointer to this new memory block
    <li> Return type is <code>void *</code> and by C type promotion rules its OK to assign <code>void *</code> to any type of pointer
    <li>If <code>NULL</code> (empty pointer) is returned, no space was allocated
    <li><strong>Alert</strong>: its very easy to <code>calloc</code> too little or too much space if you pass in incorrect sizes
    <li>Aside: <code>size_t</code> is C's data type for sizes of things (the result type of <code>sizeof</code>)<br>
-- it should be an <code>int</code> that can hold up to the size of the machine's memory, so it will be an unsigned 32 or 64-bit <code>int</code> depending on your machine.
    <li>Aside 2: in older C style the result of calloc etc would need to be <em>typecast</em>; this is no longer needed or recommended.
</ul>
<p>

Here is a little example:
<pre>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

int main()
{
    int n;
    scanf("%d",&n);
    int * arr = calloc (n,sizeof(int));
    for (int i = 1;i&lt;n;i++) printf("%d ",arr[i]);
}
</pre>
<p>

<code>void *<a href="http://www.cplusplus.com/reference/cstdlib/malloc/">malloc</a> (size_t <em>size</em>)</code><br>
&nbsp;&nbsp;&nbsp;&nbsp;e.g. <code>char * str = malloc(sizeof(char) * 10); // can copy a 9-character string into fresh str now
</code>
<ul>    <li> Creates memory block of given total <code><em>size</em></code>
    <li> Returns pointer to start of memory
</ul>
<p>

<code>void *<a href="http://www.cplusplus.com/reference/cstdlib/realloc/">realloc</a> (void *<em>ptr</em>, size_t <em>size</em>)</code>
<ul>    <li>Copies memory pointed to by <code><em>ptr</em></code> to new place with new <code><em>size</em></code>
<li>Returns a pointer to this new copy; frees memory pointed to by <code><em>ptr</em></code>
    <li> <code><em>ptr</em></code> should be a previously *<code>alloc</code>'d value
    <li> <code><em>size</em></code> is as in <em>malloc</em>, for calloc-style use a size (<code><em>numels</em> * <em>sizeel</em></code>)
    <li> If new size is bigger, new space uninitialized
</ul>
<p>For all of the *<code>alloc</code>  above, if (re-)allocation fails returns null
<pre>    char * memory = malloc(400000);
    if (!memory)  // remember null == 0, 0 is false
       printf("Failed to allocate the amount of memory you requested\n");</pre>

<h4>Deallocating memory</h4><p>

<code>void <a href="http://www.cplusplus.com/reference/cstdlib/malloc/">free</a>(void *<code><em>ptr</em></code>)</code>
<ul>
  <li> deallocates the memory at address <code><em>ptr</em></code>
    <li> <code><em>ptr</em></code> must be a previously *alloc'd return value
    <li> <code><em>ptr</em></code> is no longer pointing to valid storage after <code>free</code>
    <li>A primary source of errors in C code is either <code>free</code>ing memory you are still using, or not <code>free</code>ing memory you are finished with, and using up all your computer memory eventually (a <em>leak</em>).<br>
-- not a problem in Java/Python/etc since they have a garbage collector
</ul>


A few usage examples:

  Use of <code>calloc</code> within a function (note return type on function):
```c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;

float * dynarray (int size)
{ float *farray;
    farray = calloc(size, sizeof(float));
    return farray;
}

int main()
{ float * fdynarray;
    fdynarray = dynarray(50);
    fdynarray[3] = 23.4;
    *(fdynarray+3) = 23.4;
}
```

Using <code>realloc</code> to double the size of an array:
```c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
int main()
{
    int size = 10, *array;
    array = calloc(size, sizeof(int)); // or, "malloc(size*sizeof(int))"

    for(int j = 0; j&lt;10; j++) array[j] = 2*j + 1;

    for(int j = 0; j&lt;10; j++) printf("array[%d]=%d\n",j,array[j]);
    printf("array is now located at %p\n",array);

    int * temp = realloc(array, size*2*sizeof(int));

    if (temp)     // not NULL so good to go
        array = temp;  // array has the above data plus its now size 20
    else { printf("not enough memory\n"); return 1; }
    
    printf("array is now located at %p - it moved!\n",array);
    array[19]=99; // have 10 extra locations now!
    for(int j = 0; j&lt;20; j++) printf("array[%d]=%d\n",j,array[j]);

}
```

-->

<p>
(more coming soon)
