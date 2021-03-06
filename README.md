Parse Utils
==============================================
    Created By:   Michael D. Lowis
    Email:        mike@mdlowis.com

About This Project
----------------------------------------------
This project implements a library of useful classes for developing recursive
descent parsers in c/c++. The library provides a generic abstract syntax tree
class, lexer and parser base classes, as well as a tree visistor class with a
useful implementation for pretty printing an arbitrary syntax tree. Users of
this library can link against it statically or dynamically.

License
----------------------------------------------
Unless explicitly stated otherwise, all code and documentation contained within
this repository is released under the BSD 2-Clause license. The text for this
license can be found in the LICENSE.md file.

Requirements For Building
----------------------------------------------

TODO

Build Instructions
----------------------------------------------

You can build the project and run all unit tests with the following command:

    make

You can build just the release binaries with the following command:

    make release

You can execute just the unit tests with the following command:

    make test

Project Files and Directories
----------------------------------------------

    docs/          Documentation for the project.
    res/           Miscellaneuos files needed for the project.
    source/        The source for the DLang parser.
    tests/         Unit test and mock files.
    tools/         Tools required by the build system.
    Doxyfile       Doxygen documentation generator configuration.
    LICENSE.md     The software license notification.
    Makefile       File containing rules for building the project.
    project.vim    A VIM script with project specific configurations.
    README.md      You're reading this file right now!

