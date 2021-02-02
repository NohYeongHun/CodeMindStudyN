# include<>
- <>안의 라이브러리나 헤더파일을 해당 라인에 불러온다.
ex)
```c++
#include<iostream> //1번라인
1번라인에 iostream을 불러온다.
```
# #if~endif
- #if 조건이 만족하지 않으면 if~endif 사이의 라인들을 무효화 시킴.
- ex) 
```c++
    #if D!=0 
    #include <string>

    #include <boost\wave\token_ids.hpp>

    #include "slex_token.hpp"
    #include "slex_iterator.hpp"

    #include <boost\wave\grammars\cpp_expression_grammar.hpp>

///////////////////////////////////////////////////////////////////////////////
//  
//  Explicit instantiation of the expression_grammar_gen template with the 
//  correct token type. This instantiates the corresponding parse function, 
//  which in turn instantiates the expression_grammar object (see 
//  wave/grammars/cpp_expression_grammar.hpp)
//
///////////////////////////////////////////////////////////////////////////////

typedef boost::wave::cpplexer::slex_token<> token_type;

template struct boost::wave::grammars::expression_grammar_gen<token_type>;
    #endif
    해당 라인들이 다 무효화됨.
```