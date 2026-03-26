# 📄 get_next_line – 42 Irbid Project

> *This project is part of the 42 curriculum at 42 Irbid.*

---

## 🧾 Description

The **get_next_line** project is a core assignment in the **42 Network** curriculum, completed at **42 Irbid**.

The objective is to implement a function that reads from a file descriptor **line by line**, returning one line per call.

This project develops a strong understanding of:

* Low-level I/O using `read()`
* Static variables and state management
* Dynamic memory allocation
* Efficient buffer handling

The function `get_next_line()` returns a line including the newline character (`\n`) when present, or `NULL` when the end of file is reached or an error occurs.

---

## 📂 Project Structure

* `get_next_line.c` → Main function logic
* `get_next_line_utils.c` → Helper functions
* `get_next_line.h` → Header file and definitions

---

## ⚙️ Compilation

Compile with:

```bash id="6j8p2r"
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

If `BUFFER_SIZE` is not defined, a default value is set in the header file.

---

## 🚀 Usage

```c id="y9x2d1"
char *get_next_line(int fd);
```

### Behavior:

* Returns **one line per call**
* Includes `\n` if present
* Returns `NULL` at EOF or on error
* The returned string must be **freed by the caller**

### Example:

```c id="2k3p9f"
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
```

---

## 🧠 Implementation Overview

### 🔹 Core Idea

The implementation uses a **static buffer (storage)** to keep unread data between function calls.

---

### 🔹 Algorithm Steps

1. Maintain a static variable to store leftover data
2. Read from the file descriptor using `read()` in chunks of `BUFFER_SIZE`
3. Append new data to the stored buffer
4. Stop reading when a newline (`\n`) is found or EOF is reached
5. Extract one line from the buffer
6. Keep the remaining data for the next call

---

### 🔹 Why This Approach?

This design ensures:

* Efficient reading (no unnecessary reads)
* Works with any `BUFFER_SIZE`
* Preserves state between calls
* Handles partial reads correctly

---

## 🧪 Technical Constraints

* Compiled with `-Wall -Wextra -Werror`
* Uses only allowed functions:

  * `read`, `malloc`, `free`
* No global variables (only static allowed)
* Must handle:

  * Multiple file descriptors (if bonus)
  * Large files
  * Small buffer sizes
* Memory must be properly managed (no leaks)

---

## 🎓 About 42 Irbid

This project was developed at **42 Irbid**, part of the global 42 Network — a peer-to-peer, project-based school focused on real-world programming, problem-solving, and low-level system understanding.

---

## 📚 Resources

* `man 2 read`
* 42 subject PDF
* C documentation resources
* Various discussions on file handling in C

---

## 🤖 AI Usage Disclosure

AI tools (such as ChatGPT) were used to:

* Understand static variables and file descriptor behavior
* Clarify edge cases (EOF, buffer limits)
* Improve documentation clarity

All code was written, tested, and validated independently in compliance with 42 standards.

---

## ✨ Author

Developed by a student at **42 Irbid** as part of the 42 curriculum.

