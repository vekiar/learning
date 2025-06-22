all: clean prep 001 002 003 004 005 006 007 008 009 010 011 012 013 014 015 016 017 018 019 020 021 022 023 024 025 026 027 028 029 030 031 032 033 034 035 036 037 038 039 040 041 042 043 044 045 046 047 048 049 050 051 052 053 054 055 056 057 058 059 060 061 062 063

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
032:
	cc 032-detab.c -o ./bin/032-detab
033:
	cc 033-entab.c -o ./bin/033-entab
034:
	cc 034-fold.c -o ./bin/034-fold
035:
	cc 035-remove_comments.c -o ./bin/035-remove_comments
036:
	cc 036-syntax_check.c -o ./bin/036-syntax_check
037:
	cc 037-determine_ranges.c -o ./bin/037-determine_ranges
038:
	cc 038-rewrite_for.c -o ./bin/038-rewrite_for
039:
	cc 039-convert_hex_to_int.c -o ./bin/039-convert_hex_to_bin -lm
040:
	cc 040-squeeze_alternate.c -o ./bin/040-squeeze_alternate -lm
041:
	cc 041-any_character_strings.c -o ./bin/041-any_character_strings -lm
042:
	cc 042-bitwise_operators.c -o ./bin/042-bitwise_operators -lm
043:
	cc 043-setbits.c -o ./bin/043-setbits -lm
044:
	cc 044-invert.c -o ./bin/044-invert -lm
045:
	cc 045-rightrot.c -o ./bin/045-rightrot -lm
046:
	cc 046-bitcount.c -o ./bin/046-bitcount -lm
047:
	cc 047-faster_bitcount.c -o ./bin/047-faster_bitcount -lm
048:
	cc 048-conditional_expressions.c -o ./bin/048-conditional_expressions -lm
049:
	cc 049-lower.c -o ./bin/049-lower -lm
050:
	cc 050-binary_search.c -o ./bin/050-binary_search -lm
051:
	cc 051-binary_search_optimised.c -o ./bin/051-binary_search_optimised -lm
052:
	cc 052-switch.c -o ./bin/052-switch -lm
053:
	cc 053-switch_special_chars.c -o ./bin/053-switch_special_chars -lm
054:
	cc 054-for_infinity.c -o ./bin/054-for_infinity -lm
055:
	cc 055-atoi-version_2.c -o ./bin/055-atoi_version_2 -lm
056:
	cc 056-shell_sort.c -o ./bin/056-shell_sort -lm
057:
	cc 057-reverse_string_place.c -o ./bin/057-reverse_string_place -lm
058:
	cc 058-expand_notation.c -o ./bin/058-expand_notation -lm
059:
	cc 059-do_while.c -o ./bin/059-do_while -lm
060:
	cc 060-itoa.c -o ./bin/060-itoa -lm
061:
	cc 061-itoa_twos_complement.c -o ./bin/061-itoa_twos_complement -lm
062:
	cc 062-itob.c -o ./bin/062-itob -lm
063:
	cc 063-itoa_padded.c -o ./bin/063-itoa_padded -lm
clean:
	rm -rf ./bin/*
