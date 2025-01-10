/*
 * fetchfetch - Fetch the stats of your *fetch tools
 * Copyright (C) 2025  Spenser Black
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "args.h"

int right_pad = -1;
bool print_help = false;
bool print_version = false;

bool parse_args(int argc, char **argv) {
	char *arg;
	char *end;
	for (int i = 1; i < argc; i++) {
		arg = argv[i];
		if (strcmp(arg, "-p") == 0 || strcmp(arg, "--pad") == 0) {
			if (i == argc - 1) {
				fprintf(stderr, "--pad takes 1 argument\n");
				return false;
			}
			arg = argv[++i];
			// NOTE We're ignoring overflows (the safety check isn't a priority for this tool).
			right_pad = (int)strtol(arg, &end, 10);
			if (end == arg || right_pad < 0) {
				fprintf(stderr, "--pad expected a non-negative integer, got %s\n", arg);
				return false;
			}
		} else if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
			print_help = true;
		} else if (strcmp(arg, "-v") == 0 || strcmp(arg, "--version") == 0) {
			print_version = true;
		}
	}
	return true;
}

const char *help_message = 	"Usage: fetchfetch [OPTIONS...]\n"
							"Fetch the stats of your *fetch tools\n"
							"\n"
							"Options:\n"
							"  -p, --pad N    Right-pad labels by N spaces to align values\n"
							"  -h, --help     Print this message and exit\n"
							"  -v, --version  Print the version and exit\n";
