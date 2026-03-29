# Seven Segment Time Display

A lightweight C++ command-line application that renders the current local date and time using seven-segment-style characters directly in your terminal.

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey)
![License](https://img.shields.io/badge/License-MIT-green)

---

## Overview

This program fetches the current system date and time using the C/C++ `<time.h>` library and displays it in a retro seven-segment display format on the terminal. Each digit, separator (`:`, `-`, `/`), and space is mapped to a 3-line ASCII art pattern that mimics the look of classic seven-segment LED displays.

### Example Output

```
 _       _   _       _   _   _               _       _
 _|   *  _| |_|   *  _| | |  _| |_          |_|  *   _| |_|
|_   *  |_    |  *  |_  |_| |_  |_|     *** |_|  *   _|   |
```

The output above represents a date and time like `2/28/2026 - 8:34` rendered in seven-segment style.

---

## Features

- Displays the current local **date** and **time** in seven-segment format
- Supports rendering of:
  - Digits `0` through `9`
  - Colon `:` (used as a time separator)
  - Dash `-` (used as a date-time separator)
  - Slash `/` (used as a date separator)
  - Space ` ` (blank segment)
- Input validation with descriptive error messages
- Lightweight single-file implementation with no external dependencies
- Works on any platform with a standard C++ compiler

---

## Prerequisites

- A C++ compiler that supports C++11 or later (e.g., `g++`, `clang++`, or MSVC)
- A terminal or command prompt to run the compiled program

---

## Building and Running

### Linux / macOS

```bash
# Clone the repository
git clone https://github.com/ad-digital-labs/Seven_segment-time_display.git
cd Seven_segment-time_display

# Compile the source code
g++ -o seven_seg a.cpp

# Run the program
./seven_seg
```

### Windows (using MinGW or similar)

```cmd
g++ -o seven_seg.exe a.cpp
seven_seg.exe
```

### Windows (using MSVC Developer Command Prompt)

```cmd
cl a.cpp /Fe:seven_seg.exe
seven_seg.exe
```

---

## How It Works

### Segment Encoding

Each displayable character is encoded as a 9-character string representing a 3x3 grid:

```
Position:   0 1 2    →  Row 1 (top)
            3 4 5    →  Row 2 (middle)
            6 7 8    →  Row 3 (bottom)
```

For example, the digit **8** is encoded as `" _ |_||_|"`, which renders as:

```
 _
|_|
|_|
```

### Supported Characters

| Character | Segment Index | Description        |
|-----------|---------------|--------------------|
| `0`       | 0             | Digit zero         |
| `1`       | 1             | Digit one          |
| `2`       | 2             | Digit two          |
| `3`       | 3             | Digit three        |
| `4`       | 4             | Digit four         |
| `5`       | 5             | Digit five         |
| `6`       | 6             | Digit six          |
| `7`       | 7             | Digit seven        |
| `8`       | 8             | Digit eight        |
| `9`       | 9             | Digit nine         |
| `:`       | 10            | Colon (time sep)   |
| `-`       | 11            | Dash (separator)   |
| `/`       | 12            | Slash (date sep)   |
| ` `       | 13            | Space (blank)      |

### Program Flow

1. **`main()`** — Entry point. Calls `display_time()` and handles any errors returned.
2. **`display_time()`** — Retrieves the current local time using `localtime()`, formats it as `M/D/YYYY -H:MM`, and passes it to `display()`.
3. **`display()`** — Parses the input string character by character, looks up the corresponding segment pattern, and builds three output lines (top, middle, bottom) that are printed to `stdout`.

### Error Handling

| Error Code     | Value | Meaning                                       |
|----------------|-------|-----------------------------------------------|
| `P_OK`         | `0`   | Success                                       |
| `P_ERR_RANGE`  | `-5`  | Input string is too short (≤1) or too long (≥20) |
| `P_ERR_VAL`    | `-10` | Input contains invalid (non-digit/separator) characters |

---

## Project Structure

```
Seven_segment-time_display/
├── a.cpp           # Main source file containing all program logic
├── .gitignore      # Git ignore rules
└── README.md       # This file
```

---

## Contributing

Contributions are welcome! Here are some ideas for enhancements:

- Add a **12-hour format** option with AM/PM indicator
- Add **color support** using ANSI escape codes
- Add a **live clock mode** that refreshes every second
- Add support for **custom input strings** via command-line arguments
- Refactor the code into separate header and source files
- Add a **Makefile** or **CMakeLists.txt** for easier builds

To contribute:

1. Fork this repository
2. Create a feature branch (`git checkout -b feature/my-feature`)
3. Commit your changes (`git commit -m "Add my feature"`)
4. Push to the branch (`git push origin feature/my-feature`)
5. Open a Pull Request

---

## License

This project is open source. See the repository for license details. 
