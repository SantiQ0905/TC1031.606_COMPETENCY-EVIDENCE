
# Bitacora Analysis Tool

This is a C++ project for analyzing and managing system logs (`bitacora.txt`). The program allows users to load, sort, and filter log data based on date or IP, and generate useful insights such as the top IPs by access frequency.

## Table of Contents
- [Features](#features)
- [Folder Structure](#folder-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Menu Options](#menu-options)
- [Examples](#examples)
- [License](#license)

---

## Features

- Load log data from a file (`bitacora.txt`).
- Sort log data by date or IP address.
- Filter records based on date range or IP range.
- Generate reports, including:
  - Filtered logs by date or IP.
  - Top 5 IPs with the most accesses.
- Save filtered and processed results to files.

---

## Folder Structure

```
bitacora_project/
├── CMakeLists.txt          # CMake configuration
├── data/                   # Directory for input/output files
│   ├── bitacora.txt        # Input log file
│   ├── filtered_bitacora.txt # Output: Filtered logs by date
│   ├── filtered_ips.txt    # Output: Filtered logs by IP range
│   ├── topFive_ips.txt     # Output: Top 5 IPs by accesses
├── include/                # Header files
│   ├── FileHandler.h
│   ├── Record.h
│   ├── Date.h
│   ├── IPAddress.h
│   ├── BinarySearchTree.h
├── src/                    # Source files
│   ├── main.cpp            # Main program
│   ├── FileHandler.cpp
│   ├── Record.cpp
│   ├── Date.cpp
│   ├── IPAddress.cpp
│   ├── BinarySearchTree.cpp
```

---

## Getting Started

### Prerequisites
- **C++ Compiler**: Support for C++17 or higher.
- **CMake**: Version 3.16 or higher.
- **CLion (optional)**: For an integrated development environment.
  
### Installation
1. Clone this repository:
   ```bash
   git clone <https://github.com/SantiQ0905/TC1031.606_COMPETENCY-EVIDENCE>
   cd bitacora_project
   ```
2. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
3. Run CMake to configure the project:
   ```bash
   cmake ..
   ```
4. Build the project:
   ```bash
   cmake --build .
   ```

---

## Usage

1. Ensure the input file `bitacora.txt` is located in the `data/` folder.
2. Run the program:
   ```bash
   ./bitacora_project
   ```
3. Follow the on-screen menu to perform actions such as sorting, filtering, or generating reports.

---

## Menu Options

### **Option 1: Load and Sort by Date**
- Loads the `bitacora.txt` file, sorts the data by date, and saves the result to `filtered_bitacora.txt`.

### **Option 2: Search by Date Range**
- Allows the user to specify a date range (start and end) and displays the matching records.

### **Option 3: Search by IP Range**
- Allows the user to specify an IP range (start and end) and displays the matching records.

### **Option 4: Find Top 5 IPs by Accesses**
- Calculates the top 5 most accessed IPs and displays the results. The results are also saved to `topFive_ips.txt`.

### **Option 0: Exit**
- Exits the program.

---

## Examples

### Input (`bitacora.txt`)
```
Oct 9 10:32:24 423.2.230.77:6166 Failed password for illegal user guest
Aug 28 23:07:49 897.53.984.6:6710 Failed password for root
Aug 4 03:18:56 960.96.3.29:5268 Failed password for admin
Jun 20 13:39:21 118.15.416.57:4486 Failed password for illegal user guest
```

### Output for Option 1 (`filtered_bitacora.txt`)
```
Jun 20 13:39:21 118.15.416.57 Failed password for illegal user guest
Aug 4 03:18:56 960.96.3.29 Failed password for admin
Aug 28 23:07:49 897.53.984.6 Failed password for root
Oct 9 10:32:24 423.2.230.77 Failed password for illegal user guest
```

### Output for Option 4 (`topFive_ips.txt`)
```
423.2.230.77: 2 accesses
118.15.416.57: 1 accesses
897.53.984.6: 1 accesses
960.96.3.29: 1 accesses
```

---

## License

This project is licensed under the MIT License. See `LICENSE` for more details.

---

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

---

## Author

**Santiago Quintana**  
- [GitHub Profile](https://github.com/SantiQ0905)  
- [LinkedIn Profile](https://www.linkedin.com/in/santiago-quintana-moreno-861115192/)  
