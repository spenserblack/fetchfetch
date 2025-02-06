# Contributing

This project uses [clang format][clang-format] to format code. You can run the formatter
with `make format`.

## Supporting a new `*fetch`

Define a new function in [`src/stats.h`][stats-header] and
[`src/stats.c`][stats-implementation] for your `*fetch` tool. For example, if the tool
was called `examplefetch`, then you would define a new function `examplefetch()`.

Then, update `get_stats()` to use that newly defined function. The stats should be in
case-insensitive alphabetical order.

Finally, update the section "Supported `*fetch` tools" in the [`README.md`][readme] to
list the newly supported tool.

### Updating the example output (optional)

This shouldn't be updated too often, since everyone's environment is different and
constant updates can result in too much file churn. But after a few new `*fetch` tools
get support, it might be a good idea to update the example output in the
[`README.md`][readme]. You can always just copy and paste output from your terminal, but
here are some beginner-friendly examples to copy the output to your clipboard, so you
just have to paste into your text editor.

#### Unix

```shell
fetchfetch | xclip -selection clipboard
```

#### Windows

```batch
rem cmd.exe
fetchfetch.exe | clip.exe
```

```powershell
# PowerShell
fetchfetch.exe | Set-Clipboard
```

[clang-format]: https://clang.llvm.org/docs/ClangFormat.html
[readme]: ./README.md
[stats-header]: ./src/stats.h
[stats-implementation]: ./src/stats.c
