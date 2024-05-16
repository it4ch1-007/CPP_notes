```
while (cin >> i) /* ... */

The above statement will only terminate when the input is given such that the i is eofbit or a badbit.
```

```
app : Seek to the end before every write
ate : Seek to the end immediately after the open
```

- The default constructor takes no arguments and is synthesized by the compiler only.
- If the class does not have a default constructor then no member of the class can be initialized using the constructor.

```
Sales_data() = default;
```
- This can also be used for assigning the default constructor.
- Defining the constructor of the class outside the class
```
class::class(std::istream &is)
{
    read(is,*this);
}
```
- Here this pointer is used to reference the class and the input data from the user is stored into the class reference.

- The difference between the struct and the class is the default access level of both the datatypes.

- `friend` keyword is used for declaring the friend functions inside the classes and defining them outside the class that can use all the methods and variables of the class.

- Declaring a type of the given data using `using`:

```
class Screen {
public:
// alternative way to declare a type member using a type alias
using pos = std::string::size_type;
// other members as before
};
```

- The inline functions are attached to the code once thay are called by the compiler.
- Classes can be declared without defining them and giving it variables and methods:

```
class Myclass;
```

```
class Screen {
// Window_mgr::clear must have been declared before class Screen
friend void Window_mgr::clear(ScreenIndex);
// . . . rest of the Screen class
};
```

- Here the friend function `clear` is the friend function of Window_mgr and it can access all private components of the class Window_mgr.

- Every friend function has to be listed as a friend keyword prefiux fuynction inside the class it is the friend of .

- In classes , first the member declarations are compiled and then the member function details are compiled.

```
typedef is the keyword that is used to give a new name to a datatype
typedef int Integer
Integer x=42; (this is equivalent to int x=42;)
```
- constants and references must be intialized necessarily.

```
struct X {
X (int i, int j): base(i), rem(base % j) { }
int rem, base;
};
```
- This code has the error of prder of initialisation where the rem variable is initialized before the base variable while we have used the base variable inside the initialisation of rem variable and thus we should declare the rem variable after the declaration of base variable.

- Initialiser of constructors:

```
MyClass(int value) : data(value) {}
```
```
class ExplicitClass {
public:
    // Explicit regular constructor
    explicit ExplicitClass(int value) : data(value) {}

    // Explicit conversion constructor
    explicit ExplicitClass(double value) : data(static_cast<int>(value)) {}

private:
    int data;
};

```

- This code depicts an explicit constructor that prevents the compiler from converting all the encountered datatypes from converting to the Class datatype.

- In this example, the explicit constructor will not allow the compiler to convert the `int` and `double` datatypes to the `ExplicitClass` datatype.

- Implicit constructors are those which can be called by the compiler on its own on the making of the object of that class.

- Aggregate classes 

    They have:
    - All public data.
    - No defined constructors.
    - No in class initializers.

- Literal Classes

    - It should be non aggregate.
    - It should have all members of literal types.
    - Atleast one constexpr constructor.
    - If a data member has an in-class initializer, the initializer for a member of
        built-in type must be a constant expression.
    - The class must use default definition for its destructor, which is the member
        that destroys objects of the class type.

```
constexpr keyword is to define the member or a constructor or an object declaration that can be evaluated at compile time allowing time to the objects of constexpr instance to be created first.
```
- The below program actually is used to add two integers by binary operators and logical operators.
- Solution of 'AB' excel sheet problem where we recursively multiplies the column name to obtain the correct column and row number.

```
 int cnt=0;
    for(int i=0;i<A.size();i++){
        cnt=cnt*26 + (int(A[i])-64);
    }
    return cnt;
```
```
 int xo=A^B;
    int an=A&B;
    an=an<<1;
    if(xo&an)
    return addNumbers(xo,an);
    return (xo|an);
```

- TREES

    - Leaf nodes:
        Those which donot have any child nodes (the immediate successors).
    - Root node:
        Those which donot have any parent node (the immediate predecessor).
    - Siblings
        Children of same parent node.
    - Internal node:
        Atleast one child node.
    - Binary Tree: Only have two nodes at max attached to a node
    - Ternary Tree: Have three nodes attached at max to a node
    - N-ary/Generic Tree: Have many nodes attached to a node.
    - Traversal techniques:

        - Inorder Traversal: `Left->Root->Right`
        - Preorder Traversal: `Root->Left->Right`
        - Postorder Traversal: `Left->Right->Root`
        - Level Order Traversal: Level by Level
        - Boundary Traversal: Boundary elements first
        - Diagonal Traversal: Each diagonal is printed one by one.

    - Red-Black Tree
        - `Root` is `black`.
        - Every `Leaf` is `black`.
        - Child of a `red` node is `black`.
        - Every path from root to leaf node has the same number of `black` nodes.
        - No two adjacent `red` nodes.

        ```
        The black height of the red-black tree is the number of black nodes on a path from the root node to a leaf node. Leaf nodes are also counted as black nodes. So, a red-black tree of height h has black height >= h/2.

        Height of a red-black tree with n nodes is h<= 2 log2(n + 1).
        ```

    - AVL Tree

        - A special type of Binary Search Tree that has special form of rotations to decrease the height of the overall tree. Its form does not depend upon the order of the given input as binary tree.

        - LL imbalance, LR imbalance, RR imbalance.

        
    



