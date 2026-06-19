# CPUSim – A Pipelined CPU & Memory Hierarchy Simulator

Project X 2026 – Task 2

CPU Scheduler and Multi-Level Cache Simulator implemented in C++.

## Features

- Round Robin Scheduling
- L1, L2, L3 Cache Hierarchy
- FIFO Cache Replacement
- Cache Hit/Miss Detection
- Memory Latency Tracking
- Execution Statistics

## Project Structure

```text
src/      -> Source Code
input/    -> Input Files
docs/     -> Documentation
```

## Build

```bash
g++ src/*.cpp -o cpusim
```

## Run

### Windows

```bash
.\cpusim.exe
```

### Linux / macOS

```bash
./cpusim
```

## Input Files

- `input/input_task2.txt` – Normal test case
- `input/input_stress.txt` – Stress test for FIFO eviction

## Repository

Created for Project X 2026.

Author: Darshan Mahale
