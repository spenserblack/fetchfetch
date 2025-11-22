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

static const char app_version_fallback[STATS_VERSION_SIZE] = "Not installed\0";

/**
 * Calls a shell command and copies the output to a buffer.
 *
 * Falls back to "Not installed" if the command fails.
 */
static void
app_version(const char *restrict command, char buf[static STATS_VERSION_SIZE]) {
	char redirected_command[50];

	strcpy(redirected_command, command);
	strcat(redirected_command, " 2>/dev/null");

	FILE *fp = popen(redirected_command, "r");
	if (fp == NULL) {
		strcpy(buf, app_version_fallback);
		return;
	}

	const bool failed_to_read = fgets(buf, STATS_VERSION_SIZE, fp) == NULL;
	pclose(fp);

	if (failed_to_read || buf[0] == '\0') {
		strcpy(buf, app_version_fallback);
	}

	char c;

	// NOTE Trim at end of version string.
	for (unsigned char i = 0; i < STATS_VERSION_SIZE && (c = buf[i]) != '\0'; ++i) {
		switch (c) {
		case '\r':
		case '\n':
		case ' ':
			buf[i] = '\0';
			return;
		}
	}
}

static const char prefix_not_found[STATS_VERSION_SIZE] =
	"<unexpected version output>\0";

/**
 * Matches the provided prefix from the beginning of the version_info string, and
 * extracts the version that follows it until a boundary character is found into buf.
 */
static void extract_named_version(
	const char *version_info, const char *restrict prefix,
	const unsigned int prefix_len, char buf[static STATS_VERSION_SIZE]
) {
	unsigned int start;

	if (strcmp(version_info, app_version_fallback) == 0) {
		strcpy(buf, app_version_fallback);
		return;
	}

	for (start = 0; prefix[start] != '\0'; ++start) {
		if (version_info[start] != prefix[start]) {
			strcpy(buf, prefix_not_found);
			return;
		}
	}

	strncpy(buf, version_info + start, STATS_VERSION_SIZE - 1);
	buf[STATS_VERSION_SIZE - 1] = '\0';
}

void fastfetch(char buf[static STATS_VERSION_SIZE]) {
	// NOTE Version in the format "fastfetch x.x.x (ARCH)"
	const char prefix[] = "fastfetch ";
	char tmp[STATS_VERSION_SIZE];
	app_version("fastfetch --version", tmp);
	extract_named_version(tmp, prefix, (sizeof(prefix) / sizeof(char)), buf);
}

static void fetchfetch(char buf[static STATS_VERSION_SIZE]) { strcpy(buf, version); }

void hyfetch(char buf[static STATS_VERSION_SIZE]) {
	// NOTE Version in the format "Version: x.x.x"
	const char prefix[] = "Version: ";
	char tmp[STATS_VERSION_SIZE];
	app_version("hyfetch --version", tmp);
	extract_named_version(tmp, prefix, (sizeof(prefix) / sizeof(char)), buf);
}

void neofetch(char buf[static STATS_VERSION_SIZE]) {
	// NOTE Version in the format "Neofetch x.x.x"
	const char prefix[] = "Neofetch ";
	char tmp[STATS_VERSION_SIZE];
	app_version("neofetch --version", tmp);
	extract_named_version(tmp, prefix, (sizeof(prefix) / sizeof(char)), buf);
}

void onefetch(char buf[static STATS_VERSION_SIZE]) {
	// NOTE Version in the format "onefetch x.x.x"
	const char prefix[] = "onefetch ";
	char tmp[STATS_VERSION_SIZE];
	app_version("onefetch --version", tmp);
	extract_named_version(tmp, prefix, (sizeof(prefix) / sizeof(char)), buf);
}

void pfetch(char buf[static STATS_VERSION_SIZE]) {
	// NOTE Version in the format "pfetch x.x.x"
	const char prefix[] = "pfetch ";
	char tmp[STATS_VERSION_SIZE];
	app_version("pfetch --version", tmp);
	extract_named_version(tmp, prefix, (sizeof(prefix) / sizeof(char)), buf);
}

void screenfetch(char buf[static STATS_VERSION_SIZE]) {
	// NOTE Version in the format "screenFetch - Version x.x.x"
	const char prefix[] = "[4mscreenFetch[0m - Version ";
	char tmp[STATS_VERSION_SIZE];
	app_version("screenfetch --version", tmp);
	extract_named_version(tmp, prefix, (sizeof(prefix) / sizeof(char)), buf);
}

void uwufetch(char buf[static STATS_VERSION_SIZE]) {
	// NOTE Version in the format "UwUfetch version x.x"
	const char prefix[] = "UwUfetch version ";
	char tmp[STATS_VERSION_SIZE];
	app_version("uwufetch --version", tmp);
	extract_named_version(tmp, prefix, (sizeof(prefix) / sizeof(char)), buf);
}

const FetchStat stats[STATS_SIZE] = {
	{.label = "Fastfetch", .fetcher = fastfetch},
	{.label = "fetchfetch", .fetcher = fetchfetch},
	{.label = "hyfetch", .fetcher = hyfetch},
	{.label = "Neofetch", .fetcher = neofetch},
	{.label = "onefetch", .fetcher = onefetch},
	{.label = "pfetch", .fetcher = pfetch},
	{.label = "screenFetch", .fetcher = screenfetch},
	{.label = "UwUfetch", .fetcher = uwufetch},
};
