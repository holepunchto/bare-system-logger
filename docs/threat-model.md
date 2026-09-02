# Threat model

## What this is

`bare-system-logger` is compiled into Bare. It is listed in `src/builtins.json`, so every Bare process has it. That holds whether or not the process sealed, and no code has to load anything to reach it.

So this addon is part of Bare, and [Bare's threat model](https://github.com/holepunchto/bare/blob/main/docs/threat-model.md) covers it. Read that one first. This one only says where this addon sits in it.

## What it inherits

- **The promise.** Bare promises a sealed process gets no new native code. This addon is native code that is already in, so the seal neither adds it nor takes it away.
- **The attacker.** Untrusted JavaScript in a sealed process. It writes what it likes, runs on as many threads as it wants, and calls anything it can reach in any order and all at once. It can reach all of this addon.
- **The trust.** This addon is trusted, because Bare compiles it in. Whatever you compile in is your security policy, and this is one of the things you picked.
- **The walls.** The same table applies. A thread is not a wall and neither is a realm, so nothing here gets to assume it is alone.
- **The rules.** What Bare says to report, and what Bare says is not a bug, is the same here.

## What counts

- **Counts:** `binding.c` and the JavaScript that ships with it. Sealed JavaScript reaches all of it without loading a thing.
- **Does not count:** tests, benchmarks, and scratch code.

## What this addon adds

Writes to the operating system log, and a fatal level that ends the process.

Bare's document lists writing to the system log under what still works after the seal. This addon is how. Ending the process is already granted by `Bare.exit()`, so the fatal level adds nothing there.

## Where the risk is

This is a way out of the process, and it is the one builtin whose output does not go to the embedder's own two descriptors. Sealed code can put whatever it likes into it. If the system log leaves the device, or the platform collects it, or other apps can read it, treat this as a way to get data out and turn it off at the OS level. The seal will not.

The C formats strings that JavaScript picked and turns them into UTF-8.

## What to report

- Memory bugs in `binding.c` that JavaScript can reach, above all in formatting and UTF-8 conversion
- Any way to get more out of the logging facility than writing a message at a level
- Anything on Bare's report list

Not a bug: that sealed code can write to the system log, or end the process. Bare grants both.
