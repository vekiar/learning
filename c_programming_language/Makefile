all: clean prep 001 002 003 004 005 006 007 008 009 010 011 012 013 014 015

prep:
	if [ ! -d ./bin ]; then mkdir ./bin/; else echo "./bin detected, skipping creation..."; fi

001:
	cc 001-hello_world.c -o ./bin/001-hello_world
002:
	cc 002-f2c.c -o ./bin/002-f2c
003:
	cc 003-f2c.c -o ./bin/003-f2c
004:
	cc 004-f2c.c -o ./bin/004-f2c
005:
	cc 005-f2c.c -o ./bin/005-f2c
006:
	cc 006-c2f.c -o ./bin/006-c2f
007:
	cc 007-f2c.c -o ./bin/007-f2c
008:
	cc 008-file_copy.c -o ./bin/008-file_copy
009:
	cc 009-file_copy.c -o ./bin/009-file_copy
010:
	cc 010-char_counting.c -o ./bin/010-char_counting
011:
	cc 011-char_counting.c -o ./bin/011-char_counting
012:
	cc 012-line_counting.c -o ./bin/012-line_counting
013:
	cc 013-count_blanks_tabs_newlines.c -o ./bin/013-count_blanks_tabs_newlines
014:
	cc 014-replace_multiple_blanks.c -o ./bin/014-replace_multiple_blanks
015:
	cc 015-copy_input_replace_with_backslashes.c -o ./bin/015-copy_input_replace_with_backslashes
clean:
	rm -rf ./bin/*
