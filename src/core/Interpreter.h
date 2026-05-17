#pragma once
#include "address_opcode_map.h"
#include "constants.h"
#include <cstdint>
#include <vector>
#include <array>
#include <functional>
#include <string>
#include <unordered_map>


class Interpreter
{
    public:
        Interpreter();
        void execute(uint32_t opcode);
        void executeOpcodeName(std::string opcode);
        std::string getStackState();

    private:
        bool m_flagT{};
        std::vector<uint16_t> m_addressStack;
        std::vector<uint16_t> m_dataStack;
        std::vector<uint16_t> m_returnStack;
        std::unordered_map<std::string, uint32_t> m_addressOpcodeMap;
        using OpcodeHandler = std::function<void(Interpreter&)>;
        std::array<OpcodeHandler, 256> m_opcodeStackTable;
        std::array<OpcodeHandler, 256> m_opcodeAddrTable;
        std::array<OpcodeHandler, 256> m_opcodeDataTable;
        void decodeSingleInstruction(uint32_t opcode);
        void initAddressOpcodeTable();
        void initAddressOpcodeMap();
        void executeAddressInstruction(uint32_t address_opcode);

        void invalidOpcode();
        void AP0();
        void updateT();
};