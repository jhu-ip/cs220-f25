#include <iostream>

class BaseClass {
public:
  virtual void compute() { std::cout << "base "; }
};
class ChildClass {
public:
  virtual void compute() { std::cout << "child "; }
};

int main() {
   BaseClass b;
   b.compute();
   ChildClass c;
   c.compute();
   BaseClass *p;
   p = &b;
   p->compute();
   p = (BaseClass *) &c;
   p->compute();
   //   ChildClass cb = (ChildClass) b;
}
