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
#include "art.h"
#include "stats.h"

int main(int argc, char *argv[]) {
	FetchStat *stats = get_stats();
	for (int line_index = 0; line_index < ART_HEIGHT || line_index < STATS_SIZE; line_index++) {
		if (line_index < ART_HEIGHT) {
			for (int col_index = 0; col_index < ART_WIDTH; col_index++) {
				putchar(art[line_index][col_index]);
			}
		} else {
			printf(ART_FILLER);
		}

		// NOTE We skip a line because it looks a little better.
		if (line_index != 0 && line_index <= STATS_SIZE) {
			printf(" %s: %s", stats[line_index - 1].label, stats[line_index - 1].version);
		}
		printf("\n");
	}
	return 0;
}
