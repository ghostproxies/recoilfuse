# RecoilFuse™

[![RecoilFuse™](https://repository-images.githubusercontent.com/1194828506/810e0ef3-a313-4c82-b30f-68a85d18e07f)](https://github.com/ghostproxies/recoilfuse)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Reference](README.md?tab=readme-ov-file#reference)
- [Enterprise](README.md?tab=readme-ov-file#enterprise)

## Introduction

RecoilFuse™ is the efficient 64-bit PRNG for 128-bit output.

It's a non-cryptographic PRNG to replace non-cryptographic PRNGs that require 64-bit architecture, 128-bit output, a minimum period of at least 2⁶⁴ and hyper-fast speed.

Furthermore, it has independent parallel sequences and reversibility.

## Author

RecoilFuse™ was created by [William Stafford Parsons](https://github.com/williamstaffordparsons) as a product of [GhostProxies](https://ghostproxies.com).

## License

RecoilFuse™ is licensed with the [BSD-3-Clause](LICENSE) license.

## Reference

RecoilFuse™ was implemented in C (requiring the `stdint.h` header to define a 64-bit, unsigned integral type for `uint64_t`).

[recoilfuse.c](recoilfuse.c)

The `recoilfuse` function modifies the state in a `struct recoilfuse_state` instance to generate 2 pseudorandom `uint64_t` integers in the `output` array.

Each state variable (`a`, `b`, `c` and each integer in the `output` array) in a `struct recoilfuse_state` instance must be seeded.

RecoilFuse™ uses a Weyl sequence to generate deterministic sequences that each have a minimum period of at least 2⁶⁴.

Furthermore, RecoilFuse™ can be configured to generate independent sequences within a larger sequence that has upper-bounded asymptotic equidistribution and outputs at least 1 of each 64-bit integer.

To prevent full state collisions among parallel sequences, RecoilFuse™ uses [PulseField™](https://github.com/ghostproxies/pulsefield) instead of jump functions (jumping an arbitrary number of steps is redundant in the remaining practical use cases that require full sequence reproducibility).

As specified by [PulseField™](https://github.com/ghostproxies/pulsefield), RecoilFuse™ can generate up to 2⁶⁴ parallel instances that each avoid full state collisions (for at least 2⁶⁴ output results) among the set of parallel instances.

Skipping the first several `recoilfuse` function invocation results from each parallel instance reduces correlations among the set of parallel instances.

When each state variable was seeded with `0`, RecoilFuse™ had no default test failures in PractRand 0.96 `stdin64` (for up to at least 2TB) and TestU01 1.2.3 BigCrush (using the 128-bit output as 4 32-bit integers). The remaining PractRand 0.96 `stdin64` test results for up to at least 32TB are coming soon.

Each of the following PRNG speed test results log the fastest process execution speed (from an AMD A4-9120C) among several repetitions of a test that generates (and hashes) 1 billion pseudorandom `uint64_t` integers in a `#pragma GCC unroll 0` loop.

| PRNG | Milliseconds |
| --- | --- |
| **`recoilfuse`** (`gcc -O3`) | **806ms** |
| `shishua_sse4` (`gcc -O3 -msse4`) | 978ms |
| `shishua_sse3` (`gcc -O3 -msse3`) | 1147ms |
| `shishua_sse2` (`gcc -O3 -msse2`)| 1154ms |

## Enterprise

GhostProxies provides the following enterprise solutions for DSA efficiency.

- [Nightmare™](https://ghostproxies.com/nightmare) is the DSA efficiency R&D retainer.
- [Tome™](https://ghostproxies.com/tome) is a multi-level SLA for GhostProxies products.
- [Ectoplasm™](https://ghostproxies.com/ectoplasm) is the qubit-aligned entropy schema for classical computers.
