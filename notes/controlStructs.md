<html>
<body>

<p>
In general control structures in C are very similar to those in Java.
The <code>for</code> loop is very different than in Python.  Remember
when writing boolean expressions that all numbers are booleans in C:
zero is false, all else is true!  Anywhere a statement appears in
these generic forms, a block statement enclosed in curly braces ({})
could be used instead.
</p>

<h4>Decision statements</h4>

<p>Here are generic forms of the decision statements. 
<code><pre>
  if (boolean expr) 
    true-statement;  // or { block }

  if (boolean expr)
    true-statement;  // or { block }
  else
    false-statement; // or { block }

  switch (integer expr) {
  case c1: stmt1;  // execution starting point for c1
  case c2: stmt2;
           break;  // exits switch block
  case c3: 
  case c4: stmt3; 
           stmt4;  // executes stmt3, stmt4 and stmtlast for c3 or c4 matches
  default: stmtlast;   // if no case matches
  }
</pre></code>

<h4>Loops
</h4>

<p>Here are generic forms of the three loop types in C.
  <code><pre>
  while (boolean expr) 
    true-statement;  // or { block }, repeats to while

  do {
    statement-always-executes-at-least-once;
  } while (boolean expr);  // repeat while true

  for (init; boolean expr; update) 
    true-statement;  // or { block }
</pre></code>
<p>is equivalent to<code>
<pre>  init;
  while (boolean expr) {
    true-statement;
    update;
  }
</pre></code>


<h4>Loop invariants</h4>

<p>These are statements that should be true at the start of every
  iteration.  We can use <code>assert</code> statements to check if
  they are good (true): <code><pre>
  // need #include &lt;assert.h&gt;
  // need #include &lt;math.h&gt;  and compile with -lm option to link math library

  int i = 0;
  int val = 1;
  while (i < 15 ) {
    assert (val == pow(2,i));
    i++;
    val *= 2;
  } 
</pre></code>


</body>
</html>
