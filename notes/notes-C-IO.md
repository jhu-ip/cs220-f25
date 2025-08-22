---
id: notes-C-IO
layout: default
title: C Input/Output
---

<h3>I/O Functions</h3>

<p>See the list of functions on this 
  <a href="http://www.cplusplus.com/reference/cstdio/">reference website</a>.  

<h4>Standard input/output</h4>

<p>We must <code>#include &lt;stdio.h&gt;</code> to use this library.  The standard
     (built-in) streams are defined there: 
<ul>
  <li><code>stdin</code>: keyboard or input redirect input
</li>  <li><code>stdout</code>: standard  output (to console by default)
</li>  <li><code>stderr</code>: standard error output (to console by default)
</li>
</ul>

<h3>Output in C</h3>

<p>
Prerequisite: <code>#include &lt;stdio.h&gt;</code> in header to access library functions; <a href="http://www.cplusplus.com/reference/cstdio/">Reference for <code>stdio.h</code></a>

  <ul>
   	<li> <code>putchar('d')</code> to output characters
</li>	<li> <code>puts("some string")</code> to output strings
</li>	<li> <code>printf("<em>format string</em>", <em>args</em>...)</code> for fancier output
</li>		<li> formats: <br>
&nbsp;&nbsp;&nbsp;	<code>%i %d %f %c %s %n %ld %lf</code> for basic types<br>
&nbsp;&nbsp;&nbsp;			<code>%o</code> octal printing of ints<br>
&nbsp;&nbsp;&nbsp;			<code>%x</code> hex printing of ints
</li>		<li> field widths<br>
&nbsp;&nbsp;&nbsp;
			<code>%<em>cols</em>.<em>decf</em> </code>- eg. <code>%.2f</code>, <code>%.6f</code><br>
&nbsp;&nbsp;&nbsp;
			right justified by default, use <code>%-</code> to left justify <br>
&nbsp;&nbsp;&nbsp;
			<code>-</code> and cols works for %d and %s also
</li>		<li>See Kernighan Appendix B or <a href="http://www.cplusplus.com/reference/cstdio/printf/">this reference</a> for details
</li>	      </ul>

<h3>Input in C</h3>

<h4>Character-based Input</h4>

<ul>
	<li> <code>stdio</code> function <code>getchar()</code> reads one character from a file
</li>	<li> Returns <code>EOF</code> if at end of file
</li>    <li> Value of <code>EOF</code> is -1<br>
&nbsp;&nbsp;&nbsp; <code>getchar()</code> returns an <code>int</code> type for this reason (automatically cast to <code>char</code> if needed)
</li>    <li> Type ctrl-d in a Unix system to produce an <code>EOF</code> from keyboard (ctrl-Z (Enter) on a PC)
</li>  </ul>


<h4>Formatted Input</h4>

  <ul>
    <li>The <code>scanf</code> function works similarly to the printf
    output function for reading formatted input.
</li>    <li>  We use a format
    string followed by the <emph>memory locations</emph> (<em>addresses</em>) we are
    reading into. 
</li>    <li>We indicate this for most variables by preceding the
    variable name with an ampersand character (<code>&amp;</code>) to
    indicate "address of" the variable.  
</li>    <li>An exception is strings
    because they are arrays, and as we'll learn soon, array names are
    the memory address where the array starts. </p>
</li>  </ul>

Here is a list of the most common conversion specifications:<pre>
    %d integer  
    %ld long 
    %c char
    %s string
    %f float (real number type)
    %lf double, Lf long double
</pre>

There are also many fancy input format options, see <a href="http://www.cplusplus.com/reference/cstdio/scanf/">scanf documentation</a> for details:
<ul>
<li>Scan set notation: <code>%[a-zA-Z]</code> - inputs as long as chars in set, <code>[^0-9]</code> is "all except"
 inverse
</li><li> Use character literals to requre but skip over them, eg <code>%d-%d-%d</code> would successfully read <code>2-3-4</code>
</li><li> Use <code>%*c</code> to skip any character (<code>*</code> skips assigning any value)
</li></ul>

<p>Here is a short example:
```c
#include &lt;stdio.h&gt;
int main()
{
    int number;
    float x;
    double y;
    char word[20];
    scanf("%d", &number);
    scanf("%f %lf", &x, &y);
    scanf("%s", word);
}
```

<p>Note that we don't need <code>&amp;</code> in front of word because
        as an array it is an address already.  We also don't use a
        subscript since we're reading into the whole array.  When
        reading a string, scanf only reads up to first whitespace
        (space, tab, ret).  <emph>You must make sure memory is
        allocated for it and big enough to hold the characters that
        are input!</emph>
</p>


<h3>Sequential Files</h3>

<ul>
<li>Declare as: <code>FILE *fptr;</code> (<code>FILE</code> is the type of files, defined in <code>&lt;stdio.h&gt;</code>)
</li><li>Must open file for use, giving it pointer, name, and mode
   <code> fptr = fopen("name.txt", "w")</code>  (returns NULL if error)
</li><br />
<li>types of file openings:
    <ul>
      <li>    <code>"r"</code> - reading
     </li> <li>    <code>"w"</code> - create or overwrite file for writing
     </li> <li>    <code>"a"</code> - open or create file for appending to end
     </li> <li>    <code>"r+"</code> - open for update (read and/or write)
     </li> <li>    <code>"w+"</code> - create (overwrite) file for read &/or write
     </li> <li>    <code>"a+"</code> - open for read or write to end
   </li> </ul>
</li><br />
<li>Close a file when done: 
    <code>fclose(fptr);</code> - very important to permanently save file!
</li><br />
<li>Test for end of file: 
    <code>feof(fptr)</code> returns 1 if end, 0 otherwise
</li><li><code>fflush(fptr)</code> - flush the buffer - usually for output
</li><li><code>rewind(fptr)</code> - set <code>fptr</code> to the beginning of file

</li><br />
<li>The I/O functions above have more general versions for working with files, not  just <code>stdin/stdout</code>: put an <code>f</code> prefix on the name and add <code>fileptr</code> parameter:
    <ul>
      <li> <code>fprintf(fileptr, formatstring, ...);</code>
     </li> <li><code>fscanf(fileptr, formatstring, ...);</code>
     </li> <li><code>fgetc(fileptr)</code>; note <code>fgetc(stdin) == getchar()</code>
      </li><li><code>fputc('c',fileptr)</code>; note  <code>fputc('c', stdout) == putchar('c')</code>
  </li>    <li><code>fputs(str,maxlength,fileptr)</code>; note <code>maxlength</code> is there to prevent buffer overrun holes
</li>      <li><code>fgets(str,maxlength,fileptr)</code>
</li>    </ul>
</li>
</ul>
  
