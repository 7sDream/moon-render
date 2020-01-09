# Moon Render

A small code to render characters using moon emoji in shell.

## Example

"柒" in [TW-Kai] font:

![Kai-qi]

"7sDream" in [Fura Code](merge to one image using imagemagick):

![Fura-7sDream]

## Usage

Change config variable value to meet your needs by edit line 23-28 in `main.c` then:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./moon-render
```

If you dont want use cmake:

```bash
$ gcc -I<path/to/freetype/header> -L<path/to/freetype/library> -lfreetype main.c -o moon-render
$ ./moon-render
```

Here is my command for example: `gcc -I/usr/local/include/freetype2 -L/usr/local/lib -lfreetype main.c -o moon-render`.

## Dependencies

- [freetype] 2
- C compiler that support C11
- [CMake]（If you use）

## LICENSE

GPLv3.

[TW-Kai]: https://data.gov.tw/dataset/5961
[Fura-Code]: https://github.com/ryanoasis/nerd-fonts/tree/master/patched-fonts/FiraCode
[Kai-qi]: https://rikka.7sdre.am/files/4f660184-e5e7-4b4c-a037-8c1d656dfe86.png
[Fura-7sDream]: https://rikka.7sdre.am/files/140493ef-9484-42f7-9736-5dd6354d04db.png
[freetype]: https://www.freetype.org/
[CMake]: https://cmake.org/
