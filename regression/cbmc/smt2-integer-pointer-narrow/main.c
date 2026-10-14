// Author: Philip Zucker

/// \file
/// Exercise a wide integer cast narrowed to a 32-bit pointer by simplification.

// Avoid depending on host 32-bit system headers.
typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned int uintptr_t;

uint64_t nondet_u64(void);

int main(void)
{
  uint64_t address = nondet_u64();
  __CPROVER_assume((uint32_t)address == 0x12345678u);
  void *pointer = (void *)(uintptr_t)address;
  __CPROVER_assert(
    pointer == (void *)(uintptr_t)0x12345678u, "narrowed pointer value");
}
