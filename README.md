<div align="center">

# 42 COMPLETED PROJECTS

![C](https://img.shields.io/badge/Language-C-00599C?logo=c\&logoColor=white)
![Shell](https://img.shields.io/badge/Shell-Bash-4EAA25?logo=gnu-bash\&logoColor=white)
![Linux](https://img.shields.io/badge/OS-Linux-FCC624?logo=linux\&logoColor=white)
![Git](https://img.shields.io/badge/Tools-Git-F05032?logo=git\&logoColor=white)
![Make](https://img.shields.io/badge/Build-Make-427819?logo=cmake\&logoColor=white)

</div>

---

## 🚀 About

Welcome to my collection of projects completed during my studies at [42 Porto](https://www.42porto.com).
Each project represents a new step in mastering **C programming**, **UNIX systems**, and **software engineering fundamentals**.

At 42 Porto, the learning process is entirely project-based — no teachers, no classes, just problem-solving and peer-to-peer collaboration.
This repository gathers all the projects I've completed so far, reflecting my progress through the **Common Core**.

### 🔨 Currently Working On

**CPP Modules** – Learning Object-Oriented Programming in C++, including classes, inheritance, polymorphism, operator overloading, and deeper language concepts.

---

## 📑 Index

1. [libft](#libft)
2. [get_next_line](#get_next_line)
3. [ft_printf](#ft_printf)
4. [born2beroot](#born2beroot)
5. [so_long](#so_long)
6. [push_swap](#push_swap)
7. [pipex](#pipex)
8. [philosophers](#philosophers)
9. [minishell](#minishell)

---

## 📚 Projects Overview

| Project                         | Language                                                     | Status      | Description                                                                             |
| ------------------------------- | ------------------------------------------------------------ | ----------- | --------------------------------------------------------------------------------------- |
| [libft](#libft)                 | ![C](https://img.shields.io/badge/Language-C-blue)           | ✅ Completed | Custom implementation of standard C library functions — foundation for future projects. |
| [get_next_line](#get_next_line) | ![C](https://img.shields.io/badge/Language-C-blue)           | ✅ Completed | Reads a file line by line using static buffers and efficient memory management.         |
| [ft_printf](#ft_printf)         | ![C](https://img.shields.io/badge/Language-C-blue)           | ✅ Completed | Reimplementation of `printf`, handling formatted output and variadic arguments.         |
| [born2beroot](#born2beroot)     | ![Shell](https://img.shields.io/badge/Language-Shell-yellow) | ✅ Completed | Linux system administration and security setup in a virtual machine.                    |
| [so_long](#so_long)             | ![C](https://img.shields.io/badge/Language-C-blue)           | ✅ Completed | Simple 2D game with event handling and map parsing using MiniLibX.                      |
| [push_swap](#push_swap)         | ![C](https://img.shields.io/badge/Language-C-blue)           | ✅ Completed | Stack-based sorting algorithm challenge, emphasizing optimization.                      |
| [pipex](#pipex)                 | ![C](https://img.shields.io/badge/Language-C-blue)           | ✅ Completed | Simulates UNIX pipes and process chaining with file descriptors.                        |
| [philosophers](#philosophers)   | ![C](https://img.shields.io/badge/Language-C-blue)           | ✅ Completed | Multithreading exercise solving the Dining Philosophers problem.                        |
| [minishell](#minishell)         | ![C](https://img.shields.io/badge/Language-C-blue)           | ✅ Completed | A minimal POSIX-like shell implementing parsing, pipes, redirections, and builtins.     |

---

## 📖 Projects

### 📦 libft

**Description:**
The first project at 42, libft requires you to recreate essential functions from the C standard library (libc) from scratch. This library becomes the foundation for all future C projects at 42. Functions include string manipulation, memory management, character checks, and linked list operations.

**What I Learned:**

* Deep understanding of C standard library functions and their inner workings
* Memory allocation and management with `malloc` and `free`
* Pointer manipulation and proper memory handling
* Building reusable, well-documented code libraries
* Makefile creation and compilation processes

**How to Run:**

```bash
make
make bonus
make clean
make fclean
make re
```

**Expected Output:**
A static library file `libft.a` containing all implemented functions, ready to be linked with future projects.

---

### 📦 get_next_line

**Description:**
A function that reads from a file descriptor line by line, returning one line per call. The challenge involves managing static variables to maintain state between function calls and handling different buffer sizes efficiently.

**What I Learned:**

* Working with file descriptors and the `read()` system call
* Static variables and their persistence between function calls
* Dynamic memory allocation for variable-length strings
* Edge case handling (EOF, multiple file descriptors, memory leaks)
* Buffer management and optimization

**How to Run:**

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
./gnl test_file.txt
```

---

### 📦 ft_printf

**Description:**
A reimplementation of the standard `printf()` function from libc. This project requires handling variadic arguments and implementing various format specifiers like `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

**What I Learned:**

* Variadic functions using `va_start`, `va_arg`, and `va_end`
* Format string parsing and interpretation
* Type conversion and formatted output
* Handling different number bases
* Complex edge case handling

**How to Run:**

```bash
make
gcc ft_printf.c libftprintf.a -o ft_printf
./ft_printf
```

---

### 📦 born2beroot

**Description:**
A system administration project where you set up a secure virtual machine from scratch. Tasks include installing a minimal Linux system, configuring SSH, implementing password policies, and setting up monitoring scripts.

**What I Learned:**

* Linux system administration fundamentals
* Virtual machine management
* SSH configuration
* User and group management
* Firewall configuration
* System security practices

---

### so_long

**Description:**
A small 2D game project where the player must collect all collectibles and reach the exit. Built using the MiniLibX graphics library, introducing graphical programming and event handling.

**What I Learned:**

* Graphics programming with MiniLibX
* Event handling
* Map parsing and validation
* Basic game loop logic
* Sprite rendering

**How to Run:**

```bash
make
./so_long maps/map.ber
```

---

### 📦 push_swap

**Description:**
An algorithm project that challenges you to sort a stack of integers using only two stacks and a limited set of operations.

**What I Learned:**

* Algorithm design and optimization
* Stack data structures
* Sorting algorithm strategies
* Complexity analysis
* Debugging complex logic

**How to Run:**

```bash
make
./push_swap 3 2 1 5 4
```

---

### 📦 pipex

**Description:**
A project that mimics the behavior of shell pipes. The program takes an input file, executes commands, and redirects output similar to a shell pipeline.

**What I Learned:**

* Process creation with `fork()`
* File descriptor manipulation
* Inter-process communication with `pipe()`
* Command execution with `execve()`
* Process synchronization

**How to Run:**

```bash
make
./pipex infile "ls -l" "wc -l" outfile
```

---

### 📦 philosophers

**Description:**
An implementation of the classic Dining Philosophers problem using threads and mutexes. Philosophers alternate between eating, thinking, and sleeping while sharing resources.

**What I Learned:**

* Multithreading with pthreads
* Mutex synchronization
* Race condition prevention
* Deadlock avoidance
* Timing control with `gettimeofday()`
* Thread-safe programming

**How to Run:**

```bash
make
./philo 5 800 200 200
```

---

### 📦 minishell

**Description:**
A collaborative project where we recreated a simplified version of the Bash shell. The program reads user input, parses commands, and executes them while supporting several essential shell features.

Minishell replicates many behaviors of a real shell, including command execution, environment variable expansion, pipes, and input/output redirections.

**Key Features Implemented:**

* Command parsing and tokenization
* Execution of external programs
* Environment variable expansion (`$PATH`, `$HOME`, etc.)
* Built-in commands:

  * `echo`
  * `cd`
  * `pwd`
  * `export`
  * `unset`
  * `env`
  * `exit`
* Pipes (`|`) for chaining commands
* Input/output redirections (`>`, `>>`, `<`)
* Signal handling (`Ctrl+C`, `Ctrl+\`)
* Proper exit status handling
* Memory management for long-running shell sessions

**What I Learned:**

* Designing and implementing a command parser
* Advanced process management using `fork`, `execve`, and `waitpid`
* File descriptor duplication and redirection using `dup2`
* Managing environment variables
* Signal handling with `sigaction`
* Handling interactive terminal behavior
* Structuring large C projects across multiple modules
* Collaborative development and Git workflow

**How to Run:**

```bash
make
./minishell
```

**Example Usage:**

```bash
minishell$ ls -la
minishell$ echo Hello World
minishell$ cat file.txt | grep hello
minishell$ export PATH=/usr/bin
minishell$ cd ..
```

**Expected Behavior:**
The shell behaves similarly to Bash for supported features, correctly handling pipes, redirections, environment variables, and built-in commands while maintaining a responsive interactive prompt.

---

## 🧠 Skills Developed

* C Programming & Memory Management
* UNIX & Linux Systems
* Multithreading & Concurrency
* Process & Signal Management
* Git & Version Control
* Algorithmic Thinking
* System Design Fundamentals

---

## 📫 Contact

* **LinkedIn:** [Pedro Pereira](https://www.linkedin.com/in/pedro-pereira-7696b52b8)

---

<div align="center">

**Made with ☕ at 42 Porto**

</div>

> *“Learning to code by solving problems, not by memorizing answers.”*
> — 42 Philosophy
