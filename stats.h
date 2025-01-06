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
#ifndef FETCH_FETCH_STATS_H
#define FETCH_FETCH_STATS_H

typedef struct {
	char *label;
	char *version;
} FetchStat;

/**
 * Gets Fastfetch version information.
 */
const char* fastfetch();

/**
 * Gets Neofetch version information.
 */
const char* neofetch();

/**
 * Gets onefetch version information.
 */
const char* onefetch();

/**
 * Gets UwUfetch version information.
 */
char* uwufetch();

#define STATS_SIZE 4
/**
 * Gets all stats.
 */
FetchStat* get_stats();

#endif
