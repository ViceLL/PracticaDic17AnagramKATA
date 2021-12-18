// C++AnagramKATA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

//Funcion para agrupar anagramas de una lista de palabras dadas
set<set<string>> groupAnagrams(vector<string> const& words)
{
    //un set para guardar anagrams
    set<set<string>> anagrams;

    // construir un vector con las palabras dadas con cada palabra sorteada
    vector<string> list(words);
    for (string& s : list) 
    {        
        sort(s.begin(), s.end());
    }
    // construct un mapa en el que el key es cada palabra sorteada
    // value es una lista de indices donde esta presente
    unordered_map<string, vector<int>> map;
    for (int i = 0; i < words.size(); i++) 
    {
        map[list[i]].push_back(i);
    }
    // traversa el mapa y lee indices para cada key sorteado
    // Los anagramas estan presentes en el list actual en esos indices
    for (auto itr : map)
    {
        set<string> anagram;
        for (int index : itr.second) {
            anagram.insert(words[index]);
        }
        if (anagram.size() > 1) {
            anagrams.insert(anagram);
        }
    }
    return anagrams;
}
int main()
{
    // vector de words
    vector<string> words =
    {
        "kinship", "enlist", "boaster", "fresher", "sinks", "knits", "rots",
        "pinkish", "inlets", "boaters", "refresh", "skins", "stink", "sort",
        "listen", "borates", "silent"
    };

    // get set con todos los anagramas agrupados
    set<set<string>> anagrams = groupAnagrams(words);

    // print el resultado
    for (set<string> anagram : anagrams) 
    {
        for (string s : anagram) 
{
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}
