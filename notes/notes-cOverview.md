---
id: notes-cOverview
layout: default
title: C Overview
---

<h3>C Language Overview</h3>

<h4> Why C?
</h4>    <ul>
      <li> System level programming!  Operating systems, network protocols, device drivers (printer, keyboard, etc).
      <li> Very fast and efficient memory usage
      <li>The <em>dark side</em>: obscure code, easy to create
      security vulnerabilities, easy to shoot yourself in the foot
        <li>The burden is on the programmer to get things right; C won't protect you from yourself.
    </ul>


<h4>C compilers
</h4>    <ul>
      <li> Different language versions evolved over time
<li> Most recent standard 'C11' is from 2011; our standard will be C99 from 1999
<li> Compilers these days are "retargetable", a single compiler can compile to many different machine architectures
<li>Our official C compiler is <code>gcc</code>.
</ul>


<blockquote>REFERENCE: Skim through <a href="http://cslibrary.stanford.edu/101/EssentialC.pdf">C tutorial</a> to start.
</blockquote>

<h3>The Programming Process</h3>

<ul>
 <li> Store source code in <code><em>file</em>.c</code>
<li> Create source code with editor (<code>pico</code>, <code>emacs</code>, <code>vi</code>, etc.)
<li> Compile &amp; run 
    <ul>
      <li> <code>gcc <em>file</em>.c</code> creates <code>a.out</code>
        file; run with <code>./a.out</code> command
	<li> <code>gcc -o <em>file</em> <em>file</em>.c</code> creates
	executable <code><em>file</em></code>; run
	with <code>./<em>file</em></code> command
      </ul>
 </ul>	

<h4>The compilation steps for C
</h4>
	    <ol>
	      	<li> Pre-processing: <code>#include</code> files, definitions
	<li> Compile (program = <code>.c</code>/<code>.h</code> files = source code; assembly; machine = object code = <code>.o</code> file)
	<li> Link w/library routines
	<li> Load into memory
	<li> Execute = run in CPU
      </ol>


<h4>Preprocessor directives</h4>
      <ul>
	<li>	<code>#include "header.h"</code> -- in effect insert the file <code>header.h</code> contents <em>here</em>
	<li> <code>#define <em>THING</em> <em>value</em></code>	 - <code><em>THING</em></code> is a macro abreviation for <code><em>value</em></code>
	<li> Long comment: <code>/* here is a <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;long comment */</code>
	<li> Short comment:&nbsp;&nbsp; <code>// here is my comment</code>
      </ul>


<h3>Testing</h3>

	<ul>
<li> Use asserts to check what's going on in your code
  <li> <code>#include &lt;assert.h&gt;</code>
  <li> <code>assert(<em>boolean expr</em>)</code>
</ul>

    <h3>C Data Types</h3>
   <h4>Primitive data types</h4>
      <ul>
	<li> <code>char</code>,	<code>short</code> (int), <code>int</code> (default), <code>long</code> (int), <code>float</code>, <codeyes>double</code> (-sized float), <code>long double</code> (quadruple-sized float)
	<li> <code>unsigned</code> qualifier can apply to any to restrict to non-negative
	<li> <code>const</code> qualifier to make the data immutable (same as <code>final</code> in Java - confoosing!)
    <li> C is not as strongly typed as Java, e.g. array access out of bounds is not a checked exception (though it will often crash your program anyway; this is usually the cause of a <code>segmentation fault</code>).
	<li>Exact sizes of each type are platform dependent; <code>int</code> is generally 32-bit except on 16-bit processors.
      </ul>

<blockquote>WARNING:
In C, <em>you cannot assume variables are initialized</em> and may
  they contain junk (what was there before) and produce erratic
  results!!
</blockquote>

<h4>Integer constants</h4>
<ul>
		<li> Decimals (base 10):<br>
&nbsp;&nbsp;&nbsp;
<code>int</code>: <code>13</code>, <code>23</code>, <code>-14</code>, etc. <br>
&nbsp;&nbsp;&nbsp; <code>long</code> (integer): <code>13L</code>, <code>-14l</code>, etc. 
    <li> Octal (base 8) - precede value with 0<br>
