$CC = "clang"

$SRC = @(
    "../src/main.c"
    "../src/logger.c"
)

$CFLAGS = @(
    "-O2"
    "-nostdlib"
    "-ffreestanding"
    "-fno-builtin"
    "-I../include"
)

$LDFLAGS = @(
    "-Wl,-entry:start"
    "-Wl,-subsystem:console" 
    "-lkernel32"
)

$OUT = "../build/a.exe"

& $CC $SRC $CFLAGS $LDFLAGS -o $OUT
