#pragma once

#include <vector>

#include "Dumping/AbstractTextDumper.h"

class StructuredDataDefDumper : AbstractTextDumper
{
    enum class Block
    {
        BLOCK_NONE = 0,
        BLOCK_ENUM = 1,
        BLOCK_STRUCT = 2,
        BLOCK_PROPERTY = 3
    } m_block;

    struct
    {
        bool m_in_version : 1;
        bool m_empty_line_before_version : 1;
        bool m_empty_line_before_block : 1;
    } m_flags;

    std::vector<std::string> m_enum_entries;
    size_t m_enum_size;

    std::string m_property_name;
    std::string m_property_type_name;
    std::vector<std::string> m_property_array_specifiers;

public:
    explicit StructuredDataDefDumper(std::ostream& stream);

    void BeginVersion(int version);
    void EndVersion();

    void BeginEnum(const std::string& enumName, size_t enumEntryCount);
    void EndEnum();
    void WriteEnumEntry(const std::string& entryName, size_t entryValue);

    void BeginStruct(const std::string& structName);
    void EndStruct();
    void BeginProperty(const std::string& propertyName);
    void AddPropertyArraySpecifier(const std::string& specifierName);
    void SetPropertyTypeName(const std::string& typeName);
    void EndProperty();
};
