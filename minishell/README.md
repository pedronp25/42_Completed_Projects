*This project has been created as part of the 42 curriculum by pedromig, mjoao-te.*

# Minishell - A Simple Unix Shell Implementation

## Description

**Minishell** (or "MeowShell" affectionately) is a minimal implementation of a Unix shell, developed as part of the 42 school curriculum. The project aims to create a functional command-line interpreter that mimics the behavior of `bash`.

### Goal

The goal of this project is to understand how shells work by implementing core features from scratch, including:
- Command parsing and tokenization
- Pipeline execution
- Input/output redirections (>, <, >>)
- Heredocs (<<)
- Built-in commands (cd, exit, pwd, export, etc.)
- Variable expansion
- Shell syntax handling (quoting, operators, etc.)

### What It Does

Minishell provides a prompt where users can:
- Execute external programs
- Use built-in commands (cd, pwd, echo, env, export, unset, exit)
- Chain commands with pipes (|)
- Redirect input/output
- Handle environment variables
- Expand variables in commands
- Process heredocs (<<)
- Handle various shell syntax including quotes and escape sequences

## Instructions

### Compilation

To compile the project, use the provided Makefile:

```bash
make
```

This will compile the minishell executable and all dependencies, including the custom `libft` library.

### Installation

Simply clone the repository (if needed) and run `make`:

```bash
git clone git@github.com:margosbe/minishell.git meowshell
cd meowshell
make
```

### Execution

Run the minishell:

```bash
./minishell
```

You'll be presented with a shell prompt where you can enter commands just like in a regular shell.

#### Example Usage

```bash
$ ./minishell
meow🙀shell> pwd
/home/user/meowshell
meow🙀shell> echo "Hello World"
Hello World
meow🙀shell> ls | grep README
README.md
meow🙀shell> export MY_VAR=42
meow🙀shell> echo $MY_VAR
42
meow🙀shell> exit
exit
```

For memory leak detection with valgrind:

```bash
make valgrind
```

View the valgrind report:

```bash
cat valgrind_report.txt
```

### Cleanup

To remove compiled objects and test binaries:

```bash
make clean
```

To remove all generated files including the executable:

```bash
make fclean
```

## Project Structure

- **minishell.c** - Main entry point
- **minishell.h** - Header file with definitions
- **Makefile** - Build configuration
- **testers.md** - Testing documentation

