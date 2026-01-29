$rootDir = "$env:HCHTR_HOME/repos/atay"

$CC = "clang"

$SRC = Get-ChildItem "$rootDir/src" -Filter *.c | ForEach-Object { $_.FullName }

$CFLAGS = @(
    "-O2"
    "-nostdlib"
    "-ffreestanding"
    "-fno-builtin"
    "-I$rootDir/include"
)

$compileCommandsFile = "$rootDir/compile_commands.json"
if (Test-Path $compileCommandsFile) { Remove-Item $compileCommandsFile }

$compileCommands = @()
foreach ($file in $SRC) {
    $compileCommands += @{
        directory = $rootDir
        command   = "$CC $($CFLAGS -join ' ') -c $file"
        file      = $file
    }
}

$compileCommands | ConvertTo-Json -Depth 3 | Out-File -Encoding UTF8 $compileCommandsFile

$LDFLAGS = @(
    "-Wl,-entry:start"
    "-Wl,-subsystem:console"
    "-lkernel32"
)

$buildDir = Join-Path $rootDir 'build'

if (-not (Test-Path $buildDir)) {
    New-Item -ItemType Directory -Path $buildDir | Out-Null
}

$OUT = Join-Path $buildDir 'a.exe'

& $CC $SRC $CFLAGS $LDFLAGS -o $OUT
