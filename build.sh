#!/bin/bash -x

#make distclean && ./configure --enable-debug && make -j8 && ./test/test

function get_prev_sha() {
	git log -n2 --oneline | awk {'print $1'} | sed -n '2 p'
}

function clean() {
	make distclean
}

function build() {
	make distclean
	./configure && make -j8
}

function gdb_test() {
	pushd test
	LD_LIBRARY_PATH=/home/user/workdir/software/github/LCUI/src/.libs \
	gdb -batch -ex "run" -ex "bt" \
	/home/user/workdir/software/github/LCUI/test/.libs/test_block_layout
	popd
}

function run_test() {
	pushd test
	LD_LIBRARY_PATH=/home/user/workdir/software/github/LCUI/src/.libs \
	/home/user/workdir/software/github/LCUI/test/.libs/test_block_layout
	RET=$?
	popd
	return ${RET}
}

RET=-1
while [ "x${RET}" != "x0" ]; do
	SHA=$(git log -n2 --oneline | awk {'print $1'} | sed -n '2 p')
	git checkout ${SHA}
	git reset --hard
	cp test/test_block_layout.c.bak test/test_block_layout.c

	make distclean > build.log 2>&1
	./configure > build.log 2>&1
	make -j8 > build.log 2>&1 || echo "Build fail!!!"
	run_test > test.log 2>&1
	RET=$?
done

