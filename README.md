![rainicorn](logo.png?raw=true "logo")

- [What is `rainicorn`?](#what-is-rainicorn)
- [What does the name `rainicorn` mean?](#what-does-the-name-rainicorn-mean)
- [How should I use it?](#how-should-i-use-it)
- [Is there an "OFF" switch?](#is-there-an-off-switch)

What is `rainicorn`?
--------------------

It is a collection of macros for formatted (colored and styled) outputs via the
ANSI escape sequences in a single header file.



What does the name `rainicorn` mean?
------------------------------------

> Rainicorns are a species of rainbow/unicorn creatures that live in peace in
> the Land of Ooo and also the Crystal Dimension.
> *-- [Adventure Time Wiki](http://adventuretime.wikia.com/wiki/Rainicorns)*



How should I use it?
--------------------

First, include the header file:

```C
#include "rainicorn.h"
```

There are three types of values you can change. The `F` (foreground), the `B`
(background) and the `S` (style). We can set and remove these values with the
given macros. For example let's only change the foregrounds:

```C
printf(rc_F(rc_RED, "Hello, ")
       rc_F(rc_YELLOW, "World!")
       rc_RESET("\n"));
```

Notice, that there are now `,` between the macro calls, as they will evaluate to
string literals, which will be concatenated during the translation.

Here is another example, where we set `F` to green, and then leave it like that
and set `B` to white:

```C
printf(rc_F(rc_GREEN, "Hello, ")
       rc_B(rc_WHITE, "World!")
       rc_RESET("\n"));
```

If we want to remove the green `F` color from `"World!"` we should do:

```C
printf(rc_F(rc_GREEN, "Hello, ")
       rc_FB(rc_DEF_FG, rc_YELLOW, "World!")
       rc_RESET("\n"));
```

But, of course we can also change it to cyan as well:

```C
printf(rc_F(rc_GREEN, "Hello, ")
       rc_FB(rc_CYAN, rc_YELLOW, "World!")
       rc_RESET("\n"));
```

We don't have to overwrite a value, if we want only to remove a property, we
should use the `R` prefixed versions of the macros:

```C
printf(rc_F(rc_GREEN, "Hello, ")
       rc_RF("World!")
       rc_RESET("\n"));
```

For all the available options, you should read the header file, and for more
examples, you should check the `test.c` file!



Is there an "OFF" switch?
-------------------------

Sure, you don't have to rewrite your code-base which is using `rainicorn` if you
want to get rid of the colorful outputs. You only have to define the `MONOCORN`
preprocessor variable, either by passing it with the `D` flag to the compiler:

```
-DMONOCORN
```

or by defining it before the includes of the header (for local switching):

```C
#define MONOCORN
#include "rainicorn"
```


---

You can find the license and all other useful informations about the font used
in the logo of this project at
[FontSquirrel: Spinwerad](http://www.fontsquirrel.com/fonts/spinwerad)
