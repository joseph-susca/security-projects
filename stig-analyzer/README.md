# STIG Analyzer

A C++ command-line tool for logging, analyzing, and reporting STIG security findings.

## About

This tool was built as part of my preparation for a Cyber Systems Security Engineer position at Lockheed Martin Aeronautics. STIG assessments play a large part in the role of a Security Engineer, and this tool is meant to make reporting and analyzing easier.

## Features 

- **v1.0** - Manual entry of STIG findings with input validation
- **v2.0** - CSV file input support, user-specified filenames, and menu-driven interface
- Categorizes findings by CAT I, CAT II, and CAT III
- Tracks finding status, whether Open, Not a Finding, Not applicable, or Not reviewed
- Generates a summary report to both the terminal and an exported .txt file

## CSV Format

V-220708,CAT I,Password complexity not enforced,Open
V-220715,CAT II,Audit logging not enabled,Not a Finding

## Technologies

- C++
- File I/O (fstream)
- Structs and vectors
- Input validation
