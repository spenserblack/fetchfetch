# `fetchfetch`

[![CI](https://github.com/spenserblack/fetchfetch/actions/workflows/ci.yml/badge.svg)](https://github.com/spenserblack/fetchfetch/actions/workflows/ci.yml)

Fetch information about your `*fetch` tools.

## Example

```console
$ fetchfetch
 ______________________________________
|                                      | Fastfetch: 2.55.0
|  >_                                  | fetchfetch: 1.1.0
|                                      | hyfetch: 2.0.4
|                                      | Neofetch: Not installed
|                                      | onefetch: Not installed
|                                      | pfetch: Not installed
|                                      | UwUfetch: 2.1
|                                      |
|______________________________________|
```

## Supported `*fetch` tools

* [Fastfetch][fastfetch]
* [Hyfetch][hyfetch]
* [Neofetch][neofetch]
* [onefetch][onefetch]
* [pfetch][pfetch]
* [UwUfetch][uwufetch]
* [screenFetch][screenfetch]

[fastfetch]: https://github.com/fastfetch-cli/fastfetch
[hyfetch]: https://github.com/hykilpikonna/hyfetch
[neofetch]: https://github.com/dylanaraps/neofetch
[onefetch]: https://github.com/o2sh/onefetch
[pfetch]: https://github.com/dylanaraps/pfetch
[uwufetch]: https://github.com/ad-oliviero/uwufetch
[screenfetch]: https://github.com/KittyKatt/screenFetch

## Installation

[![Packaging status](https://repology.org/badge/vertical-allrepos/fetchfetch.svg)](https://repology.org/project/fetchfetch/versions)

### Arch Linux

fetchfetch is available as [an AUR package][fastfetch-aur].
It can be installed using an AUR helper (e.g. paru):

```shell
paru -S fetchfetch
```

### From source

```shell
git clone https://github.com/spenserblack/fetchfetch
cd fetchfetch
sudo make install
```

[fastfetch-aur]: https://aur.archlinux.org/packages/fetchfetch
