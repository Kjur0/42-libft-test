#!/bin/sh

make pre > /dev/null

if [ -z "$1" ]; then
	make all > /dev/null
	if [ $? -ne 0 ]; then
		echo "Build failed."
		exit 1
	fi
	set failed = 0
	for test in ./bin/*; do
		"$test"
		failed=$((failed + $?))
	done
	if [ $failed -eq 0 ]; then
		echo "All tests passed!"
	else
		echo "$failed tests failed."
	fi
else
	make "$1" > /dev/null
	if [ $? -ne 0 ]; then
		echo "Build failed."
		exit 1
	fi
	./bin/$1
fi

make clean > /dev/null
