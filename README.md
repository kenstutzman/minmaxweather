# Fort Collins Temperature Records Lookup

A lightweight C program (and data header) that displays today's record high and low temperatures for the Fort Collins, Colorado area, based on historical weather data.

<img src="https://upload.wikimedia.org/wikipedia/commons/0/09/Downtown_Fort_Collins_Colorado.jpg"/>

(Example output – actual temperatures depend on today's date)

Fort Collins area temperature records
Today: 2026-03-09
Record high:   77 °F   (1972)
Record low:   -28 °F   (1932)

## Features

- Static lookup table with **366 days** of record highs/lows (including Feb 29)
- No external files or network required at runtime — everything compiled in
- Uses only standard C library (`<time.h>`, `<stdio.h>`, etc.)
- Very small binary size — suitable for embedded systems, Raspberry Pi, or quick CLI tool
- Primary record year shown (most recent / prominent year from dataset)

## Data Source

- Historical daily temperature records for Fort Collins area
- Format derived from CSV containing record highs/lows and associated years
- Includes some unusually recent years (up to 2025–2026) — likely provisional or updated extremes
- Coldest recorded: –59 °F (Dec 21, 1919)
- Hottest recorded: 103 °F (Jul 21, 2005)

## Requirements

- GCC or any C99/C11 compiler
- Linux / macOS / BSD (uses `localtime()` — should work on Windows with minor tweaks)

## Build & Run

```bash
# 1. Save the header file as focominmax.h
# 2. Save the main program as today-foco-records.c

# Compile
gcc -o today-foco-records today-foco-records.c -Wall -O2

# Run
./today-foco-records
