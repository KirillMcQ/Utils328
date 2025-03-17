# Utils 328

This library provides bare bone utilies to use some key features on the ATmega328P.

**These libraries are specific to the ATmega328P, and must be modified for use on other processors.**

## Key files

### `Serial328.h`

- This file contains key functions that enable the ATmega328P to communicate via USB to the computer through USB.
- `Serial_begin(baud)` **must** be called before using any other Serial function in this file.

### `Delay328.h`

- This file contains the `delay(seconds)` function, and allows a delay for a specified amount of seconds.
- This only allows an integer amount of seconds, but a fix for this is in progress.
- `getCounterValue(seconds)` provides no value outside of its use inside `delay(seconds)`.
