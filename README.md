# Aplikacja Drzewa Genealogicznego

> Projekt aplikacji drzewa genealogicznego na zaliczenie Inżynierii Oprogramowania

Wersja repozytorium: **1.5**

---

### Lista zmian (v.1.5)
- Dodanie kolejnej wersji DP
- Dodanie kolejnej wersji DF
- Dodanie działącej bazy aplikacji Drzewa Genealogicznego
- Dodanie kolejnych wersji oprogramowania Drzewa Genealogicznego
- Dodanie v4
- Dodanie v5

### Struktura zmian
```
  .
    ├── DP                   
        ├── inop_78_Stefanski_(DP)_v_2_0.pdf          # Pierwsza coś zawierająca dokumentacja projektu          
        ├── inop_78_Stefanski_(DP)_v_3_0.pdf          # Obszerna dokumentacja projektu (FS, FOW)
        ├── inop_78_Stefanski_(DP)_v_4_0.pdf          # Obszerna dokumentacja projektu (FS, FOW (poprawki), FA)
        ├── inop_78_Stefanski_(DP)_v_5_0.pdf          # Obszerna dokumentacja projektu (FS, FOW, FA, FP)
        ├── inop_78_Stefanski_(DP)_v_6_0.pdf          # Odchudzona dokumentacja, poprawiony Algorytm
        ├── inop_78_Stefanski_(DP)_v_7_0.pdf          # Generowany spis treści, aktualizacje
        ├── inop_78_Stefanski_(DP)_v_9.0.pdf          # Uzupełnienie dokumentacji, dopisanie funkcjonalności
        └── README.md
    ├── DF
        ├── inop_78_Stefanski_(DF)_v_3_0.pdf          # Pierwsza znacząca dokumentacja firmy z poprawkami
        └── inop_78_Stefanski_(DF)_v_4_0.pdf          # Generowany spis treści, aktualizacje
    ├── Solution
        ├── tree.exe                                  # Działająca baza programu (plik wykonywalny)
        ├── v2
        │   ├── Date.cpp
        │   ├── Date.h
        │   ├── in.txt                                # Przykładowy plik wejściowy
        │   ├── menu.cpp
        │   ├── Person.cpp
        │   ├── Person.h
        │   ├── Tree.cpp
        │   ├── Tree.h
        │   └── tree_v2.exe                           # Działający program drzewa genealogicznego (brak wsparcia dla Windows XP)
        └── v3
        │   ├── tree
        │   │   ├── include
        │   │   │   ├── Date.h
        │   │   │   ├── Person.h
        │   │   │   └── Tree.h
        │   │   ├── src
        │   │   │   ├── Date.cpp
        │   │   │   ├── Person.cpp
        │   │   │   └── Tree.cpp
        │   │   ├── in.txt                            # Przykładowy plik wejściowy
        │   │   ├── main.cpp
        │   │   ├── tree.zip                          # Kod źródłowy spakowany wraz z plikiem wykonywalnym
        │   │   └── tree_v3.exe                       # Działający program (eliminowanie błędów) wsparcie dla Windows XP
        │   └── tree_pl_char
        │       ├── include
        │       │   ├── Date.h
        │       │   ├── Person.h
        │       │   └── Tree.h
        │       ├── src
        │       │   ├── Date.cpp
        │       │   ├── Person.cpp
        │       │   └── Tree.cpp
        │       ├── in.txt                            # Przykładowy plik wejściowy
        │       ├── main.cpp
        │       ├── tree_pl_char.zip                  # Kod źródłowy spakowany wraz z plikiem wykonywalnym
        │       └── tree_pl_char.exe                  # Działający program (eliminowanie błędów) Polskie znaki (nie dla XP)
        │
        └── v4 | v5                                   # poprawki w V5
            ├── tree
            │   ├── include
            │   │   ├── Date.h
            │   │   ├── Person.h
            │   │   └── Tree.h
            │   ├── src
            │   │   ├── Date.cpp
            │   │   ├── Person.cpp
            │   │   └── Tree.cpp
            │   ├── in.txt                            # Przykładowy plik wejściowy
            │   ├── main.cpp
            │   ├── resources.rc                      # Dodanie ikony
            │   ├── tree.ico                          # Ikona
            │   ├── tree_v4.zip                       # Kod źródłowy spakowany wraz z plikiem wykonywalnym
            │   └── tree_v4.exe                       # Działający program (eliminowanie błędów) wsparcie dla Windows XP
            └── tree_v4_pl_char | tree_v5_pl_char
                ├── include
                │   ├── Date.h
                │   ├── Person.h
                │   └── Tree.h
                ├── src
                │   ├── Date.cpp
                │   ├── Person.cpp
                │   └── Tree.cpp
                ├── in.txt                            # Przykładowy plik wejściowy
                ├── main.cpp
                ├── resources.rc                      # Dodanie ikony
                ├── tree.ico
                ├── tree_v4_pl_char.zip | tree_v5_pl_char.zip   # Kod źródłowy spakowany wraz z plikiem wykonywalnym
                └── tree_v4_pl_char.exe | tree_v5_pl_char.exe   # Działający program (eliminowanie błędów) Polskie znaki (nie dla XP)
```