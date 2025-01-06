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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stats.h"

/**
 * Calls a shell command and returns the output as a string.
 *
 * Falls back to "Not installed" if the command fails.
 */
char* app_version(const char *command) {
	FILE *fp;
	// NOTE 50 should be more than enough space for version info.
	char buffer[50];

	fp = popen(command, "r");
	if (fp == NULL) {
		return "Not installed";
	}

	fgets(buffer, sizeof(buffer), fp);
	pclose(fp);

	return strdup(buffer);
}

/**
 * Checks if a character is a boundary character.
 */
bool is_boundary(char c) {
	return c == ' ' || c == '\n';
}

/**
 * Splits outputs in the format `"Appname x.y.z\n"` into `"x.y.z"`.
 */
char* extract_named_version(const char *version_info) {
	int start;
	int end;
	int len;

	len = strlen(version_info);
	for (start = 0; version_info[start] != ' ' && start < len; start++);
	for (end = start + 1; end < len && !is_boundary(version_info[end]); end++);
	return strndup(version_info + start + 1, end - start - 1);
}

char* fastfetch() {
	// NOTE Version in the format "fastfetch x.x.x (ARCH)"
	char *out = app_version("fastfetch --version");
	return extract_named_version(out);
}

char* neofetch() {
	// NOTE Version in the format "Neofetch x.x.x"
	char *out = app_version("neofetch --version");
	return extract_named_version(out);
}

char* onefetch() {
	// NOTE Version in the format "onefetch x.x.x"
	char *out = app_version("onefetch --version");
	return extract_named_version(out);
}

FetchStat* get_stats() {
	FetchStat *stats = malloc(STATS_SIZE * sizeof(FetchStat));
	stats[0].label = "Fastfetch";
	stats[0].version = fastfetch();
	stats[1].label = "Neofetch";
	stats[1].version = neofetch();
	stats[2].label = "onefetch";
	stats[2].version = onefetch();
	return stats;
}
