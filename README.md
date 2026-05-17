# Mouse Kitty

## macOS Setup

First, run the setup script to install dependencies:

```bash
chmod +x setup_kitty_macos.sh
./setup_macos.sh
```

Then build:

```bash
mkdir build && cd build
cmake ..
make
./kitty
```

## Linux Setup

Install dependencies:
```bash
sudo apt install git cmake libraylib-dev libx11-dev
```

Then build as above.
