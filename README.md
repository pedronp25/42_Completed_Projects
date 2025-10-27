# 42 COMPLETED PROJECTS

<div align="center">

![C](https://img.shields.io/badge/Language-C-00599C?logo=c&logoColor=white)
![Shell](https://img.shields.io/badge/Shell-Bash-4EAA25?logo=gnu-bash&logoColor=white)
![Linux](https://img.shields.io/badge/OS-Linux-FCC624?logo=linux&logoColor=white)
![Git](https://img.shields.io/badge/Tools-Git-F05032?logo=git&logoColor=white)
![Make](https://img.shields.io/badge/Build-Make-427819?logo=cmake&logoColor=white)

</div>

---

## 🚀 About

Welcome to my collection of projects completed during my studies at [42 Porto](https://www.42porto.com).  
Each project represents a new step in mastering **C programming**, **UNIX systems**, and **software engineering fundamentals**.

At 42 Porto, the learning process is entirely project-based — no teachers, no classes, just problem-solving and peer-to-peer collaboration.  
This repository gathers all the projects I've completed so far, reflecting my progress through the **Common Core**.

### 🔨 Currently Working On
**minishell** - Building a minimal bash-like shell from scratch

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

---

## 📚 Projects Overview

| Project | Language | Status | Description |
|---------|---------|--------|-------------|
| [libft](#libft) | ![C](https://img.shields.io/badge/Language-C-blue) | ✅ Completed | Custom implementation of standard C library functions — foundation for future projects. |
| [get_next_line](#get_next_line) | ![C](https://img.shields.io/badge/Language-C-blue) | ✅ Completed | Reads a file line by line using static buffers and efficient memory management. |
| [ft_printf](#ft_printf) | ![C](https://img.shields.io/badge/Language-C-blue) | ✅ Completed | Reimplementation of `printf`, handling formatted output and variadic arguments. |
| [born2beroot](#born2beroot) | ![Shell](https://img.shields.io/badge/Language-Shell-yellow) | ✅ Completed | Linux system administration and security setup in a virtual machine. |
| [so_long](#so_long) | ![C](https://img.shields.io/badge/Language-C-blue) | ✅ Completed | Simple 2D game with event handling and map parsing using MiniLibX. |
| [push_swap](#push_swap) | ![C](https://img.shields.io/badge/Language-C-blue) | ✅ Completed | Stack-based sorting algorithm challenge, emphasizing optimization. |
| [pipex](#pipex) | ![C](https://img.shields.io/badge/Language-C-blue) | ✅ Completed | Simulates UNIX pipes and process chaining with file descriptors. |
| [philosophers](#philosophers) | ![C](https://img.shields.io/badge/Language-C-blue) | ✅ Completed | Multithreading exercise solving the Dining Philosophers problem. |

---

## 📖 Projects

### libft

**Description:**  
The first project at 42, libft requires you to recreate essential functions from the C standard library (libc) from scratch. This library becomes the foundation for all future C projects at 42. Functions include string manipulation, memory management, character checks, and linked list operations.

**What I Learned:**
- Deep understanding of C standard library functions and their inner workings
- Memory allocation and management with `malloc` and `free`
- Pointer manipulation and proper memory handling
- Building reusable, well-documented code libraries
- Makefile creation and compilation processes

**How to Run:**
```bash
# Compile the library
make

# This creates libft.a which can be linked to other projects
# Compile with bonus functions (linked lists)
make bonus

# Clean object files
make clean

# Remove all generated files
make fclean

# Recompile everything
make re
```

**Expected Output:**  
A static library file `libft.a` containing all implemented functions, ready to be linked with future projects.

**Testers:**
- [Tripouille/libftTester](https://github.com/Tripouille/libftTester)
- [jtoty/Libftest](https://github.com/jtoty/Libftest)

---

### get_next_line

**Description:**  
A function that reads from a file descriptor line by line, returning one line per call. The challenge involves managing static variables to maintain state between function calls and handling different buffer sizes efficiently.

**What I Learned:**
- Working with file descriptors and the `read()` system call
- Static variables and their persistence between function calls
- Dynamic memory allocation for variable-length strings
- Edge case handling (EOF, multiple file descriptors, memory leaks)
- Buffer management and optimization

**How to Run:**
```bash
# Compile with your main file
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

# Run the executable
./a.out [test_file.txt]
```

**Expected Output:**  
The program should read and print the file line by line, handling various buffer sizes correctly without memory leaks.

**Testers:**
- [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
- [xicodomingues/francinette](https://github.com/xicodomingues/francinette)

---

### ft_printf

**Description:**  
A reimplementation of the standard `printf()` function from libc. This project requires handling variadic arguments and implementing various format specifiers like `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

**What I Learned:**
- Variadic functions using `va_start`, `va_arg`, and `va_end`
- Format string parsing and interpretation
- Type conversion and formatted output
- Handling different number bases (decimal, hexadecimal)
- Building complex functions with multiple edge cases

**How to Run:**
```bash
# Compile the library
make

# This creates libftprintf.a
# Link it with your test file
gcc main.c libftprintf.a

# Run tests
./a.out
```

**Expected Output:**  
Your `ft_printf` should produce identical output to the standard `printf` for all implemented format specifiers.

**Testers:**
- [Tripouille/printfTester](https://github.com/Tripouille/printfTester)
- [xicodomingues/francinette](https://github.com/xicodomingues/francinette)

---

### born2beroot

**Description:**  
A system administration project where you set up a secure virtual machine from scratch. Tasks include installing a minimal Debian or Rocky Linux system, configuring SSH, implementing strict password policies, setting up UFW/firewalld, configuring sudo rules, and creating monitoring scripts.

**What I Learned:**
- Linux system administration fundamentals
- Virtual machine setup and management (VirtualBox)
- SSH configuration and secure remote access
- User and group management
- Sudo configuration and privilege escalation
- Firewall setup (UFW/firewalld)
- Password policy enforcement (PAM)
- System monitoring with bash scripts
- LVM (Logical Volume Manager) and disk partitioning
- Security best practices and hardening

**Expected Deliverable:**  
A fully configured virtual machine with strict security policies, demonstrating system administration skills through a monitoring script and proper configuration files.

---

### so_long

**Description:**  
A small 2D game project where the player must collect all collectibles and reach the exit in the minimum number of moves. Built using the MiniLibX graphics library, this project introduces graphical programming, event handling, and basic game logic.

**What I Learned:**
- Graphics programming with MiniLibX
- Event handling (keyboard input, window events)
- Map parsing and validation
- Sprite rendering and 2D graphics
- Game loop implementation
- Path-finding and map validation algorithms

**How to Run:**

First, install MiniLibX:
```bash
# For Linux (42's version)
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make

# Alternatively, for macOS
git clone https://github.com/42Paris/minilibx-opengl.git
cd minilibx-opengl
make
```

Then compile so_long:
```bash
# Compile the project (adjust MiniLibX path if needed)
make

# Run with a map file
./so_long maps/map.ber

# Clean and rebuild
make fclean
make
```

**Expected Output:**  
A window opens displaying your map with the player, collectibles, walls, and exit. The player should be able to move using WASD or arrow keys, and the move count should be displayed. The game ends when all collectibles are gathered and the exit is reached.

**Testers:**
- Manual testing with various map configurations
- [GQDeltex/so_long_tester](https://github.com/GQDeltex/so_long_tester)

---

### push_swap

**Description:**  
An algorithm project that challenges you to sort a stack of integers using only two stacks and a limited set of operations. The goal is to sort the numbers in the minimum number of moves possible. This project emphasizes algorithmic thinking and optimization.

**What I Learned:**
- Algorithm design and optimization
- Stack data structures and operations
- Sorting algorithms (quick sort, insertion sort adaptations)
- Complexity analysis and performance optimization
- Problem decomposition and solution strategies
- Debugging complex logical problems

**How to Run:**
```bash
# Compile the program
make

# Run with random numbers
./push_swap 3 2 1 5 4

# The program outputs the operations needed to sort
# Pipe to checker to verify correctness
./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4

# Test with random numbers
ARG=$(shuf -i 0-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Clean
make fclean
```

**Expected Output:**  
A list of operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) that sort the stack efficiently. For 100 numbers, under 700 operations is good, under 900 passes the project.

**Testers:**
- [LeoFu9487/push_swap_tester](https://github.com/LeoFu9487/push_swap_tester)
- [gemartin99/Push-Swap-Tester](https://github.com/gemartin99/Push-Swap-Tester)

---

### pipex

**Description:**  
A project that mimics the behavior of shell pipes. The program takes an input file, executes two commands (like a shell pipeline), and writes the output to an output file. This project teaches process creation, file descriptor manipulation, and inter-process communication.

**What I Learned:**
- UNIX process creation with `fork()`
- File descriptor manipulation and redirection
- Pipe creation and inter-process communication
- Using `execve()` to execute commands
- Path resolution and environment variables
- Process synchronization with `wait()` and `waitpid()`
- Error handling in system calls

**How to Run:**
```bash
# Compile
make

# Basic usage (mimics: < infile cmd1 | cmd2 > outfile)
./pipex infile "ls -l" "wc -l" outfile

# This is equivalent to:
< infile ls -l | wc -l > outfile

# Example with grep and wc
./pipex input.txt "grep hello" "wc -w" output.txt

# Bonus: handle multiple pipes
./pipex infile "cmd1" "cmd2" "cmd3" "cmd4" outfile

# Clean
make fclean
```

**Expected Output:**  
The output file should contain the result of piping cmd1's output into cmd2, just like in a shell pipeline.

**Testers:**
- [vfurmane/pipex-tester](https://github.com/vfurmane/pipex-tester)
- Manual comparison with actual shell behavior

---

### philosophers

**Description:**  
An implementation of the classic Dining Philosophers problem using threads and mutexes. Philosophers alternate between eating, thinking, and sleeping, sharing forks (mutexes) between them. The challenge is preventing deadlocks and ensuring no philosopher starves.

**What I Learned:**
- Multithreading with pthread library
- Mutex locks for resource synchronization
- Race condition prevention
- Deadlock avoidance strategies
- Thread lifecycle management
- Concurrent programming concepts
- Precise timing with `usleep()` and `gettimeofday()`
- Data races and thread-safe programming

**How to Run:**
```bash
# Compile
make

# Run: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
./philo 5 800 200 200

# Example: 4 philosophers, dies in 310ms, eats in 200ms, sleeps in 100ms
./philo 4 310 200 100

# With optional 5th argument (simulation stops after each philosopher eats 5 times)
./philo 5 800 200 200 5

# Clean
make fclean
```

**Expected Output:**  
Timestamped logs showing each philosopher's actions (taking forks, eating, sleeping, thinking). No philosopher should die if the parameters are valid, and the simulation should run smoothly without data races or deadlocks.

**Testers:**
- [nesvoboda/socrates](https://github.com/nesvoboda/socrates)
- Manual testing with various timing parameters

---

## 🧠 Skills Developed

- C Programming & Memory Management  
- UNIX & Linux Systems  
- Git & Version Control  
- Algorithmic Thinking  
- Networking & Multithreading  
- System Design & Security Basics  

---

## 📫 Contact

- **LinkedIn:** [Pedro Pereira](https://www.linkedin.com/in/pedro-pereira-7696b52b8)

---

<div align="center">

**Made with ☕ at 42 Porto**

</div>

> *“Learning to code by solving problems, not by memorizing answers.”*  
> — 42 Philosophy
