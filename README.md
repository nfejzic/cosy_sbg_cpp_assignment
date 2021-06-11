# C++ Assignment at Uni Salzburg

Semester: WS20/21

## Compilation

Run `make` command inside the repo directory

## Running the programm

`./programm stadt.dat gebiet.dat strasse.dat City1 City2`

The `.dat` files are files containing information about cities (`stadt.dat`), areas (`gebiet.dat`) and streets (`strasse.dat`) needed for computing the shortest path.

### `stadt.dat` is formatted as follows:

| city_id | city_name | population | area_id | elevation |

### `gebiet.dat` is formatted as follows:

| area_id | area_name | super_area_id | type |

**NOTE:** This file is not used in this project, was there as part of assignment specification

### `strasse.dat` is formatted as follows:

| from_city_id | to_city_id | distance |

## **NOTE:** About `compile_commands.json`

I use Sublime Text 4 with SublimeLSP package using `clangd` language server.

`clangd` needs the `compile_commands.json` file in order to work correctly.
To generate `compile_commands.json` use the [Bear](https://github.com/rizsotto/Bear)!

Command: `make clean; bear -- make` performs compilation and creates `compile_commands.json` for you.
