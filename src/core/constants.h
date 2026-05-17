#pragma once
#include <cstdint>

constexpr uint8_t EXTENDED_SHIFT {16};
constexpr uint32_t EXTENDED_MASK {0b1};
constexpr uint32_t ASTACK_OPCODE_SHIFT {12};
constexpr uint32_t ASTACK_OPCODE_MASK {0b11111 << ASTACK_OPCODE_SHIFT};