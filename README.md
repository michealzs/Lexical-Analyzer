# Lexical-Analyzer

A flex scanner for the small teaching language used in the UMGC CMSC 430
(Compiler Theory and Design) projects. It reads a source file on standard
input, echoes it back as a line-numbered listing, reports any character it
cannot classify as a lexical error, and writes every token it recognizes
(token number and matched text, one per line) to `lexemes.txt`.

The scanner recognizes whitespace, `//` and `--` line comments, the
arithmetic, relational and logical operators, the language keywords
(`function`, `returns`, `begin`, `end`, `if`, `elsif`, `endif`, `switch`,
`case`, `fold`, `when`, and so on), identifiers, and integer, real,
character and `#hex` literals.

## Build

Requires `flex`, `g++` and `make`. The makefile runs flex on `scanner.l`,
renames the output to `scanner.c`, and compiles it together with `listing.cc`
using g++.

```sh
make
```

This produces an executable named `compile`.

Known issue: on the current `main` branch, lines 9 to 16 of `scanner.l` hold
a comment block that is not valid flex syntax (the opening `/*` line is
indented but the lines after it are not), so `flex` stops with "incomplete
name definition". Removing or indenting those lines lets `make` finish. The
`v1` branch does not have this problem.

## Run

```sh
./compile < program.txt
```

The listing goes to standard output and ends with `Compiled Successfully` or
a count of lexical, syntax and semantic errors. The tokens go to
`lexemes.txt` in the current directory.

## Layout

- `scanner.l` - flex rules for the language and the `main()` function
- `tokens.h` - the `Tokens` enum returned by the scanner (values start at 256)
- `listing.h`, `listing.cc` - line-numbered listing output and error counting
- `makefile` - build rules
- `note.txt` - a scratch shell script that removes build output and runs
  `compile` against test files in `../p1data/` (those files are not in this
  repository)

Status: coursework project, kept for reference.
