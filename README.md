![rainicorn](img/logo.png?raw=true "logo")

- [What is `rainicorn`?](#what-is-rainicorn)
- [What does the name `rainicorn` mean?](#what-does-the-name-rainicorn-mean)
- [How should I use it?](#how-should-i-use-it)
- [Is there an "OFF" switch?](#is-there-an-off-switch)
- [License](#license)



What is `rainicorn`?
--------------------

It is a header only *library*. A collection of macros to create formatted
outputs &mdash; that is, colored and styled &mdash; using the [ANSI escape
sequences](https://en.wikipedia.org/wiki/ANSI_escape_code).



What does the name `rainicorn` mean?
------------------------------------

> Rainicorns are a species of rainbow/unicorn creatures that live in peace in
> the Land of Ooo and also the Crystal Dimension.
> *-- [Adventure Time Wiki](http://adventuretime.wikia.com/wiki/Rainicorns)*



How should I use it?
--------------------

First, include the header file:

```C
#include <rainicorn/rainicorn.h>
```

There are three types of values you can change. The `F` (foreground), the `B`
(background) and the `S` (style). These values can be set and removed
individually or with combinations of each other via the predefined macros. For
example let's change only the foregrounds:

```C
puts("\""
     RC_F(RC_RED, "Hello, ")
     RC_F(RC_YELLOW, "World!")
     RC_XFBS("\"\n"));
```

> **NOTE:** There are no commas (`,`) after the macro calls. This is because
> these macros will evaluate to string literals, which are going to be
> concatenated during the translation.

The last macro, `RC_XFBS`, is the *ultimate* reset, as it sets the foreground
and background colors and the style as well to their original default values.

The previous example will produce the following output:

![doc-01](img/doc-01.png?raw=true "doc-01-output")

In the next example, we set `F` to blue for the entire text, but also we set
`B` to white for the second word:

```C
puts("\""
     RC_F(RC_BLUE, "Hello, ")
     RC_B(RC_WHITE, "World!")
     RC_XFBS("\"\n"));
```

![doc-02](img/doc-02.png?raw=true "doc-02-output")

If we want to remove the green `F` color from `"World!"` in the next example,
we can do it in two ways:

```C
/* Set the F back to default and set the background to magenta */
puts("\""
     RC_F(RC_GREEN, "Hello, ")
     RC_FB(RC_DEFAULT, RC_MAGENTA, "World!")
     RC_XFBS("\"\n"));

/* Remove the foreground color and set the background color to magenta */
puts("\""
     RC_F(RC_GREEN, "Hello, ")
     RC_XF(RC_B(RC_MAGENTA, "World!"))
     RC_XFBS("\"\n"));
```

The output for both is going to be:

![doc-03](img/doc-03.png?raw=true "doc-03-output")

> **NOTE:** Though the two are the same, the former is creating a single
> control sequence, while the latter will produce two. (The performance
> difference is probably neglectable, and since both are correct, use the one
> which is easier to read/understand for you.)

Sometimes removing a particular value is the right move! For example if you want
to colorize and make bold the first third of the next line; and then you want to
have bold but uncolored text for the second third; and last, you want letters
without color or style for the end, then you would do something like this:

```C
puts("\""
     RC_FS(RC_CYAN, RC_BOLD, "Hello, ")
     RC_XF("World! ")
     RC_XFBS("Good bye!\"\n"));
```

![doc-04](img/doc-04.png?raw=true "doc-04-output")

*For all the available options and values, you should consult the header files!*



Is there an "OFF" switch?
-------------------------

Of course, if you want to get rid of all the fine, and joyful colors, you don't
have to rewrite your code-base which is using `rainicorn`! All you have to do is
define the `RC_MONOCORN` preprocessor variable, either by passing it with the
`D` flag to your C compiler:

```
-DRC_MONOCORN
```

or by defining it before the includes of the headers:

```C
#define MC_MONOCORN
#include <rainicorn/rainicorn.h>
```



License
-------

Copyright &copy; 2015 - 2016 Peter Varo
&lt;[http://github.com/petervaro/rainicorn](http://github.com/petervaro/rainicorn)&gt;

This program is free software: you can redistribute it
and/or modify it under the terms of the GNU General
Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your
option) any later version.

This program is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public
License along with this program, most likely a file in
the root directory, called "LICENSE". If not, see
&lt;[http://www.gnu.org/licenses](http://www.gnu.org/licenses)&gt;.

---

You can find the license and all other useful informations about the font used
in the logo of this project at
[FontSquirrel: Spinwerad](http://www.fontsquirrel.com/fonts/spinwerad)
