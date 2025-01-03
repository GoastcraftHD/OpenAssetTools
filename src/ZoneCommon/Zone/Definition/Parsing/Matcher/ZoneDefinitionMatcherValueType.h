#pragma once

#include "Parsing/Matcher/AbstractMatcher.h"
#include "Zone/Definition/Parsing/ZoneDefinitionParserValue.h"

class ZoneDefinitionMatcherValueType final : public AbstractMatcher<ZoneDefinitionParserValue>
{
    ZoneDefinitionParserValueType m_type;

protected:
    MatcherResult<ZoneDefinitionParserValue> CanMatch(ILexer<ZoneDefinitionParserValue>* lexer, unsigned tokenOffset) override;

public:
    explicit ZoneDefinitionMatcherValueType(ZoneDefinitionParserValueType type);
};
