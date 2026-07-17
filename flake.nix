{
  description = "HRenderer's development shell";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs { inherit system; };
  in
  {
    devShells.${system}.default = pkgs.mkShell {
      packages = with pkgs; [
        gcc
        gdb
        gnumake
        ninja
        
        cmake
        pkg-config

        glfw3
        glm
      ];
    };
  };
}
