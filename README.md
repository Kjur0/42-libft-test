# `libft-test`

**IT IS NOT NORM COMPLIANT**

## Running test

### Before testing
clone your `libft` into `libft` folder

### All tests

```shell
./test.sh
```

### Specific function

```shell
./test.sh <libc function name>
```

## Adding tests

1. Create a `<test>.c` file in `srcs`
2. `#include "test.h"`
3. Setup a test:
```c
//no printing
SETUP_TEST(/*<any params needed>*/) {
	// whatever you need to setup

	TEST(/*condition to check*/)
	// whatever you need to run after testing (like free)
	TEST_FINAL(/*condition to check*/)
}
//printing results
SETUP_TEST(/*<any params needed>*/) {
	// whatever you need to setup

	TEST_PRINT(/*condition to check*/, "PRINTF str with two %% %d %d", /*expected*/, /*real*/)
	// whatever you need to run after testing (like free)
	TEST_FINAL(/*condition to check*/)
}
```
4. Run the tests (inside `main`)
```c
int	main(void)
{
	INIT_TESTS("NAME")

	TEST_CASE(/*args*/);
	TESTS_RESULT
}
```
