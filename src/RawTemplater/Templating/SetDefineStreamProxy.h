#pragma once

#include "Parsing/Impl/AbstractDirectiveStreamProxy.h"
#include "Parsing/Impl/DefinesStreamProxy.h"
#include "Utils/ClassUtils.h"

namespace templating
{
    class SetDefineStreamProxy final : public AbstractDirectiveStreamProxy
    {
    public:
        explicit SetDefineStreamProxy(IParserLineStream* stream);

        void SetDefinesProxy(DefinesStreamProxy* definesProxy);

        ParserLine NextLine() override;
        bool IncludeFile(const std::string& filename) override;
        void PopCurrentFile() override;
        _NODISCARD bool IsOpen() const override;
        _NODISCARD bool Eof() const override;

    private:
        static constexpr const char* SET_DIRECTIVE = "set";

        _NODISCARD bool MatchSetDirective(const ParserLine& line, size_t directiveStartPosition, size_t directiveEndPosition) const;
        _NODISCARD bool MatchDirectives(const ParserLine& line) const;

        IParserLineStream* const m_stream;
        DefinesStreamProxy* m_defines_proxy;
    };
} // namespace templating
