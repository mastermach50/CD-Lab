# shell.nix for C/C++ Environment
{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  name = "C";

  nativeBuildInputs = with pkgs; [
    # Compilers and Libraries
    gcc
    clang

    # Editor Support
    gdb
    lldb
    clang-tools

    # Dependency Discovery
    pkg-config

    bison
    flex
  ];

  buildInputs = with pkgs; [ ];

  shellHook = ''
    export CPATH="${pkgs.glibc.dev}/include:$CPATH"

    if [ -t 0 ] && [ -z "$NU_SHELL_ACTIVE" ]; then
      export NU_SHELL_ACTIVE=1
      exec nu
    fi
  '';
}
