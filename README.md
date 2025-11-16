# pocket-racing-server

A simple racing server implementation with a library, server binary, and tests built using Meson.

## Building

This project uses the Meson build system. To build:

```bash
# Setup build directory
meson setup builddir

# Compile
meson compile -C builddir
```

## Running Tests

```bash
# Run all tests
meson test -C builddir
```

## Running the Server

```bash
# Run the server binary
./builddir/pocket-racing-server
```

## Project Structure

- `include/` - Public header files
- `src/` - Source files for the library and server
- `tests/` - Test files
- `meson.build` - Main build configuration
- `tests/meson.build` - Test build configuration

## Components

### Library (`libracing.a`)
A static library providing racing functionality.

### Server (`pocket-racing-server`)
The main server binary that uses the racing library.

### Tests (`test_racing`)
Unit tests for the racing library.