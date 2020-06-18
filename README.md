A multi-language, multi-engine home for various mostly code-generated bindings to the [dear imgui](https://github.com/ocornut/imgui) library.

what's implemented:
* [lua bindings](src/lua-bindings/README.md)
* [wren bindings](src/wren-bindings/README.md)
* [love2d integration, using lua bindings](src/love-imgui/README.md)

The code-generated pieces of these bindings originate from the [bindings2](bindings2) lua script.

## Building

As a user of these bindings, you can just integrate the subset of files you
would like to use into your project or engine. however, Go to each individual
project for more specific info. If you would like to help develop the bindings,
or compile the test cases, we use cmake.

```
$ mkdir build
$ cmake ..
$ make
```

cmake will automatically re-run the bindings when it detects a source file has
changed. Adding new files, either manually written cpp or binding script files,
should be added to cmake.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

