all: clean prep 001 002 003 004 005 006 007 008 009 010 011 012 013 014 015 016 017 018 019 020 021 022 023 024 025 026 027 028 029 030 031

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
016:
	cc 016-word_counting.c -o ./bin/016-word_counting
017:
	cc 017-test_word_counting.c -o ./bin/017-test_word_counting
018:
	cc 018-one_word_per_line.c -o ./bin/018-one_word_per_line
019:
	cc 019-arrays.c -o ./bin/019-arrays
020:
	cc 020-histogram_horizontal.c -o ./bin/020-histogram_horizontal
021:
	cc 021-histogram_vertical.c -o ./bin/021-histogram_vertical
022:
	cc 022-histogram_character.c -o ./bin/022-histogram_character
023:
	cc 023-functions.c -o ./bin/023-functions
024:
	cc 024-f2c_function.c -o ./bin/024-f2c_function
025:
	cc 025-pass_by_value.c -o ./bin/025-pass_by_value
026:
	cc 026-pass_by_reference.c -o ./bin/026-pass_by_reference
027:
	cc 027-longest_line.c -o ./bin/027-longest_line
028:
	cc 028-longest_line_stats.c -o ./bin/028-longest_line_stats
029:
	cc 029-longer_80_chars.c -o ./bin/029-longer_80_chars
030:
	cc 030-remove_blanks_tabs.c -o ./bin/030-remove_blanks_tabs
031:
	cc 031-reverse_string.c -o ./bin/031-reverse_string
clean:
	rm -rf ./bin/*
