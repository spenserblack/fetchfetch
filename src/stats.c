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
#include "stats.h"
#include "version.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *app_version_fallback = "Not installed";

/**
 * Calls a shell command and returns the output as a string.
 *
 * Falls back to "Not installed" if the command fails.
 */
char *app_version(const char *command) {
	FILE *fp;
	char redirected_command[50];
	// NOTE 50 should be more than enough space for version info.
	char buffer[50];
	bool failed_to_read;

	strcpy(redirected_command, command);
	strcat(redirected_command, " 2>/dev/null");

	fp = popen(redirected_command, "r");
	if (fp == NULL) {
		return app_version_fallback;
	}

	failed_to_read = fgets(buffer, sizeof(buffer), fp) == NULL;
	pclose(fp);

	if (failed_to_read || strlen(buffer) == 0) {
		return app_version_fallback;
	}

	return strdup(buffer);
}

/**
 * Checks if a character is a boundary character.
 */
bool is_boundary(char c) { return c == ' ' || c == '\n'; }

/**
 * Splits outputs in the format `"Appname x.y.z\n"` into `"x.y.z"`.
 */
char *extract_named_version(const char *version_info, const char *prefix) {
	int start;
	int end;
	int len;
	int prefix_len = strlen(prefix);

	if (version_info == app_version_fallback) {
		return app_version_fallback;
	}

	len = strlen(version_info);
	for (start = 0; version_info[start] != '\0' &&
					strncmp(version_info + start, prefix, prefix_len) != 0;
		 start++)
		;
	if (start >= len) {
		return NULL; // Prefix not found
	}
	start += prefix_len;
	for (end = start; end < len && !is_boundary(version_info[end]); end++)
		;
	return strndup(version_info + start, end - start);
}

char *fastfetch() {
	// NOTE Version in the format "fastfetch x.x.x (ARCH)"
	char *out = app_version("fastfetch --version");
	return extract_named_version(out, "fastfetch ");
}

char *neofetch() {
	// NOTE Version in the format "Neofetch x.x.x"
	char *out = app_version("neofetch --version");
	return extract_named_version(out, "Neofetch ");
}

char *onefetch() {
	// NOTE Version in the format "onefetch x.x.x"
	char *out = app_version("onefetch --version");
	return extract_named_version(out, "onefetch ");
}

char *pfetch() {
	// NOTE Version in the format "pfetch x.x.x"
	char *out = app_version("pfetch --version");
	return extract_named_version(out, "pfetch ");
}

char *uwufetch() {
	// NOTE Version in the format "UwUfetch version x.x"
	char *out = app_version("uwufetch --version");
	return extract_named_version(out, "UwUfetch version ");
}

FetchStat *get_stats() {
	FetchStat *stats = malloc(STATS_SIZE * sizeof(FetchStat));
	stats[0].label = "Fastfetch";
	stats[0].version = fastfetch();
	stats[1].label = "fetchfetch";
	stats[1].version = version;
	stats[2].label = "Neofetch";
	stats[2].version = neofetch();
	stats[3].label = "onefetch";
	stats[3].version = onefetch();
	stats[4].label = "pfetch";
	stats[4].version = pfetch();
	stats[5].label = "UwUfetch";
	stats[5].version = uwufetch();
	return stats;
}
