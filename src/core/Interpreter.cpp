#include "Interpreter.h"
#include <iostream>

Interpreter::Interpreter() 
{
    initAddressOpcodeTable();
    initAddressOpcodeMap();
}

void Interpreter::initAddressOpcodeTable()
{
{
    m_opcodeAddrTable.fill([](Interpreter& i){ i.invalidOpcode(); });
    m_opcodeAddrTable[0x0] = [](Interpreter& i){ i.AP0(); };
}
}

void Interpreter::initAddressOpcodeMap() {
    m_addressOpcodeMap = {
        { "AP.0",  AP0_VAL << ASTACK_OPCODE_SHIFT | (1 << 17) },
    };
}

std::string Interpreter::getStackState()
{
    std::string address_stack;
    for(const auto value : m_addressStack)
        {
            address_stack += std::format("0x{:02X}\n", value);
        }
    return address_stack;
}

void Interpreter::execute(uint32_t opcode)
{
    decodeSingleInstruction(opcode);
}

void Interpreter::executeOpcodeName(std::string opcode)
{
    auto it = m_addressOpcodeMap.find(opcode);
    if (it != m_addressOpcodeMap.end())
    {
        decodeSingleInstruction(it->second);
    }
}

void Interpreter::decodeSingleInstruction(uint32_t opcode)
{
    bool is_extended {(opcode & EXTENDED_MASK) >> EXTENDED_SHIFT };
    if(is_extended)
    {
        return;
    }
    else
    {   
        uint32_t address_opcode {(opcode & ASTACK_OPCODE_MASK) >> ASTACK_OPCODE_SHIFT};
        executeAddressInstruction(address_opcode);
    }
}

void Interpreter::executeAddressInstruction(uint32_t address_opcode)
{
    m_opcodeAddrTable[address_opcode](*this);
}

void Interpreter::AP0()
{
    std::cout << "test";
    m_addressStack.push_back(0);
}

void Interpreter::invalidOpcode()
{
    std::cout << "Invalid instruction";
}

void Interpreter::updateT() {
    if(m_addressStack.back() == 0)
    {
        m_flagT = 0;
    }
}
