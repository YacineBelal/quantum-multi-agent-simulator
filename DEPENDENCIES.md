# Dependencies and build notes

## External multi-agent framework

The archived makefiles refer to the following layout:

```text
GestionAgents/
└── LibMoRis/
    ├── include/   # MAS.h, Agent.h, ...
    └── lib/       # libAgents.a
```

They set `AGENTSLIBNAME=Agents`, include `${DIRAGENTS}/LibMoRis/include`, and link against `${DIRAGENTS}/LibMoRis/lib/libAgents.a`. The source files include `MAS.h` and `Agent.h`.

The framework itself is **not present** in the supplied archive. The name `MoRis` alone is not enough to identify its provenance: a currently public GitHub project named [MoRIS](https://github.com/charlesrocabert/MoRIS) is a different application (Model of Routes of Invasive Spread), not the multi-agent runtime referenced by these makefiles. Do not substitute it.

## Toolchain

The historical makefiles use `g++` and GNU Make. They enable `-Wall -Werror -pedantic`. The source also uses POSIX `unistd.h` in example programs. Exact compiler and framework versions are unknown.

## Reproducibility

A complete dependency lockfile cannot be supplied from the available material. To make this project reproducible, the original `GestionAgents/LibMoRis` source/library, its license, its version/commit, and the original build environment would need to be recovered.