&nbsp;&nbsp;&nbsp; digits range from 0 to 7<br>
&nbsp;&nbsp;&nbsp; <code>032</code>
    <li> Hexadecimal (base 16) - precede value with <code>0x</code><br>
&nbsp;&nbsp;&nbsp;
       digits range from 0 to 9 and a-f or A-F<br>
&nbsp;&nbsp;&nbsp;
       <code>0x15</code>, <code>0xA</code>
	<li> Binary (base 2) - precede value with <code>0b</code><br>
&nbsp;&nbsp;&nbsp;
 digits are 0 and 1 only<br>
&nbsp;&nbsp;&nbsp;
 <code>0b1000</code>, <code>0b01101</code>
</ul>       

<h4>Booleans 
</h4>
    <ul>
      	<li> <code>bool</code> type added in c99 w/values <code>true</code>, <code>false</code>
          <li> In older (most) C code you will see <code>int</code>s, where 0=false, non-zero=true used instead
          <li>In C, any integer type may be used as a boolean; a value of <code>0</code> is treated as <code>false</code>, and <em>any</em> other value is treated as <code>true</code>.
      </ul>		

<h4>ASCII characters, escape sequences</h4>
      <ul>
	<li> <code>#include &lt;ctype.h&gt;</code>  if you want to use character library functions;  <a href="http://www.cplusplus.com/reference/cctype/">Reference for <code>ctype.h</code> functions</a>
	<li> <code>isalpha('a')</code> (returns <code>true</code>), <code>isdigit</code>, etc. functions to test characters
	<li> <code>tolower('A')</code>, <code>toupper('a')</code> for case conversion
	<li>Note the previous functions have return type <code>int</code> -- this is because return value <code>-1</code> indicates error.
      </ul>

<h4>Size calculations</h4>
<ul>
  <li><code>sizeof</code> operator: returns integer # bytes of object
  <li> <code>sizeof(<em>anytype</em>)</code>, <code>sizeof <em>varname</em></code>
</ul>
<p>


      <h3>C Operators</h3>
      
<h4>Common Operators</h4>
	<ul>
	  <li> Arithmetic: <code>+ - * / %</code>  (no exponentiation operator)
	<li> Relational: <code>&lt; &gt; &lt;= &gt;= == !=  </code>
    <li> Logical: <code>!</code> not   <code>&&</code> and   <code>||</code> or	
    <li> Assignment: <code>= += -= *= %= ++ --</code>
    <li> Precedence order:  always know where to look this up quickly (e.g. <a href="http://www.csee.umbc.edu/courses/104/fall06/burt/precedenceTable.html">here</a>)
	<li> Short-circuit (lazy) evaluation of boolean expressions
      </ul>			

Caution on equality and assignment:
```c
if (num = 10)  // evaluates to 10, which is considered to be true (non-zero)
if (num == 10) // double equals only evalutes to true if num is in fact a 10
```
    
<h4>Bitwise operators</h4>
<ul>
  <li>    <code>num1 & num2</code> - bitwise and
  <li>    <code>num1 | num2</code> - bitwise inclusive or
  <li>    <code>num1 ^ num2</code> - bitwise exclusive or
  <li>    <code>~num1</code> - bitwise complement
  <li>   <code>num &lt;&lt; shiftbits</code> - left shift of num by shiftbits places, pad 0 right
  <li>    <code>num &gt;&gt; shiftbits </code>- similar right shift, pad is system dependent
</ul>

<h4>Built-in floating-point math functions
</h4>   
  <ul>
    <li> Use <code>#include &lt;math.h&gt;</code>
    <li> Probably need to compile with <code>gcc -lm</code> option
    <li> Math library functions generally take <code>double</code> arguments, return <code>double</code> values
    <li> eg: <code>sqrt(x)</code>, <code>pow(x,y)</code>, <code>exp(x)</code>, <code>log(x)</code>, <code>ceil(x)</code>, <code>floor(x)</code>, <code>sin(x)</code>
  </ul>
  
