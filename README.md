# hifive1b_bootloader [RED-V]
_A bootloader for SiFive HiFive 1B based on cyancore_

This bootloader is used to reset clock and give a 2 sec delay before booting to the application code.

This is necessary for the developer to tap into the cpu for debugging before entering the buggy application that may cut the clock.

---

### Build the bootloader
Steps to build the BL for Hifive 1B. (Note: The LED is used for Sparkfun RedV Things board, please change as per your board)

1. Clone cyancore framework
2. cd to projects
3. clone this repository
4. cd to root directory of cyancore
5. run `make list`
6. run `make hifive1b_bootloader`, Note: Toolchain is necessary to build, please refer [wiki](https://github.com/VisorFolks/cyancore/wiki)
7. Flash using Ozone (Segger), use .bin/.hex to flash.

![Bootloader](https://raw.githubusercontent.com/VisorFolks/vf_artifacts/stable/cyancore/images/misc/hifive1b_bootloader.png)
