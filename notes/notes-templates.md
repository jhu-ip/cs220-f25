---
id: notes-templates
layout: default
title: Templates in C++
---

<h3>Template Definitions</h3>

We can define our own function and class templates to be instantiated
and used with multiple different types, similarly to the STL
algorithms and classes.

<h4>Function Templates</h4>

<ul>
  <li> Can use to define generic function with abstract param types
</li><li> Use <code>template&lt;class Tname&gt;</code> before prototype and function definition
</li><li> Use <code>Tname</code> as type in function
</li><li> Compiler generates the actual functions by substituting types of
    arguments in the various function calls
</li></ul>

Example:

```cpp
template <class T>        // generic class type name T
T cubeit(T num)           // header using type T
{
    return num * num * num;   // assumes * operation defined for type T
}

int main(void) {
  cubeit(3);
}
```


<h4>Class Templates</h4>
