<p align="center">
  <h1 align="center">Seven-Segment Time Display</h1>
  <p align="center">
    A lightweight, cross-platform C++ command-line application that renders the current local date and time using seven-segment-style ASCII art directly in your terminal.
  </p>
</p>

<p align="center">
  <a href="https://isocpp.org/"><img src="https://img.shields.io/badge/Language-C%2B%2B11-00599C?logo=cplusplus&logoColor=white" alt="C++11"></a>
  <a href="#supported-platforms"><img src="https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-informational" alt="Platform"></a>
  <a href="#license"><img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License: MIT"></a>
  <a href="https://github.com/ad-digital-labs/Seven_segment-time_display"><img src="https://img.shields.io/github/last-commit/ad-digital-labs/Seven_segment-time_display" alt="Last Commit"></a>
  <a href="https://github.com/ad-digital-labs/Seven_segment-time_display/issues"><img src="https://img.shields.io/github/issues/ad-digital-labs/Seven_segment-time_display" alt="Issues"></a>
</p>

---

## Table of Contents

- [Overview](#overview)
- [Demo](#demo)
- [Features](#features)
- [Supported Platforms](#supported-platforms)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
  - [Linux](#linux)
  - [macOS](#macos)
  - [Windows](#windows)
- [Usage](#usage)
- [Calendar & Date/Time Format](#calendar--datetime-format)
  - [Display Format](#display-format)
  - [Supported Characters](#supported-characters)
  - [Seven-Segment Rendering](#seven-segment-rendering)
- [How It Works](#how-it-works)
  - [Segment Encoding](#segment-encoding)
  - [Program Flow](#program-flow)
  - [Error Handling](#error-handling)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [Roadmap](#roadmap)
- [FAQ](#faq)
- [License](#license)
- [Author](#author)

---

## Overview

**Seven-Segment Time Display** is a minimalist, zero-dependency C++ program that transforms the current system date and time into a retro-style seven-segment LED display rendered entirely in ASCII art within your terminal.

Inspired by classic digital clocks and embedded display panels, this project provides:

- A fun, visual way to view the current date and time from the command line
- A clean example of character mapping, string manipulation, and system time handling in C++
- A single-file, portable implementation that compiles and runs on any major operating system

---

## Demo

When you run the program, it outputs the current date and time in seven-segment format:

```
 _   _       _   _       _   _   _   _          _   _       _   _
| | |_|   * |_|  _|   *  _| | |  _|  _|   ***  | |  _|  *   _|  _|
|_|  _|  *  |_| |_   *  |_  |_| |_   _|        |_| |_   *  |_   _|
```

> **Example:** The output above represents a date and time rendered in seven-segment style.

---

## Features

- **Real-time display** — Fetches and displays the current local system date and time
- **Seven-segment ASCII art** — Mimics the look of classic LED/LCD seven-segment displays
- **Cross-platform** — Compiles and runs on Linux, macOS, and Windows
- **Zero dependencies** — Uses only the C++ Standard Library (`<iostream>`, `<string>`, `<time.h>`, `<cctype>`)
- **Single-file implementation** — All logic contained in a single `a.cpp` file for easy compilation
- **Input validation** — Validates internal formatting with descriptive error codes
- **Lightweight** — Minimal binary size; compiles in under a second
- **Portable** — Requires only a C++11-compliant compiler

---

## Supported Platforms

| Platform        | Compiler(s)                          | Status       |
|-----------------|--------------------------------------|--------------|
| **Linux**       | `g++`, `clang++`                     | Fully supported |
| **macOS**       | `clang++` (Xcode), `g++` (Homebrew) | Fully supported |
| **Windows**     | MSVC (`cl`), MinGW (`g++`), Clang   | Fully supported |
| **FreeBSD**     | `clang++`, `g++`                     | Should work  |
| **WSL**         | `g++`, `clang++`                     | Fully supported |

---

## Prerequisites

A C++ compiler that supports **C++11 or later** is required. Below are setup instructions for each platform.

### Linux (Debian/Ubuntu)

```bash
sudo apt update
sudo apt install g++ build-essential
```

### Linux (Fedora/RHEL/CentOS)

```bash
sudo dnf install gcc-c++ make
```

### Linux (Arch Linux)

```bash
sudo pacman -S gcc make
```

### macOS

Install the Xcode Command Line Tools (includes `clang++`):

```bash
xcode-select --install
```

Alternatively, install GCC via [Homebrew](https://brew.sh/):

```bash
brew install gcc
```

### Windows

Choose one of the following options:

#### Option A: MinGW-w64 (Recommended for beginners)

1. Download and install [MinGW-w64](https://www.mingw-w64.org/downloads/) or install via [MSYS2](https://www.msys2.org/):

   ```bash
   # Using MSYS2 package manager
   pacman -S mingw-w64-x86_64-gcc
   ```

2. Add the MinGW `bin` directory to your system `PATH`.

#### Option B: Microsoft Visual Studio (MSVC)

1. Download and install [Visual Studio](https://visualstudio.microsoft.com/) (Community Edition is free).
2. During installation, select the **"Desktop development with C++"** workload.
3. Use the **Developer Command Prompt** or **Developer PowerShell** to compile.

#### Option C: Windows Subsystem for Linux (WSL)

1. Enable WSL and install a Linux distribution from the Microsoft Store:

   ```powershell
   wsl --install
   ```

2. Inside WSL, follow the [Linux installation instructions](#linux-debianubuntu).

---

## Installation

### Linux

```bash
# 1. Clone the repository
git clone https://github.com/ad-digital-labs/Seven_segment-time_display.git

# 2. Navigate to the project directory
cd Seven_segment-time_display

# 3. Compile the source code
g++ -std=c++11 -o seven_seg a.cpp

# 4. (Optional) Install system-wide
sudo cp seven_seg /usr/local/bin/
```

### macOS

```bash
# 1. Clone the repository
git clone https://github.com/ad-digital-labs/Seven_segment-time_display.git

# 2. Navigate to the project directory
cd Seven_segment-time_display

# 3. Compile with clang++ (default on macOS)
clang++ -std=c++11 -o seven_seg a.cpp

# Alternative: Compile with g++ (if installed via Homebrew)
# g++ -std=c++11 -o seven_seg a.cpp

# 4. (Optional) Install to local bin
cp seven_seg /usr/local/bin/
```

### Windows

#### Using MinGW (Command Prompt or PowerShell)

```cmd
:: 1. Clone the repository
git clone https://github.com/ad-digital-labs/Seven_segment-time_display.git

:: 2. Navigate to the project directory
cd Seven_segment-time_display

:: 3. Compile the source code
g++ -std=c++11 -o seven_seg.exe a.cpp
```

#### Using MSVC (Developer Command Prompt)

```cmd
:: 1. Clone the repository
git clone https://github.com/ad-digital-labs/Seven_segment-time_display.git

:: 2. Navigate to the project directory
cd Seven_segment-time_display

:: 3. Compile the source code
cl /EHsc /std:c++14 a.cpp /Fe:seven_seg.exe
```

#### Using WSL (Windows Subsystem for Linux)

```bash
# Follow the Linux instructions above inside your WSL terminal
```

---

## Usage

After compilation, run the executable:

### Linux / macOS

```bash
./seven_seg
```

### Windows

```cmd
seven_seg.exe
```

### Example Output

```
 _       _   _       _   _   _               _       _
 _|   *  _| |_|   *  _| | |  _| |_          |_|  *   _| |_|
|_   *  |_    |  *  |_  |_| |_  |_|     *** |_|  *   _|   |
```

The program automatically reads your system clock and renders the current local date and time. No arguments or configuration are needed.

> **Tip:** For a quick glance at the time, you can create a shell alias:
>
> ```bash
> # Add to your ~/.bashrc or ~/.zshrc
> alias clock='~/Seven_segment-time_display/seven_seg'
> ```

---

## Calendar & Date/Time Format

### Display Format

The program displays the current local date and time in the following format:

```
MM/DD/YYYY -HH:MM
```

| Component | Description                          | Range         | Example  |
|-----------|--------------------------------------|---------------|----------|
| `MM`      | Month (zero-padded)                  | `00` – `11`   | `03`     |
| `DD`      | Day of the month (zero-padded)       | `01` – `31`   | `15`     |
| `YYYY`    | Full four-digit year                 | `1900`+       | `2026`   |
| `-`       | Date-time separator (rendered as `***`) | —          | `-`      |
| `HH`      | Hour in 24-hour format (zero-padded) | `00` – `23`   | `14`     |
| `MM`      | Minute (zero-padded)                 | `00` – `59`   | `30`     |

**Separators:**

| Separator | Purpose              | ASCII Art Rendering |
|-----------|----------------------|---------------------|
| `/`       | Date separator       | Diagonal slash      |
| `:`       | Time separator       | Stacked dots        |
| `-`       | Date-time separator  | Horizontal bar      |
| ` `       | Visual spacing       | Blank segment       |

### Time Source

The program uses the C standard library's `time()` and `localtime()` functions to obtain the current system time. The displayed time reflects your machine's **local timezone** setting.

- **Linux/macOS:** Timezone is determined by the `TZ` environment variable or the system's `/etc/localtime` configuration.
- **Windows:** Timezone is determined by the system's date and time settings (Control Panel > Date and Time).

### Supported Characters

The following characters can be rendered as seven-segment patterns:

| Character | Segment Index | Rendered As          |
|-----------|---------------|----------------------|
| `0`       | 0             | ![zero](https://img.shields.io/badge/-0-black?style=flat-square)   |
| `1`       | 1             | ![one](https://img.shields.io/badge/-1-black?style=flat-square)    |
| `2`       | 2             | ![two](https://img.shields.io/badge/-2-black?style=flat-square)    |
| `3`       | 3             | ![three](https://img.shields.io/badge/-3-black?style=flat-square)  |
| `4`       | 4             | ![four](https://img.shields.io/badge/-4-black?style=flat-square)   |
| `5`       | 5             | ![five](https://img.shields.io/badge/-5-black?style=flat-square)   |
| `6`       | 6             | ![six](https://img.shields.io/badge/-6-black?style=flat-square)    |
| `7`       | 7             | ![seven](https://img.shields.io/badge/-7-black?style=flat-square)  |
| `8`       | 8             | ![eight](https://img.shields.io/badge/-8-black?style=flat-square)  |
| `9`       | 9             | ![nine](https://img.shields.io/badge/-9-black?style=flat-square)   |
| `:`       | 10            | Colon (time separator)    |
| `-`       | 11            | Dash (date-time divider)  |
| `/`       | 12            | Slash (date separator)    |
| ` `       | 13            | Space (blank segment)     |

### Seven-Segment Rendering

Each character is encoded as a 9-character string representing a **3x3 grid**:

```
Position:   0 1 2    ->  Row 1 (top)
            3 4 5    ->  Row 2 (middle)
            6 7 8    ->  Row 3 (bottom)
```

**Digit rendering examples:**

```
Digit 0:    Digit 1:    Digit 8:    Colon:     Dash:
 _                       _
| |            |        |_|           *              
|_|            |        |_|           *         ***  
```

---

## How It Works

### Segment Encoding

Each displayable character is mapped to a 9-character string in a lookup table (`segment[14]`). The string encodes a 3x3 grid where:

- Positions `0-2` form the **top row**
- Positions `3-5` form the **middle row**
- Positions `6-8` form the **bottom row**

For example, the digit **8** is encoded as `" _ |_||_|"`:

```
 _      <- positions 0,1,2
|_|     <- positions 3,4,5
|_|     <- positions 6,7,8
```

### Program Flow

The program follows a simple three-function architecture:

```
main()
  |
  +-- display_time()
        |
        +-- time() / localtime()    // Get current system time
        |
        +-- Format as "MM/DD/YYYY -HH:MM"
        |
        +-- display(formatted_string)
              |
              +-- Validate input length (2-19 chars)
              |
              +-- Map each character to segment index
              |
              +-- Build 3 output lines (top, middle, bottom)
              |
              +-- Print to stdout
```

| Function         | Responsibility                                                                 |
|------------------|-------------------------------------------------------------------------------|
| `main()`         | Entry point. Calls `display_time()` and handles error reporting.              |
| `display_time()` | Retrieves the current time, formats it, and passes it to `display()`.         |
| `display()`      | Parses the input string, looks up segment patterns, and renders ASCII output. |

### Error Handling

The program uses integer error codes to signal issues:

| Error Code     | Value  | Condition                                                        |
|----------------|--------|------------------------------------------------------------------|
| `P_OK`         | `0`    | Success — date/time rendered without errors.                     |
| `P_ERR_RANGE`  | `-5`   | Input string is too short (< 2 chars) or too long (> 19 chars).  |
| `P_ERR_VAL`    | `-10`  | Input contains unsupported characters (not a digit or separator).|

If an error occurs, a descriptive message is printed to `stdout` before the program exits.

---

## Project Structure

```
Seven_segment-time_display/
|
+-- a.cpp              # Main source file — contains all program logic
|                      #   - Segment lookup table (14 patterns)
|                      #   - display()        : ASCII art renderer
|                      #   - display_time()   : Time formatter
|                      #   - main()           : Entry point & error handler
|
+-- .gitignore         # Git ignore rules (build artifacts, IDE configs)
|
+-- README.md          # Project documentation (this file)
```

---

## Contributing

Contributions, bug reports, and feature requests are welcome! Here's how to get started:

### Getting Started

1. **Fork** the repository on GitHub
2. **Clone** your fork locally:

   ```bash
   git clone https://github.com/<your-username>/Seven_segment-time_display.git
   cd Seven_segment-time_display
   ```

3. **Create** a feature branch:

   ```bash
   git checkout -b feature/my-new-feature
   ```

4. **Make** your changes and test them:

   ```bash
   g++ -std=c++11 -Wall -Wextra -o seven_seg a.cpp
   ./seven_seg
   ```

5. **Commit** your changes:

   ```bash
   git commit -m "Add: brief description of your change"
   ```

6. **Push** to your fork:

   ```bash
   git push origin feature/my-new-feature
   ```

7. **Open** a Pull Request against the `main` branch

### Code Style Guidelines

- Follow the existing code formatting and commenting style
- Use descriptive variable names and add comments for complex logic
- Test your changes on at least one platform before submitting

### Reporting Issues

Found a bug? Have a suggestion? Please [open an issue](https://github.com/ad-digital-labs/Seven_segment-time_display/issues) with:

- A clear description of the problem or suggestion
- Steps to reproduce (for bugs)
- Your platform and compiler version

---

## Roadmap

Planned enhancements and ideas for future versions:

- [ ] **12-hour format** — Add AM/PM indicator with a toggle option
- [ ] **Seconds display** — Include seconds in the time output (`HH:MM:SS`)
- [ ] **ANSI color support** — Add terminal color themes for the display
- [ ] **Live clock mode** — Auto-refresh display every second (`--live` flag)
- [ ] **Custom input mode** — Accept arbitrary strings via command-line arguments
- [ ] **Makefile / CMake** — Add build system support for easier compilation
- [ ] **Unit tests** — Add test coverage for display logic and edge cases
- [ ] **Larger font sizes** — Support 5x5 or 7x5 segment grids for bigger displays
- [ ] **Configuration file** — Support for custom date/time formats via config

---

## FAQ

**Q: What time format does the display use?**
A: The program uses a 24-hour clock format and displays the date as `MM/DD/YYYY` followed by the time as `HH:MM`.

**Q: Can I change the date/time format?**
A: Not currently. The format is hardcoded in the `display_time()` function. See the [Roadmap](#roadmap) for planned configurability.

**Q: Does it work with Unicode terminals?**
A: Yes. The program uses only basic ASCII characters (`|`, `_`, `*`, and space), which are universally supported across all terminal emulators.

**Q: Why is the source file named `a.cpp`?**
A: This is the original filename from the project's creation. Future versions may refactor the code into multiple files with more descriptive names.

**Q: How do I change the timezone?**
A: The program uses your system's local timezone. To change it:
- **Linux/macOS:** Set the `TZ` environment variable (e.g., `export TZ="America/New_York"`) or update `/etc/localtime`.
- **Windows:** Change the timezone in **Settings > Time & Language > Date & Time**.

---

## License

This project is open source and available under the [MIT License](https://opensource.org/licenses/MIT).

---

## Author

**AD Digital Labs**

- GitHub: [@ad-digital-labs](https://github.com/ad-digital-labs)

---

<p align="center">
  <sub>Built with standard C++ and a love for retro displays.</sub>
</p>  
