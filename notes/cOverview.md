<html>
<body>

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


<h3>C Data Types
</h3>
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

<h4>Operators</h4>
	<ul>
	  <li> Arithmetic: <code>+ - * / %</code>  (no exponentiation operator)
	<li> Relational: <code>&lt; &gt; &lt;= &gt;= == !=  </code>
    <li> Logical: <code>!</code> not   <code>&&</code> and   <code>||</code> or	
    <li> Assignment: <code>= += -= *= %= ++ --</code>
    <li> Precedence order:  always know where to look this up quickly (e.g. <a href="http://www.csee.umbc.edu/courses/104/fall06/burt/precedenceTable.html">here</a>)
	<li> Short-circuit (lazy) evaluation of boolean expressions
	<li> Bitwise logical operators (details later)
	<li> Bitwise shift operators (details later)
      </ul>			

<h3>Output in C</h3>

<p>
Prerequisite: <code>#include &lt;stdio.h&gt;</code> in header to access library functions; <a href="http://www.cplusplus.com/reference/cstdio/">Reference for <code>stdio.h</code></a>

  <ul>
   	<li> <code>putchar('d')</code> to output characters
	<li> <code>puts("some string")</code> to output strings
	<li> <code>printf("<em>format string</em>", <em>args</em>...)</code> for fancier output
		<li> formats: <br>
&nbsp;&nbsp;&nbsp;	<code>%i %d %f %c %s %n %ld %lf</code> for basic types<br>
&nbsp;&nbsp;&nbsp;			<code>%o</code> octal printing of ints<br>
&nbsp;&nbsp;&nbsp;			<code>%x</code> hex printing of ints
		<li> field widths<br>
&nbsp;&nbsp;&nbsp;
			<code>%<em>cols</em>.<em>decf</em> </code>- eg. <code>%.2f</code>, <code>%.6f</code><br>
&nbsp;&nbsp;&nbsp;
			right justified by default, use <code>%-</code> to left justify <br>
&nbsp;&nbsp;&nbsp;
			<code>-</code> and cols works for %d and %s also
		<li>See Kernighan Appendix B or <a href="http://www.cplusplus.com/reference/cstdio/printf/">this reference</a> for details
	      </ul>

</body>
</html>
