#!/bin/sh

if [ -z "$1" ]; then
	make all > /dev/null
	if [ $? -ne 0 ]; then
		echo "Build failed."
		exit 1
	fi
	./bin/libft-test
else
	make "$1" > /dev/null
	if [ $? -ne 0 ]; then
		echo "Build failed."
		exit 1
	fi
	./bin/$1
fi
