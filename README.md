# Moon Render

A small code to render characters using moon emoji in shell.

## Example

Github Logos in [Font Awesome]:

![](https://rikka.7sdre.am/files/22a7b2b3-7b52-4834-a3cd-9eaae67f51f2.png)

![](https://rikka.7sdre.am/files/0a8414a4-59e6-433c-8f54-e1c60d4dafd2.png)

"柒" in [TW-Kai] font:

<img src="https://rikka.7sdre.am/files/4f660184-e5e7-4b4c-a037-8c1d656dfe86.png" height="480" width="auto">

"7sDream" in [Fura Code](merge to one image using imagemagick):

![](https://rikka.7sdre.am/files/a16c38e5-50f5-40ac-9962-0a7607d959b1.png)

## Usage

Clone this repo and `cd` into it.

Change config variables' value to meet your needs by edit [line 23-28 in `main.c`][edit-config], then:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./moon-render
```

If you don't have cmake:

```bash
$ gcc -I<path/to/freetype/header> -L<path/to/freetype/library> -lfreetype main.c -o moon-render
$ ./moon-render
```

Here is my command for example:

```bash
$ gcc -I/usr/local/include/freetype2 -L/usr/local/lib -lfreetype main.c -o moon-render
```

## Dependencies

- [freetype] 2
- C compiler that support C11
- [CMake]（optional）

## LICENSE

GPLv3.

[Font Awesome]: https://fontawesome.com/
[TW-Kai]: https://data.gov.tw/dataset/5961
[Fura Code]: https://github.com/ryanoasis/nerd-fonts/tree/master/patched-fonts/FiraCode
[edit-config]: https://github.com/7sDream/moon-render/blob/master/main.c#L23-L28
[freetype]: https://www.freetype.org/
[CMake]: https://cmake.org/
