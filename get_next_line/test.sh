#! /bin/bash

SOURCES=(get_next_line get_next_line_utils)
SRCSDIR=../../repo/
CFLAGS="-Wall -Wextra -Werror"
TESTS=(free_fd_test test)
MSG_TESTFAILED="Test failed !"
MSG_TESTPASSED="Test passed !"
FILESDIR=files/

w84kpress () {
	echo "Press any key to continue."
	read -n 1
}

da42_test_result () {
	if [[ $1 -eq 1 ]]
	then
		echo $MSG_TESTPASSED
	else
		echo $MSG_TESTFAILED
	fi;
}

da42_compile() {
	local buffer_size=32
	if [[ ! -z "$2" ]]
		then
			buffer_size=$2
	fi
	echo "Compiling with command :"
	echo "gcc $CFLAGS -D BUFFER_SIZE=${buffer_size} -I../repo/ $files $1.c -o $1"
	gcc $CFLAGS -D BUFFER_SIZE=${buffer_size} -I../repo/ $files $1.c -o $1 
}

da42_free_fd_test() {
	local test_res=0

	da42_compile free_fd_test 55
	echo "Test with fd = -1"
	./free_fd_test -1
	if [[ $? -eq 255 ]]
	then
		test_res=1
	fi
	echo $test_res
	da42_test_result $test_res
	rm free_fd_test
	w84kpress
}

da42_test() {
	clear
	echo "Standard tests"
	local buffer_size=(32 1 2048)
	local buffer_qualify=("std" "tiny" "large")
	local file=("standard" "long" "verylongline" "empty")
	local test_res=1
	local bdx;
	for (( bdx=${#buffer_size[@]} - 1; bdx >= 0; bdx-- ))
	do
		clear
		echo "Test ${buffer_qualify[$bdx]} BUFFER_SIZE=${buffer_size[$bdx]}" 
		da42_compile test ${buffer_size[$bdx]}
		w84kpress
		for fname in ${file[@]}
		do
			echo "Testing with ${fname}"
			./test ${FILESDIR}${fname}.out ${FILESDIR}${fname} 
			diff ${FILESDIR}${fname}.out ${FILESDIR}${fname}
			if [[ $? -ne 0 ]]
			then
				test_res=0
			fi
			da42_test_result $test_res
			test_res=1
			w84kpress
		done
	done
	clear
	echo "Test specific buffer sizes for 8 char long files"
	file=(file8)
	buffer_size=(7 9)
	buffer_qualify=("-1 char long buffer" "+1 char long buffer")
	for (( bdx=${#buffer_size[@]} - 1; bdx >= 0; bdx-- ))
	do
		clear
		echo "Test ${buffer_qualify[$bdx]} BUFFER_SIZE=${buffer_size[$bdx]}"
		da42_compile test ${buffer_size[$bdx]}
		w84kpress
		for fname in ${file[@]}
		do
			echo "Testing with ${fname}"
			./test ${FILESDIR}${fname}.out ${FILESDIR}${fname}
			diff ${FILESDIR}${fname}.out ${FILESDIR}${fname}
			if [[ $? -ne 0 ]]
			then
				test_res=0
			fi
			da42_test_result $test_res
			test_res=1
			w84kpress
		done
	done
	rm test
	rm ${FILESDIR}*.out 
}

da42_bonus() {
	local test_res
	clear
	echo "Testing bonus"
	norminette $files
	da42_compile bonus
	./bonus bonus.out ${FILESDIR}std1 ${FILESDIR}std2 ${FILESDIR}std3
	diff bonus.out ${FILESDIR}bonus.cmp
	if [[ $? -eq 0 ]]
	then
		test_res=1
	fi
	da42_test_result $test_res
	w84kpress
	chmod u+w bonus.out
	rm bonus.out
	rm bonus
	echo "Compte du nombre d'occurence de static dans les fichiers bonus."
	local stat_res;
	stat_res=$(cat $files | grep 'static' | wc -l)
	echo "Il y a $stat_res occurences"
	if [[ stat_res -eq 1 ]] 
	then
		test_res=1
	else
		test_res=0
	fi
	da42_test_result $test_res 
}

da42_test_stdin() {
	
	local test_res=1;
	clear
	echo "Testing stdin"
	da42_compile test_stdin
	cat files/standard | ./test_stdin 
	diff files/standard test_stdin.log
	if [[ $? -ne 0 ]]
	then
		test_res=0
	fi
	da42_test_result $test_res
	w84kpress
	chmod u+w test_stdin.log
	rm test_stdin test_stdin.log
}

files=""
for file in ${SOURCES[@]}  ; do
	files+=" ${SRCSDIR}${file}.c"
done
clear
norminette $files
w84kpress
for test in ${TESTS[@]} ; do
	da42_${test}
done
da42_test_stdin
files=""
for file in ${SOURCES[@]} ; do
	files+=" ${SRCSDIR}${file}_bonus.c"
done
da42_bonus
