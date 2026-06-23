*This project has been created as part of the 42 curriculum by **kjurkows***

# `libft-test`

**IT IS NOT NORM COMPLIANT**

## Description

`libft-test` is a testing suite for `libft`. Used for tesing all functions using `gtest`(Google Test).

See [Detailed description](#detailed-description) for list of tests.

## Instructions

### Before testing

clone your `libft` into `libft` folder

### Running all tests

```shell
./test.sh
```

### Running tests for a specific function

```shell
./test.sh <function name>
```
> [!NOTE]
> `<function name>` shouldn't include the prefix `ft_`

## Resources

* [GoogleTest User’s Guide](https://google.github.io/googletest/)

### AI Usage

> [!IMPORTANT]
> All AI code was used after carefull analysis.

#### Google search AI mode & Gemini

AI mode was used while searching for edge cases in `libc`/`libbsd` functions (Part 1)

Gemini was used while searching for edge cases in parts 2 & 3.

> [!IMPORTANT]
> While AI was used for searching for the edge cases it was not the only source of them.  
> Most edge cases were crafted and tested by manual analysis

#### GitHub Copilot

AI inline suggestions were used for repetative tasks, such as:
* Writing `#include`s
* Writing *boilerplate code* (`malloc`s, `free`s, same functions with different inputs)

## Detailed description

Some tests are `DeathTest`s, they only check if the function handles segfaults gracefully. They do not check for the output of the function.

Below is the list as all tests:

### Norminette

| Name    | Description                           |
|---------|---------------------------------------|
| `norme` | Check if all files are norm compliant |

### Part 1 - `libc` functions

For those test `libft` is tested against `libc`

[^bsd]: functions are tested against `libbsd`
[^dt]: `DeathTest` - only checks if the function handles segfaults gracefully. Does not check for the output of the function.

#### [`isalpha`](srcs/isalpha.cpp)

| Test         | Tested chars               |
|--------------|----------------------------|
| space        | `' '`                      |
| digit        | `'1'`                      |
| lowercase    | `'a'`                      |
| uppercase    | `'A'`                      |
| punctuaction | `'-'`                      |
| null_char    | `'\0'`                     |
| control_char | `'\r'`                     |
| non_ascii    | `'\255'`                   |
| undefined    | non `unsigned char` values |

#### [`isdigit`](srcs/isdigit.cpp)

| Test         | Tested chars               |
|--------------|----------------------------|
| space        | `' '`                      |
| digit        | `'1'`                      |
| lowercase    | `'a'`                      |
| uppercase    | `'A'`                      |
| punctuaction | `'-'`                      |
| null_char    | `'\0'`                     |
| control_char | `'\r'`                     |
| non_ascii    | `'\255'`                   |
| undefined    | non `unsigned char` values |

#### [`isalnum`](srcs/isalnum.cpp)

| Test         | Tested chars               |
|--------------|----------------------------|
| space        | `' '`                      |
| digit        | `'1'`                      |
| lowercase    | `'a'`                      |
| uppercase    | `'A'`                      |
| punctuaction | `'-'`                      |
| null_char    | `'\0'`                     |
| control_char | `'\r'`                     |
| non_ascii    | `'\255'`                   |
| undefined    | non `unsigned char` values |

#### [`isascii`](srcs/isascii.cpp)

| Test         | Tested chars               |
|--------------|----------------------------|
| space        | `' '`                      |
| digit        | `'1'`                      |
| lowercase    | `'a'`                      |
| uppercase    | `'A'`                      |
| punctuaction | `'-'`                      |
| null_char    | `'\0'`                     |
| control_char | `'\r'`                     |
| non_ascii    | `'\255'`                   |
| undefined    | non `unsigned char` values |

#### [`isprint`](srcs/isprint.cpp)

| Test         | Tested chars               |
|--------------|----------------------------|
| space        | `' '`                      |
| digit        | `'1'`                      |
| lowercase    | `'a'`                      |
| uppercase    | `'A'`                      |
| punctuaction | `'-'`                      |
| null_char    | `'\0'`                     |
| control_char | `'\r'`                     |
| non_ascii    | `'\255'`                   |
| undefined    | non `unsigned char` values |

#### [`strlen`](srcs/strlen.cpp)

| Test                  | String tested          |
|-----------------------|------------------------|
| basic                 | `"Hello, World!"`      |
| empty_string          | `""`                   |
| long_string           | `"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."` |
| string_with_null_char | `"Hello\0World"`       |
| nullptr[^dt]          | `nullptr`              |

#### [`memset`](srcs/memset.cpp)

| Test          | Description                       |
|---------------|-----------------------------------|
| basic         | Set 5 bytes of a buffer to `'x'`  |
| full_length   | Set entire buffer to `'x'`        |
| non_printable | Set 5 bytes of a buffer to `'\0'` |
| zero_length   | Set 0 bytes of a buffer to `'x'`  |
| nullptr[^dt]  | Graceful `segfault` handling      |

#### [`bzero`](srcs/bzero.cpp)

| Test           | Description                                          |
|----------------|------------------------------------------------------|
| basic          | Zero 5 bytes of a buffer                             |
| zero_length    | Zero 0 bytes of a buffer                             |
| full_length    | Zero entire buffer                                   |
| partial_length | Zero part of a buffer                                |
| non_ascii      | Zero 5 bytes of a buffer containing non-ASCII values |
| nullptr[^dt]   | Graceful `segfault` handling                         |

#### [`memcpy`](srcs/memcpy.cpp)

| Test             | Description                           |
|------------------|---------------------------------------|
| basic            | Copy full buffer                      |
| zero_length      | Copy 0 bytes                          |
| null_char        | Copy string with `'\0'` in the middle |
| partial_length   | Copy part of a buffer                 |
| nullptr_dst[^dt] | Graceful `segfault` handling          |
| nullptr_src[^dt] | Graceful `segfault` handling          |

#### [`memmove`](srcs/memmove.cpp)

| Test             | Description                                     |
|------------------|-------------------------------------------------|
| move_backwards   | Move bytes to an earlier position in the buffer |
| move_forwards    | Move bytes to a later position in the buffer    |
| zero_length      | Move 0 bytes                                    |
| null_char        | Move string with `'\0'` in the middle           |
| in_place         | Move bytes to the same position in the buffer   |
| nullptr_dst[^dt] | Graceful `segfault` handling                    |
| nullptr_src[^dt] | Graceful `segfault` handling                    |

#### [`strlcpy`](srcs/strlcpy.cpp)[^bsd]

| Test             | Description                                 |
|------------------|---------------------------------------------|
| basic            | Copy string into a buffer with enough space |
| zero_size        | Copy string into a buffer of size 0         |
| smaller_size     | Copy string into a smaller buffer           |
| empty_string     | Copy an empty string into a buffer          |
| exact_size       | Copy string into a buffer of exact size     |
| nullptr_dst[^dt] | Graceful `segfault` handling                |
| nullptr_src[^dt] | Graceful `segfault` handling                |

#### [`strlcat`](srcs/strlcat.cpp)[^bsd]

| Test                     | Description                                                |
|--------------------------|------------------------------------------------------------|
| basic                    | Concatenate string into a buffer with enough space         |
| zero_size                | Concatenate string into a buffer of size 0                 |
| size_smaller_than_dst    | Concatenate string into a buffer smaller than `dst`        |
| size_smaller_than_src    | Concatenate string into a buffer smaller than needed       |
| empty_src                | Concatenate an empty string into a buffer                  |
| empty_dst                | Concatenate string into an empty buffer                    |
| size_equal_to_dst        | Concatenate string into a buffer of size equal to `dst`    |
| size_equal_to_dst_plus_1 | Concatenate string into a buffer of size equal to `dst + 1`|
| size_equal_to_src        | Concatenate string into a buffer of size equal to `src`    |
| size_one                 | Concatenate string into a buffer of size 1                 |
| exact_size               | Concatenate string into a buffer of exact size             |
| dst_not_nul_teminated    | Concatenate string into a non `NUL`-terminated buffer      |
| nullptr_dst[^dt]         | Graceful `segfault` handling                                |
| nullptr_src[^dt]         | Graceful `segfault` handling                                |

#### [`toupper`](srcs/toupper.cpp)

| Test         | Tested chars               |
|--------------|----------------------------|
| basic        | `'a', 'z', 'A', 'Z'`       |
| numbers      | `'0', '9'`                 |
| special      | `'@', '/', ':'`            |
| non_ascii    | `'\128'`                   |
| negative     | `-12`                      |
| out_of_range | `256`                      |
| null_char    | `'\0'`                     |
| all_chars    | all `unsigned char` values |
| eof          | `EOF`                      |

#### [`tolower`](srcs/tolower.cpp)

| Test         | Tested chars               |
|--------------|----------------------------|
| basic        | `'a', 'z', 'A', 'Z'`       |
| numbers      | `'0', '9'`                 |
| special      | `'@', '/', ':'`            |
| non_ascii    | `'\128'`                   |
| negative     | `-12`                      |
| out_of_range | `256`                      |
| null_char    | `'\0'`                     |
| all_chars    | all `unsigned char` values |
| eof          | `EOF`                      |

#### [`strchr`](srcs/strchr.cpp)

| Test                 | Description                          |
|----------------------|--------------------------------------|
| basic                | `'o'` in `"Hello, World!"`           |
| not_found            | `'x'` in `"Hello, World!"`           |
| null_terminator      | `'\0'` in `"Hello, World!"`          |
| empty_string         | `'a'` in `""`                        |
| multiple_occurrences | `'l'` in `"Hello, World!"`           |
| non_ascii            | `256 + 'a'` in `"Hello, \255World!"` |
| nullptr[^dt]         | Graceful `segfault` handling         |

#### [`strrchr`](srcs/strrchr.cpp)

| Test                 | Description                          |
|----------------------|--------------------------------------|
| basic                | `'o'` in `"Hello, World!"`           |
| not_found            | `'x'` in `"Hello, World!"`           |
| null_terminator      | `'\0'` in `"Hello, World!"`          |
| empty_string         | `'a'` in `""`                        |
| multiple_occurrences | `'l'` in `"Hello, World!"`           |
| non_ascii            | `256 + 'a'` in `"Hello, \255World!"` |
| nullptr[^dt]         | Graceful `segfault` handling         |

#### [`strncmp`](srcs/strncmp.cpp)

| Test                  | Description                                                    |
|-----------------------|----------------------------------------------------------------|
| equal                 | Compare `"Hello, World!"` and `"Hello, World!"`                |
| different             | Compare `"Hello, World!"` and `"Hello. World!"`                |
| zero_length           | Compare `"Hello, World!"` and `"Hello. World!"` with length 0  |
| null_char             | Compare `"Hello\0World"` and `"Hello\0World"`                  |
| n_less_than_length    | Compare `"Hello, World!"` and `"Hello, world!"` with length 5  |
| n_greater_than_length | Compare `"Hello, World!"` and `"Hello, world!"` with length 20 |
| non_ascii             | Compare `"Héllo, wörld!"` and `"Héllo, wörld!"`                |
| non_ascii_different   | Compare `"Héllo, wörld!"` and `"Héllo, world?"`                |
| nullptr1[^dt]         | Graceful `segfault` handling                                   |
| nullptr2[^dt]         | Graceful `segfault` handling                                   |

#### [`memchr`](srcs/memchr.cpp)

| Test                 | Description                              |
|----------------------|------------------------------------------|
| basic                | `'o'` in `"Hello, World!"`               |
| not_found            | `'x'` in `"Hello, World!"`               |
| zero_length          | `'o'` in `"Hello, World!"` with length 0 |
| null_char            | `'\0'` in `"Hello, World!"`              |
| non_ascii            | `255` in `"Hello, \255World!"`           |
| multiple_occurrences | `'l'` in `"Hello, World!"`               |
| nullptr[^dt]         | Graceful `segfault` handling             |

#### [`memcmp`](srcs/memcmp.cpp)

| Test           | Description                                                   |
|----------------|---------------------------------------------------------------|
| basic          | Compare `"Hello, World!"` and `"Hello, World!"`               |
| different      | Compare `"Hello, World!"` and `"Hello. World!"`               |
| zero_length    | Compare `"Hello, World!"` and `"Hello, World!"` with length 0 |
| null_char      | Compare `"Hello\0World"` and `"Hello\0World"`                 |
| partial_length | Compare `"Hello, World!"` and `"Hello, World!"` with length 5 |
| non_ascii      | Compare `"Hello, \255World!"` and `"Hello, World!"`           |
| nullptr1[^dt]  | Graceful `segfault` handling                                  |
| nullptr2[^dt]  | Graceful `segfault` handling                                  |

#### [`strnstr`](srcs/strnstr.cpp)[^bsd]

| Test                    | Description                                        |
|-------------------------|----------------------------------------------------|
| basic                   | Find `"world"` in `"Hello, world!"` with length 13 |
| not_found               | Find `"42"` in `"Hello, world!"` with length 13    |
| empty_to_find           | Find `""` in `"Hello, world!"` with length 13      |
| length_limit            | Find `"world"` in `"Hello, world!"` with length 5  |
| null_char               | Find `"world"` in `"Hello\0world!"` with length 13 |
| to_find_longer_than_str | Find `"Hello, world!"` in `"Hello"` with length 13 |
| nullptr_big[^dt]        | Graceful `segfault` handling                       |
| nullptr_little[^dt]     | Graceful `segfault` handling                       |

#### [`atoi`](srcs/atoi.cpp)

| Test             | Number tested                    |
|------------------|----------------------------------|
| 0                | `0`                              |
| 1                | `1`                              |
| 42               | `42`                             |
| overflow         | `2147483648`                     |
| underflow        | `-2147483649`                    |
| whitespace       | `"\t\n\v\f\r 42"`                |
| plus_sign        | `"+42"`                          |
| minus_sign       | `"-42"`                          |
| non_numeric      | `"42abc"`                        |
| empty_string     | `""`                             |
| only_whitespace  | `"\t\n\v\f\r "`                  |
| multiple_signs   | `"--42", "++42", "+-42", "-+42"` |
| too_large_number | `"999999999999999999999999"`     |
| too_small_number | `"-999999999999999999999999"`    |
| nullptr[^dt]     | Graceful `segfault` handling     |

#### [`calloc`](srcs/calloc.cpp)

| Test       | `nmemb`        | `size`        |
|------------|----------------|---------------|
| basic      | `5`            | `sizeof(int)` |
| zero_nmemb | `0`            | `sizeof(int)` |
| zero_size  | `5`            | `0`           |
| overflow   | `__SIZE_MAX__` | `sizeof(int)` |

#### [`strdup`](srcs/strdup.cpp)

| Test                  | String                       |
|-----------------------|------------------------------|
| basic                 | `"Hello, World!"`            |
| empty_string          | `""`                         |
| long_string           | `"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."` |
| string_with_null_char | `"Hello\0World"`             |
| nullptr[^dt]          | Graceful `segfault` handling |

### Part 2 - Additional functions

These are tested agains expected output, not `libc`

#### [`substr`](srcs/substr.cpp)

| Test                | Description                              | Expected  |
|---------------------|------------------------------------------|-----------|
| basic               | Extract `"World"` from `"Hello, World!"` | `"World"` |
| start_beyond_length | Index is greater than string length      | `""`      |
| length_exceeds      | Length extends beyond string end         | `"ello"`  |
| zero_length         | Length is 0                              | `""`      |

#### [`strjoin`](srcs/strjoin.cpp)

| Test         | Description                     | Expected          |
|--------------|---------------------------------|-------------------|
| basic        | Join `"Hello, "` and `"World!"` | `"Hello, World!"` |
| empty_first  | Join `""` and `"World!"`        | `"World!"`        |
| empty_second | Join `"Hello, "` and `""`       | `"Hello, "`       |
| both_empty   | Join `""` and `""`              | `""`              |

#### [`strtrim`](srcs/strtrim.cpp)

| Test      | Description                             | Expected           |
|-----------|-----------------------------------------|--------------------|
| basic     | Trim whitespace from both ends          | `"Hello, World!"`  |
| no_trim   | No characters to trim                   | `"Hello, World!"`  |
| all_trim  | Trim all characters                     | `""`               |
| empty_set | Trim with empty set                     | `"Hello, World!"`  |

#### [`split`](srcs/split.cpp)

| Test            | Description                       | Expected               |
|-----------------|-----------------------------------|------------------------|
| basic           | Split `"Hello, World!"` by space  | `["Hello,", "World!"]` |
| empty_string    | Split `""` by space               | `[]`                   |
| only_delimiters | Split `"   "` by space            | `[]`                   |
| no_delimiters   | Split `"HelloWorld!"` by space    | `["HelloWorld!"]`      |
| null_delimiter  | Split `"Hello, World!"` by `'\0'` | `["Hello, World!"]`    |
| consecutive     | Split `"Hello,,World!"` by `','`  | `["Hello", "World!"]`  |
| edges           | Split `",Hello,World!,"` by `','` | `["Hello", "World!"]`  |

#### [`itoa`](srcs/itoa.cpp)

| Test    | Number tested | Expected        |
|---------|---------------|-----------------|
| 0       | `0`           | `"0"`           |
| 42      | `42`          | `"42"`          |
| 123     | `123`         | `"123"`         |
| neg42   | `-42`         | `"-42"`         |
| int_min | `-2147483648` | `"-2147483648"` |
| int_max | `2147483647`  | `"2147483647"`  |

#### [`strmapi`](srcs/strmapi.cpp)

| Test    | Description                                                        | Expected          |
|---------|--------------------------------------------------------------------|-------------------|
| index   | Create new string where each `char` is modified based on its index | `"0123456798"`    |
| toupper | Convert string to uppercase                                        | `"HELLO, WORLD!"` |
| tolower | Convert string to lowercase                                        | `"hello, world!"` |
| empty   | Apply function to an empty string                                  | `""`              |


#### [`striteri`](srcs/striteri.cpp)

| Test   | Description                                                  |
|--------|--------------------------------------------------------------|
| basic  | Ensure each character is `'0' + i` and function run 10 times |
| empty  | Ensure function does not run on an empty string              |
| change | Ensure function can modify the string in place               |

#### [`putchar_fd`](srcs/putchar_fd.cpp)

| Test | Description                                                 |
|------|-------------------------------------------------------------|
| test | Ensure that `'A'` is written to `/tmp/tests/putchar_fd.txt` |

#### [`putstr_fd`](srcs/putstr_fd.cpp)

| Test | Description                                                            |
|------|------------------------------------------------------------------------|
| test | Ensure that `"Hello, World!"` is written to `/tmp/tests/putstr_fd.txt` |

#### [`putendl_fd`](srcs/putendl_fd.cpp)

| Test | Description                                                               |
|------|---------------------------------------------------------------------------|
| test | Ensure that `"Hello, World!\n"` is written to `/tmp/tests/putendl_fd.txt` |

#### [`putnbr_fd`](srcs/putnbr_fd.cpp)

| Test    | Description                                                                |
|---------|----------------------------------------------------------------------------|
| 42      | Ensure that `42` is written to `/tmp/tests/putnbr_fd_42.txt`               |
| 0       | Ensure that `0` is written to `/tmp/tests/putnbr_fd_0.txt`                 |
| neg1    | Ensure that `-1` is written to `/tmp/tests/putnbr_fd_neg1.txt`             |
| neg42   | Ensure that `-42` is written to `/tmp/tests/putnbr_fd_neg42.txt`           |
| int_min | Ensure that `-2147483648` is written to `/tmp/tests/putnbr_fd_int_min.txt` |
| int_max | Ensure that `2147483647` is written to `/tmp/tests/putnbr_fd_int_max.txt`  |

### Part 3 - linked list

#### [`lstnew`](srcs/lstnew.cpp)

| Test  | Description                                                   |
|-------|---------------------------------------------------------------|
| basic | Ensure that a new list node is created with the given content |

#### [`lstadd_front`](srcs/lstadd_front.cpp)

| Test      | Description                                                 |
|-----------|-------------------------------------------------------------|
| basic     | Ensure that a new node is added to the front of the list    |
| null_list | Ensure that a new node is added to the front of a null list |

#### [`lstsize`](srcs/lstsize.cpp)

| Test   | Description                                                   |
|--------|---------------------------------------------------------------|
| basic  | Ensure that the size of a list with multiple nodes is correct |
| empty  | Ensure that the size of an empty list is 0                    |
| single | Ensure that the size of a list with one node is 1             |

#### [`lstlast`](srcs/lstlast.cpp)

| Test   | Description                                                        |
|--------|--------------------------------------------------------------------|
| basic  | Ensure that the last node of a list with multiple nodes is correct |
| empty  | Ensure that `nullptr` is returned for an empty list                |
| single | Ensure that the last node of a list with one node is that node     |

#### [`lstadd_back`](srcs/lstadd_back.cpp)

| Test      | Description                                                    |
|-----------|----------------------------------------------------------------|
| basic     | Ensure that a new node is added to the back of the list        |
| null_list | Ensure that a new node is set as the first node of a null list |

#### [`lstdelone`](srcs/lstdelone.cpp)

| Test      | Description                                             |
|-----------|---------------------------------------------------------|
| basic     | Ensure that a node is deleted and its content freed     |
| null_node | Ensure that deleting a null node does not cause a crash |

#### [`lstclear`](srcs/lstclear.cpp)

| Test      | Description                                                         |
|-----------|---------------------------------------------------------------------|
| basic     | Ensure that all nodes in a list are deleted and their content freed |
| null_list | Ensure that clearing an empty list does not cause a crash           |

#### [`lstiter`](srcs/lstiter.cpp)

| Test      | Description                                                   |
|-----------|---------------------------------------------------------------|
| basic     | Ensure that a function is applied to each node's content      |
| null_list | Ensure that iterating over a null list does not cause a crash |

#### [`lstmap`](srcs/lstmap.cpp)

| Test      | Description                                              |
|-----------|----------------------------------------------------------|
| basic     | Ensure that a function is applied to each node's content |
| null_list | Ensure that mapping over a null list returns a null list |
