cmake_minimum_required(VERSION 3.16.3)
project(236_Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(236_Project1 main.cpp
        Lexer.cpp
        Lexer.h
        AddAutomaton.h
        AddAutomaton.cpp
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        Facts.cpp
        Facts.h
        ID.cpp
        ID.h
        Left_Paren.cpp
        Left_Paren.h
        Multiply.cpp
        Multiply.h
        Period.cpp
        Period.h
        Q_Mark.cpp
        Q_Mark.h
        Queries.cpp
        Queries.h
        Right_Paren.cpp
        Right_Paren.h
        Rules.cpp
        Rules.h
        Schemes.cpp
        Schemes.h
        String.cpp
        String.h
        Single_Comment.cpp
        Single_Comment.h
        Multi_Comment.cpp
        Multi_Comment.h
        Token.cpp
        Token.h)