- **ms_parser/** - Command parsing and tokenization
  - `ms_tokenizer.c` - Breaks input into tokens
  - `ms_parser.c` - Main parsing logic
  - `ms_var_expander.c` - Variable expansion ($VAR)
  - `ms_quote_handler.c` - Handles single and double quotes
  - `ms_redirect_segmenter.c` - Identifies redirections
  - `ms_command_segmenter.c` - Segments commands
  - `ms_char_handler.c` - Character handling
  - `ms_error_handler.c` - Error handling
  - `ms_operator_utils.c` - Operator utilities
  - `ms_parser.h` - Parser header
  - `ms_quoted_string_handler.c` - Quoted string handling
  - `ms_token_manager.c` - Token management
  - `ms_type_checker.c` - Type checking
  - `ms_word_collector.c` - Word collection

- **ms_executor/** - Command execution engine
  - `ms_executor_main.c` - Main execution logic
  - `ms_executor_pipeline.c` - Pipe handling
  - `ms_executor_redirections.c` - I/O redirection
  - `ms_executor_heredoc.c` - Heredoc processing
  - `ms_executor_signals.c` - Signal handling
  - `ms_executor_builtin.c` - Built-in command execution
  - `ms_executor_env.c` - Environment handling
  - `ms_executor_external.c` - External command execution
  - `ms_executor_heredoc_preprocess.c` - Heredoc preprocessing
  - `ms_executor_pipeline_utils.c` - Pipeline utilities
  - `ms_executor_utils.c` - Executor utilities
  - `ms_executor.h` - Executor header
  - `ms_find_utils.c` - Find utilities

- **ms_built_in/** - Built-in shell commands
  - `ms_echo.c` - Echo command
  - `ms_env.c` - List environment variables
  - `ms_exit.c` - Exit shell
  - `ms_helpers.c` - Helper functions
  - `ms_pwd.c` - Print working directory
  - `ms_unset.c` - Unset variables
  - `ms_cd/` - Change directory
    - `ms_cd.c` - Main cd logic
    - `ms_cd_error.c` - Cd error handling
    - `ms_cd_helpers.c` - Cd helpers
  - `ms_export/` - Export environment variables
    - `ms_export.c` - Main export logic
    - `ms_export_extract_info.c` - Extract info
    - `ms_export_helpers.c` - Export helpers
    - `ms_export_print_vars.c` - Print variables
    - `ms_export_update_vars.c` - Update variables

- **libft/** - Custom C library (modified 42 libft project)
  - String manipulation functions (ft_str*.c)
  - Memory management (ft_mem*.c)
  - List structures (ft_lst*.c)
  - Printf implementation (printf_utils/)
  - Get next line function (gnl_utils/)
  - `libft.h` - Library header
  - `Makefile` - Library build

- **ms_utils/** - Utility functions
  - `ms_mem_manager.c` - Memory allocation tracking

- **tests/** - Test files
  - `basic_tokenizer_tester.c` - Basic tokenizer tests
  - `command_segment_tester.c` - Command segment tests
  - `complex_tokenizer_tester.c` - Complex tokenizer tests
  - `var_expansion_tester.c` - Variable expansion tests

## Built-in Commands

Minishell supports the following built-in commands:

- **cd [directory]** - Change the current working directory
- **pwd** - Print the current working directory
- **echo [arguments]** - Display text (supports -n flag)
- **env** - Print environment variables
- **export [name=value]** - Set environment variables
- **unset [name]** - Unset environment variables
- **exit [status]** - Exit the shell with optional exit code

## Technical Features

- **Tokenization** - Robust handling of shell syntax including operators and whitespace
- **Variable Expansion** - Expands variables like `$VAR` and `$?` (last exit status)
- **Piping** - Full support for command pipelines with proper file descriptor management
- **Redirections** - Input (<), output (>), and append (>>)
- **Heredocs** - Support for here-documents (<<)
- **Signal Handling** - Proper handling of SIGINT (Ctrl+C) and SIGQUIT (Ctrl+\)
- **Quote Handling** - Single quotes (literal), double quotes (with expansion), escape characters
- **Error Handling** - Comprehensive error messages and status codes

## Resources

### Shell Documentation
- [GNU Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html) - Official bash documentation
- [POSIX Shell Standard](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/sh.html) - POSIX shell specification
- [The Linux Command Handbook](https://www.freecodecamp.org/news/the-linux-command-handbook/) - Beginner-friendly guide

### C Programming References
- [C Standard Library Documentation](https://en.cppreference.com/w/c) - C standard library reference
- [Advanced Linux Programming](http://advancedlinuxprogramming.com/) - System calls and process management
- [Manual Pages (man pages)](https://man7.org/linux/man-pages/) - Linux manual pages for system calls

### Testing Resource
- [Minishell Tester](https://github.com/LucasKuhn/minishell_tester) - Popular community tester

## AI Usage

AI was used for the following purposes in this project:

1. **Testing** - Assisted in creating comprehensive test cases and identifying edge cases in the parsing and execution logic
2. **Bash Research** - Helped research and clarify bash behavior and shell syntax that wasn't immediately clear, including specific behaviors of operators and redirections
3. **Debugging** - Assisted in identifying and fixing bugs, particularly in complex areas like pipeline execution, variable expansion, and signal handling

AI was used to supplement development but did not generate the core project structure or primary implementation logic.

## Note

- This is an educational project intended for learning purposes as part of the 42 curriculum