# smm : show me the members

Lightweigth single header C++20 library.

Offerings two simple functionalities,  
to introspect public data stucture (*aggregate*),  
without any need for annotation or change in user code.

***

### `smm::for_each_member`     
A function use to apply the same invocable,  
on each data member.  

```
    #include <iostream>
    #include "for_each.hpp"
    
    struct Point{ double x{}, y{}, z{}; };
    
    int main()
    {
        Point p {1, 2, 3};
        auto print = [](double m){ std:: cout << m << ' '; };
        smm::for_each_member(p, print);
    }
    // => output : "1 2 3 "
```

***

###  `smm::for_all_members`     
A function use to apply an invocable once,  
with all data members as argument.  


```
    #include <iostream>
    #include "for_each.hpp"
    
    struct Point{ double x{}, y{}, z{}; };
    
    int main()
    {
        Point p {1, 2, 3};
        auto print = [](double m0, auto...ms)
        {
            std:: cout << m0;
            ((std:: cout << ' ' << ms), ...);
        };
        smm::for_all_members(p, print);
    }
    // => output : "1 2 3"
```
