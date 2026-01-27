$CC = "clang"

$SRC = @(
    "../src/main.c"
)

$CFLAGS = @(
    "-O2"
    "-nostdlib"
    "-ffreestanding"
    "-fno-builtin"
)

$LDFLAGS = @(
    "-Wl,-entry:start"
    "-Wl,-subsystem:console" 
    "-lkernel32"
)

$OUT = "../build/a.exe"

& $CC $SRC $CFLAGS $LDFLAGS -o $OUT
