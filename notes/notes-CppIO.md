---
id: notes-CppIO
layout: default
title: C++ I/O
---

<h3>Input/Output in C++</h3>

C++ has a very simple system for I/O.

<ul>
<li>The bit shift operators <code>&lt;&lt;</code> and <code>&gt;&gt;</code> are overloaded to perform output (stream insertion) and input (stream extraction), respectively
</li><li>C++ overloads meanings of other operators as well, e.g. "<code>+</code>" can concatenate strings (more on this later)
</li>
  <li>Stream extraction operator <code>&gt;&gt;</code> will read into any primitive data type; type read is based on type of variable, not a format string
</li><li> Uses all forms of whitespace to tokenize
</li><li> Invalid input (wrong data type) puts stream in error condition
</li><li> <code>&lt;&lt;</code> and <code>&gt;&gt;</code> are binary operators, result is modified stream, allows chaining
</li><li> Using <code>cin</code> as loop control:  
    value is <code>true</code> boolean if stream is in good state, <code>false</code> otherwise:<br />
<code>while (cin &gt;&gt; n) process(n);<br />
while (cin.get(ch)) process(ch);
</code>
</li><li> Output buffer automatically flushed with <code>\n</code>, <code>endl</code>, <code>read</code>, or buffer full
</li></ul>

Here are some examples:

```cpp
std::cin >> thing1 >> thing2;    // read thing1 then thing2 from cin, standard input stream
std::cout << thing1 << thing2;   // write thing1 then thing2 to cout, standard output stream (no spaces included)
std::cout << '\n' << std::endl;  // output newline, newline and flush buffer
std::cin.get(ch);                // read one character

// equivalent form if appropriate using declarations were given:

cin >> thing1 >> thing2;
cout << thing1 << thing2;
cout << '\n' << endl;
cin.get(ch);
```




