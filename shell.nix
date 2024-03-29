{ pkgs ? import<nixos-unstable>{} }:
let
  stdenv = pkgs.gcc11Stdenv;
in stdenv.mkDerivation rec {
  name = "uvbind";
  src = pkgs.fetchFromGitHub {
    repo = name;
    owner = "zerhud";
    rev = "de41b2577203672e6704b11e28946b75f08299eb";
    sha256 = "0rs9bxxrw4wscf4a8yl776a8g880m5gcm75q06yx2cn3lw2b7v22";
  };
  nativeBuildInputs = with pkgs; [ meld qtcreator cmake ninja ];
  buildInputs = with pkgs; [ libuv boost17x ];
  CTEST_OUTPUT_ON_FAILURE=1;
}
