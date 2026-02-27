# CrypText: Hybrid File Encryption Utility

This was our first semester project in programming fundamentals. We made a tool that takes a text file and locks it so no one else can read it. We used C++ to handle the files and change the data.
 A C++ command-line tool designed to secure text files using a multi-layer cryptographic approach.

## The Core Mechanism
This utility processes data through two distinct logical layers to ensure that the output is unrecognizable without the correct decryption sequence.

### Layer 1: Caesar Substitution
The system modifies the ASCII value of each character by a fixed `SHIFT_KEY` (3).
* **Encryption:** `char + 3`
* **Decryption:** `char - 3`

### Layer 2: Bitwise XOR Logic
The system applies a bitwise XOR operation against a static key (`'K'`). 
* This adds a layer of complexity that simple substitution lacks, as XOR is a fundamental logic gate used in modern cryptography.

## Cause-and-Effect Logic
To successfully recover the data, the layers must be applied in **exact reverse order**:
1. **Encrypt:** Shift ➔ XOR
2. **Decrypt:** XOR ➔ Shift

 ## Developers
- Ashfaq Ahmad
- Annas Asif

